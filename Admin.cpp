#include "Admin.hpp"
#include "StaffMember.hpp"

using namespace Backend;

Admin::Admin()
{}

bool Admin::addStaffMember(const std::string &id) const
{
	if (g_staffMembers.find_if(
			[](const StaffMember &staffMember) -> bool
			{
				return id = staffMember.getID();
			}))
	{
		return 0;
	}
	
	g_staffMembers.push_back(StaffMember(id));
	return 1;
}
