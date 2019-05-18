//
// Created by shiqing on 18-12-9.
//

/**
 * chapter8:深入模板基础
 */

#include "UsefullFwd.h"

namespace ch8 {
    template<typename T>
    union AllocChunk {
        T obj;
        unsigned char bytes[sizeof(T)];
    };

    template<typename T>
    class Stack {
    };

    template<typename T>
    class Array {
    };


    template<typename T>
    void reportTop(const Stack<T> &, int number = 0);

    template<typename T>
    void fill(Array<T> *, const T & = T());

    template<int I>
    class CupBoard {
        void open();

        class Shelf;

        static double totalWeight_;
    };

    template<int I>
    void CupBoard<I>::open() {
        cout << "I = " << I << endl;
    }

    template<int I>
    class CupBoard<I>::Shelf {
    public:
        static void printShelf() {
            cout << "printShelf(): " << endl;
        }
    };

    template<int I>
    double CupBoard<I>::totalWeight_ = 2.0;

    class Dynamic {
    public:
        virtual ~Dynamic();
//        template<typename T>
//        virtual void copy(const T &); virtual' cannot be specified on member function templates
    };

    class C {
    };

    int C = 0; // 正确：类名称和非类名称位于不同的名字空间

    int X;

//    template<typename T>
//    class X; 在同一个作用域内类模板不能和另外一个实体共享一个名称
//    struct S;
    template<typename T>
    class S;

    extern "C++" template<typename T>
    void normal(); // 这是缺省的情况，上面的链接规范可以不写

//    extern "C" template<typename T>
//    void invalid();Templates must have C++ linkage

//    extern "Xroma" template<typename T>
//    void xromaLink();error: language string ‘"Xroma"’ not recognized
//     extern "Xroma" template<typename T>
    template<typename T>
    void external(); // 作为一个声明，引用位于其他文件的具有相同名称实体：即引用位于其他文件的external() 函数模板，也称前置声明

    template<typename T>
    static void internal();//与其他文件中具有相同的名称的模板没有关系，即不是外部链接

//    因次我们知道（外部链接）；不能在函数内部声明模板
//    基本模板的声明：指没有在模板名称后添加尖括号
    template<typename T>
    class Box; // 基本声明
//    template<typename T> class Box<T>;
    template<typename T>
    void translate(T *);

//    template<typename T> void translate<T>(T *);
    template<>
    class S<int>; // 实例化声明

    template<typename>
    class MM;// 没有用到的参数名称在声明中可以省略不写
    template<typename T, T *Root, template<T *> class Buf>
    class Structure;

//    非类型模板参数可以是 整数或枚举类型 指针类型 引用类型 其他类型现今都是不允许作为非类型参数使用的
    template<typename T, typename T::Allocator *Allocator>
    class List;

    template<int buf[5]>
    class Lexer;

    template<int *buf>
    class Lexer; // 等同声明 函数和数组类型可也为非类型参数，但他们会隐式转型 decay
    template<const int length>
    class Buffer;

    template<int Length>
    class Buffer; // const 是没有的等同与int Length

    template<template<typename X> class C>
    void f(C<int> *p);//模板的模板参数是代表模板的占位符(placeholder);

    class MyAllocator;

//    template<template<typename X> struct C> void m(C<int> *p);
//    Template template parameter requires 'class' after the parameter list
    template<template<typename T, typename A = MyAllocator> class Container>
    class Adaptation {
        Container<int> storage;//隐式等同于Container<int, MyAllocator>

    };

    template<template<typename T, T *> class Buf>
    class LexerT {
        static char storage[5];
        Buf<char, LexerT::storage> buf;
    };

    template<template<typename T, T *> class Buf> char LexerT<Buf>::storage[5] = {'a', 'b', 'c', 'd', 'e'};

    template<template<typename T> class List>
    class Node {
//        static T *storage;模板的模板的参数在这里不能被使用，它的参数名称只能被自身其他参数的声明使用。
//        通常而言，T 并不会在后面用到，而此常省略不写
    };

//    for example:
    template<typename T, template<typename, typename = MyAllocator> class CONT>
    class Adapter {
        CONT<T> store;

    };

    template<typename T, typename Allocator = std::allocator<T>>
    class ListNode;//默认实参不能依赖自身的参数，但可以依赖与前面的参数
//    在新标准中我们可以为函数和类模板提供默认实参，默认实参通常在同一个模板声明提供的，但也可以在前面的模板声明中提供；
//    for example:
    template<typename T1, typename T2, typename T3, typename T4 = int, typename T5 = char>
    class Quintuple;

    template<typename T1, typename T2, typename T3 = char, typename T4, typename T5>
    class Quintuple;

//    template<typename T1 = char, typename T2, typename T3, typename T4, typename T5>
//    class Quintuple;T2 也需要默认实参
    template<typename T>
    inline const T max(const T &lhs, const T &rhs) {
        return lhs < rhs ? rhs : lhs;
    }

    template<typename DstT, typename SrcT>
    inline DstT implicit_cast(const SrcT &x) {
        return x;
    }

    template<typename Func, typename T>
    void apply(Func funObj, T x) {
        funObj(x);
    }

    template<typename T>
    void single(T x) {
        cout << "ch8::single(): x is: " << typeid(x).name() << endl;
    }

    template<typename T>
    void multi(T) {}

    template<typename T>
    void multi(T *) {}

    template<typename RT, typename T>
    RT test(const typename T::X *x) {
        cout << "ch8::test() x is: " << typeid(x).name() << endl;
    }

    template<typename RT, typename T>
    RT test(T &&t) {
        cout << "ch8::test() x is: " << typeid(t).name() << endl;
    }

    template<int N>
    int g() { return N; }

    template<int *P>
    int g() { return *P; }

    template<typename T>
    class ListT {
    };

    typedef struct {
        double x, y, z;
    } Point;
    typedef enum {
        red, green, blue
    } *ColorPtr;

    template<typename T, T nontype_param>
    class CT;

    CT<int, 42> *ct;

    int a;
    CT<int *, &a> *ct1;

    void f();

    void f(int);

    CT<void (*)(int), f> *ct2;

    class X {
    public:
        int n;
        static bool b;
    };

    CT<bool &, X::b> *ct3;
    CT<int X::*, &X::n> *ct4;// 指向成员的指针
    template<typename T>
    void tempFun();

    CT<void (*)(), tempFun<double>> *ct5; // 函数模板实例同时也是函数
    /**
     * 模板实参的一个普遍的约束：在程序创建的时候，编译器或者连接器要能够确定实参的值
     *
     */
    template<const char *str>
    class Message;

    extern const char hello[] = "hello"; //没有extern 就是一个内链接
    Message<hello> *helloMsg;

//    Message<"hello"> *helloM; non-type template argument does not refer to any declaration
    template<typename T, T nonTypeParam>
    class CX;

    class Base {
    public:
        int i;
    };

    Base base;

    class Derived : public Base {
    };

    Derived derivedObj;

//    CX<Base *, &derivedObj> *err1; 这里不会考虑派生类到基类的类型转换
//    Non-type template argument of type 'ch8::Derived *' cannot be converted to a value of type 'ch8::Base *'

//    CX<int, base.i> *err2;Non-type template argument is not a constant expression

    int array[10];
//    CX<int *, &array[0]> *error;Non-type template argument does not refer to any declaration
    CX<int *, array> *error; // 正确

//    “模板的模板参数” 必须是一个类型模板，它本身具有参数，该参数必须精确匹配它“所替换的模板的模板参数” 本身的参数。
    template<typename T1, typename T2, template<typename> class Container>
    class Relation {
    public:
    private:
        Container<T1> dom1;
        Container<T2> dom2;
    };

    template<typename T>
    class NodeT;

//    友元类的声明不能是类的定义，因此友元类通常都不会出现问题，在引入模板之后，友元类声明的唯一变化只是：可以命名一个特定的类模板实例为友元。
    template<typename T>
    class Tree {
        friend class Factory;//正确，即使这里是Factory 的首次声明
        friend class NodeT<T>; // 友元声明 Node 在此必须是可见的（即要求模板有前置声明或者在这可以看到定义）
    };

//    友元函数
    template<typename T1, typename T2>
    void combine(T1, T2);

    class Mixer {
        /*
         * 通过确认紧接在友元函数名称后面的一对尖括号，我们可以把函数模板的实例声明为友元。尖括号可以包含模板参数，但也可以通过调用参数来演绎出实参
         * 若果全部实参都可通过演绎出来，尖括号可以为空。
         */
        friend void combine<>(int &, int &);

        friend void combine<int, int>(int, int);

        friend void combine<char>(char, int);
//        friend void combine<char>(char &, int);
//        No function template matches function template specialization 'combine'
//        friend void combine<>(long, long) {}
    };


    /*
         * 我们不能在友元声明中定义一个模板实例（最多只能定义一个特化）。
         * 若果名称后面没有紧跟一对尖括号，那么只有在下面两种情况下是合法的。
         * 1.若果名称不是受限的（没有包含一个形如双冒号的域运算符）那么该名称一定也不是引用一个模板实例。如果在友元声明的地方，还看不到所匹配的非
         * 模板函数，那么这个友元声明就是函数的首次声明。于是，该声明可以是定义。
         * 2.如果名称是受限的，那么该名称必须引用一个在此前声明的函数或者函数模板，在匹配的过程中，匹配的函数要优先于函数模板。这样的友元声明不能是定义。
         *
         */
    void multiply(void *);

    template<typename T>
    void multiply(T);

    class Comrades {
        friend void multiply(int) {} //定义一个新函数
        friend void ch8::multiply(void *); // 引用上面普通的函数
        friend void ch8::multiply(int); // 引用模板实例
        friend void ch8::multiply<double *>(double *); //受限名称也可以具有一对简括号但模板必须是可见的
//        受限的友元不能是一个定义。


    };

    /**
     * 我们是在一个普通类里面声明友元函数，如果需要在类模板里面声明友元函数，前面的这些规则依然适用，
     * 唯一的区别就是：可以使用模板参数来标识友元函数
     *
     */
    template<typename T>
    class NodeN {
        NodeN<T> *allocate();
    };

    template<typename T>
    class ListL {
        friend NodeN<T> *NodeN<T>::allocate();// 引用类的成员函数；
    };

    template<typename T>
    class Creator {
     /*   friend void appear() {
            //一个新函数：appear() 但要等到Creator被实例化之后才存在
        }*/

        friend void appeared(Creator<T> *) {

        }

    };

    Creator<int> miracle;
//    Creator<double> oops;Error: appear() 第2此被定义。
    Creator<double> oops;
//    最后一点就是：由于函数的实体处于类定义的内部，所以都是内联的



    /*
     * 通常的友元声明是：函数模板实例或类模板实例，有时候也需要模板的所有实例都是友元，这就需要友元模板
     */
    template<typename>
    class Task;
    class Manager {
        template<typename T>
        friend class Task;
        template<typename T>
        friend void dispatch(Task<T> *);

        template<typename T>
        friend int ticket() {
            return ++Manager::counter;
        };

        static int counter;

    };
    /*
     * 和普通友元声明一样，只有在友元模板声明的是一个非受限的函数名称，并且后面没有紧跟尖括号的情况下，
     * 该友元模板声明才能成为定义。
     *.
     */







}

int main() {
    cout << typeid(class ch8::C).name() << endl;
    ch8::max<double>(1.0, -3.0);// 显式指定
    ch8::max(1.0, 3.2);// deduction double
    ch8::max<int>(1.0, 3.0);

    double value = ch8::implicit_cast<double>(-1);
    cout << "value = " << value << "\n";

    ch8::apply(ch8::single<int>, 3);
//    ch8::apply(ch8::multi<int>, 7);
//    error: no matching function for call to ‘apply(<unresolved overloaded function type>, int)’
//    ch8::apply(ch8::multi<int>, 7);

//    ch8::apply(ch8::test<int>(), 7);
//    error: no matching function for call to ‘test()’
//     ch8::apply(ch8::test<int>(), 7);
    auto rg = ch8::g<1>();//"替换失败并非错误---SFINAE" 原则是令函数模板进行重载的重要因素。
    cout << "rg = " << rg << endl;


    struct Association {
        int *p, *q;
    };

    ch8::ListT<Association *> error; //

    ch8::ListT<ch8::ColorPtr> error2;

    ch8::ListT<ch8::Point> ok;

//    ch8::Relation<int, double, std::list> rel;
//    Template template argument has different template parameters than its corresponding template template parameter


    return 0;
}

