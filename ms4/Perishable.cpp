#include "Perishable.h"
#include <cstring>
#include <string>
#include <fstream>
#include "Utils.h"

namespace sdds
{
    Perishable::Perishable() : Item()
    {
        Date m_expire_date;
        m_instruction = nullptr;
    };

    Perishable::Perishable(const Perishable &pe) : Item(pe)
    {
        if (pe.m_instruction != nullptr)
        {
            m_instruction = new char(strlen(pe.m_instruction) + 1);
            strcpy(m_instruction, pe.m_instruction);
            m_expire_date = pe.m_expire_date;
            m_expire_date = pe.m_expire_date;
        }
        else
        {
            m_instruction = nullptr;
            m_expire_date = pe.m_expire_date;
        }
    };

    Perishable::~Perishable()
    {
        delete[] m_instruction;
    };

    Perishable &Perishable::operator=(const Perishable &pe)
    {
        if (pe.m_instruction != nullptr)
        {
            delete[] m_instruction;
            m_instruction = nullptr;
            m_instruction = new char[strlen(pe.m_instruction) + 1];
            strcpy(m_instruction, pe.m_instruction);
            m_expire_date = pe.m_expire_date;
        }

        else
        {
            m_instruction = nullptr;
            m_expire_date = pe.m_expire_date;
        }
        return *this;
    };

    const Date &Perishable::expiry()
    {
        return m_expire_date;
    };

    int Perishable::readSku(std::istream &istr)
    {
        m_SKU = ut.getint(10000, 39999, "SKU: ");
        std::cin.ignore(1000, '\n');
        // std::cin.get();
        return m_SKU;
    }

    std::ofstream &Perishable::save(std::ofstream &ofstr) const
    {
        Item::save(ofstr);
        ofstr << '\t';
        if (m_instruction != nullptr)
        {
            ofstr << m_instruction;
        }
        ofstr << '\t';
        ofstr << m_expire_date;
        return ofstr;
    };

    std::ifstream &Perishable::load(std::ifstream &ifstr)
    {
        string temp;
        Item::load(ifstr);
        ifstr.ignore(10000, '\t');
        getline(ifstr, temp, '\t');
        m_instruction = new char[temp.length() + 1];
        strcpy(m_instruction, temp.c_str());
        ifstr.ignore(10000, '\t');
        m_expire_date.read(ifstr);
        ifstr.ignore(10000, '\n');
        if (ifstr.fail())
            m_state = "Input file stream read (perishable) failed!";
        return ifstr;
    };

    std::ostream &Perishable::display(std::ostream &ostr) const
    {

        if (!m_state)
        {
            ostr << m_state;
        }
        else
        {
            if (Item::Linear())
            {
                Item::display(ostr);
                if (m_instruction != nullptr)
                    ostr << '*';
                else
                    ostr << ' ';
                ostr << m_expire_date;
            }
            else
            {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_expire_date;
                if (m_instruction != nullptr)
                {
                    ostr << "Handling Instructions: ";
                    ostr << m_instruction;
                }
                ostr << std::endl;
            }
        }
        return ostr;
    };

    std::istream &Perishable::read(std::istream &istr)
    {
        Item::read(istr);
        delete[] m_instruction;
        m_instruction = nullptr;
        std::cout << "Expiry date (YYMMDD): ";
        istr >> m_expire_date;
        istr.ignore(1000, '\n');
        std::cout << "Handling Instructions, ENTER to skip: ";
        if (istr.peek() != '\n')
        {
            istr.getline(m_instruction, '\n');
            istr.ignore(1000, '\n');
        }
        if (istr.fail())
        {
            m_state = "Perishable console date entry failed!";
        }
        return istr;
    };

}