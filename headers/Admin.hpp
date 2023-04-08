#pragma once

#include "StaffMember.hpp"

namespace Backend
{
	class Admin : public Account
	{
	public:
		Admin();

		bool createStaffMember(const std::string &id) const;
	};
}
