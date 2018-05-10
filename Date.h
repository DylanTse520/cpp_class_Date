#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d);
	friend istream &operator >>(istream &is, Date &date);
	friend ostream &operator <<(ostream &os, const Date &date);
	bool vadality_check();						//check whether the date is valid
	friend bool leap_check(int y);				//check whether the year is a leap year

	int days_to_the_beginning() const;			//calculate which day the date is of the year 
	int days_to_the_end_of_the_year() const;	//calculate how many days are left of the year
	int days_to_the_end_of_the_month() const;	//calculate how many days are left of the month

	int same_month(const Date &date);			//if the two dates share the same year and the same month
	int same_year(const Date &date);			//if the two dates share the same year and different months
	int dif_year(const Date &date);				//if the two dates share different years
	int operator -(const Date &date);			//calculate how many days there are between two dates

	Date same_month(int days);					//if the following date is in the same month
	Date same_year(int days);					//if the following date is in the same year but a different month
	Date dif_year(int days);					//if the following date is in a different year
	Date operator +(int days);					//calculate which date is certain days after a date

};
