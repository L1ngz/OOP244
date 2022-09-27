/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Date.h
Version 1.0
Author    Ling Zhang
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/21  Start Coding
2022/03/22  Finish Debugging
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef AIDMAN_H
#define ADIMAN_H
#include "Menu.h"
namespace sdds{
	class AidMan : public Menu {
		char* m_filename;
		unsigned int menu();
	public:
		AidMan();
		~AidMan();
		void run();
};

}


#endif