#include <fstream>
#include <sstream>

#include "Account.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Account::loadAccounts()
{
	std::ifstream fi;
	fi.open(ACCOUNTS_PATH);
	std::cerr << ACCOUNTS_PATH << '\n';
	
	if (!fi.is_open())
	{
		return 0;
	}

	std::string line;
	while (std::getline(fi, line))
	{
		std::stringstream streamLine;
		streamLine.str(line);
		
		std::string type, username, password;
		std::getline(streamLine, type, ',');
		std::getline(streamLine, username, ',');
		std::getline(streamLine, password, ',');

		switch (stringToType(type))
		{
		case Type::Admin:
			g_admin.setUsername(username);
			g_accounts.push_back(static_cast<Account*>(&g_admin));
			break;
		case Type::StaffMember:
			g_staffMembers.push_back(StaffMember(username));
			g_accounts.push_back(static_cast<Account*>(&g_staffMembers.back()));
			break;
		default:
			g_students.push_back(Student(username));
			g_accounts.push_back(static_cast<Account*>(&g_students.back()));
		}

		g_accounts.back()->setPassword(password);
	}
	return 1;
}

Account::Type Account::stringToType(const std::string &type)
{
	std::string typeUpcase;
	for (auto c: type)
	{
		typeUpcase += std::toupper(c);
	}
	
	if (typeUpcase == "ADMIN")
	{
		return Type::Admin;
	}
	if (typeUpcase == "STAFF MEMBER")
	{
		return Type::StaffMember;
	}
	return Type::Student;
}

bool Account::signIn(const std::string &username, const std::string &password)
{
	for (auto it = g_accounts.begin(); it != g_accounts.end(); ++it)
	{
		if (username == (*it)->username_ && password == (*it)->password_)
		{
			setActiveUser(*it);
			return 1;
		}
	}
	return 0;
}

void Account::logOut()
{
	activeUser = nullptr;
}

Account::Account(Account::Type nType)
	: type_(nType)
{}

Account::Type Account::getType() const
{
	return type_;
}

const std::string& Account::getFirstName() const
{
	return firstName_;
}

const std::string& Account::getLastName() const
{
	return lastName_;
}

std::string Account::getName() const
{
	return firstName_ + lastName_;
}

const std::string& Account::getSocialID() const
{
	return socialID_;
}

Account::Gender Account::getGender() const
{
	return gender_;
}

const Date& Account::getDateOfBirth() const
{
	return dateOfBirth_;
}

void Account::setType(Account::Type nType)
{
	type_ = nType;
}

void Account::setFirstName(const std::string &nFirstName)
{
	firstName_ = nFirstName;
}

void Account::setLastName(const std::string &nLastName)
{
	lastName_ = nLastName;
}

void Account::setSocialID(const std::string &nSocialID)
{
	socialID_ = nSocialID;
}

void Account::setGender(const std::string &nGender)
{
	std::string nGenderUpcase;
	for (auto c: nGender)
	{
		nGenderUpcase += std::toupper(c);
	}

	gender_ = (nGenderUpcase == "MALE" ? Account::Gender::Male : Account::Gender::Female);
}

void Account::setGender(Gender nGender)
{
	gender_ = nGender;
}

void Account::setDateOfBirth(const std::string &nDateOfBirth)
{
	int day = nDateOfBirth[0]*10 + nDateOfBirth[1];
	int month = nDateOfBirth[3]*10 + nDateOfBirth[4];
	int year = nDateOfBirth[6]*1000 + nDateOfBirth[7]*100 + nDateOfBirth[8]*10 + nDateOfBirth[9];
	dateOfBirth_ = Date(year, month, day);
}

void Account::setDateOfBirth(const Date &nDateOfBirth)
{
	dateOfBirth_ = nDateOfBirth;
}

bool Account::changePassword(const std::string &oldPassword,
							 const std::string &newPassword,
							 const std::string &confirmNewPassword)
{
	if (oldPassword != password_ || newPassword != confirmNewPassword)
	{
		return 0;
	}

	password_ = newPassword;
	return 1;
}

const std::string& Account::getUsername() const
{
	return username_;
}

void Account::setUsername(const std::string &nUsername)
{
	username_ = nUsername;
}

const std::string& Account::getPassword() const
{
	return password_;
}

void Account::setPassword(const std::string &nPassword)
{
	password_ = nPassword;
}
