//
// Created by shiqing on 18-12-7.
//

/**
 * 非类型的类模板参数:
 *
 */

#include "UsefullFwd.h"

namespace ch {
    template<typename T, int MAXSIZE>
    class Stack {
    public:
        Stack() : numElems_(0) {}
        void push(const T &);
        void pop();
        T top() const;
        bool empty() const {
            return numElems_ == 0;
        }
        bool full() const {
            return numElems_ == MAXSIZE;
        }

    private:
        T elems_[MAXSIZE];
        int numElems_;
    };


    template<typename T, int MAXSIZE>
    void Stack<T, MAXSIZE>::push(const T &t) {
        if (numElems_ == MAXSIZE) {
            throw std::out_of_range("Stack<>::push(): full stack");
        }
        elems_[numElems_] = t;
        ++numElems_;
    }

    template<typename T, int MAXSIZE>
    void Stack<T, MAXSIZE>::pop() {
        if (numElems_ <= 0) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        --numElems_;
    }

    template<typename T, int MAXSIZE>
    T Stack<T, MAXSIZE>::top() const {
        if (numElems_ <= 0) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems_[numElems_ - 1];
    }




    template<typename T, int VAL>
    T addValue(const T &t) {
        return t + VAL;
    }

//    template<double VAT>
//    double process(double v) {
//        return VAT + v;
//    }
//    error: ‘double’ is not a valid type for a template non-type parameter
//     template<double VAT>
//    浮点数和类对象是不允许作为非类型模板参数的
    template<const char * name>
    class MyClass {};

//    MyClass<"name"> x;常量字符串是内部链接对象（因为具有相同名称但处于不同模块的字符串，是不同的对象
    const char *s = "hello";
//    MyClass<s> x;全局指针（指向内部链接对象）
    extern const char ss[] = "hello";

    MyClass<ss> x;// 全局字符数组ss 由"hello" 初始化

//    Summarize:
//    num1:模板可以具有值模板参数，而不仅仅是类型模板参数
//    num2:对于非类型模板参数，不能是浮点数，class 类型对象，和内部链接对象

}



int main(int argc, char *argv[]) {
    using namespace ch;
    try {
        Stack<int, 20> i20Stack;
        Stack<int, 40> i40Stack;
        Stack<string, 40> str40Stack;

        i20Stack.push(7);
        cout << i20Stack.top() << endl;
        i20Stack.pop();

        str40Stack.push("hello");
        cout << str40Stack.top() << endl;
        str40Stack.pop();
        str40Stack.pop();

    } catch (std::exception &e) {
        std::cerr << e.what() << endl;
    }


    cout << addValue<int, 45>(5) << endl;




    return 0;
}



