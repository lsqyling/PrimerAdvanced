//
// Created by shiqing on 19-5-2.
//

#ifndef PRIMERADVANCED_STRBLOB_H
#define PRIMERADVANCED_STRBLOB_H

#include "../common/CommonHeaders.h"

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
public:
    using SizeType = vector<string>::size_type ;
    StrBlob();

    StrBlobPtr begin();

    StrBlobPtr end();

    ConstStrBlobPtr begin() const;

    ConstStrBlobPtr end() const;


    StrBlob(std::initializer_list<string>);
    SizeType size() const {
        return ptr_->size();
    }

    bool empty() const {
        return ptr_->empty();
    }


    void pushBack(const string &s) {
        ptr_->push_back(s);
    }
    string popBack();


    string &front();
    const string &front() const;
    string &back();
    const string &back() const;





private:
    shared_ptr<vector<string>> ptr_;
    void check(SizeType i, const string &msg) const;


};


bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

#endif //PRIMERADVANCED_STRBLOB_H
