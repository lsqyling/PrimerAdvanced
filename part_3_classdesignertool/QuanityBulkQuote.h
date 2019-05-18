//
// Created by shiqing on 19-5-8.
//

#ifndef PRIMERADVANCED_QUANITYBULKQUOTE_H
#define PRIMERADVANCED_QUANITYBULKQUOTE_H


#include "DiscQuote.h"

class QuantityBulkQuote : public DiscQuote {
public:
    QuantityBulkQuote() = default;

    QuantityBulkQuote(const string &bookNo, double price, size_t maxQty, double discount);

    QuantityBulkQuote(const QuantityBulkQuote &qbq) : DiscQuote(qbq) {}
    QuantityBulkQuote(QuantityBulkQuote &&qbq) noexcept : DiscQuote(std::move(qbq)) {}

    QuantityBulkQuote &operator=(const QuantityBulkQuote &qbq) {
        DiscQuote::operator=(qbq);
        return *this;
    }

    QuantityBulkQuote &operator=(QuantityBulkQuote &&qbq) {
        DiscQuote::operator=(std::move(qbq));
        return *this;
    }


    QuantityBulkQuote *clone() const & override {
        return new QuantityBulkQuote(*this);
    }

    QuantityBulkQuote *clone() && override {
        return new QuantityBulkQuote(std::move(*this));
    }


    ~QuantityBulkQuote(){}



    double netPrice(size_t n) const override;

    virtual void debug() const override;

};


#endif //PRIMERADVANCED_QUANITYBULKQUOTE_H
