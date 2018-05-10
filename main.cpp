#include <iostream>
#include "Date.h"

int main()
{
	cout << "input two dates, return how many days there are between the two dates" << endl;
	Date d1, d2;
	cin >> d1 >> d2;
	int days1 = d1 - d2;
	if (days1 == 0 || days1 == 1)
	{
		cout << "there is " << days1 << " day between " << d1 << " and " << d2 << endl;
	}
	else
	{
		cout << "there are " << days1 << " days between " << d1 << " and " << d2 << endl;
	}

	cout << "input a date and certain days, return which date is those days after that date" << endl;
	Date d3;
	cin >> d3;
	int days2;
	cin >> days2;
	if (days2 == 0 || days2 == 1)
	{
		cout << d3 + days2 << " is " << days2 << " day after " << d3 << endl;
	}
	else
	{
		cout << d3 + days2 << " is " << days2 << " days after " << d3 << endl;
	}
	return 0;
}
