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

	for (auto file: std::filesystem::directory_iterator(path))
	{
		g_classes.push_back(Class(toString(file.path().stem())));
		loadOneClass(file.path());
	}
	return 1;
}

void Class::loadOneClass(const std::filesystem::path &path)
{
	Class &currClass = g_classes.back();
	
	std::ifstream fi(path);
	std::string line;
	std::stringstream streamLine;
	while (!std::getline(fi, line))
	{
		streamLine.str(line);

		std::string no, studentID, firstName, lastName, gender, dateOfBirth, socialID;
		
		std::getline(streamLine, no);
		
		if (!std::getline(streamLine, studentID))
		{
			continue;
		}
		
		auto currStudent = g_students.find_if(
			[&](const Student &student)
			{
				return student.getID() == studentID;
			});

		std::getline(streamLine, firstName);
		currStudent->setFirstName(firstName);

		std::getline(streamLine, lastName);
		currStudent->setLastName(lastName);

		std::getline(streamLine, gender);
		currStudent->setGender(gender);

		std::getline(streamLine, dateOfBirth);
		currStudent->setDateOfBirth(dateOfBirth);

		std::getline(streamLine, socialID);
		currStudent->setSocialID(socialID);
	}
}

Class::Class()
{}

Class::Class(const std::string &nID)
{
	setID(nID);
}

const std::string& Class::getID() const
{
	return id_;
}

const List<Student*>& Class::getStudents() const
{
	return students_;
}

void Class::setID(const std::string &nID)
{
	id_ = nID;
}

bool Class::addStudent(Student *nStudent)
{
	if (students_.find(nStudent) == students_.end())
	{
		return 0;
	}
	
	students_.push_back(nStudent);
	nStudent->class_ = this;
	return 1;
}
