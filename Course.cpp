#include <fstream>
#include <sstream>
#include <algorithm>

#include "Course.hpp"
#include "Student.hpp"
#include "Class.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Course::loadCourses(const std::filesystem::path &path, Semester *semester)
{
	if (!std::filesystem::exists(path))
	{
		return 0;
	}

	clearCourses(semester);

	for (auto courseFile: std::filesystem::directory_iterator(path))
	{
		loadOneCourse(courseFile.path(), semester);
	}
	return 1;
}

void Course::loadOneCourse(const std::filesystem::path &courseFile, Semester *semester)
{
	std::string courseFileStem = courseFile.stem().string();
	createCourse(courseFileStem, semester->getID(), semester->schoolYear()->getStartYear());

	std::ifstream fi(courseFile);
	loadOneCourseGeneral(fi);
	loadOneCourseStudents(fi);
}

void Course::loadOneCourseGeneral(std::ifstream &fi)
{
	Course &currCourse = g_courses.back();
	
	std::string line, word;

	/* course name
	 * teacher name
	 * max number of students
	 * number of credits
	 * MON,S1 */

	if (std::getline(fi, line))
	{
		currCourse.setCourseName(line);
	}
	if (std::getline(fi, line))
	{
		currCourse.setTeacherName(line);
	}
	if (std::getline(fi, line))
	{
		currCourse.setMaxStudents(std::stoi(line));
	}
	if (std::getline(fi, line))
	{
		currCourse.setNumberOfCredits(std::stoi(line));
	}

	/* MON,S1 */
	if (std::getline(fi, line))
	{
		std::stringstream streamLine(line);
		std::getline(streamLine, word, ',');
		currCourse.session().day = word;
		std::getline(streamLine, word, ',');
		currCourse.session().type = word;
	}
}

void Course::loadOneCourseStudents(std::ifstream &fi)
{
	Course &currCourse = g_courses.back();
	
	std::string line;
	
	// Read studentInfos' information
	// Each line's content has the form of:
	// no,ID,midtermMark,finalMark,otherMark,totalMark
	while (std::getline(fi, line))
	{
		std::stringstream streamLine(line);
		std::string no, id, midtermMark, finalMark, otherMark, totalMark;

		if (!std::getline(streamLine, no, ','))
		{
			continue;
		}
		
		if (!std::getline(streamLine, id, ','))
		{
			continue;
		}
		auto currStudent = g_students.find_if(
			[&](const Student &student) -> bool
			{
				return student.getID() == id;
			});
		if (currStudent == g_students.end())
		{
			Student::createStudent(id);
			currStudent = g_students.end()-1;
		}
		currCourse.addStudent(&*currStudent);

	    StudentInfo &currStudentInfo = currCourse.studentInfos().back();

		if (!std::getline(streamLine, midtermMark, ','))
		{
			continue;
		}
		currStudentInfo.midtermMark = std::stof(midtermMark);
		
		if (!std::getline(streamLine, finalMark, ','))
		{
			continue;
		}
		currStudentInfo.finalMark = std::stof(finalMark);
		
		if (!std::getline(streamLine, otherMark, ','))
		{
			continue;
		}
		currStudentInfo.otherMark = std::stof(otherMark);
		
		if (!std::getline(streamLine, totalMark, ','))
		{
			continue;
		}
		currStudentInfo.totalMark = std::stof(totalMark);
	}
}

void Course::saveCourses(const std::filesystem::path &path, const Semester *semester)
{
	std::filesystem::remove_all(path);
	std::filesystem::create_directories(path);
	
	std::ofstream fo;
	for (const Course *course: semester->courses())
	{
		if (!course)
		{
			continue;
		}
		fo.open(path/(course->getID() + ".csv"));
		saveOneCourseGeneral(fo, course);
		saveOneCourseStudents(fo, course);
		fo.close();
	}
}

void Course::saveOneCourseGeneral(std::ofstream &fo, const Course *course)
{
	fo << course->getCourseName() << '\n';
	fo << course->getTeacherName() << '\n';
	fo << course->getMaxStudents() << '\n';
	fo << course->getNumberOfCredits() << '\n';
	fo << course->session().day << ','
	   << course->session().type << '\n';
}

void Course::saveOneCourseStudents(std::ofstream &fo, const Course *course)
{
	int no = 0;
	for (const StudentInfo &studentInfo: course->studentInfos())
	{
		fo << ++no << ',';
		fo << studentInfo.student->getID() << ',';
		fo << studentInfo.midtermMark << ',';
		fo << studentInfo.finalMark << ',';
		fo << studentInfo.otherMark << ',';
		fo << studentInfo.totalMark << '\n';
	}
}

void Course::clearCourses(Semester *semester)
{
	while (!semester->courses().empty())
	{
		Course::deleteCourse(semester->courses().front()->getID());
	}
}

bool Course::createCourse(const std::string &courseID, int semesterID, int schoolStartYear)
{
	if (g_courses.find_if(
			[&](const Course &course) -> bool
			{
				return course.getID() == courseID;
			})
		!= g_courses.end())
	{
		return 0;
	}
	
    auto currSemester = g_semesters.find_if(
		[&](const Semester &semester) -> bool
		{
			return semester.schoolYear()->getStartYear() == schoolStartYear
				&& semester.getID() == semesterID;
		});

	if (currSemester == g_semesters.end())
	{
		return 0;
	}

	std::string classID = courseID_to_classID(courseID);
	
	auto currClass = g_classes.find_if(
		[&](const Class &class_) -> bool
		{
			return class_.getID() == classID;
		});

	if (currClass == g_classes.end())
	{
		Class::createClass(classID);
		currClass = g_classes.end()-1;
	}
	
	g_courses.push_back(Course(courseID, &*currSemester));
	currSemester->addCourse(&g_courses.back());
	currClass->addCourse(&g_courses.back());

	return 1;
}

bool Course::deleteCourse(const std::string &id)
{
	auto currCourse = g_courses.find_if(
		[&](const Course &course) -> bool
		{
			return course.getID() == id;
		});

	if (currCourse == g_courses.end())
	{
		return 0;
	}

	currCourse->semester()->removeCourse(&*currCourse);
	currCourse->getClass()->removeCourse(&*currCourse);
	
	while (!currCourse->studentInfos().empty())
	{
		currCourse->removeStudent(currCourse->studentInfos().front().student);
	}

	g_courses.erase(currCourse);
	
	return 1;
}

std::string Course::courseID_to_classID(const std::string &courseID)
{
	std::string classID;
	for (auto iCourseID = courseID.rbegin(); iCourseID != courseID.rend(); ++iCourseID)
	{
		if (*iCourseID == '_')
		{
			break;
		}

		classID += (*iCourseID);
	}
	std::reverse(classID.begin(), classID.end());
	return classID;
}

std::string Course::Session::getTime() const
{
	std::string res = this->day + " " + this->type + " ";
	std::string time;
	if (this->type == "S1")
	{
		time = "7:30";
	}
	else if (this->type == "S2")
	{
		time = "9:30";
	}
	else if (this->type == "S3")
	{
		time = "13:30";
	}
	else
	{
		time = "15:30";
	}
	return res += "(" + time + ")";
}

Course::StudentInfo::StudentInfo(Student *nStudent,
								 float nMidtermMark,
								 float nFinalMark,
								 float nOtherMark,
								 float nTotalMark)
{
	student = nStudent;
	midtermMark = nMidtermMark;
	finalMark = nFinalMark;
	otherMark = nOtherMark;
	totalMark = nTotalMark;
}

Course::Course()
	: semester_(nullptr), maxStudents_(DEFAULT_MAX_STUDENTS)
{
	session_.day = session_.type = "NOT SET";
}

Course::Course(const std::string &nID, Semester *semester)
	: Course()
{
	setID(nID);
	
}

const std::string& Course::getID() const
{
	return id_;
}

Semester*& Course::semester()
{
	return semester_;
}

Semester* const& Course::semester() const
{
	return semester_;
}
	
const std::string& Course::getCourseName() const
{
	return courseName_;
}

const std::string& Course::getTeacherName() const
{
	return teacherName_;
}

int Course::getMaxStudents() const
{
	return maxStudents_;
}

int Course::getNumberOfCredits() const
{
	return numberOfCredits_;
}

void Course::setID(const std::string &nID)
{
	id_ = nID;
}

void Course::setCourseName(const std::string &nCourseName)
{
	courseName_ = nCourseName;
}

void Course::setTeacherName(const std::string &nTeacherName)
{
	teacherName_ = nTeacherName;
}

void Course::setMaxStudents(int nMaxStudents)
{
	maxStudents_ = nMaxStudents;
}

void Course::setNumberOfCredits(int nNumberOfCredits)
{
	numberOfCredits_ = nNumberOfCredits;
}

List<Course::StudentInfo>& Course::studentInfos()
{
	return studentInfos_;
}

const List<Course::StudentInfo>& Course::studentInfos() const
{
	return studentInfos_;
}

Course::Session& Course::session()
{
	return session_;
}

const Course::Session& Course::session() const
{
	return session_;
}

Class*& Course::getClass()
{
	return class_;
}

Class* const& Course::getClass() const 
{
	return class_;
}

bool Course::addStudent(Student *student)
{
	if (studentInfos().find_if(
			[&](const StudentInfo &studentInfo) -> bool
			{
				return studentInfo.student == student;
			})
		!= studentInfos().end())
	{
		return 0;
	}

	studentInfos().push_back(StudentInfo(student));
	student->courseInfos().push_back(Student::CourseInfo(this,
														 &studentInfos().back()));
	
	return 1;
}

bool Course::removeStudent(Student *student)
{
	auto currStudentInfo = studentInfos().find_if(
		[&](const StudentInfo &studentInfo) -> bool
		{
			return studentInfo.student == student;
		});

	if (currStudentInfo == studentInfos().end())
	{
		return 0;
	}

	currStudentInfo->student->courseInfos().remove_if(
		[&](const Student::CourseInfo &courseInfo) -> bool
		{
			return courseInfo.course == this;
		});

	studentInfos().erase(currStudentInfo);

	return 1;
}
