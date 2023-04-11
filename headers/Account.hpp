#pragma once

#include <string>

#include "Date.hpp"

namespace Backend
{
	class Account
	{
	public:
		enum class Type
		{
			Student, StaffMember, Admin
		};

		enum class Gender
		{
			Male, Female
		};

		static bool signIn(const std::string &username, const std::string &password);
		
		Account(Type nType = Type::Admin);
		
		Type getType() const;
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		std::string getName() const;
		const std::string& getSocialID() const;
		Gender getGender() const;
		const Date& getDateOfBirth() const;

		void setType(const std::string &nType);
		void setType(Type nType);
		
		void setFirstName(const std::string &nFirstName);
		void setLastName(const std::string &nLastName);
		void setSocialID(const std::string &nSocialID);
		
		void setGender(const std::string &nGender); // format "dd/mm/yyyy"
		void setGender(Gender nGender);
		
		void setDateOfBirth(const std::string &nDateOfBirth);
		void setDateOfBirth(const Date &nDateOfBirth);
		
		bool changePassword(const std::string &oldPassword,
							const std::string &newPassword,
							const std::string &confirmNewPassword);
	protected:
		Type type_;
		std::string username_, password_, firstName_, lastName_, socialID_;
		Gender gender_;
		Date dateOfBirth_;
	};
}