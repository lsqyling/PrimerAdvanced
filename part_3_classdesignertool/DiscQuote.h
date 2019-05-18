//
// Created by shiqing on 19-5-8.
//

#ifndef PRIMERADVANCED_DISCQUOTE_H
#define PRIMERADVANCED_DISCQUOTE_H

#include "../common/CommonHeaders.h"
#include "Quote.h"


class DiscQuote : public Quote {

public:
    DiscQuote(const string &bookNo, double price, size_t qty, double discount)
            : Quote(bookNo, price), qty_(qty), discount_(discount) {}

    DiscQuote(const DiscQuote &dq);
    DiscQuote(DiscQuote &&dq) noexcept ;
    DiscQuote &operator=(const DiscQuote &dq);
    DiscQuote &operator=(DiscQuote &&dq);
    ~DiscQuote();
    virtual double netPrice(size_t n) const = 0;

protected:
    size_t qty_;
    double discount_;

};



#endif //PRIMERADVANCED_DISCQUOTE_H
