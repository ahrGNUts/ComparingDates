// class implementation file
#include <iostream>
#include "date.h"
using namespace std;

Date::Date()// standard constructor
{
	month = day = 1;
	year = 2001;
}

Date::Date(const Date &obj)// copy constructor
{
	day = obj.day;
	month = obj.month;
	year = obj.year;
}// end copy constructor

// overloaded operators
bool Date::operator== (const Date &right)
{
	if(day == right.day && month == right.month && year == right.year)
		return true;
	else
		return false;
}

const Date Date::operator= (const Date &right)
{
	month = right.month;
	day = right.day;
	year = right.year;

	return *this;
}

bool Date::operator> (const Date &right)
{
	if(year > right.year)
		return true;
	else if(year == right.year && month > right.month)
		return true;
	else if(year == right.year && month == right.month && day > right.day)
		return true;
	else
		return false;
}

Date Date::operator- (const Date &right)
{
	Date tmp;// returned object
	
	if((day - right.day) < 0)
	{
		month--;// borrowing a month
		tmp.day = (day + right.day) - 30; // days + days minus a month that was borrowed
	}// days
	else// nothing needs to be borrowed
		tmp.day = day - right.day;

	if((month - right.month) < 0)
	{
		year--; // borrow a year
		tmp.month = (month + right.month) - 12;// adding the days and subtracting the borrowed year
	}//months
	else// nothing needs to be borrowed
		tmp.month = month - right.month;

	tmp.year = year - right.year;// years

	return tmp;
}

ostream &operator<< (ostream &strm, const Date &obj)
{
	strm << obj.month << '/' << obj.day << '/' << obj.year;
	return strm;
}

istream &operator>> (istream &strm, Date &obj)
{
	char slash;// for holding the slash between m,d,y

	strm >> obj.month >> slash >> obj.day >> slash >> obj.year;
	return strm;
}