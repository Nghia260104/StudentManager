#include "Student.hpp"

using namespace Backend;

Student::Student()
	: Account(Account::Type::Student), class_(nullptr)
{}

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

const List<Course*>& Student::getCourses() const
{
	return courses_;
}

void Student::setID(const std::string &nID)
{
	id_ = nID;
}

void Student::setClass(Class *nClass)
{
	class_->addStudent(this);
}

void Student::addCourse(Course *nCourse)
{
	nCourse->addStudent(this);
}
