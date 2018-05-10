#include <iostream>
#include <cmath>
#include "Date.h"

Date::Date()
	: year(1970), month(1), day(1) { }

Date::Date(int y, int m, int d)
	: year(y), month(m), day(d) { }

istream &operator >>(istream &is, Date &d)
{
	do
	{
		is >> d.year >> d.month >> d.day;
		if (d.vadality_check())
		{
			return is;
		}
		else
		{
			cout << "the date is not valid" << endl;
		}
	} while (1);
}

ostream &operator <<(ostream &os, const Date &d)
{
	os << d.year << '/' << d.month << '/' << d.day;
	return os;
}

bool Date::vadality_check()
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day >= 1 && day <= 31)
		{
			return true;
		}
		else
		{
			return false;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	case 2:
		if (leap_check(year))
		{
			if (day >= 1 && day <= 29)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (day >= 1 && day <= 28)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	default:
		return false;
	}
}

bool leap_check(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Date::days_to_the_beginning() const
{
	int leap = 0;
	if (leap_check(year))
	{
		leap = 1;
	}

	int days;
	switch (month)
	{
	case 1:
		days = day;
		break;
	case 2:
		days = day + 31;
		break;
	case 3:
		days = day + 59 + leap;
		break;
	case 4:
		days = day + 90 + leap;
		break;
	case 5:
		days = day + 120 + leap;
		break;
	case 6:
		days = day + 151 + leap;
		break;
	case 7:
		days = day + 181 + leap;
		break;
	case 8:
		days = day + 212 + leap;
		break;
	case 9:
		days = day + 243 + leap;
		break;
	case 10:
		days = day + 273 + leap;
		break;
	case 11:
		days = day + 304 + leap;
		break;
	case 12:
		days = day + 334 + leap;
		break;
	}
	return days;
}

int Date::days_to_the_end_of_the_year() const
{
	int to_the_end;
	if (leap_check(year))
	{
		to_the_end = 366 - days_to_the_beginning();
	}
	else
	{
		to_the_end = 365 - days_to_the_beginning();
	}
	return to_the_end;
}

int Date::days_to_the_end_of_the_month() const
{
	int leap = 0;
	if (leap_check(year))
	{
		leap = 1;
	}

	int to_the_end;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		to_the_end = 31 - day;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		to_the_end = 30 - day;
		break;
	case 2:
		to_the_end = 28 + leap - day;
		break;
	}
	return to_the_end;
}