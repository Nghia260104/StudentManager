#pragma once

#include <string>
#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class Semester;
	
	class SchoolYear
	{
	public:
		static bool loadSchoolYears();
		
		SchoolYear();
		SchoolYear(int nStartYear);

		int getStartYear() const;

		List<Semester*>& semesters();
		const List<Semester*>& semesters() const;
		void setStartYear(int nStartYear);
		bool addSemester(Semester *nSemester);
		void removeSemester(Semester *semester);

	private:
		int startYear_;
		List<Semester*> semesters_;
		std::filesystem::path path_;
	};
}
