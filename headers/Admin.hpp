#pragma once

#include "StaffMember.hpp"

namespace Backend
{
	class Admin : public Account
	{
	public:
		static bool loadAdmin();
		
		Admin();

		bool createStaffMember(const std::string &socialID) const;
	};
}
