//

#include "SalesData.h"

SalesData::SalesData(std::istream &is) : SalesData() {
    read(is, *this);
}

SalesData &SalesData::combine(const SalesData &rhs) {
    unitsSold_ += rhs.unitsSold_;
    revenue_ += rhs.revenue_;
    return *this;
}

inline double SalesData::avgPrice() const {
    if (unitsSold_) {
        return revenue_ / unitsSold_;
    }
    return 0;
}


SalesData add(const SalesData &lhs, const SalesData &rhs) {
    SalesData sum(lhs);
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream &os, const SalesData &sd) {
    os << sd.bookNo_ << " " << sd.unitsSold_ << " "
       << sd.revenue_ << " " << sd.avgPrice();
    return os;
}

std::istream &read(std::istream &is, SalesData &sd) {
    double price;
    is >> sd.bookNo_ >> sd.unitsSold_ >> price;
    sd.revenue_ = sd.unitsSold_ * price;
    return is;
}


const string SalesData::* SalesData::mPtr2BookNo() noexcept {
    return &SalesData::bookNo_;
}



size_t std::hash<SalesData>::operator()(const SalesData &s) const {
    return std::hash<string>()(s.bookNo_)
           ^ std::hash<unsigned>()(s.unitsSold_)
           ^ std::hash<double>()(s.revenue_);
}
