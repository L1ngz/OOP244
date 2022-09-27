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
#include "AidMan.h"
#include "Date.h"
#include <iostream>
namespace sdds {
	AidMan::AidMan():Menu(7,"1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n0- Exit") {
		m_filename = nullptr;
	}

	unsigned int AidMan::menu() {
		Date a;
		std::cout << "Aid Management System Version 0.1" << std::endl;
		std::cout << "Date: ";
		std::cout << a << std::endl;
		std::cout << "Data file: ";
		if (!m_filename)
			std::cout << "No file" << std::endl;
		else
			std::cout << m_filename << std::endl;
		std::cout << "---------------------------------" << std::endl;
		unsigned int i = Menu::run();
		return i;
	}
	AidMan::~AidMan() {
		delete[] m_filename;
	}

	void AidMan::run() {
		bool flag = true;
		unsigned int i;
		do {
			i = menu();
			switch (i){
			case 1:
				std::cout << "\n****List Items****\n\n";
				break;
			case 2:
				std::cout << "\n****Add Item****\n\n";
				break;
			case 3:
				std::cout << "\n****Remove Item****\n\n";
				break;
			case 4:
				std::cout << "\n****Update Quantity****\n\n";
				break;
			case 5:
				std::cout << "\n****Sort****\n\n";
				break;
			case 6:
				std::cout << "\n****Ship Items****\n\n";
				break;
			case 7:
				std::cout << "\n****New/Open Aid Database****\n\n";
				break;
			case 0:
				std::cout << "Exiting Program!\n\n";
				flag = false;
				break;
			}
		} while (flag);

	}

}

