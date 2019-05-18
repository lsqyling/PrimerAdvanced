//
// Created by shiqing on 19-4-22.
//

#ifndef PRIMERADVANCED_SALESDATA_H
#define PRIMERADVANCED_SALESDATA_H

#include <functional>
#include "../common/CommonHeaders.h"




class SalesData {
    friend std::ostream &print(std::ostream &os, const SalesData &sd);

    friend struct std::hash<SalesData>;

    friend std::istream &read(std::istream &is, SalesData &sd);

public:

    using mPtr2AvgPriceFunction = double (SalesData::*)() const;

    SalesData() = default;

    explicit SalesData(std::istream &is);

    explicit SalesData(const string &bookNo) : bookNo_(bookNo) {}

    SalesData(const string &bookNo, unsigned unitsSold, double price) :
            bookNo_(bookNo), unitsSold_(unitsSold), revenue_(unitsSold * price) {}

    string isbn() const {
        return bookNo_;
    }

    SalesData &combine(const SalesData &rhs);

    double avgPrice() const;

    static const string SalesData::*mPtr2BookNo() noexcept ;


private:
    string bookNo_;
    unsigned unitsSold_ = 0;
    double revenue_ = 0.0;
};


namespace std {
    template<>
    struct hash<SalesData> {

        typedef size_t result_type;
        typedef SalesData argument_type;

        size_t operator()(const SalesData &s) const;

    };
}




SalesData add(const SalesData &lhs, const SalesData &rhs);

std::ostream &print(std::ostream &os, const SalesData &sd);

std::istream &read(std::istream &is, SalesData &sd);


#endif //PRIMERADVANCED_SALESDATA_H
