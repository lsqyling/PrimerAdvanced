//
// Created by shiqing on 19-5-8.
//

#include "Quote.h"


double Quote::printTotal(std::ostream &os, const Quote &q, size_t n) {
    double ret = q.netPrice(n);
    os << "ISBN: " << q.isbn()
       << " # sold: " << n << " total due: "
       << ret << endl;
    return ret;

}


Quote::Quote(const Quote &quote) : bookNo_(quote.bookNo_), price_(quote.price_) {
    cout << "Quote, copy-constructor..." << endl;
}

Quote::Quote(Quote &&quote) noexcept : bookNo_(quote.bookNo_), price_(quote.price_) {
    cout << "Quote, move-constructor..." << endl;
}

Quote &Quote::operator=(const Quote &rhs) {
    cout << "Quote, copy-assign function..." << endl;
    bookNo_ = rhs.bookNo_;
    price_ = rhs.price_;
    return *this;
}

Quote &Quote::operator=(Quote &&rhs) {
    cout << "Qutoe, move-assign function..." << endl;
    bookNo_ = rhs.bookNo_;
    price_ = rhs.price_;
    return *this;
}


Quote::~Quote() {
    cout << "Quote, destorying..." << endl;
}


void Quote::debug() const {
    cout << "{" << bookNo_ << " " << price_  << "}";
}
