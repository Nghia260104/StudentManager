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

	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
	};
}
