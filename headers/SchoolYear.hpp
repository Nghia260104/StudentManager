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
		const List<Semester*>& getSemesters() const;
		/* const std::string& getPath() const; */

		void setStartYear(int nStartYear);
		bool addSemester(Semester *nSemester);

	private:
		int startYear_;
		List<Semester*> semesters_;
		std::filesystem::path path_;
	};
}
