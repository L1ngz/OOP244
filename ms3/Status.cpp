/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Status.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
namespace sdds
{
    Status::Status()
    {
        Desc = nullptr;
        Code = 0;
    }

    Status::Status(const char* desc)
    {
        if (desc != nullptr) {
            Desc = new char[strlen(desc) + 1];
            strcpy(Desc, desc);
            Code = 0;
        }
        else {
            Desc = nullptr;
            Code = 0;
        }
    }

    Status::Status(const Status& sts) {
        if (sts.Desc != nullptr) {
            Desc = new char[strlen(sts.Desc) + 1];
            strcpy(Desc, sts.Desc);
            Code = sts.Code;
        }
        else {
            Desc = nullptr;
            Code = sts.Code;
        }
    }

    Status &Status::operator=(const char *desc)
    {
        if (desc != nullptr)
        {
            delete[] Desc;
            Desc = new char[strlen(desc) + 1];
            strcpy(Desc, desc);
        }
        return *this;
    }

    Status& Status::operator=(int code){
        Code = code;
        return *this;
    }

    Status::operator int() const{
        return Code;
    }

    Status::operator bool() const{
        if(Desc == nullptr)
            return true;
        else 
            return false;
    }

    Status::operator const char*() const{
        return Desc;
    }

    Status& Status::clear(){
        delete[] Desc;
        Desc = nullptr;
        Code = 0;
        return *this;
    }

    ostream& operator<< (ostream& ostr, const Status& status) {
        if (!status) {
            if (status.Code == 0)
                ostr << status.Desc;
            else
                ostr << "ERR#" << status.Code << ": " << status.Desc;
        }
        return ostr;
    }
    Status::~Status(){
        delete[] Desc;
        Desc = nullptr;
    }


}