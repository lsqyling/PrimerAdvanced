//
// Created by shiqing on 19-5-8.
//

#include "QuanityBulkQuote.h"




QuantityBulkQuote::QuantityBulkQuote(const string &bookNo, double price, size_t maxQty, double discount)
        : DiscQuote(bookNo, price, maxQty, discount) {
}

void QuantityBulkQuote::debug() const {
    Quote::debug();
    cout << ": {" << qty_ << " " << discount_ << "}";
}

double QuantityBulkQuote::netPrice(size_t n) const {
    if (n <= qty_) {
        return n * (1 - discount_) * price_;
    }
    return n * price_;
}




