//
// Created by shiqing on 19-5-12.
//

#ifndef PRIMERADVANCED_STRING_H
#define PRIMERADVANCED_STRING_H

#include "Vector.h"

namespace tem {


    template<typename >
    class BasicString;

    template<typename T>
    BasicString<T> operator+(const BasicString<T> &lhs, const BasicString<T> &rhs);
    template<typename T>
    class BasicString : public Vector<T> {
        friend BasicString operator+(const BasicString &lhs, const BasicString &rhs);
    public:
        using Vector<T>::Vector;
        template<unsigned M>
        BasicString(const T (&array)[M]) : Vector<T>(std::begin(array), std::end(array) - 1) {}

        BasicString &operator+=(const BasicString &bs);


        BasicString &append(const BasicString &bs);

        BasicString &append(const T &val);


    };

    template<typename T>
    BasicString<T> operator+(const BasicString<T> &lhs, const BasicString<T> &rhs) {
        for (const auto &item : rhs) {
            lhs.pushBack(item);
        }
        return lhs;
    }


    template<typename T>
    BasicString<T> &BasicString<T>::operator+=(const BasicString &bs) {
        for (auto c : bs) {
            this->pushBack(c);
        }
        return *this;
    }

    template<typename T>
    BasicString<T> &BasicString<T>::append(const BasicString &bs) {
        operator+=(bs);
        return *this;
    }

    template<typename T>
    BasicString<T> &BasicString<T>::append(const T &val) {
        this->pushBack(val);
        return *this;
    }


    using String = BasicString<char>;

}




#endif //PRIMERADVANCED_STRING_H
