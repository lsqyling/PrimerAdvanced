//
// Created by shiqing on 19-5-16.
//

#include <fstream>
#include "../common/CommonHeaders.h"


/*
 * Exercise 18.1: What is the type of the exception object in the following throws?
 * Answer:a)range_error b)exception, exception * ,there will be runtime error.
 *
 * Exercise 18.2: Explain what happens if an exception occurs at the indicated point:
 * Answer:v and in can normally destroy, the space "p" points will not be free.There will be a memory leak.
 *
 * Exercise 18.3: There are two ways to make the previous code work correctly if an exception is thrown.
 * Describe them and implement them.
 * @exercise();
 *
 */


/*
 * Exercise 18.4 --- Exercise 18.6:
 * already done.
 */

/*
 * Exercise 18.7:
 * already done.
 */


namespace ch18 {

    class MyException : public std::exception {
    public:
        MyException(string msg) try : exception(), msg_(msg) {} catch (...) {}

        const char *what() const noexcept override;

        MyException(const MyException &) = default;

        MyException &operator=(const MyException &) = default;

        MyException(MyException &&) noexcept = default;

        MyException &operator=(MyException &&) = default;


    private:
        string msg_;
    };

    class MyDetailException : public MyException {
    public:
        MyDetailException(string detail) : MyException(detail) {}

        const char *what() const noexcept override;

    };


    const char *MyException::what() const noexcept {
        return msg_.c_str();
    }

    const char *MyDetailException::what() const noexcept {
        string msg = MyException::what() + string(":detail mydetailexception");
        return msg.c_str();
    }


    void exercise(int *a, int *b) {
        int *p = new int[5];
        std::ifstream in("ints");
        try {
//            .....
            throw MyDetailException("this point raised the exception");
        } catch (MyException e) {
            cout << e.what() << endl;
            delete[] p;
        } catch (std::runtime_error e) {
            cout << e.what() << endl;
            cout << "catch anything" << endl;
        } catch (...) {
            throw;
        }


    }


    void testingException() {
        int a[] = {0, 1, 2, 3, 5};
        exercise(std::begin(a), std::end(a));


    }


}


/*
 * Exercise 18.8: Review the classes you’ve written and add appropriate
 * exception specifications to their constructors and destructors. If you think one
 * of your destructors might throw, change the code so that it cannot throw.
 * already done.
 *
 * Exercise 18.9: Define the bookstore exception classes described in this
 * section and rewrite your Sales_data compound assigment operator to throw an exception.
 * already done.
 *
 * Exercise 18.10: Write a program that uses the Sales_data addition operator on objects that have differing ISBN s.
 * Write two versions of the program: one that handles the exception and one that does not. Compare the
 * behavior of the programs so that you become familiar with what happens when an uncaught exception occurs.
 * already done.
 *
 *
 * Exercise 18.11: Why is it important that the what function doesn’t throw?
 * answer:pure function cann't make any exceptions that is better to solve the problems.
 */


/*
 * Exercise 18.12 --- Exercise 18.14:
 * already done.
 */


/*
 * Exercise 18.15 --- Exercise 18.17:
 * already done.
 */



namespace A {
    class C {
        friend void f2();

        friend void f(const C &c) {};


    };
}


/*
 * Exercise 18.18: Given the following typical definition of swap § 13.3 (p.517), determine which version of swap is
 * used if mem1 is a string. What if mem1 is an int? Explain how name lookup works in both cases.
 * Answer:because std::swap is a template function, so no template is priority
 * current scope -> outer scope -> class Type args's scope
 *
 * Exercise 18.19: What if the call to swap was std::swap(v1.mem1, v2.mem1)?
 * Answer:call std::swap();
 *
 */

void testingNamesLookup() {
    A::C cobj;
    f(cobj);
//    f2(); error: use of undeclared identifier 'f2'
//    A::f2();error: no member named 'f2' in namespace 'A'
//    A::C::f2(); error: no member named 'f2' in 'A::C'
//    A::f(cobj);error: no type named 'f' in namespace 'A'
//    A::C::f(cobj);error: no type named 'f' in 'A::C'

}


namespace primeLib {
    void compare() { cout << "primeLib::compare()" << endl; }

    void compare(int) { cout << "primerLib::compare(int)" << endl; }

    void compare(const void *) { cout << "primeLib::compare(const void *)" << endl; }
}


namespace ch18_20 {
//    using primeLib::compare;error: declaration conflicts with target of using declaration already in scope
    using namespace primeLib;

    void compare(int) { cout << "compare(int)" << endl; };


    void compare(double, double = 3.4) { cout << "compare(double, double = 3.4" << endl; };

    void compare(char *, char * = 0) { cout << "compare(char *, char*)" << endl; }

    void f() {
        compare(0);
    }

}

void testingOverride() {
    ch18_20::f();
}


/*
 * Exercise 18.20: In the following code, determine which function, if any,matches the call to compute.
 * List the candidate and viable functions. What type conversions, if any, are applied to the argument
 * to match the parameter in each viable function?
 * @testingOverride();
 *
 */


namespace multi {

    /*
     * Exercise 18.21: Explain the following declarations. Identify any that are in error and explain why they are incorrect:
     * Answer:a) legal b)illegal c)legal
     *
     * Exercise 18.22: Given the following class hierarchy, in which each class defines a default constructor:
     * Answer:A->B->C  Y->X->Z
     *
     */
    /*
     * Exercise 18.23 --- Exercise 18.25:
     * already done.
     *
     *
     *
     */

    class A {};
    class B : public A {};
    class C : public B {};
    class X {};
    class Y {};
    class Z : public X, public Y {};
    class MI : public C, public Z {};
    class D : public X, public C {};

    void testingBind() {
        D *pd = new D;
        X *px = pd;
        A *pa = pd;
        B *pb = pd;
        C *pc= pd;
        delete pd;
    }


    /*
     * Exercise 18.25 --- Exercise 18.30:
     * already done.
     */








}

int main() {
    ch18::testingException();
    testingOverride();
    multi::testingBind();
    return 0;
}

