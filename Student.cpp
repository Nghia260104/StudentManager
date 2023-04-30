#include <fstream>

#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

Student::CourseInfo::CourseInfo(Course *nCourse, Course::StudentInfo *nStudentInfo)
{
	this->course = nCourse;
	this->studentInfo = nStudentInfo;
}

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

Class* Student::getClass()
{
	return class_;
}

const Class* Student::getClass() const
{
	return class_;
}

List<Student::CourseInfo>& Student::courseInfos()
{
	return courseInfos_;
}

const List<Student::CourseInfo>& Student::courseInfos() const
{
	return courseInfos_;
}

void Student::setID(const std::string &nID)
{
	id_ = nID;
	username_ = id_;
}
