#include <sstream>

#include "Date.hpp"

using namespace Backend;

std::string Date::dateToString(const Date &date)
{
	std::string year = std::to_string(date.year);
	std::string month = (date.month < 10 ? "0" : "") + std::to_string(date.month);
	std::string day = (date.day < 10 ? "0" : "") + std::to_string(date.day);
	return day + "/" + month + "/" + year;
}

Date Date::stringToDate(const std::string &date)
{
	std::stringstream stream(date);
	std::string yearString, monthString, dayString;
	int day = (std::getline(stream, dayString, '/') ? std::stoi(dayString) : 0);
	int month = (std::getline(stream, monthString, '/') ? std::stoi(monthString) : 0);
	int year = (std::getline(stream, yearString, '/') ? std::stoi(yearString) : 0);
	return Date(year, month, day);
}

Date::Date(int nYear, int nMonth, int nDay)
	: year(nYear), month(nMonth), day(nDay)
{}

bool Date::isValidDate()
{
	if (year <= 0 || month <= 0 || month > 12 || day <= 0)
	{
		return 0;
	}

	bool isLeapYear = (year%100 == 0 ? year%400 == 0 : year%4 == 0);
	const int *numDaysOfMonths = new int[]{31, (isLeapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool result =  (day <= numDaysOfMonths[month-1]);
	delete[] numDaysOfMonths;
	return result;
}

bool Date::operator<(const Date &x)
{
	return (year < x.year ||
			(year == x.year && month < x.month) ||
			(year == x.year && month == x.month && day < x.day));
}

bool Date::operator>(const Date &x)
{
	return (year > x.year ||
			(year == x.year && month > x.month) ||
			(year == x.year && month == x.month && day > x.day));
}

bool Date::operator==(const Date &x)
{
	return (year == x.year && month == x.month && day == x.day);
}
