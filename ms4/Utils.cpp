/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Utils.cpp
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
#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"
#include <string>
#include <iomanip>
using namespace std;
namespace sdds
{
   Utils ut;
   void Utils::testMode(bool testmode)
   {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int *year, int *mon, int *day)
   {
      if (m_testMode)
      {
         if (day)
            *day = sdds_testDay;
         if (mon)
            *mon = sdds_testMon;
         if (year)
            *year = sdds_testYear;
      }
      else
      {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day)
            *day = lt.tm_mday;
         if (mon)
            *mon = lt.tm_mon + 1;
         if (year)
            *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year) const
   {
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
      int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

   void Utils::alocpy(char *&destination, const char *source)
   {
      delete[] destination;
      destination = nullptr;
      if (source != nullptr)
      {
         destination = new char[strlen(source) + 1];
         strcpy(destination, source);
      }
   }

   int Utils::getint(const char *prompt)
   {
      bool flag = true;
      size_t intFound = 0;
      string input;
      if (prompt != nullptr)
      {
          cout << prompt;
         while (flag)
         {
           
            cin >> input;
            for (size_t i = 0; i < input.size(); i++)
            {
               if (input[i] > 47 && input[i] < 58)
                  intFound++;   
            }
            if(intFound == input.size())
               flag = false;
            else
               cout << "Invalid Integer, retry: ";
         }
      }
      return stoi(input);
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes){
      bool flag = true;
      int i;
       i = getint(prompt);
      while(flag){
         if (i < min || i > max) {
             if (errMes != nullptr){
                 cout << errMes << ", retry: ";
                 i= getint(" ");
             }
             else{
                 cout << "Value out of range [" << min << "<=val<=" << max << "]:";
                 i = getint(" ");
             }
         }
         else
             flag = false;
         
      }
      
      return i;


   }

      double Utils::getdouble(const char* prompt){
         double temp;
         bool flag = false;
         if (prompt)
            cout << prompt;
         while(!flag){
            cin >> temp;
            if(!cin.fail()){
               flag = true;
            }
            else
               cout << "Invalid number, retry: ";
            cin.clear();
            cin.ignore(1000,'\n');
         }

         return temp;

      }

      double Utils::getdouble(double min, double max, const char* prompt, const char* errMes){
         bool flag = true;
      double i;
       i = getdouble(prompt);
      while(flag){
         if (i < min || i > max) {
             if (errMes != nullptr){
                 cout << errMes << ", retry: ";
                 i= getdouble(" ");
             }
             else{
                 cout << "Value out of range [" << fixed << setprecision(2) <<min << "<=val<=" << fixed << setprecision(2) << max << "]:";
                 i = getdouble(" ");
             }
         }
         else
             flag = false;
         
      }
      
      return i;
 
      };



}