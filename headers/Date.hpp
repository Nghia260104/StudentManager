#pragma once

#include <string>

namespace Backend
{
	struct Date
	{
		int year, month, day;
	
		static std::string dateToString(const Date &date);
		static Date stringToDate(const std::string &date);

		Date(int nYear = 0, int nMonth = 0, int nDay = 0);
		
		bool isValidDate();
		bool operator<(const Date &x);
		bool operator>(const Date &x);
		bool operator==(const Date &x);
	};
}
