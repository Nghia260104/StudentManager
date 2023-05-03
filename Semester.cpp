#include <filesystem>

#include "Semester.hpp"
#include "Course.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Semester::loadSemesters(const std::filesystem::path &path, SchoolYear *schoolYear)
{
	if (!std::filesystem::exists(path))
	{
		std::cerr << "Semesters path does not exist" << std::endl;
		return 0;
	}

	std::cerr << "Semesters path exists" << std::endl;
	for (auto semesterPath: std::filesystem::directory_iterator(path))
	{
		int id = std::stoi(semesterPath.path().filename());
		std::cerr << id << std::endl;
		g_semesters.push_back(Semester(id, schoolYear));
		Course::loadCourses(semesterPath.path(), &g_semesters.back());
	}
	return 1;
}

Semester::Semester()
	: schoolYear_(nullptr)
{}

Semester::Semester(int nID, SchoolYear *schoolYear)
	: Semester()
{
	setID(nID);
	/* directoryPath_ = schoolYear_->getDirectoryPath() + std::to_string(id_) + "/"; */
	schoolYear->addSemester(this);
}

int Semester::getID() const
{
	return id_;
}

SchoolYear*& Semester::schoolYear()
{
	return schoolYear_;
}

SchoolYear* const& Semester::schoolYear() const
{
	return schoolYear_;
}

List<Course*>& Semester::courses()
{
	return courses_;
}

const List<Course*>& Semester::courses() const
{
	return courses_;
}

/* const std::string& Semester::getPath() const
 * {
 * 	return path_;
 * } */

void Semester::setID(int nID)
{
	id_ = nID;
}

bool Semester::addCourse(Course *nCourse)
{
	if (courses_.find(nCourse) != courses_.end())
	{
		return 0;
	}
	
	courses_.push_back(nCourse);
	nCourse->semester() = this;
	/* nCourse->filePath_ = directoryPath_ + nCourse->getID() + ".csv"; */
	return 1;
}

bool Semester::removeCourse(Course *course)
{
	auto currCourse = courses().find(course);
	
	if (currCourse == courses().end())
	{
		return 0;
	}

	(*currCourse)->semester() = nullptr;
	courses().erase(currCourse);
	
	return 1;
}
