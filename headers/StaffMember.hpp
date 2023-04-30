#pragma once

#include "Account.hpp"

namespace Backend
{
	class StaffMember : public Account
	{
	public:
		static bool loadStaffMembers();
		
		StaffMember();
		StaffMember(const std::string &nSocialID);

		void setSocialID(const std::string &nSocialID) override;

		bool createStudent(const std::string &studentID) const;
		void deleteStudent(const std::string &studentID) const;

		bool createSchoolYear(int startYear) const;
		void deleteSchoolYear(int startYear) const;
		
		bool createSemester(int id, int schoolYear) const;
		void deleteSemester(int id, int schoolYear) const;
		
		bool createCourse(const std::string &id) const;
		void deleteCourse(const std::string &id) const;
		
	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
	};
}
