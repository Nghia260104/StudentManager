#include "SchoolYear.hpp"
#include "Semester.hpp"

using namespace Backend;

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

bool SchoolYear::addSemester(Semester *nSemester)
{
	if (semesters_.find(nSemester))
	{
		return 0;
	}
	
	semesters_.push_back(nSemester);
	nSemester->schoolYear_ = this;
	return 1;
}
