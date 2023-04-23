#pragma once

#include "Account.hpp"

namespace Backend
{
	class StaffMember : public Account
	{
	public:
		StaffMember();
		StaffMember(const std::string &nSocialID);

		static bool loadStaffMembers();

		bool createStudent(const std::string &studentID) const;
	};
}
