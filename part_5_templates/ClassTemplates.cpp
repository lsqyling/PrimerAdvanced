//
// Created by shiqing on 18-12-6.
//
/**
 * 3.1类模板的栈实现
 * please check @class Stack
 *
 *
 */

#include <deque>
#include "UsefullFwd.h"

template<typename T>
class Stack {
public:
    void push(const T &);

    void pop();

    T top() const;

    bool empty() const {
        return elems.empty();
    }


private:
    vector<T> elems;

};


template<typename T>
void Stack<T>::push(const T &t) {
    elems.push_back(t);
}

template<typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();
}

template<typename T>
T Stack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}


template<>
class Stack<string> {
public:
    void push(const string &);

    void pop();

    string top() const;

    bool empty() const {
        return elems.empty();
    }

private:
    std::deque<string> elems;
};


void Stack<string>::push(const string &s) {
    elems.push_back(s);
}

void Stack<string>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack<string>::pop(): empty stack");
    }
    elems.pop_back();
}

string Stack<string>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack<string>::top(): empty stack");
    }
    return elems.back();
}


template<typename T1, typename T2>
class MyClass {

};

//以下是局部特化
template<typename T>
class MyClass<T, T> {
};

template<typename T>
class MyClass<T, int> {
};

//局部特化：偏特化两个模板参数都是指针类型
template<typename T1, typename T2>
class MyClass<T1 *, T2 *> {
};

void TestingPartialSpecialization() {
    MyClass<int, float> mif; // MyClass<T1, T2>
    MyClass<float, float> mff; // MyClass<T, T>
    MyClass<float, int> mfi;//MyClass<T, int>
    MyClass<int *, float *> mp; // MyClass<T1*, T2*>

//    MyClass<int, int> mii;同等程度匹配MyClass<T, T> MyClass<T, int>
//    MyClass<int *, int *> mpp;同等程度匹配MyClass<T, T> MyClass<T1*, T2*> 最佳匹配 MyClass<T*, T*>


}


template<typename T, typename CONT = std::vector<T> >
class StackDefault {
public:
    void push(const T &);

    void pop();

    T top() const;

    bool empty() const {
        return elems.empty();
    }

private:
    CONT elems;
};


template<typename T, typename CONT>
void StackDefault<T, CONT>::push(const T &t) {
    elems.push_back(t);
}

template<typename T, typename CONT>
void StackDefault<T, CONT>::pop() {
    if (empty()) {
        throw std::out_of_range("StackDefualt<>::pop(): empty stack");
    }
    elems.pop_back();
}

template<typename T, typename CONT>
T StackDefault<T, CONT>::top() const {
    if (empty()) {
        throw std::out_of_range("StackDefault<>::top() empty stack");
    }
    return elems.back();
}


int main(int argc, char *argv[]) {
    try {
        Stack<int> intStack;
        Stack<string> strStack;
        intStack.push(7);
        std::cout << intStack.top() << endl;

        strStack.push("hello");
        cout << strStack.top() << endl;
        strStack.pop();
        strStack.pop();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << endl;
    }

    TestingPartialSpecialization();

    try {
        StackDefault<int> iStack;
        StackDefault<double, std::deque<double>> dblStack;
        iStack.push(7);
        cout << iStack.top() << endl;
        iStack.pop();

        dblStack.push(42.42);
        cout << dblStack.top() << endl;
        dblStack.pop();
        dblStack.pop();

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << endl;
    }


    return 0;
}



