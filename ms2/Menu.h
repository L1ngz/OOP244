#ifndef MENU_H
#define MENU_H

namespace sdds {
	const int max_option = 15;
	class Menu {
		char* m_option;
		unsigned int m_numofoption;
	public:
		Menu(unsigned int, const char*);
		~Menu();
		unsigned int run();
	};

}
#endif // !MENU_H
