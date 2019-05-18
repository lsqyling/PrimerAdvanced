//
// Created by shiqing on 19-5-8.
//

#include "DiscQuote.h"



DiscQuote::DiscQuote(const DiscQuote &dq) : Quote(dq), qty_(dq.qty_), discount_(dq.discount_) {
    cout << "DiscQuote, copy-constructor..." << endl;
}

DiscQuote::DiscQuote(DiscQuote &&dq) noexcept : Quote(std::move(dq)), qty_(dq.qty_), discount_(dq.discount_) {
    cout << "DiscQuote, move-constructor..." << endl;
}

DiscQuote &DiscQuote::operator=(const DiscQuote &dq) {
    cout << "DiscQuote, copy-assign function..." << endl;
    Quote::operator=(dq);
    qty_ = dq.qty_;
    discount_ = dq.discount_;
    return *this;
}

DiscQuote &DiscQuote::operator=(DiscQuote &&dq) {
    cout << "DisQuote, move-assign function..." << endl;
    Quote::operator=(std::move(dq));
    qty_ = dq.qty_;
    discount_ = dq.discount_;
    return *this;
}

DiscQuote::~DiscQuote() {
    cout << "DiscQuote destroy..." << endl;
}
