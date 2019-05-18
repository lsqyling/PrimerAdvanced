//
// Created by shiqing on 18-12-7.
//

#include <bitset>
#include <typeinfo>

#include "UsefullFwd.h"


/**
 * chapter 5.技巧性基础知识
 */

namespace cp5 {
    template<typename T>
    class MyClass {
        typename T::SubType *ptr;
//        Note:如果不是typename , T::SubType 会被认为是T的静态成员,表达式 T::SubType * ptr; 是一个算术乘积表达式
//        通常来说，依赖模板参数的名称是一个类型时，就应该使用typename
    };

//    打印容器的元素
    template<typename C>
    void printContainer(const C &container) {
        for (const auto begin = container.begin(); begin != container.end(); ++begin) {
            cout << *begin << ", ";
        }
        cout << endl;
    }

    template<int N>
    void printBitset(const std::bitset<N> &bs) {
        cout << bs.to_string() << endl; // 较好方案，c11 c14 已更新
        cout << bs.template to_string<char, std::char_traits<char>,
                std::allocator<char> >(); // c98
    }

    template<typename T>
    class Base {
    public:
        void say() {
            cout << "Base::say() hi" << endl;
        }

    };


    template<typename T>
    class Derived : public Base<T> {
    public:
        void foo() {
//            say();
//            printf("Derived<%s>::foo()", typeid(T).name());
            this->say();
            T t();
            cout << "Derived<" << typeid(t).name() << ">::foo()" << endl;
        }
//        对于那些在基类中的声明，并且依赖与模板参数的符号（函数或者变量）应该用this->访问，或Base<T>::

    };


    template<typename T>
    class Stack {
    public:
        void push(const T &t);

        void pop();

        T top() const;

        bool empty() const {
            return elems_.empty();
        }

        template<typename T2>
        Stack &operator=(const Stack<T2> &rhs);

    private:
        std::deque<T> elems_;
    };


    template<typename T>
    void Stack<T>::push(const T &t) {
        elems_.push_back(t);
    }

    template<typename T>
    void Stack<T>::pop() {
        if (empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems_.pop_back();
    }

    template<typename T>
    T Stack<T>::top() const {
        if (empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems_.back();
    }

    template<typename T>
    template<typename T2>
    Stack<T> &Stack<T>::operator=(const Stack<T2> &rhs) {
        if (reinterpret_cast<void *>(this) == reinterpret_cast<void *>(const_cast<Stack<T2> *>(&rhs))) {
            return *this;
        }
        Stack<T2> temp(rhs);
        elems_.clear();
        while (!temp.empty()) {
            elems_.push_front(temp.top());
            temp.pop();
        }
        return *this;
    }


    template<typename T, typename CONT = std::deque<T>>
    class StackSetContainer {
    public:
        void push(const T &t);

        void pop();

        T top() const;

        bool empty() const {
            return elems_.empty();
        }

        template<typename T2, typename CONT2>
        StackSetContainer &operator=(const StackSetContainer<T2, CONT2> &rhs);

    private:
        CONT elems_;
    };


    template<typename T, typename CONT>
    template<typename T2, typename CONT2>
    StackSetContainer<T, CONT> &StackSetContainer<T, CONT>::operator=(const StackSetContainer<T2, CONT2> &rhs) {
        if (reinterpret_cast<void *>(this)
            == reinterpret_cast<void *>(const_cast<StackSetContainer<T2, CONT2> *>(&rhs))) {
            return *this;
        }
        StackSetContainer<T2, CONT2> temp(rhs);
        elems_.clear();
        while (!temp.empty()) {
            elems_.push_front(temp.top());
            temp.pop();
        }
        return *this;
    }

    template<typename T, typename CONT>
    void StackSetContainer<T, CONT>::push(const T &t) {
        elems_.push_back(t);
    }

    template<typename T, typename CONT>
    void StackSetContainer<T, CONT>::pop() {
        if (empty()) {
            throw std::out_of_range("StackSetContainer<>::pop(): empty stack");
        }
        elems_.pop_back();
    }

    template<typename T, typename CONT>
    T StackSetContainer<T, CONT>::top() const {
        if (empty()) {
            throw std::out_of_range("StackSetContainer<>::top(): empty stack");
        }
        return elems_.back();
    }

    /**
     * template<typename E> class CONT 为声明一个类模板，第二个参数必须是一个类模板，且有第一个参数传递，一般来说可以使用类模板任何类型来
     * 实例化模板的模板参数.
     * Note:class 不能由typename 替代
     * 由于我们并不会用到"模板的模板参数" ，所以E可以省略不写
     * Error: template<typename T, template<typename> //class CONT = std::deque>
     * expected a template of type template<class> class CONT’, got ‘template<class _Tp, class _Alloc> class std::deque’
     * @tparam T
     * @tparam CONT
     */
    template<typename T, template<typename E, typename /*Alloc 没用到，可以省略不写*/ = std::allocator<E>> class CONT = std::deque>
    class StackSetTemplateParameters {
    public:
        void push(const T &t);

        void pop();

        T top() const;

        bool empty() const {
            return elems_.empty();
        }

        template<typename T2, template<typename E, typename = std::allocator<E>> class CONT2>
        StackSetTemplateParameters &operator=(const StackSetTemplateParameters<T2, CONT2> &rhs);

    private:
        CONT<T> elems_;
    };


    template<typename T, template<typename, typename> class CONT>
    void StackSetTemplateParameters<T, CONT>::push(const T &t) {
        elems_.push_back(t);
    }

    template<typename T, template<typename, typename> class CONT>
    void StackSetTemplateParameters<T, CONT>::pop() {
        if (empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems_.pop_back();
    }


    template<typename T, template<typename, typename> class CONT>
    T StackSetTemplateParameters<T, CONT>::top() const {
        if (empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems_.back();
    }


    template<typename T, template<typename, typename> class CONT>
    template<typename T2, template<typename, typename> class CONT2>
    StackSetTemplateParameters<T, CONT>
    &StackSetTemplateParameters<T, CONT>::operator=(const StackSetTemplateParameters<T2, CONT2> &rhs) {
          if (reinterpret_cast<void *>(this) ==
                  reinterpret_cast<void *>(const_cast<StackSetTemplateParameters<T2, CONT2> *>(&rhs))) {
              return *this;
          }
          StackSetTemplateParameters<T2, CONT2> temp(rhs);
          elems_.clear();
          while (!temp.empty()) {
              elems_.push_front(temp.top());
              temp.pop();
          }
    }


//    函数模板并不支持模板的模板参数
    template<typename T, typename CONT>
    auto find(const T &t, const CONT &container) {
        for (auto begin = container.begin(); begin != container.end(); ++begin) {
            if (t == *begin) return begin;
        }
        return container.end();
    }


//    引用比较
    template<typename T>
    const T &maxByReference(const T &a, const T &b) {
        return a < b ? b : a;
    }


//    传值
    template<typename T>
    T maxByValue(T a, T b) {
        return a < b ? b : a;
    }

    template<typename T>
    void ref(const T &x) {
        cout << "x in ref(const T &): "
            << typeid(x).name() << "\n";
    }

    template<typename T>
    void nonref(T x) {
        cout << "x in nonref(T): "
            << typeid(x).name() << "\n";
    }





}

int main() {
    using namespace cp5;
    cp5::Derived<int> d;
    d.say();

    Stack<int> iS, iS2;
    Stack<float> fS;
    for (int i = 0; i != 10; ++i) {
        fS.push(i);
    }
    iS = fS;
    iS2 = iS;//调用生成的赋值运算符
    while (!iS.empty()) {
        cout << iS.top() << ", ";
        iS.pop();
    }
    cout << endl;

    while (!iS2.empty()) {
        cout << iS2.top() << ", ";
        iS2.pop();
    }
    cout << endl;

    //    Note:对于类模板而言， 只有那些被调用的成员函数才会被实例化。
    StackSetContainer<int, vector<int>> vS;
    vS.push(42);
    vS.push(42);
    cout << vS.top() << endl;


    const vector<int> vi = {1, 2, 3, 4};
    cout << "find: " << *find(1, vi) << endl;

    try {
        StackSetTemplateParameters<int> istp;
        StackSetTemplateParameters<float> fstp;

        istp.push(5);
        istp.push(7);

        fstp.push(7.7);

        fstp = istp;

        cout << fstp.top() << endl;
        fstp.pop();
        cout << fstp.top() << endl;
        fstp.pop();
        fstp.pop();

    } catch (std::exception &ex) {
        std::cerr << ex.what() << endl;
    }

    string s;
    maxByReference("apple", "peach"); // paramType -> const char(&)[6], T -> char[6]
//    maxByReference("apple", "tomato"); 实参类型不同无法匹配
//    maxByReference(s, "apple"); 实参类型不同无法匹配

    maxByValue("apple", "peach"); // T -> const char *
    maxByValue("apple", "tomato");
//    maxByValue(s, "apple");实参类型不同无法匹配

    ref("hello");
    nonref("hello");








    return 0;
}
