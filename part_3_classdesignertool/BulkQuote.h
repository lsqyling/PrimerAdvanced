//
// Created by shiqing on 19-5-8.
//

#ifndef PRIMERADVANCED_BULKQUOTE_H
#define PRIMERADVANCED_BULKQUOTE_H

#include "../common/CommonHeaders.h"
#include "DiscQuote.h"

class BulkQuote : public DiscQuote {
public:
    BulkQuote() = default;

    BulkQuote(const string &, double, size_t, double);

    BulkQuote(const BulkQuote &bq) : DiscQuote(bq) {}

    BulkQuote(BulkQuote &&bq) noexcept : DiscQuote(std::move(bq)) {}

    BulkQuote &operator=(const BulkQuote &bq) {
        DiscQuote::operator=(bq);
        return *this;
    }

    BulkQuote &operator=(BulkQuote &&bq) {
        DiscQuote::operator=(std::move(bq));
        return *this;
    }

    BulkQuote *clone() const & override { return new BulkQuote(*this); }

    BulkQuote *clone() && override {
        return new BulkQuote(std::move(*this));
    }


    ~BulkQuote() {}

    double netPrice(size_t n) const override;

    virtual void debug() const override;


};


#endif //PRIMERADVANCED_BULKQUOTE_H
