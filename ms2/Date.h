/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Date.h
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
#ifndef DATE_H
#define DATE_H
#include<iostream>
#include "Status.h"
using namespace std;
namespace sdds {
	const int max_year_value = 2030;
	const int current_year = 2022;
	class Date {
		int Year;
		int Month;
		int Day;
		Status State;
		bool Formatted;
		bool validate();
		int uniqueDateValue();
	public:
		Date();
		Date(int, int, int);
		Date(const Date&);
		friend bool operator==(Date&, Date&);
		friend bool operator!=(Date&, Date&);
		friend bool operator < (Date&, Date&);
		friend bool operator > (Date&, Date&);
		friend bool operator <=(Date&, Date&);
		friend bool operator >=(Date&, Date&);
		const Status& state();
		Date& formatted(bool);
		ostream& write(ostream&) const;
		istream& read(istream&);
		friend ostream& operator<< (ostream&, const Date&);
		friend istream& operator>> (istream&, Date&);

	};
}
#endif // !DATE_H