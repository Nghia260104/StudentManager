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

		static bool createStudent(const std::string &studentID);
	    static bool deleteStudent(const std::string &studentID);
		
		static bool createSchoolYear(int startYear);
	    static bool deleteSchoolYear(int startYear);
		
		static bool createSemester(int id, int schoolYear);
	    static bool deleteSemester(int id, int schoolYear);
		
		static bool createCourse(const std::string &id, int semesterID, int startYear);
	    static bool deleteCourse(const std::string &id);
		
		static bool createClass(const std::string &id);
	    static bool deleteClass(const std::string &id);

		void setSocialID(const std::string &nSocialID) override;
		
	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
	};
}
