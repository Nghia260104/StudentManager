#pragma once

#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class SchoolYear;
	class Course;

	class Semester
	{
	public:
		Semester();
		Semester(int nID, SchoolYear *schoolYear);

		static bool loadSemesters(const std::filesystem::path &path, SchoolYear *schoolYear);
		
		int getID() const;
		SchoolYear* schoolYear();
		const SchoolYear* schoolYear() const;
		List<Course*>& courses();
		const List<Course*>& courses() const;
		/* const std::string& getPath() const; */

		void setID(int nID);
		void setSchoolYear(SchoolYear *nSchoolYear);
		bool addCourse(Course *nCourse);
		void removeCourse(Course *course);
		
	private:
		int id_;
		SchoolYear *schoolYear_;
		List<Course*> courses_;
		/* std::filesystem::path path_; */
		
		friend class SchoolYear;
	};
}
