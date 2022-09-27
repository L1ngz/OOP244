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
#include "Menu.h"
#include "Utils.h"

#include<iostream>
#include <cstring>

namespace sdds {
	Menu::Menu(unsigned int a, const char* b) {
		if (a > max_option || b == nullptr) {
			m_numofoption = 0;
			m_option = nullptr;
		}
		else {
			m_numofoption = a;
			m_option = new char[strlen(b) + 1];
			strcpy(m_option, b);
		}
	}
	Menu::~Menu() {
		delete[] m_option;
	}

	unsigned int Menu::run() {
		std::cout << m_option << std::endl;
		return ut.getint(0, 7, "> ");

	}

}