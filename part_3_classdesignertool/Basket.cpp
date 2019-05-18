//
// Created by shiqing on 19-5-9.
//

#include "Basket.h"

double Basket::printTotal(std::ostream &os, const Quote &quote, size_t n) const {
    double total = quote.netPrice(n);
    quote.printTotal(os, quote, n);
    return total;
}

double Basket::totalReceipt(std::ostream &os) const {
    double sum = 0;
    for (auto iter = items_.begin(); iter != items_.end(); iter = items_.upper_bound(*iter)) {
        sum += printTotal(os, **iter, items_.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}


