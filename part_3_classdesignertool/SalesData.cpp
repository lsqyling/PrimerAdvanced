//
// Created by shiqing on 19-5-7.
//

#include "SalesData.h"



sd::SalesData::SalesData(std::istream &in) {
    double price;
    in >> isbn_ >> unitsSold_ >> price;
    if (in) {
        revenue_ = unitsSold_ * price;
    } else {
        SalesData();
    }
}

sd::SalesData &sd::SalesData::operator+=(const sd::SalesData &rhs) {
    unitsSold_ += rhs.unitsSold_;
    revenue_ += rhs.revenue_;
    return *this;
}


bool sd::operator==(const sd::SalesData &lhs, const sd::SalesData &rhs) {
    return lhs.isbn_ == rhs.isbn_;
}

sd::SalesData sd::operator+(const sd::SalesData &lhs, const sd::SalesData &rhs) {
    SalesData sum = lhs;
    sum += rhs;
    return sum;
}

std::ostream &sd::operator<<(std::ostream &os, const sd::SalesData &rhs) {
    os << rhs.isbn_ << " " << rhs.unitsSold_ << rhs.revenue_;
    return os;
}


std::istream &sd::operator>>(std::istream &is, sd::SalesData &rhs) {
    double price;
    is >> rhs.isbn_ >> rhs.unitsSold_ >> price;
    if (is) {
        rhs.revenue_ = rhs.unitsSold_ * price;
    }
    return is;
}


bool sd::operator!=(const sd::SalesData &lhs, const sd::SalesData &rhs) {
    return !(lhs == rhs);
}







