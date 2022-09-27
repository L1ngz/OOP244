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
#ifndef ITEM_H
#define ITEM_H
#include "iProduct.h"
#include "Status.h"
#include <iostream>
namespace sdds
{
    class Item : public iProduct
    {
    private:
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char *m_description;
        bool m_linear;

    protected:
        Status m_state;
        int m_SKU;
        bool Linear() const;

    public:
        Item();
        Item(const Item &);
        ~Item();
        Item &operator=(const Item &);
        int readSku(std::istream &istr);
        int operator-=(int qty);
        int operator+=(int qty);
        operator double() const;
        operator bool() const;
        int qtyNeeded() const;
        int qty() const;
        void linear(bool isLinear);
        std::ofstream &save(std::ofstream &ofstr) const;
        std::ifstream &load(std::ifstream &ifstr);
        std::ostream &display(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        bool operator==(int sku) const;
        bool operator==(const char *description) const;
        void clear();
    };
};
#endif