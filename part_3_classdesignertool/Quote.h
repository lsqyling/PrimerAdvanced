//
// Created by shiqing on 19-5-8.
//

#ifndef PRIMERADVANCED_QUOTE_H
#define PRIMERADVANCED_QUOTE_H

#include "../common/CommonHeaders.h"

class Quote {

public:
    Quote() = default;

    Quote(const string &bookNo, double price) : bookNo_(bookNo), price_(price) {}

    string isbn() const { return bookNo_; }

    virtual Quote *clone() const & { return new Quote(*this); }

    virtual Quote *clone() && { return new Quote(std::move(*this)); }



//    copy control member
    Quote(const Quote &quote);
    Quote(Quote &&quote) noexcept ;

    Quote &operator=(const Quote &rhs);
    Quote &operator=(Quote &&rhs);



    virtual double netPrice(size_t n) const { return n * price_; }

    virtual void debug() const;

    virtual ~Quote();

    static double printTotal(std::ostream &os, const Quote &q, size_t n);

private:
    string bookNo_;
protected:
    double price_ = 0.0;

};


#endif //PRIMERADVANCED_QUOTE_H
