#include <fstream>
#include <filesystem>

#include "Class.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Class::loadClasses()
{
	std::filesystem::path path(CLASSES_PATH);

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
		return 0;
	}

	clearClasses();

	for (auto file : std::filesystem::directory_iterator(path))
	{
		loadOneClass(file.path());
	}

	return 1;
}

void Class::loadOneClass(const std::filesystem::path &path)
{
	createClass(path.stem().string());
	Class &currClass = g_classes.back();

	std::ifstream fi;
	fi.open(path);

	if (!fi.is_open())
	{
		return;
	}

	loadOneClassCourses(fi, currClass);
	loadOneClassStudents(fi, currClass);
}

void Class::loadOneClassCourses(std::ifstream &fi, Class &currClass)
{
	std::string line;
	std::getline(fi, line);
	std::stringstream streamLine(line);

	std::string courseID;
	while (std::getline(streamLine, courseID, ','))
	{
		auto currCourse = g_courses.find_if(
			[&](const Course &course) -> bool
			{
				return course.getID() == courseID;
			});
		
		if (currCourse == g_courses.end())
		{
			continue;
		}

		currClass.addCourse(&*currCourse);
	}
}

void Class::loadOneClassStudents(std::ifstream &fi, Class &currClass)
{
	
	std::string line;
	while (std::getline(fi, line))
	{
		std::stringstream streamLine(line);
		std::string no, studentID, firstName, lastName, gender, dateOfBirth, socialID;

		std::getline(streamLine, no, ',');

		if (!std::getline(streamLine, studentID, ','))
		{
			continue;
		}

		List<Student>::iterator currStudent;
		if (Student::createStudent(studentID))
		{
			currStudent = g_students.end() - 1;
		}
		else
		{
			currStudent = g_students.find_if(
				[&](const Student &student) -> bool
				{
					return student.getID() == studentID;
				});
		}
		currClass.addStudent(&*currStudent);

		std::getline(streamLine, firstName, ',');
		currStudent->setFirstName(firstName);

		std::getline(streamLine, lastName, ',');
		currStudent->setLastName(lastName);

		std::getline(streamLine, gender, ',');
		currStudent->setGender(gender);

		std::getline(streamLine, dateOfBirth, ',');
		currStudent->setDateOfBirth(dateOfBirth);

		std::getline(streamLine, socialID, ',');
		currStudent->setSocialID(socialID);
	}
}

void Class::saveClasses()
{
	std::filesystem::path classesPath(CLASSES_PATH);
	std::filesystem::remove_all(classesPath);
	std::filesystem::create_directories(classesPath);

	for (auto iClass = g_classes.begin(); iClass != g_classes.end(); ++iClass)
	{
		saveOneClass(&*iClass);
	}
}

void Class::saveOneClass(Class *currClass)
{
	std::filesystem::path path(CLASSES_PATH + "/" + currClass->getID() + ".csv");
	std::ofstream fo(path);

	for (Course* const& course: currClass->courses())
	{
		fo << course->getID() << ',';
	}
	fo << '\n';

	int no = 0;
	for (const Student *student: currClass->students())
	{
		fo << ++no << ',';
		fo << student->getID() << ',';
		fo << student->getFirstName() << ',';
		fo << student->getLastName() << ',';
		fo << Account::genderToString(student->getGender()) << ',';
		fo << Date::dateToString(student->getDateOfBirth()) << ',';
		fo << student->getSocialID() << '\n';
	}
}

void Class::clearClasses()
{
	while (!g_classes.empty())
	{
		Class &currClass = g_classes.front();
		while (!currClass.students().empty())
		{
			currClass.removeStudent(currClass.students().front());
		}
		g_classes.pop_front();
	}
}

bool Class::createClass(const std::string &id)
{
	if (g_classes.find_if(
			[&](const Class &currClass) -> bool
			{
				return currClass.getID() == id;
			}) != g_classes.end())
	{
		return 0;
	}

	g_classes.push_back(Class(id));
	return 1;
}

bool Class::deleteClass(const std::string &id)
{
	auto currClass = g_classes.find_if(
		[&](const Class &class_) -> bool
		{
			return class_.getID() == id;
		});

	if (currClass == g_classes.end())
	{
		return 0;
	}

	while (!currClass->students().empty())
	{
		currClass->removeStudent(currClass->students().front());
	}

	while (!currClass->courses().empty())
	{
		Course::deleteCourse(currClass->courses().front()->getID());
	}

	g_classes.erase(currClass);

	return 1;
}

Class::Class()
{
}

Class::Class(const std::string &nID)
{
	setID(nID);
}

const std::string &Class::getID() const
{
	return id_;
}

List<Student *> &Class::students()
{
	return students_;
}

const List<Student *> &Class::students() const
{
	return students_;
}

List<Course *> &Class::courses()
{
	return courses_;
}

const List<Course *> &Class::courses() const
{
	return courses_;
}

void Class::setID(const std::string &nID)
{
	id_ = nID;
}

bool Class::addStudent(Student *nStudent)
{
	// std::cerr << "BACKEND ADD STUDENT" << std::endl;
	// std::cerr << nStudent << std::endl;
	if (g_students.find_if(
			[&](const Student &student) -> bool
			{
				// std::cerr << &student << std::endl;
				return &student == nStudent;
			})
		== g_students.end())
	{
		return 0;
	}

	if (students().find(nStudent) != students().end())
	{
		return 0;
	}

	students().push_back(nStudent);

	if (nStudent->getClass())
	{
		nStudent->getClass()->removeStudent(nStudent);
	}

	nStudent->getClass() = this;

	return 1;
}

bool Class::removeStudent(Student *student)
{
	auto currStudent = students().find(student);

	if (currStudent == students().end())
	{
		return 0;
	}

	student->getClass() = nullptr;
	students().erase(currStudent);

	return 1;
}

bool Class::addCourse(Course *course)
{
	auto currCourse = courses().find(course);

	if (currCourse != courses().end())
	{
		return 0;
	}

	course->getClass() = this;
	courses().push_back(course);

	return 1;
}

bool Class::removeCourse(Course *course)
{
	auto currCourse = courses().find(course);

	if (currCourse == courses().end())
	{
		return 0;
	}

	course->getClass() = nullptr;
	courses().erase(currCourse);

	return 1;
}
