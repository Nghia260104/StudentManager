#include "Class.hpp"
#include "Student.hpp"

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
	if (students_.find(nStudent))
	{
		return 0;
	}
	
	students_.push_back(nStudent);
	nStudent->class_ = this;
	return 1;
}
