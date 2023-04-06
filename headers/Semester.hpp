#pragma once

#include "SchoolYear.hpp"

namespace Backend
{
	class Course;

	class Semester
	{
	public:
		Semester();
		Semester(int nID);
		
		int getID() const;
		const SchoolYear* getSchoolYear() const;
		const List<Course*>& getCourses() const;

		void setID(int nID);
		void setSchoolYear(SchoolYear *nSchoolYear);
		void addCourse(Course *nCourse);
		
	private:
		int id_;
		SchoolYear *schoolYear_;
		List<Course*> courses_;
		
		friend class SchoolYear;
	};
}
