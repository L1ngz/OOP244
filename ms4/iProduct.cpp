/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Utils.h
Version 1.0
Author    Ling Zhang
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/26  Start Coding
2022/03/30  Finish Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "iProduct.h"
#include <iostream>
namespace sdds
{
    std::ostream& operator << (std::ostream& ostr, const iProduct& ipro){
        ipro.display(ostr);
        return ostr;
    };

    std::istream&  operator >> (std::istream& istr, iProduct& ipro){
        ipro.read(istr);
        return istr;
    };
}
