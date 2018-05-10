#include <iostream>
#include <cmath>
#include "Date.h"

Date Date::same_month(int days)
{
	Date result(*this);
	result.day += days;
	return result;
}

Date Date::same_year(int ds)
{
	int days = days_to_the_beginning() + ds;

	int leap = 0;
	if (leap_check(year))
	{
		leap = 1;
	}

	Date result(*this);

	if (days <= 31)
	{
		result.month = 1;
		result.day = days;
	}
	if (days > 31 && days <= 59 + leap)
	{
		result.month = 2;
		result.day = days - 31;
	}
	if (days > 59 + leap && days <= 90 + leap)
	{
		result.month = 3;
		result.day = days - 59 - leap;
	}
	if (days > 90 + leap && days <= 120 + leap)
	{
		result.month = 4;
		result.day = days - 90 - leap;
	}
	if (days > 120 + leap && days <= 151 + leap)
	{
		result.month = 5;
		result.day = days - 120 - leap;
	}
	if (days > 151 + leap && days <= 181 + leap)
	{
		result.month = 6;
		result.day = days - 151 - leap;
	}
	if (days > 181 + leap && days <= 212 + leap)
	{
		result.month = 7;
		result.day = days - 181 - leap;
	}
	if (days > 212 + leap && days <= 243 + leap)
	{
		result.month = 8;
		result.day = days - 212 - leap;
	}
	if (days > 243 + leap && days <= 273 + leap)
	{
		result.month = 9;
		result.day = days - 243 - leap;
	}
	if (days > 273 + leap && days <= 304 + leap)
	{
		result.month = 10;
		result.day = days - 273 - leap;
	}
	if (days > 304 + leap && days <= 334 + leap)
	{
		result.month = 11;
		result.day = days - 304 - leap;
	}
	if (days > 334 + leap && days <= 365 + leap)
	{
		result.month = 12;
		result.day = days - 334 - leap;
	}

	return result;
}

Date Date::dif_year(int days)
{
	Date result(*this);

	int to_the_end = days_to_the_end_of_the_year();
	days -= to_the_end + 1;
	result.year++;
	result.month = 1;
	result.day = 1;

	for (int years = year + 1;; years++)
	{
		int leap = 0;
		if (leap_check(years))
		{
			leap = 1;
		}

		if (days > 365 + leap)
		{
			days -= 365 + leap;
			result.year++;
		}
		else
		{
			result = result.same_year(days);
			return result;
		}
	}
}

Date Date::operator +(int days)
{
	int to_the_end_of_the_month = days_to_the_end_of_the_month();
	int to_the_end_of_the_year = days_to_the_end_of_the_year();
	if (days <= to_the_end_of_the_month)
	{
		return same_month(days);
	}
	if (days > to_the_end_of_the_month&&days <= to_the_end_of_the_year)
	{
		return same_year(days);
	}
	else
	{
		return dif_year(days);
	}
}