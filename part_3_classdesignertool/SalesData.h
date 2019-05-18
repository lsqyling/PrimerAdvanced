//
// Created by shiqing on 19-5-7.
//

#ifndef PRIMERADVANCED_SALESDATA_H
#define PRIMERADVANCED_SALESDATA_H

#include "../common/CommonHeaders.h"

namespace sd {

    class SalesData {
        friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);

        friend bool operator==(const SalesData &lhs, const SalesData &rhs);

        friend bool operator!=(const SalesData &lhs, const SalesData &rhs);

        friend std::ostream &operator<<(std::ostream &os, const SalesData &rhs);
        friend std::istream &operator>>(std::istream &is, SalesData &rhs);

    public:
        SalesData() = default;

        SalesData(string isbn, unsigned unitsSold, double price)
                : isbn_(isbn), unitsSold_(unitsSold), revenue_(unitsSold * price) {}

        explicit SalesData(std::istream &in);

        string isbn() const { return isbn_; }

        SalesData &operator+=(const SalesData &rhs);

        explicit operator std::string() const { return isbn_; }
        explicit operator double() const { return revenue_; }

    private:
        string isbn_;
        unsigned unitsSold_ = 0;
        double revenue_ = .0;
    };

    SalesData operator+(const SalesData &lhs, const SalesData &rhs);

    bool operator==(const SalesData &lhs, const SalesData &rhs);

    bool operator!=(const SalesData &lhs, const SalesData &rhs);
    std::ostream &operator<<(std::ostream &os, const SalesData &rhs);
    std::istream &operator>>(std::istream &is, SalesData &rhs);
}



#endif //PRIMERADVANCED_SALESDATA_H
