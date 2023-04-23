#include <filesystem>

#include "SchoolYear.hpp"
#include "Semester.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool SchoolYear::loadSchoolYears()
{
	std::filesystem::path schoolYearsPath(SCHOOL_YEARS_PATH);
	
	if (!std::filesystem::exists(schoolYearsPath))
	{
		std::filesystem::create_directories(schoolYearsPath);
		return 0;
	}

	for (auto directory: std::filesystem::directory_iterator(schoolYearsPath))
	{
		int schoolStartYear = std::stoi(directory.path().filename());
		g_schoolYears.push_back(SchoolYear(schoolStartYear));
		Semester::loadSemesters(directory.path(), &g_schoolYears.back());
	}
	return 1;
}

SchoolYear::SchoolYear()
{}

SchoolYear::SchoolYear(int nStartYear)
{
	setStartYear(nStartYear);
	/* path_ = SCHOOL_YEARS_PATH + "/" + std::to_string(startYear_); */
}

int SchoolYear::getStartYear() const
{
	return startYear_;
}

const List<Semester*>& SchoolYear::getSemesters() const
{
	return semesters_;
}

/* const std::string& SchoolYear::getPath() const
 * {
 * 	return path_;
 * } */

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
