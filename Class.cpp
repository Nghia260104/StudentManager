#include "Class.hpp"

using namespace Backend;

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

const List<Student*>& getStudents() const
{
	return students_;
}

void Student::setID(const std::string &nID)
{
	id_ = nID;
}

void Student::addStudent(Student *nStudent)
{
	students_.push_back(nStudent);
	nStudent->class_ = this;
}
