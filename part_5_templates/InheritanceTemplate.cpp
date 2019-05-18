//
// Created by shiqing on 18-12-13.
//

/*
 * chapter16:模板与继承
 */

#include "UsefullFwd.h"

namespace ch16 {
    class EmptyClass {
        typedef int Int;
    };

    class EmptyTwo : public EmptyClass {};

    class EmptyTree : public EmptyTwo {};

    class NoEmpty : public EmptyClass, public EmptyTwo {};


    /*
     * CRTP：（Curiously Recurring Template Pattern)
     * for example:
     */

    template<typename CountedType>
    class ObjCounter {
    protected:
        ObjCounter() {
            ++count;
        }

        ObjCounter(const ObjCounter &oc) {
            ++count;
        }

        ~ObjCounter() {
            --count;
        }

    public:
        static size_t live() {
            return count;
        }

    private:
        static size_t count;
    };


    template<typename T> size_t ObjCounter<T>::count = 0;

    template<typename CharT>
    class MyStr : public ObjCounter<MyStr<CharT>> {

    };


    class NotVirtual {};
    class Virtual {
    public:
        virtual void foo() {}
    };

    template<typename VBase>
    class Base : private VBase {
    public:
//        foo()的虚拟性依赖于它在基类VBase的声明
        void foo() {
            cout << "Base:foo()" << endl;
        }
    };

    template<typename V>
    class Derived : public Base<V> {
    public:
        void foo() {
            cout << "Derived:foo()" << endl;
        }
    };





}


int main() {
    cout << "sizeof(EmptyClass): " << sizeof(ch16::EmptyClass) << endl;
    cout << "sizeof(EmptyTwo): " << sizeof(ch16::EmptyTwo) << endl;
    cout << "sizeof(EmptyTree): " << sizeof(ch16::EmptyTree) << endl;
//    NoEmpty 的基类Empty 和 EmptyTwo 不能分配到同一地址空间，否则EmptyTwo 的基类Empty 会和NoEmpty 的基类Empty撞在同一地址空间上，
//    换句话说，两个相同类型的子对象偏移量相同，这是c++ 对象布局所不允许的。
    cout << "sizeof(NoEmpty): " << sizeof(ch16::NoEmpty) << endl;
    /*
     * 空基类优化 EBCO --- empty base class optimization
     * c++ 标准规定，当空类作为基类时，只要不会与同一类型的另一个对象或子对像分配在同一地址，就不需要为其分配任何空间。
     */

    using namespace ch16;
    MyStr<char> s1, s2;
    MyStr<wchar_t > ws;
    cout << "number of MyStr<char>: " << MyStr<char>::live() << endl;
    cout << "number of MyStr<wchar_t>: " << MyStr<wchar_t>::live() << endl;

    Base<NotVirtual> *p1 = new Derived<NotVirtual>;
    p1->foo(); // Base::foo();

    Base<Virtual> *p2 = new Derived<Virtual>;
    p2->foo();//Derived::foo();








    return 0;
}