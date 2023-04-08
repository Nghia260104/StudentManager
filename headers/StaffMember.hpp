#pragma once

#include "Account.hpp"
#include "Student.hpp"

namespace Backend
{
	class StaffMember : public Account
	{
	public:
		StaffMember();
		StaffMember(const std::string &nSocialID);

		bool createStudent(const std::string &studentID) const;
	};
}
