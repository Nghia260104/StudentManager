#include <fstream>
#include <sstream>

#include "Admin.hpp"
#include "StaffMember.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Admin::loadAdmin()
{
	std::ifstream fi(ACCOUNTS_PATH + "/admin.csv");
	
	if (!fi.is_open())
	{
		return 0;
	}
	
	if (!std::getline(fi, g_admin.username_, ','))
	{
		return 0;
	}
	
	std::getline(fi, g_admin.password_, ',');
	return 1;
}

Admin::Admin()
{}

bool Admin::createStaffMember(const std::string &socialID) const
{
	if (g_staffMembers.find_if(
			[&](const StaffMember &staffMember) -> bool
			{
				return socialID == staffMember.getSocialID();
			})
		== g_staffMembers.end())
	{
		return 0;
	}
	
	g_staffMembers.push_back(StaffMember(socialID));
	g_accounts.push_back(&g_staffMembers.back());
	return 1;
}

void Admin::deleteStaffMember(const std::string &socialID) const
{
	g_accounts.remove_if(
		[&](const Account *account) -> bool
		{
			return account->getSocialID() == socialID;
		});

	g_staffMembers.remove_if(
		[&](const StaffMember &staffMember) -> bool
		{
			return staffMember.getSocialID() == socialID;
		});
}
