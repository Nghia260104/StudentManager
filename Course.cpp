#include "Course.hpp"
#include "Student.hpp"

using namespace Backend;

Course::Course()
	: semester_(nullptr), maxStudents_(DEFAULT_MAX_STUDENTS)
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

int Course::getMaxStudents() const
{
	return maxStudents_;
}

const List<Student*>& Course::getStudents() const
{
	return students_;
}

void Course::setID(const std::string &nID)
{
	id_ = nID;
}

void Course::setMaxStudents(int nMaxStudents)
{
	maxStudents_ = nMaxStudents;
}

bool Course::addStudent(Student *nStudent)
{
	if (students_.size() == maxStudents_ || tudents_.find(nStudent))
	{
		return 0;
	}
	
	students_.push_back(nStudent);
	nStudent->courses_.push_back(this);
	return 1;
}
