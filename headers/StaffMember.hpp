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
	    bool deleteStudent(const std::string &studentID) const;

		bool createSchoolYear(int startYear) const;
	    bool deleteSchoolYear(int startYear) const;
		
		bool createSemester(int id, int schoolYear) const;
	    bool deleteSemester(int id, int schoolYear) const;
		
		bool createCourse(const std::string &id) const;
	    bool deleteCourse(const std::string &id) const;

		bool createClass(const std::string id) const;
	    bool deleteClass(const std::string id) const;
		
	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
	};
}
