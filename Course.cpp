#include "Course.hpp"

using namespace Backend;

Course::Course()
	: semester_(nullptr)
{}

Course::Course(const std::string &nID)
	: Course()
{
	setID(nID);
}

const std::string& Course::getID() const
{
	return id_;
}

const List<Student*>& Course::getStudents() const
{
	return students_;
}

void Course::setID(const std::string &nID)
{
	id_ = nID;
}

void Course::addStudent(Student *nStudent)
{
	students_.push_back(nStudent);
	nStudent->courses_.push_back(this);
}
