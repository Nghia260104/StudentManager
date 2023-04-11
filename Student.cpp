#include "Student.hpp"

using namespace Backend;

Student::Student()
	: Account(Account::Type::Student), class_(nullptr)
{
	password_ = "123456";
}

Student::Student(const std::string &nID)
	: Student()
{
	id_ = nID;
	username_ = id_;
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