/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Date.cpp
Version 1.0
Author    Ling Zhang
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/10  Start Coding
2022/03/15  Finish Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Date.h"
#include "Utils.h"
#include "Status.h"
#include <iomanip>
#include <string>
using namespace std;
namespace sdds
{
	bool Date::validate()
	{
		bool flag = false;
		if (Year <= max_year_value && Year >= current_year)
		{
			if (Month <= 12 && Month >= 1)
			{
				if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
				{
					if (Day >= 1 && Day <= 31)
						flag = true;
					else
					{
						State = "Invalid day in date";
						State = 3;
					}
				}
				else if (Year % 4 == 0 && Month == 2)
				{
					if (Day >= 1 && Day <= 29)
						flag = true;
					else
					{
						State = "Invalid day in date";
						State = 3;
					}
				}
				else if (Month == 2 && Year % 4 != 0)
				{
					if (Day >= 1 && Day <= 28)
						flag = true;
					else
					{
						State = "Invalid day in date";
						State = 3;
					}
				}

				else
				{
					if (Day >= 1 && Day <= 30)
						flag = true;
					else
					{
						State = "Invalid day in date";
						State = 3;
					}
				}
			}
			else
			{
				State = "Invalid month in date";
				State = 2;
			}
		}
		else
		{
			State = "Invalid year in date";
			State = 1;
		}

		return flag;
	}

	int Date::uniqueDateValue()
	{
		return Year * 372 + Month * 31 + Day;
	}

	Date::Date()
	{
		ut.getSystemDate(&Year, &Month, &Day);
		Formatted = true;
	}

	Date::Date(int year, int month, int day)
	{
		Year = year;
		Month = month;
		Day = day;
		if (validate())
			State.clear();
		Formatted = true;
	}

	Date::Date(const Date &a)
	{
		Year = a.Year;
		Month = a.Month;
		Day = a.Day;
		Formatted = true;
	}

	bool operator==(Date &a, Date &b)
	{
		if (a.uniqueDateValue() == b.uniqueDateValue())
			return true;
		else
			return false;
	}

	bool operator!=(Date &a, Date &b)
	{
		if (a.uniqueDateValue() != b.uniqueDateValue())
			return true;
		else
			return false;
	}

	bool operator<(Date &a, Date &b)
	{
		if (a.uniqueDateValue() < b.uniqueDateValue())
			return true;
		else
			return false;
	}

	bool operator>(Date &a, Date &b)
	{
		if (a.uniqueDateValue() > b.uniqueDateValue())
			return true;
		else
			return false;
	}

	bool operator<=(Date &a, Date &b)
	{
		if (a.uniqueDateValue() <= b.uniqueDateValue())
			return true;
		else
			return false;
	}

	bool operator>=(Date &a, Date &b)
	{
		if (a.uniqueDateValue() >= b.uniqueDateValue())
			return true;
		else
			return false;
	}

	const Status &Date::state()
	{
		return State;
	}

	Date &Date::formatted(bool a)
	{
		Formatted = a;
		return *this;
	}

	ostream &Date::write(ostream &ostr) const
	{
		if (Formatted)
		{
			ostr << Year << "/" << setw(2) << setfill('0') << Month << "/" << setw(2) << setfill('0') << Day;
		}
		else
			ostr << Year - 2000 << setw(2) << setfill('0') << Month << setw(2) << setfill('0') << Day;

		return ostr;
	}

	istream &Date::read(istream &istr)
	{
		string entered;
		char y[5], m[3], d[3];
		bool foundchar = false;
		istr >> entered;
		for (size_t i = 0; i < entered.length(); i++)
		{
			if (entered[i] > 57 || entered[i] < 48)
				foundchar = true;
		}
		if (!foundchar)
		{
			if (entered.length() == 4)
			{
				m[0] = entered[0];
				m[1] = entered[1];
				m[2] = '\0';
				d[0] = entered[2];
				d[1] = entered[3];
				d[2] = '\0';
				Month = atoi(m);
				Day = atoi(d);
				if (!validate())
					istr.setstate(ios::badbit);
			}
			else if (entered.length() == 6)
			{
				y[0] = '2';
				y[1] = '0';
				y[2] = entered[0];
				y[3] = entered[1];
				y[4] = '\0';
				m[0] = entered[2];
				m[1] = entered[3];
				m[2] = '\0';
				d[0] = entered[4];
				d[1] = entered[5];
				d[2] = '\0';
				Year = atoi(y);
				Month = atoi(m);
				Day = atoi(d);
				if (!validate())
					istr.setstate(ios::badbit);
			}
			else if (entered.length() == 2)
			{
				d[0] = entered[0];
				d[1] = entered[1];
				d[2] = '\0';
				Day = atoi(d);
				Month = 0;
				if (!validate())
					istr.setstate(ios::badbit);
			}
			else
			{
				validate();
				istr.setstate(ios::badbit);
			}
		}
		else
		{
			cout << "Invalid date value";
			istr.setstate(ios::badbit);
		}
		return istr;
	}

	ostream &operator<<(ostream &ostr, const Date &date)
	{
		return date.write(ostr);
	}

	istream &operator>>(istream &istr, Date &date)
	{
		return date.read(istr);
	}

	Date &Date::operator=(const Date &date)
	{
		Year = date.Year;
		Month = date.Month;
		Day = date.Day;
		State = date.State;
		Formatted = date.Formatted;
		return *this;
	};

}