#pragma once

#include "Account.hpp"
#include "Student.hpp"

namespace Backend
{
	class StaffMember : public Account
	{
	public:
		StaffMember();
		StaffMember(const std::string &nID);

		bool addStudent(const std::string &studentID) const;
	};
}
