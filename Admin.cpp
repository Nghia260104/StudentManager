#include "Admin.hpp"
#include "StaffMember.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

Admin::Admin()
{}

bool Admin::createStaffMember(const std::string &socialID) const
{
	if (g_staffMembers.find_if(
			[&](const StaffMember &staffMember) -> bool
			{
				return socialID == staffMember.getSocialID();
			}))
	{
		return 0;
	}
	
	g_staffMembers.push_back(StaffMember(socialID));
	return 1;
}
