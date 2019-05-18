//
// Created by shiqing on 18-8-4.
//

#ifndef PRIMER_SALES_ITEM_H
#define PRIMER_SALES_ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Sales_item {

public:
    string isbn;
    unsigned units_sold;
    double revenue;

public:
    Sales_item(const string &book) : isbn(book), units_sold(0), revenue(0.0) {}

    Sales_item(istream &is) { is >> *this; }

    friend istream &operator>>(istream &, Sales_item &);

    friend ostream &operator<<(ostream &, const Sales_item &);

public:
    Sales_item &operator+=(const Sales_item &);

public:
    double avg_price() const;

    bool same_isbn(const Sales_item &rhs) const {
        return isbn == rhs.isbn;
    }

    Sales_item() : units_sold(0), revenue(0.0) {}


};

Sales_item operator+(const Sales_item &, const Sales_item &);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs) {
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.same_isbn(rhs);
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs) {
    return !(lhs == rhs);
}

inline Sales_item &Sales_item::operator+=(const Sales_item &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) {
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}

inline istream &operator>>(istream &in, Sales_item &s) {
    double price;
    in >> s.isbn >> s.units_sold >> price;
    if (in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();
    return in;
}

inline ostream &operator<<(ostream &out, const Sales_item &s) {
    out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price();
    return out;
}

inline double Sales_item::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

#endif //PRIMER_SALES_ITEM_H
