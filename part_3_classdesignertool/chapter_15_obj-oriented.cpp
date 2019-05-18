//
// Created by shiqing on 19-5-8.
//

#include "../common/CommonHeaders.h"
#include "Quote.h"
#include "BulkQuote.h"
#include "QuanityBulkQuote.h"
#include "Basket.h"
#include "TextQuery.h"

/*
 * Exercise 15.1: What is a virtual member?
 * Answer:
 * A virtual member in a base class expects its derived class define its own version.
 * In particular base classes ordinarily should define a virtual destructor, even if it does no work.
 *
 *
 * Exercise 15.2: How does the protected access specifier differ from private?
 * Answer:
 * private member: base class itself and friend can access
 * protected members: base class itself, friend and derived classes can access
 *
 * Exercise 15.3: Define your own versions of the Quote class and the print_total function.
 * @class Quote, BulkQuote.
 *
 */


/*
 * Exercise 15.4: Which of the following declarations, if any, are incorrect? Explain why.
 * class Base { ... };
 * (a) class Derived : public Derived { ... }; //illegal
 * (b) class Derived : private Base { ... }; // legal
 * (c) class Derived : public Base; // illegal
 *
 *
 * Exercise 15.5: Define your own version of the Bulk_quote class.
 * @see class BulkQuote.
 *
 * Exercise 15.6: Test your print_total function from the exercises in §15.2.1 (p. 595) by passing both
 * Quote and Bulk_quote objects o that function.
 * @see testingPrintTotal();
 *
 * Exercise 15.7: Define a class that implements a limited discount strategy, which applies a discount to books purchased
 * up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.
 * @see class QuantityBulkQuote.
 *
 */


/*
 * Exercise 15.8: Define static type and dynamic type.
 * Answer:
 * The static type of an expression is always known at compile time.
 * The dynamic type is the type of the object in memory that the variable or expression represents.
 * The dynamic type may not be known until run time.
 *
 *
 * Exercise 15.9: When is it possible for an expression’s static type to differ
 * from its dynamic type? Give three examples in which the static and dynamic type differ.
 * Answer:
 * The static type of a pointer or reference to a base class may differ from its dynamic type.
 * Anything like this can be an example.
 * @see testingPrintTotal();
 *
 * Exercise 15.10: Recalling the discussion from §8.1 (p. 311), explain how the program on page 317 that passed an
 * ifstream to the Sales_data read function works.
 * Answer: The function takes a std::istream from which std::ifstream is derived.
 * Hence the ifstream object "is a" istream , which is why it works.
 *
 *
 */


void testingPrintTotal() {
    Quote quote("978-7-121-15535-2", 67.5);
    BulkQuote bulkQuote("978-7-121-15536-3", 80.3, 20, .2);
    QuantityBulkQuote quantityBulkQuote("978-7-121-15537-4", 90.5, 50, .115);
    Quote &rq = quote, &rbq = bulkQuote, &rqbq = quantityBulkQuote;

    Quote::printTotal(cout, rq, 35);
    Quote::printTotal(cout, rbq, 43);
    Quote::printTotal(cout, rqbq, 60);

}

/*
 * Exercise 15.11: Add a virtual debug function to your Quote class hierarchy that displays the data members of the
 * respective classes.
 * @testingDubug();
 *
 *
 * Exercise 15.12: Is it ever useful to declare a member function as both override and final? Why or why not?
 * Sure. override means overriding the same name virtual function in base class.
 * final means preventing any overriding this virtual function by any derived classes that are more lower at the hierarchy.
 *
 * Exercise 15.13: Given the following classes, explain each print function:
 * If there is a problem in this code, how would you fix it?
 *
 *
 * Exercise 15.14: Given the classes from the previous exercise and the following objects,
 * determine which function is called at run time:
 * Answer:b d b d b d
 */

void testingDebug() {
    Quote quote("978-7-121-15535-2", 67.5);
    BulkQuote bulkQuote("978-7-121-15536-3", 80.3, 20, .2);
    QuantityBulkQuote quantityBulkQuote("978-7-121-15537-4", 90.5, 50, .115);
    Quote &rq = quote, &rbq = bulkQuote, &rqbq = quantityBulkQuote;

    rq.debug();
    cout << endl;
    rbq.debug();
    cout << endl;
    rqbq.debug();
    cout << endl;

    vector<Quote> vq;
    vq.push_back(bulkQuote);
    vq.push_back(quantityBulkQuote);

    for (const auto &item : vq) {
        item.netPrice(20);
        item.debug();
    }

    vector<std::shared_ptr<Quote>> v
            = {std::make_shared<Quote>(std::move(quote)), std::make_shared<Quote>(bulkQuote),
               std::make_shared<Quote>(quantityBulkQuote)};
    for (const auto &item2 : v) {
        item2->debug();
        item2->netPrice(45);
    }
}

namespace oo {
    class Base {
    public:
        Base(const string &name) : name_(name) {}

        string name() const { return name_; }

        virtual void print() const {
            cout << name_ << " ";
        }

    private:
        string name_;
    };

    class Derived : public Base {
    public:
        Derived(const string &name, int i) : Base(name), i_(i) {}

        void print() const override {
            Base::print();
            cout << "i = " << i_;
        }

    private:
        int i_;
    };


    void testingBaseAndDerived() {
        Base b("Apollo");
        Derived d("Hello", 3);
        Base &rb = b, &rd = d;
        rb.print();
        d.print();
//        DiscQuote discQuote("ehl", 20, 3, .2);error: variable type 'DiscQuote' is an abstract class
    }

}


/*
 * Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.
 * @see class DiscQuote.
 * Exercise 15.16: Rewrite the class representing a limited discount strategy, which you wrote for the exercises
 * in § 15.2.2 (p. 601), to inherit from Disc_quote.
 * @see class DiscQuote.
 * Exercise 15.17: Try to define an object of type Disc_quote and see what errors you get from the compiler.
 * Answer:error:variable type 'DiscQuote' is an abstract class.
 */

namespace ac {
    class Pal;

    class Base {
        friend class Pal;

    public:
        void pubMem() {}

    protected:
        int proMem_;
    private:
        char privMem_;
    };

    struct PubDerv : public Base {
        int f() { return proMem_; }
    };

    struct PubFromPubDerv : public PubDerv {
        void memFun(Base &b) { b = *this; }
    };

//    char g() { return privMem_; }error: use of undeclared identifier 'privMem_'

    class ProcDerv : protected Base {
        int f1() { return proMem_; }
    };

    class ProFromProcDerv : protected ProcDerv {
        void memFun(Base &b) { b = *this; }
    };

    struct PrivDerv : private Base {
        int f1() const { return proMem_; }

        void memFun(Base &b) { b = *this; }
    };

    class PrivFromPrivDerv : public PrivDerv {
//        void memFun(Base &b) { return b = *this; } error: 'Base' is a private member of 'ac::Base'
    };

    void testingAccess() {
        PubDerv pd;
        pd.f();
        pd.pubMem();

        ProcDerv procDerv;
//        procDerv.pubMem();error: 'pubMem' is a protected member of 'ac::Base'
//        procDerv.privMem_;error: 'privMem_' is a private member of 'ac::Base'
//        procDerv.proMem_;error: 'proMem_' is a protected member of 'ac::Base'

        PrivDerv privDerv;
        privDerv.f1();

    }

    class Pal {
    public:
        int f(Base b) { return b.proMem_; } //or b.privMem_; ok}
//        Pal is a friend of Base, so Pal
//        can access the members of Base objects. That access includes access to Base
//        objects that are embedded in an object of a type derived from Base.
        int f2(PubDerv &p) { return p.privMem_; }//p.provMem_; can't access}

//        int f3(ProcDerv &p) { return p.proMem_; }public embedded ok
    };

    class D2 : public Pal {
    public:
        int mem(Base p) {
            return 0; /* p.xxx * Friendship is not inherited; each class controls access to its members.*/
        }
    };
}


/*
 * Exercise 15.18: Given the classes from page 612 and page 613, and assuming each object has the type specified in the
 * comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:
 * Answer:T F F T F F
 *
 * Exercise 15.19: Assume that each of the classes from page 612 and page 613 has a member function of the form:
 * void memfcn(Base &b) { b = *this; }
 * For each class, determine whether this function would be legal.
 * Answer: T T T T T F
 * @see namespace ac.
 *
 * Exercise 15.20: Write code to test your answers to the previous two exercises.
 * @see namespace ac;
 *
 *
 * Exercise 15.21: Choose one of the following general abstractions containing a family of types (or choose one of your own).
 * Organize the types into an inheritance hierarchy:
 * @see namespace ab;
 *
 *
 * Exercise 15.22: For the class you chose in the previous exercise, identify some of the likely
 * virtual functions as well as public and protected members.
 * @see namespace ab;
 */

namespace ab {
    class Graphic {
    public:

        Graphic() = default;

        Graphic(double area, double perimeter) : area_(area), perimeter_(perimeter) {}

        virtual double getArea() const { return area_; }

        virtual double getPerimeter() const { return perimeter_; }

    protected:
        double area_ = 0.0;
        double perimeter_ = 0.0;

    };

    class Rectangle : public Graphic {

    public:
        Rectangle(double height, double width) : Graphic(), height_(height), width_(width) {}

        double getArea() const override final {
            return calcArea();
        }

        double getPerimeter() const override final {
            return calcPerimeter();
        }


        virtual double calcArea() const {
            return height_ * width_;
        }

        virtual double calcPerimeter() const {
            return 2 * (height_ + width_);
        }


    protected:
        double height_;
        double width_;
    };

}


/*
 * Exercise 15.23: Assuming class D1 on page 620 had intended to override
 * its inherited fcn function, how would you fix that class? Assuming you fixed
 * the class so that fcn matched the definition in Base, how would the calls in that section be resolved?
 * @see namespace at::Base.
 *
 *
 */

namespace at {
    class Base {
    public:
        virtual int fcn();
    };

    int Base::fcn() {
        cout << "Bse::fcn()" << endl;
        return 42;
    }


    class D1 : public Base {
    public:
        using Base::fcn;

        int fcn();

        int fcn(int i);

        virtual void f2();
    };

    int D1::fcn() {
        cout << "D1::fcn()" << endl;
        return 0;
    }

    int D1::fcn(int i) {
        cout << "D1:fcn(int)" << endl;
        return 43;
    }

    void D1::f2() {
        cout << "D1::f2()" << endl;
    }

    class D2 : public D1 {
    public:
        int fcn(int);

        int fcn();

        void f2();
    };

    int D2::fcn(int) {
        cout << "D2::fcn(int)" << endl;
        return 44;
    }

    int D2::fcn() {
        cout << "D2::fcn()" << endl;
        return 45;
    }

    void D2::f2() {
        cout << "D2::f2()" << endl;
    }

    void testingLookUpNames() {
        D1 d1;
        Base *p = &d1;
        p->fcn();
    }


}


/*
 * Exercise 15.24: What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?
 * Answer:
 * Generally, a base class should define a virtual destructor. The destructor needs to be virtual to allow objects in
 * the inheritance hierarchy to be dynamically allocated and destroyed.
 *
 */


/*
 * Exercise 15.25: Why did we define a default constructor for Disc_quote? What effect, if any, would removing that
 * constructor have on the behavior of Bulk_quote?
 * Without it, when building the statement below, the compiler would complain that:
 * Answer:
 * note: 'Bulk_quote::Bulk_quote()' is implicitly deleted because the default definition would be ill-formed.
 * The reason is that a constructor taking 4 parameters has been defined, which prevented the compiler
 * generate synthesized version default constructor.
 * As a result, the default constructor of any class derived from it has been defined as deleted.
 * Thus the default constructor must be defined explicitly so that the derived classes can call it when executing
 * its default constructor.
 *
 */


/*
 * Exercise 15.26: Define the Quote and Bulk_quote copy-control members
 * to do the same job as the synthesized versions. Give them and the other
 * constructors print statements that identify which function is running. Write
 * programs using these classes and predict what objects will be created and
 * destroyed. Compare your predictions with the output and continue
 * experimenting until your predictions are reliably correct.
 *
 * @see class Quote DiscQuote QuantityBulkQuote BulkQuote
 *
 */


/*
 * Exercise 15.28: Define a vector to hold Quote objects but put Bulk_quote objects into that vector.
 * Compute the total net_price of all the elements in the vector.
 * @see testingDebug();
 *
 * Exercise 15.29: Repeat your program, but this time store shared_ptrs to objects of type Quote.
 * Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy,
 * explain why there isn’t one.
 * @see testingDebug();
 *
 *
 */


void testingBasket() {
    Basket basket;
    Quote quote("978-7-121-15535-2", 67.5);
    BulkQuote bulkQuote("978-7-121-15536-3", 80.3, 20, .2);
    QuantityBulkQuote quantityBulkQuote("978-7-121-15537-4", 90.5, 50, .115);
    basket.addItem(quote);
    basket.addItem(std::move(bulkQuote));
    basket.addItem(std::move(quantityBulkQuote));


    basket.totalReceipt(cout);
}

/*
 * Exercise 15.30: Write your own version of the Basket class and use it to compute prices for the same transactions
 * as you used in the previous exercises.
 * @see testingBasket();
 */



/*
 * The requirement for this topic is to design and implement this text query system.
 * Executing Query for:
 * Daddy Daddy occurs 3 times
 * (line 2) Her Daddy says when the wind blows
 * (line 7) "Daddy, shush, there is no such thing,"
 * (line 10) Shyly, she asks, "I mean, Daddy, is there?"
 *
 *
 * • Not queries, using the ~ operator, yield lines that don’t match the query:
 * Executing Query for: ~(Alice)
 * ~(Alice) occurs 9 times
 * (line 2) Her Daddy says when the wind blows
 * (line 3) through her hair, it looks almost alive,
 * (line 4) like a fiery bird in flight.
 * ...
 *
 * • Or queries, using the | operator, return lines matching either of two queries:
 * Executing Query for: (hair | Alice)
 * (hair | Alice) occurs 2 times
 * (line 1) Alice Emma has long flowing red hair.
 * (line 3) through her hair, it looks almost alive,
 *
 * • And queries, using the & operator, return lines matching both queries:
 * Executing query for: (hair & Alice)
 * (hair & Alice) occurs 1 time
 * (line 1) Alice Emma has long flowing red hair.
 *
 *
 * Executing Query for: ((fiery & bird) | wind)
 * ((fiery & bird) | wind) occurs 3 times
 * (line 2) Her Daddy says when the wind blows
 * (line 4) like a fiery bird in flight.
 * (line 5) A beautiful fiery bird, he tells her,
 *
 */


/*
 * first, design and implement TextQuery And QueryResult.
 * done.
 */


/*
 * second, design Query interface
 * done.
 */


/*
 * third, Design and implement the QueryBase inheritance system.
 * done.
 */


/*
 * Fourth, parse the query string and generate a query expression.
 * done.
 */


/*
 * fifth, testing the program.
 * done.
 */


/*
 * Exercise15.31 ----- Exercise15.42. Please check namespace query.
 */




int main(int argc, char *argv[]) {
    query::runQueries();
    testingBasket();
    at::testingLookUpNames();
    testingDebug();
    testingPrintTotal();
    oo::testingBaseAndDerived();
    return 0;
}
