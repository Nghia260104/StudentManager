#include <fstream>

#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Student::loadStudents()
{
	std::ifstream fi(ACCOUNTS_PATH + "/students.csv");

	if (!fi.is_open())
	{
		return 0;
	}

	std::string line;
	std::stringstream streamLine;
	while (std::getline(fi, line))
	{
		streamLine.str(line);
		
		std::string no, studentID, firstName, lastName, gender, dateOfBirth, socialID;
		readCSV(streamLine, no);
		readCSV(streamLine, studentID);
		readCSV(streamLine, firstName);
		readCSV(streamLine, lastName);
		readCSV(streamLine, gender);
		readCSV(streamLine, dateOfBirth);
		readCSV(streamLine, socialID);
		
		g_students.push_back(Student(studentID));
		Student &currStudent = g_students.back();
		g_accounts.push_back(&currStudent);
	    currStudent.setFirstName(firstName);
	    currStudent.setLastName(lastName);
	    currStudent.setGender(gender);
	    currStudent.setDateOfBirth(dateOfBirth);
	}

	return 1;
}

void Student::readCSV(std::stringstream &streamLine, std::string &word)
{
	std::string tmp;
	if (std::getline(streamLine, tmp, ','))
	{
		word = tmp;
	}
}

<<<<<<< HEAD
=======
Student::CourseInfo::CourseInfo(Course *nCourse, Course::StudentInfo *nStudentInfo)
{
	this->course = nCourse;
	this->studentInfo = nStudentInfo;
}

>>>>>>> build_login_feature
Student::Student()
	: Account(Account::Type::Student), class_(nullptr)
{
	password_ = "123456";
}

Student::Student(const std::string &nID)
	: Student()
{
	setID(nID);
}

const std::string& Student::getID() const
{
	return id_;
}

const Class* Student::getClass() const
{
	return class_;
}

const List<Student::CourseInfo>& Student::getCourseInfos() const
{
	return courseInfos_;
}

void Student::setID(const std::string &nID)
{
	id_ = nID;
	username_ = id_;
}
