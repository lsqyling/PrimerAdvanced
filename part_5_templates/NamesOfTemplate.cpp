//
// Created by shiqing on 18-12-10.
//

#include "UsefullFwd.h"

/**
 * chapter9:模板中的名字
 *
 *
 *
 */


namespace ch9 {
    int x;
    class B {
    public:
        int i;
    };

    class D : public B {
    };

    void f(D *pd) {
        pd->i = 3;//受限查找 B::i
//        D::x = 2;受限查找并不能找到外围作用域中的::x
    }

    int count = 1;
    int lookupExample(int count) {
        if (count < 0) {
            count = 2;
            lookupExample(count);
        }
        return count += ch9::count;
    }

    namespace BigMath {
        class BigNumber {

        };

        bool operator<(const BigNumber &lhs, const BigNumber &rhs) {
            return false;
        };
    }

    template<typename T>
    T max(const T &lhs, const T &rhs) {
        return lhs < rhs ? rhs : lhs;
    }

    using namespace BigMath;
    void g(const BigNumber &a, const BigNumber &b) {
        BigNumber x = max(a, b);
//        ADL(Argument-Dependent Lookup)
    }

    namespace X {
        template<typename T> void f(T);
    }

    namespace N {
        using namespace X;
        enum E { e1 };
        void f(E) {
            cout << "N::f(N::E) called\n";
        }
    }

    void f(int) {
        cout << "::f(int) called\n";
    }

    template<typename T>
    class C {
        friend void f();
        friend void f(const C<T> &);
    };

    C<int> ci;
    C<double> cd;

    void g(C<int> *p) {
//        f();不可见
        f(*p);//可见 ADL
    }


    void f() {
        cout << "ch9::f()\n";
    }

    void f(const C<int> &ic) {
        cout << "ch::f(const C<T> &)\n";
    }

    /**
     * 在类中的友元函数的声明可以是该友元函数的首次声明。在此前提下对于包含这个友元函数的类，假设它所属的最近名字空间作用域为A，
     * 我们就可以认为该函数在作用域A中声明的。关于可见性？
     * 通常而言，友元声明在外围（类）作用域中是不可见的。
     * 如果友元函数所在的类属于ADL的关联集合，那么我们在外围类是可以找到该友元声明的。
     */


    namespace M {

        template<template<typename> class TT> class X {

        };

        template<typename T> class C {
            C *a; // C<T> * a;
            C<void> *b; //C<void> *b;
            X<C> c;//
            X<ch9::M::C> d;
        };



    }

    /*
     * typename 表示类型时的使用：
     * 1.名称出现在一个模板中
     * 2.名称是受限的
     * 3.名称不是用于指定基类继承的列表中，也不是位于构造函数的初始化列表中
     * 4.名称依赖于模板参数
     *
     */


    namespace NX {
        class X {

        };
        template<int I> void select(X *) {}
    }

    void gx(NX::X *xp) {
        NX::select<3>(xp);
//        select<3>(xp);编译器把表达式解析成(select<3)>(xp);

    }

    /**
     * 非依赖型基类：无须知道模板实参就可以完全确定类型的基类。
     */
    template<typename X>
    class Base {
    public:
        int baseField;
        typedef int T;
    };

    class D1 : public Base<Base<void>> { //
    public:
        void f() { baseField = 3; }
    };

    template<typename T>
    class D2 : public Base<double> {//非依赖类型
    public:
        void f() { baseField = 7; }
        T strange;//不是模板参数是Base<double>::T
    };









}

int main() {
    using namespace ch9;
    f(N::e1); //ADL 将查找到N::f(E)
    ch9::f(N::e1); //受限函数名称：不会使用ADL ch9::f(int)

    return 0;
}