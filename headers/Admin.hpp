#pragma once

#include "StaffMember.hpp"

namespace Backend
{
	class Admin : public Account
	{
	public:
		Admin();

		static bool loadAdmin();

		bool createStaffMember(const std::string &id) const;
	};
}
