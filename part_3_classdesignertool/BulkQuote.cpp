//
// Created by shiqing on 19-5-8.
//

#include "BulkQuote.h"


BulkQuote::BulkQuote(const string &bookNo, double price, size_t minQty, double discount)
        : DiscQuote(bookNo, price, minQty, discount) {
}

double BulkQuote::netPrice(size_t n) const {
    if (n >= qty_) {
        return n * (1 - discount_) * price_;
    }
    return n * price_;
}


void BulkQuote::debug() const {
    this->Quote::debug();
    cout << ": {" << qty_ << " " << discount_  << "}";
}
