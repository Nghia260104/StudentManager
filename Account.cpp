#include "Account.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Account::signIn(const std::string &username, const std::string &password)
{
	for (auto it = g_accounts.begin(); it != g_accounts.end(); ++it)
	{
		if (username == (*it)->getUsername() && password == (*it)->getPassword())
		{
			activeUser = *it;
			return 1;
		}
	}
	return 0;
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

const std::string& Account::getName() const
{
	return firstName_ + lastName_;
}

const std::string& Account::getSocialID() const
{
	return socialID_;
}

Gender Account::getGender() const
{
	return gender_;
}

const Date& Account::getDateOfBirth() const
{
	return dateOfBirth_;
}

void Account::setType(const std::string &nType) const
{
	std::string nTypeUpcase;
	for (auto c: nType)
	{
		nTypeUpcase += std::toupper(c);
	}

	switch (nTypeUpcase)
	{
	case "STUDENT":
		type_ = Account::Type::Student;
		break;
		
	case "STAFFMEMBER":
		type_ = Account::Type::StaffMember;
		break;

	case "ADMIN":
		type_ = Account::Type::Admin;
		break;
	}
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
	if (oldPassword != getPassword() || newPassword != confirmNewPassword)
	{
		return 0;
	}

	setPassword(newPassword);
	return 1;
}
