/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Status.h
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
#ifndef STATUS_H
#define STATUS_H
#include <iostream>
using namespace std;
namespace sdds
{
    class Status
    {
        char *Desc;
        int Code;

    public:
        Status();
        Status(const char *desc);
        Status(const Status &);
        Status &operator=(const char *);
        Status &operator=(int);
        Status &operator=(const Status &);
        operator int() const;
        operator bool() const;
        operator const char *() const;
        Status &clear();
        friend ostream &operator<<(ostream &, const Status &);
        ~Status();
    };
    extern Status sts;
}

#endif