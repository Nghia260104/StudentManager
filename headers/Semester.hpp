#pragma once

#include "List.hpp"

namespace Backend
{
	class SchoolYear;
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
		bool addCourse(Course *nCourse);
		
	private:
		int id_;
		SchoolYear *schoolYear_;
		List<Course*> courses_;
		
		friend class SchoolYear;
	};
}
