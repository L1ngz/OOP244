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
#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
namespace sdds
{
    Item::Item() : iProduct()
    {
        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_SKU = 0;
        Status m_state;
        m_description = nullptr;
        m_linear = false;
    };

    Item::Item(const Item &item)
    {
        m_linear = item.m_linear;
        m_price = item.m_price;
        m_qty = item.m_qty;
        m_qtyNeeded = item.m_qtyNeeded;
        m_SKU = item.m_SKU;
        m_state = item.m_state;
        m_description = new char[strlen(item.m_description) + 1];
        strcpy(m_description, item.m_description);
    }

    Item::~Item()
    {
        delete[] m_description;
    };

    Item &Item::operator=(const Item &item)
    {
        m_linear = item.m_linear;
        m_price = item.m_price;
        m_qty = item.m_qty;
        m_qtyNeeded = item.m_qtyNeeded;
        m_SKU = item.m_SKU;
        m_state = item.m_state;
        delete[] m_description;
        m_description = nullptr;
        m_description = new char[strlen(item.m_description) + 1];
        strcpy(m_description, item.m_description);
        return *this;
    }
    int Item::qtyNeeded() const
    {
        return m_qtyNeeded;
    }

    int Item::qty() const
    {
        return m_qty;
    }

    Item::operator double() const
    {
        return m_price;
    }

    Item::operator bool() const
    {
        return bool(m_state);
    }

    int Item::operator-=(int qty)
    {
        m_qty -= qty;
        return m_qty;
    }

    int Item::operator+=(int qty)
    {
        m_qty += qty;
        return m_qty;
    }

    void Item::linear(bool isLinear)
    {
        m_linear = isLinear;
    }

    void Item::clear()
    {
        m_state.clear();
    }

    bool Item::operator==(int sku) const
    {
        if (m_SKU != sku)
            return false;
        else
            return true;
    }

    bool Item::operator==(const char *description) const
    {
        string temp = std::string(m_description);
        string cmp = std::string(description);
        if (temp.find(cmp) != string::npos)
            return true;
        else
            return false;
    }

    std::ofstream &Item::save(std::ofstream &ofstr) const
    {
        if (m_state)
        {
            ofstr << m_SKU << '\t' << m_description << '\t' << m_qty << '\t' << m_qtyNeeded << '\t' << m_price << std::endl;
        }
        return ofstr;
    }

    std::ifstream &Item::load(std::ifstream &ifstr)
    {
        string temp;
        delete[] m_description;
        m_description = nullptr;
        ifstr >> m_SKU;
        ifstr.ignore(10000, '\t');
        getline(ifstr, temp, '\t');
        m_description = new char[temp.length() + 1];
        strcpy(m_description, temp.c_str());
        // ifstr.ignore(10000,'\t');
        ifstr >> m_qty;
        ifstr >> m_qtyNeeded;
        ifstr >> m_price;
        ifstr.ignore(10000, '\n');
        // ifstr.get();
        if (ifstr.fail())
            m_state = "Input file stream read failed!";
        return ifstr;
    };

    std::ostream &Item::display(std::ostream &ostr) const
    {
        if (m_linear == true)
        {
            if (strlen(m_description) <= 28)
            {
                ostr << m_SKU;
                ostr << " | ";
                ostr << setw(35);
                ostr << std::left << m_description;
                ostr << " | ";
                ostr.width(4);
                ostr << std::right<<m_qty;
                ostr << " | ";
                ostr.width(4);
                ostr << std::right << m_qtyNeeded;
                ostr << " | ";
                ostr.width(7);
                ostr << std::fixed << std::setprecision(2) << std::right << m_price;
                ostr << " |";
            }
            else{
                string temp(m_description);
                string p = temp.substr(0,35);
                ostr << m_SKU;
                ostr << " | ";
                ostr << setw(35);
                ostr << std::left << p;
                ostr << " | ";
                ostr.width(4);
                ostr << std::right << m_qty;
                ostr << " | ";
                ostr.width(4);
                ostr << std::right << m_qtyNeeded;
                ostr << " | ";
                ostr.width(7);
                ostr << std::fixed << std::setprecision(2) << std::right<< m_price;
                ostr << " |";



            }
        }

        else
        {
            ostr << "AMA Item:" << std::endl;
            ostr << m_SKU << ": " << m_description << endl;
            ostr << "Quantity Needed: " << m_qtyNeeded << std::endl;
            ostr << "Quantity Available: " << m_qty << std::endl;
            ostr << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << std::endl;
            ostr << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << m_price * (m_qtyNeeded - m_qty) << std::endl;
        }

        return ostr;
    }

    int Item::readSku(std::istream &istr)
    {
        m_SKU = ut.getint(40000, 99999, "SKU: ");
        std::cin.ignore(1000, '\n');
        // std::cin.get();
        return m_SKU;
    }

    std::istream &Item::read(std::istream &istr)
    {
        char temp[1000];
        delete[] m_description;
        m_description = nullptr;
        m_state.clear();
        std::cout << "AMA Item:" << std::endl;
        std::cout << "SKU: " << m_SKU << std::endl;
        std::cout << "Description: ";
        istr.get(temp, '\n');
        istr.ignore(10000, '\n');
        // istr.get();
        m_description = new char[strlen(temp) + 1];
        strcpy(m_description, temp);
        m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ");
        m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ");
        m_price = ut.getdouble(0.00, 9999.00, "Unit Price: $");
        if (istr.fail())
            m_state = "Console entry failed!";

        return istr;
    }

}