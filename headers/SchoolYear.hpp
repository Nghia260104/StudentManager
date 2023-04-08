#pragma once

#include "List.hpp"

namespace Backend
{
	class Semester;
	
	class SchoolYear
	{
	public:
		SchoolYear();
		SchoolYear(int nStartYear);

		int getStartYear() const;
		const List<Semester*> getSemesters() const;

		void setStartYear(int nStartYear);
		bool addSemester(Semester *nSemester);

	private:
		int startYear_;
		List<Semester*> semesters_;
	};
}
