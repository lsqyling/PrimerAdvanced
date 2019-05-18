//
// Created by shiqing on 19-5-2.
//

#include "StrBlob.h"
#include "StrBlobPtr.h"


StrBlob::StrBlob(): ptr_(new vector<string>) {}


// A better approach is to use the ‘’make_shared()’’ function.
StrBlob::StrBlob(std::initializer_list<string> il) : ptr_(new vector<string>(il)){}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, size());
}


string StrBlob::popBack() {
    check(0, "pop back on empty StrBlob");
    string t = ptr_->back();
    ptr_->pop_back();
    return t;
}

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return ptr_->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return ptr_->back();
}


const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return ptr_->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return ptr_->back();
}


void StrBlob::check(StrBlob::SizeType i, const string &msg) const {
    if (i >= ptr_->size()) {
        throw std::out_of_range(msg);
    }
}


ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this, 0);
}

ConstStrBlobPtr StrBlob::end() const {
    return ConstStrBlobPtr(*this, size());
}


bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return lhs.ptr_ == rhs.ptr_ || (!(lhs.ptr_ != rhs.ptr_) && *lhs.ptr_ == *rhs.ptr_);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}
