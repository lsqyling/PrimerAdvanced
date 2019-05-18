//
// Created by shiqing on 18-5-14.
//

#ifndef DSA_STACK_H
#define DSA_STACK_H

#include "../common/CommonHeaders.h"
#include <stack>


template<typename T>
class Stack: public std::stack<T> {

public:
    /**
     * *******************************************************
     * Functional Interface
     * *******************************************************
     */

    void push(const T &e);

    T pop();

    T& top();

};

template<typename T>
void Stack<T>::push(const T &e) {
    this->push(e);
}

template<typename T>
T Stack<T>::pop() {
    T t = this->top();
    this->pop();
    return t;
}

template<typename T>
T &Stack<T>::top() {
    return this->top();
}


#endif //DSA_STACK_H
