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
		std::cerr << "School Years path does not exist" << std::endl;
		return 0;
	}

	std::cerr << "School Years path exists" << std::endl;
	for (auto directory: std::filesystem::directory_iterator(schoolYearsPath))
	{
		int schoolStartYear = std::stoi(directory.path().filename());
		std::cerr << schoolStartYear << std::endl;
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

List<Semester*>& SchoolYear::semesters()
{
	return semesters_;
}

const List<Semester*>& SchoolYear::semesters() const
{
	return semesters_;
}

void SchoolYear::setStartYear(int nStartYear)
{
	startYear_ = nStartYear;
}

bool SchoolYear::addSemester(Semester *nSemester)
{
	if (semesters_.find(nSemester) != semesters_.end())
	{
		return 0;
	}
	
	semesters_.push_back(nSemester);
	nSemester->schoolYear_ = this;
	return 1;
}

bool SchoolYear::removeSemester(Semester *semester)
{
	auto currSemester = semesters().find(semester);

	if (currSemester == semesters().end())
	{
		return 0;
	}

	(*currSemester)->schoolYear() = nullptr;
	semesters().erase(currSemester);

	return 1;
}
