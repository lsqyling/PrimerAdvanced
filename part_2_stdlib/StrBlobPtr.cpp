//
// Created by shiqing on 19-5-3.
//

#include "StrBlobPtr.h"
#include "StrBlob.h"



auto StrBlobPtr::check(StrBlobPtr::SizeType i, const string &msg) const {
    auto ret = weakPtr_.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

string &StrBlobPtr::deref() const {
    auto p = check(curr_, "deference past end");
    return (*p)[curr_];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return operator==(lhs.weakPtr_.lock(), rhs.weakPtr_.lock());
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}


const string &ConstStrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const string *ConstStrBlobPtr::operator->() const {
    return &this->operator*();
}
