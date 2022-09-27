#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"
#include <iostream>
namespace sdds
{
    class Perishable : public Item
    {
        Date m_expire_date;
        char *m_instruction;

    public:
        Perishable();
        Perishable(const Perishable &);
        ~Perishable();
        Perishable &operator=(const Perishable &);
        const Date &expiry();
        int readSku(std::istream &istr);
        std::ofstream &save(std::ofstream &ofstr) const;
        std::ifstream &load(std::ifstream &ifstr);
        std::ostream &display(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
    };
}
#endif