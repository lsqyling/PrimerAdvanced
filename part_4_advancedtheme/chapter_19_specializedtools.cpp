//
// Created by shiqing on 19-5-17.
//

#include <algorithm>
#include "../common/CommonHeaders.h"
#include "../part_1_foundation/SalesData.h"




/*
 * Exercise 19.1: Write your own operator new(size_t) function using malloc and use free to write the operator
 * delete(void*) function.
 * @testingSelfNew();
 *
 * Exercise 19.2: By default, the allocator class uses operator new to obtain storage and operator delete to free it.
 * Recompile and rerun your StrVec programs (§ 13.5, p. 526) using your versions of the functions from the previous exercise.
 * @testingSelfNew();
 *
 */


/*
 * Exercise 19.3 --- Exercise 19.8:
 * already done.
 */


namespace mem {


    namespace test {
        class A {
        public:
            virtual ~A() {}
        };

        class B : public A {
        };

        class C : public B {
        };

        class D : public B {
        };

        void testingDynamicCast() {
            A *pa = new C;
            if (B *pb = dynamic_cast<B *>(pa)) {
                cout << "B *pb = dynamic_cast<B*>(pa): true pb = " << pb << endl;
            }

            B *pb = new B;
            if (C *pc = dynamic_cast<C *>(pb)) {
                cout << "C *pc = dynamic_cast<C*>(pb): true pc = " << pc << endl;
            }

            B *pd = new D;
            if (B *pt = dynamic_cast<B *>(pd)) {
                cout << "B *pb = dynamic_cast<B*>(pd): true pt = " << pt << endl;
            }


            delete pa;
            delete pb;
            delete pd;


        }


    }


    struct A {

        void *operator new(size_t sz) {
            cout << "self operator new" << endl;
            void *r;
            if (r = malloc(sz)) {
                return r;
            }
            throw std::bad_alloc();
        }

        void operator delete(void *p) noexcept {
            cout << "self operator delete" << endl;
            free(p);
        }


    };


    void testingSelfNew() {
        A *pa = new A;
        delete pa;
    }


    class Base {
        friend bool operator==(const Base &lhs, const Base &rhs);

    public:
        Base(string s1, string s2) : s1_(s1), s2_(s2) {}

        Base() = default;

        virtual ~Base() {}

    protected:
        virtual bool equal(const Base &rhs) const noexcept {
            return s1_ == rhs.s1_ && s2_ == rhs.s2_;
        }

    private:
        string s1_, s2_;
    };

    class Derived : public Base {
    public:
        using Base::Base;

        Derived(string string1, string string2, string s1, string s2)
                : Base(s1, s2), string1_(string1), string2_(string2) {}

    protected:
        bool equal(const Base &rhs) const noexcept override {
            auto r = dynamic_cast<const Derived &>(rhs);
            return Base::equal(rhs) && (string1_ == r.string1_ && string2_ == r.string2_);
        }


    private:
        string string1_, string2_;

    };

    bool operator==(const Base &lhs, const Base &rhs) {
        return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
    }


    void testingDerived() {
        Derived d;
        Derived d1("hello", "world");
        Derived d2(d1);
        Derived d3(d);
        Derived d4("hello", "world", "lady", "gaga");
        cout << (d2 == d1) << endl;
        cout << (d3 == d) << endl;
        cout << (d4 == d3) << endl;

        Base *p = &d;
        int arr[10];
        cout << typeid(42).name() << ",\t"
             << typeid(arr).name() << ",\t"
             << typeid(SalesData).name() << ",\t"
             << typeid(string).name() << ",\t"
             << typeid(p).name() << ",\t"
             << typeid(*p).name() << endl;


    }


    /*
     * Exercise 19.9 --- Exercise 19.10:
     * already done.
     */


    /*
     * Exercise 19.11 --- Exercise 19.13:
     * already done.
     */

    /*
     * Exercise 19.14 --- Exercise 19.17:
     * already done.
     */


    /*
     * Exercise 19.18 --- Exercise 19.20:
     * already done.
     */






    namespace em {

        void testingSalesDataMemptr() {
            SalesData data("0-201-78345-X", 3, 20.00);
            SalesData *p = &data;
            auto mptr = SalesData::mPtr2BookNo();
            cout << data.*mptr << endl;
            cout << p->*mptr << endl;
            SalesData::mPtr2AvgPriceFunction mpf = &SalesData::avgPrice;
            cout << (data.*mpf)() << endl;
            cout << (p->*mpf)() << endl;
        }

        bool gtLength(const string &s, size_t len) noexcept {
            return s.length() > len;
        }

        void testingCallObj() {
            vector<string> vs = {"", "hello", "world", "lady", "", "gaga"};
            auto cn = std::count_if(vs.begin(), vs.end(), [](const string &s) { return s.empty(); });
            cout << "cn = " << cn << endl;
            using namespace std::placeholders;

            auto it = std::find_if(vs.begin(), vs.end(), std::bind(gtLength, _1, 2));
            if (it != vs.end()) {
                cout << *it << endl;
            }
        }


    }


    /*
     * Exercise 19.21 --- Exercise 19.24:
     * already done.
     */

    enum Int{ a = 1024, b};

    class Task;

    void testingVolatile() {
        volatile int displayRegister;
        volatile Task *currTask;
        volatile int iax[5];

        volatile int v;
        int *volatile vip;
        volatile int *ivp;
        volatile int *volatile vivp;
//        int *ip = &v;error: cannot initialize a variable of type 'int *' with an rvalue of type 'volatile int *'
        ivp = &v;
        vivp = &v;
    }

    /*
     * Exercise 19.25 --- Exercise 19.26:
     * already done.
     */

    extern "C" int compute(int *, int);

    void testingLinkageDirective() {

    }




}


int main() {
    mem::testingSelfNew();
    mem::test::testingDynamicCast();
    mem::testingDerived();
    mem::em::testingSalesDataMemptr();
    mem::em::testingCallObj();
    cout << mem::a << ", b = " << mem::b << endl;
    mem::Int x = mem::b;
    cout << "x = " << x << endl;

    return 0;
}
