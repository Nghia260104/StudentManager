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

	clearSchoolYears();

	for (auto directory: std::filesystem::directory_iterator(schoolYearsPath))
	{
		int schoolStartYear = std::stoi(directory.path().filename());
		createSchoolYear(schoolStartYear);
		Semester::loadSemesters(directory.path(), &g_schoolYears.back());
	}
	return 1;
}

void SchoolYear::saveSchoolYears()
{
	std::filesystem::path schoolYearsPath(SCHOOL_YEARS_PATH);
	
	std::filesystem::remove_all(schoolYearsPath);
	std::filesystem::create_directories(schoolYearsPath);
	
	for (auto schoolYear: g_schoolYears)
	{
		std::filesystem::path currSchoolYearPath(schoolYearsPath/std::to_string(schoolYear.getStartYear()));
		Semester::saveSemesters(currSchoolYearPath, &schoolYear);
	}
}

void SchoolYear::clearSchoolYears()
{
	while (!g_schoolYears.empty())
	{
		SchoolYear::deleteSchoolYear(g_schoolYears.back().getStartYear());
	}
}

bool SchoolYear::createSchoolYear(int startYear)
{
	if (g_schoolYears.find_if(
			[=](const SchoolYear &schoolYear) -> bool
			{
				return schoolYear.getStartYear() == startYear;
			})
		!= g_schoolYears.end())
	{
		return 0;
	}

	g_schoolYears.push_back(SchoolYear(startYear));
	setActiveSchoolYear(g_schoolYears.empty() ? nullptr : &g_schoolYears.back());
	
	return 1;
}

bool SchoolYear::deleteSchoolYear(int startYear)
{
	auto currSchoolYear = g_schoolYears.find_if(
		[&](const SchoolYear &schoolYear) -> bool
		{
			return schoolYear.getStartYear() == startYear;
		});

	if (currSchoolYear == g_schoolYears.end())
	{
		return 0;
	}

	while (!currSchoolYear->semesters().empty())
	{
		Semester::deleteSemester(currSchoolYear->semesters().front()->getID(), startYear);
	}

	g_schoolYears.erase(currSchoolYear);
	setActiveSchoolYear(nullptr);

	return 1;
}

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
	if (semesters().find(nSemester) != semesters().end())
	{
		return 0;
	}

	semesters().push_back(nSemester);
	nSemester->schoolYear() = this;
	return 1;
}

bool SchoolYear::removeSemester(Semester *semester)
{
	auto currSemester = semesters().find(semester);

	if (currSemester == semesters().end())
	{
		return 0;
	}
	
	semester->schoolYear() = nullptr;
	semesters().erase(currSemester);

	return 1;
}
