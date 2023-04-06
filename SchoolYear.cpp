#include "SchoolYear.hpp"

SchoolYear::SchoolYear()
{}

SchoolYear::SchoolYear(int nStartYear)
{
	setStartYear(nStartYear);
}

int SchoolYear::getStartYear() const
{
	return startYear_;
}

const List<Semester*> SchoolYear::getSemesters() const
{
	return semesters_;
}

void SchoolYear::setStartYear(int nStartYear)
{
	startYear_ = nStartYear;
}

void SchoolYear::addSemester(Semester *nSemester)
{
	semesters_.push_back(nSemester);
	nSemester->schoolYear_ = this;
}
