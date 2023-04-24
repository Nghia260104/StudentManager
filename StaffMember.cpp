#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool StaffMember::loadStaffMembers()
{
	std::ifstream fi(ACCOUNTS_PATH + "/staff members.csv");

	if (!fi.is_open())
	{
		return 0;
	}

	std::string line;
	std::stringstream streamLine;
	while (std::getline(fi, line))
	{
		streamLine.str(line);
		
		std::string no, firstName, lastName, gender, dateOfBirth, socialID;
		readCSV(streamLine, no);
		readCSV(streamLine, firstName);
		readCSV(streamLine, lastName);
		readCSV(streamLine, gender);
		readCSV(streamLine, dateOfBirth);
		readCSV(streamLine, socialID);
		
		g_staffMembers.push_back(StaffMember(socialID));
		StaffMember &currStaffMember = g_staffMembers.back();
		g_accounts.push_back(&currStaffMember);
		currStaffMember.setFirstName(firstName);
		currStaffMember.setLastName(lastName);
		currStaffMember.setGender(gender);
		currStaffMember.setDateOfBirth(dateOfBirth);
	}

	return 1;
}

void StaffMember::readCSV(std::stringstream &streamLine, std::string &word)
{
	std::string tmp;
	if (std::getline(streamLine, tmp, ','))
	{
		word = tmp;
	}
}

StaffMember::StaffMember()
{}

StaffMember::StaffMember(const std::string &nSocialID)
{
	setSocialID(nSocialID);
}

void StaffMember::setSocialID(const std::string &nSocialID)
{
	socialID_ = nSocialID;
	username_ = socialID_;
}

bool StaffMember::createStudent(const std::string &studentID) const
{
	if (g_students.find_if(
			[&studentID](const Student &student) -> bool
			{
				return student.getID() == studentID;
			}))
	{
		return 0;
	}
	
	g_students.push_back(Student(studentID));
	return 1;
}
