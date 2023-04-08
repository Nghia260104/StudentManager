#pragma once

#include "StaffMember.hpp"

namespace Backend
{
	class Admin : public Account
	{
	public:
		Admin();

		bool addStaffMember(const std::string &id) const;
	};
}
