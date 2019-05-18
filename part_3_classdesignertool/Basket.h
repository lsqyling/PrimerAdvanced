//
// Created by shiqing on 19-5-9.
//

#ifndef PRIMERADVANCED_BASKET_H
#define PRIMERADVANCED_BASKET_H

#include <set>
#include "../common/CommonHeaders.h"
#include "Quote.h"

class Basket {
public:
    void addItem(const Quote &quote);

    void addItem(Quote &&quote);

    double totalReceipt(std::ostream &os) const;


private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs);

    double printTotal(std::ostream &os, const Quote &quote, size_t n) const;
//    Note that parentheses cannot be used here, and classes can only be initialized with the = or braces.
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items_{compare};


};


inline void Basket::addItem(const Quote &quote) {
    items_.insert(std::shared_ptr<Quote>(quote.clone()));
}


inline void Basket::addItem(Quote &&quote) {
//    if the class of Quote don't define the function that end of & or &&, you can use
//    items_.insert(std::shared_ptr<Quote>(quote.clone())); ,because quote is left reference.
    items_.insert(shared_ptr<Quote>(std::move(quote).clone()));
}

inline bool Basket::compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
}


#endif //PRIMERADVANCED_BASKET_H
