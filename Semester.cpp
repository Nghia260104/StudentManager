#include "Semester.hpp"

using namespace Backend;

Semester::Semester()
	: schoolYear_(nullptr)
{}

Semester::Semester(int nID)
	: Semester()
{
	setID(nID);
}

int Semester::getID() const
{
	return id_;
}

const SchoolYear* Semester::getSchoolYear() const
{
	return schoolYear_;
}

const List<Course*>& Semester::getCourses() const
{
	return courses_;
}

void Semester::setID(int nID)
{
	id_ = nID
}

void Semester::setSchoolYear(SchoolYear *nSchoolYear)
{
	schoolYear_ = nSchoolYear;
}

void Semester::addCourse(Course *nCourse)
{
	courses_.push_back(nCourse);
	nCourse->semester_ = this;
}
