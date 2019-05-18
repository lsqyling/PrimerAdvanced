//
// Created by shiqing on 19-5-3.
//

#ifndef PRIMERADVANCED_STRBLOBPTR_H
#define PRIMERADVANCED_STRBLOBPTR_H

#include "../common/CommonHeaders.h"
#include "StrBlob.h"


class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
public:
    using SizeType = vector<string>::size_type;

    StrBlobPtr() : curr_(0) {}

    StrBlobPtr(StrBlob &sb, SizeType pos = 0) : weakPtr_(sb.ptr_), curr_(pos) {}

    string &deref() const;

    StrBlobPtr &incr();


private:
    auto check(SizeType, const string &) const;

    std::weak_ptr<vector<string>> weakPtr_;
    SizeType curr_ = 0;
};

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);



class ConstStrBlobPtr {
public:
    ConstStrBlobPtr():curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):wptr(a.ptr_), curr(sz) { } // should add const
    bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
    const string& deref() const { // return value should add const
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    const string &operator*() const;
    const string *operator->() const;

private:
    std::shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<vector<string>> wptr;
    size_t curr;
};




#endif //PRIMERADVANCED_STRBLOBPTR_H
