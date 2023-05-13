#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

void StaffMember::readCSV(std::stringstream &streamLine, std::string &word)
{
	std::string tmp;
	if (std::getline(streamLine, tmp, ','))
	{
		word = tmp;
	}
}

bool StaffMember::createStaffMember(const std::string &socialID)
{
	if (g_staffMembers.find_if(
			[&](const StaffMember &staffMember) -> bool
			{
				return socialID == staffMember.getSocialID();
			})
		!= g_staffMembers.end())
	{
		return 0;
	}
	
	g_staffMembers.push_back(StaffMember(socialID));
	g_accounts.push_back(static_cast<Account*>(&g_staffMembers.back()));
	
	return 1;
}

bool StaffMember::deleteStaffMember(const std::string &socialID)
{
	auto currStaffMember = g_staffMembers.find_if(
		[&](const StaffMember &staffMember) -> bool
		{
			return staffMember.getSocialID() == socialID;
		});

	if (currStaffMember == g_staffMembers.end())
	{
		return 0;
	}

	g_accounts.remove_if(
		[&](Account* const &account) -> bool
		{
			return account == &*currStaffMember;
		});
	g_staffMembers.erase(currStaffMember);

	return 1;
}

StaffMember::StaffMember()
	: Account(Type::StaffMember)
{}

StaffMember::StaffMember(const std::string &nSocialID)
	: StaffMember()
{
	setSocialID(nSocialID);
}

void StaffMember::setSocialID(const std::string &nSocialID)
{
	socialID_ = nSocialID;
	username_ = socialID_;
}
