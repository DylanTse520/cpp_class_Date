#include <iostream>
#include <cmath>
#include "Date.h"

int Date::same_month(const Date &d)
{
	return abs(day - d.day);
}

int Date::same_year(const Date &d)
{
	int days_1, days_2;
	days_1 = days_to_the_beginning();
	days_2 = d.days_to_the_beginning();
	return abs(days_1 - days_2);
}

int Date::dif_year(const Date &d)
{
	Date d_early, d_late;
	if (year > d.year)
	{
		d_early = d;
		d_late = *this;
	}
	else
	{
		d_early = *this;
		d_late = d;
	}

	int to_the_end = d_early.days_to_the_end_of_the_year();

	int leaps = 0;
	for (int y = d_early.year + 1; y < d_late.year; y++)
	{
		if (leap_check(y))
		{
			leaps++;
		}
	}
	int days_in_between = (d_late.year - d_early.year - 1) * 365 + leaps;

	int to_the_beginning = d_late.days_to_the_beginning();

	return to_the_end + days_in_between + to_the_beginning;
}

int Date::operator -(const Date &d)
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			return same_month(d);
		}
		else
		{
			return same_year(d);
		}
	}
	else
	{
		return dif_year(d);
	}
}