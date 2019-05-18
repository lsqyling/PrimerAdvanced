//
// Created by shiqing on 19-4-22.
//

#include "../common/CommonHeaders.h"
#include "SalesData.h"
#include "Person.h"
#include "Screen.h"
#include "ScreenManager.h"


/*
 * Exercise 7.1:
 * Write a version of the transaction-processing program from
 * §1.6 (p. 24) using the Sales_data class you defined for the exercises in §2.6.1 (p. 72).
 *
 * @see transactionProcessing();
 */


void transactionProcessing() {
    SalesData total;
    if (read(cin, total)) {
        SalesData trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cout << "No Data?!" << endl;
    }
}


/*
 * Exercise 7.2:
 * Add the combine and isbn members to the Sales_data
 * class you wrote for the exercises in § 2.6.2 (p. 76).
 * @see SalesData.cpp
 */


/*
 * Exercise 7.3:
 * Revise your transaction-processing program from § 7.1.1 (p.256) to use these members.
 *
 * @see transactionProcessing();
 */

/*
 * Exercise 7.4:
 * Write a class named Person that represents the name and
 * address of a person. Use a string to hold each of these elements.
 * Subsequent exercises will incrementally add features to this class.
 *
 * @see Person.cpp
 */


/*
 * Exercise 7.5:
 * Provide operations in your Person class to return the name
 * and address. Should these functions be const? Explain your choice.
 * @see Person.cpp
 * Should be const, because of the functions is readable.
 */


/*
 * Exercise 7.6:
 * Define your own versions of the add, read, and print functions.
 * @see SalesData.cpp
 */

/*
 * Exercise 7.7:
 * Rewrite the transaction-processing program you wrote for the
 * exercises in § 7.1.2 (p. 260) to use these new functions.
 * @see transactionProcessing();
 */

/*
 * Exercise 7.8:
 * Why does read define its Sales_data parameter as a plain
 * reference and print define its parameter as a reference to const?
 *
 * Answer:
 * read should change the SalesData.
 * Write shouldn't change the SalesData.
 */

/*
 * Exercise 7.9:
 * Add operations to read and print Person objects to the code
 * you wrote for the exercises in § 7.1.2 (p. 260).
 *
 * @see Person.cpp
 */

/*
 * Exercise 7.10:
 * What does the condition in the following if statement do?
 * if (read(read(cin, data1), data2))
 * Answer:
 * the condition of the if statement would read two Sales_data object at one time.
 */


/*
 * Exercise 7.11:
 * Add constructors to your Sales_data class and write a
 * program to use each of the constructors.
 * @see SalesData.h;
 *
 *
 *
 * Exercise 7.12:
 * Move the definition of the Sales_data constructor that
 * takes an istream into the body of the Sales_data class.
 *
 * @see SalesData.h;
 *
 * Exercise 7.13:
 * Rewrite the program from page 255 to use the istream constructor.
 *
 * @see SalesData.h
 *
 * Exercise 7.14:
 * Write a version of the default constructor that explicitly
 * initializes the members to the values we have provided as in-class initializers.
 *
 * Exercise 7.15:
 * Add appropriate constructors to your Person class.
 * @see Person.h
 */


/*
 * Exercise 7.16:
 * What, if any, are the constraints on where and how often an
 * access specifier may appear inside a class definition? What kinds of members
 * should be defined after a public specifier? What kinds should be private?
 *
 * Answer:
 * There are no restrictions on how often an access specifier may appear.
 * The specified access level remains in effect until the next access specifier or the end of the class body.
 * The members which are accessible to all parts of the program should define after a public specifier.
 * The members which are accessible to the member functions of the class
 * but are not accessible to code that uses the class should define after a private specifier.
 *
 *
 * Exercise 7.17:
 * What, if any, are the differences between using class or struct?
 * Answer:
 * The only difference between using class and using struct to define a class is the default access level.
 * (class : private, struct : public)
 *
 *
 * Exercise 7.18:
 * What is encapsulation? Why is it useful?
 * Answer:
 * encapsulation is the separation of implementation from interface.
 * It hides the implementation details of a type.
 * (In C++, encapsulation is enforced by putting the implementation in the private part of a class)
 *
 * Exercise 7.19:
 * Indicate which members of your Person class you would declare as public and which you would declare as private.
 * Explain your choice.
 *
 * Answer:
 * public include: constructors, getName(), getAddress(). private include: name, address.
 * the interface should be defined as public, the data shouldn't expose to outside of the class.
 */


/*
 * Exercise 7.20:
 * When are friends useful? Discuss the pros and cons of using friends.
 *
 * Answer:
 * friend is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.
 *
 * Pros:
 * the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
 * you can access all the nonpublic members conveniently.
 * sometimes, more readable to the users of class.
 *
 * Cons:
 * lessens encapsulation and therefore maintainability.
 * code verbosity, declarations inside the class, outside the class.

 *
 * Exercise 7.21:
 * Update your Sales_data class to hide its implementation.
 * The programs you’ve written to use Sales_data operations should still
 * continue to work. Recompile those programs with your new class definition to
 * verify that they still work.
 * @see SalesData.cpp
 *
 *
 * Exercise 7.22:
 * Update your Person class to hide its implementation.
 *
 * @see SalesData.cpp
 */



void testingPersonReadAndPrint() {
    using namespace p;
    Person person;
    read(cin, person);
    print(cout, person);
}

/*
 * Exercise 7.23:
 * Write your own version of the Screen class.
 *
 * @see Screen.h;
 *
 *
 * Exercise 7.24:
 * Give your Screen class three constructors: a default
 * constructor; a constructor that takes values for height and width and initializes the contents
 * to hold the given number of blanks;
 * and a constructor that takes values for height, width, and a character to use as the contents of the screen.
 *
 * @see Scrren.h;
 *
 * Exercise 7.25:
 * Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?
 * Answer: yes.
 *
 * Exercise 7.26:
 * Define Sales_data::avg_price as an inline function.
 * @see SalesData.h
 */

void testingScreen() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;

    myScreen.display(cout);
    cout << endl;

    ScreenManager sm;
    sm.addScreen(myScreen);
    sm.clear(1);
    myScreen.display(cout);
    cout << endl;

    cout << "---------------------------";
    myScreen.clear();
    myScreen.display(cout);
    cout << "---------------------------" << endl;




}


/*
 * Exercise 7.27:
 * Add the move, set, and display operations to your
 * version of Screen. Test your class by executing the following code:
 * @see testingScreen();
 *
 * Exercise 7.28:
 * What would happen in the previous exercise if the return
 * type of move, set, and display was Screen rather than Screen&?
 *
 * Answer:The second call to display couldn't print # among the output,
 * cause the call to set would change the temporary copy, not myScreen.
 *
 *
 * Exercise 7.29:
 * Revise your Screen class so that move, set, and display functions return Screen and
 * check your prediction from the previous exercise.
 * already be done.
 *
 * Exercise 7.30:
 * It is legal but redundant to refer to members through the this pointer.
 * Discuss the pros and cons of explicitly using the this pointer to access members.
 *
 * Answer:
 * Pros:
 * more explicit
 * less scope for misreading
 * can use the member function parameter which name is same as the member name.
 * void setAddr(const std::string &addr) { this->addr = addr; }
 *
 * Cons:
 * more to read
 * sometimes redundant
 *
 */



/*
 * Exercise 7.31:
 * Define a pair of classes X and Y, in which X has a pointer to
 * Y, and Y has an object of type X.
 *
 * @see class X, Y;
 */


class X;
class Y;

class X {
    Y *pY;
    int j;
    int i;

    // b is
    bool b;
public:
    X(int val) : j(val), i(j) {
        cout << "i = " << i << ", j = " << j << endl;
    }

    X() {
        cout << "i = " << i << ", j = " << j << ", b = " << b << endl;
    };




};

class Y {
    X x;
};


/*
 * Exercise 7.32:
 * Define your own versions of Screen and Window_mgr in
 * which clear is a member of Window_mgr and a friend of Screen.
 *
 * @ScreenManager.h
 */


/*
 * Exercise 7.33:
 * What would happen if we gave Screen a size member
 * defined as follows? Fix any problems you identify.
 * @see Screen.h;
 */


void testingExplicitInitializing() {
    SalesData item("0-201-78345-X", 3, 20.00);
    string book = "0-201-78345-X";
//    It is legal to not add the explicit keyword.
//    item.combine(book);
//    print(cout, item) << endl;
//
//    item = book;
//    SalesData sd = book;
//    SalesData other(book);

    SalesData sd(book); // ok: direct initialization
    print(cout, sd) << endl;
    item.combine(static_cast<SalesData>(book));


}


/*
 * Exercise 7.34:
 * What would happen if we put the typedef of pos in the
 * Screen class on page 285 as the last line in the class?
 *
 * Answer:Unknown type name 'pos'
 *
 *
 * Exercise 7.35:
 * Explain the following code, indicating which definition of
 * Type or initVal is used for each use of those names. Say how you would fix any errors.
 */

/*
 * Ordinarily, an inner scope can redefine a name from an outer scope even if that name
 * has already been used in the inner scope. However, in a class, if a member uses a
 * name from an outer scope and that name is a type, then the class may not subsequently redefine that name.
 */

typedef string Type;
Type initVal(); // use `string`
class Exercise {
public:
    typedef double Type; //legal
    Type setVal(Type); // use `double`
    Type initVal(); // use `double`
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm) {  // if not "Exercise::Type",the first is `string`, second is `double`
    val = parm + initVal();     // Exercise::initVal()
    return val;
}

Exercise::Type Exercise::initVal() {
    return 0;
}


/*
 * Exercise 7.36: The following initializer is in error. Identify and fix the problem.
 * struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};

 * Answer:
 * Should be X(int i, int j) : rem(i % j), base(i) {}
 *
 * Exercise 7.37:
 * Using the version of Sales_data from this section,
 * determine which constructor is used to initialize each of the following variables and list the values of
 * the data members in each object:
 *
 * Sales_data first_item(cin);
 * Answer: Sales_data(std::ostream &os);
 *
 * int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
    Answer: Sales_data(const string &);
}
 *
 * Exercise 7.38:
 * We might want to supply cin as a default argument to the
 * constructor that takes an istream&. Write the constructor declaration that
 * uses cin as a default argument.
 * Should:SalesData(std::istream &os = cin);
 *
 * Exercise 7.39:
 * Would it be legal for both the constructor that takes a string and the one that takes an
 * istream& to have default arguments? If not, why not?
 *
 * Answer:illegal. cause the call of overloaded 'Sales_data()' is ambiguous.
 *
 *
 *
 * Exercise 7.40:
 * Choose one of the following abstractions (or an abstraction of your own choosing).
 * Determine what data are needed in the class. Provide an appropriate set of constructors.
 * Explain your decisions.
 * (a) Book
 * (b) Date
 * (c) Employee
 * (d) Vehicle
 * (e) Object
 * (f) Tree
 *
 * already be done.
 */


/*
 * Exercise 7.41:
 * Rewrite your own version of the Sales_data class to use delegating constructors.
 * Add a statement to the body of each of the
 * constructors that prints a message whenever it is executed. Write
 * declarations to construct a Sales_data object in every way possible. Study
 * the output until you are certain you understand the order of execution among delegating constructors.
 *
 * @see Person.h;
 * @see class Employee
 *
 *
 * Exercise 7.42:
 * For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291),
 * decide whether any of the constructors might use delegation. If so, write the
 * delegating constructor(s) for your class. If not, look at the list of abstractions
 * and choose one that you think would use a delegating constructor. Write the
 * class definition for that abstraction.
 * @see Employee.
 * already be done.
 */


class Employee {
public:
    Employee() : Employee("", "", 0, "female") {}

    explicit Employee(string id) : Employee(id, "Liu", 18, "female") {}

    Employee(string id, string name, unsigned age, string gender) : id_(id), name_(name), age_(age), gender_(gender) {}
private:
    string id_;
    string name_;
    unsigned age_ = 0;
    string gender_;
};

/*
 * Exercise 7.43:
 * Assume we have a class named NoDefault that has a
 * constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault.
 * Define the default constructor for C.
 *
 * @see class NoDefault , class C.
 *
 *
 * Exercise 7.44:
 * Is the following declaration legal? If not, why not?
 * vector<NoDefault> vec(10);
 *
 * illegal.vector<NoDefault> vec(10) should be default initialization.
 * no comfort for constructors.
 *
 *
 *
 * Exercise 7.45:
 * What if we defined the vector in the previous execercise to hold objects of type C?
 * Answer: yes .
 *
 *
 *
 * Exercise 7.46:
 * Which, if any, of the following statements are untrue? Why?
 * (a) A class must provide at least one constructor.
 * (b) A default constructor is a constructor with an empty parameter list.
 * (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
 * (d) If a class does not define a default constructor, the compiler generates one that initializes each data member
 * to the default value of its associated type.
 *
 *
 * Answer:
 * a) A class must provide at least one constructor. (untrue, "The compiler-generated constructor is known as the synthesized default constructor.")
 * b) A default constructor is a constructor with an empty parameter list.
 * (untrue, A default constructor is a constructor that is used if no initializer is supplied.What's more,
 * A constructor that supplies default arguments for all its parameters also defines the default constructor)
 * c) If there are no meaningful default values for a class, the class should not provide a default constructor.
 * (untrue, the class should provide.)
 * d) If a class does not define a default constructor,
 * the compiler generates one that initializes each data member to the default value of its associated type.
 * (untrue, only if our class does not explicitly define any constructors,
 * the compiler will implicitly define the default constructor for us.)
 */


/*
 * Exercise 7.47:
 * Explain whether the Sales_data constructor that takes a
 * string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?
 * Answer:
 * Whether the conversion of a string to Sales_data is desired depends on how we think our users will use the conversion.
 * In this case, it might be okay. The string in null_book probably represents a nonexistent ISBN.
 * Benefits:
 * prevent the use of a constructor in a context that requires an implicit conversion
 * we can define a constructor which is used only with the direct form of initialization
 *
 * Drawbacks:
 * meaningful only on constructors that can be called with a single argument
 *
 *
 *
 * Exercise 7.48:
 * Assuming the Sales_data constructors are not explicit,
 * what operations happen during the following definitions
 * string null_isbn("9-999-99999-9");
 * Sales_data item1(null_isbn);
 * Sales_data item2("9-999-99999-9");
 * What happens if the Sales_data constructors are explicit?
 *
 * answer:nothing to happen.
 *
 * Exercise 7.49:
 * For each of the three following declarations of combine,
 * explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:
 * (a) Sales_data &combine(Sales_data); //ok
 * (b) Sales_data &combine(Sales_data&);//[Error] no matching function for call to 'Sales_data::combine(std::string&)'
 * (`std::string&` can not convert to `Sales_data` type.)
 * (c) Sales_data &combine(const Sales_data&) const;
 * // The trailing const mark can't be put here, as it forbids any mutation on data members.
 * This conflicts with combine's semantics.
 *
 * Some detailed explanation about problem (b) :It's wrong. Because combine’s parameter is a non-const reference ,
 * we can't pass a temporary to that parameter. If combine’s parameter is a reference to const ,
 * we can pass a temporary to that parameter. Like this :Sales_data &combine(const Sales_data&);
 * Here we call the Sales_data combine member function with a string argument. This call is perfectly legal;
 * the compiler automatically creates a Sales_data object from the given string. That newly generated (temporary)
 * Sales_data is passed to combine.(Also you can read C++ Primer Page 295(English Edition))
 *
 *
 *
 * Exercise 7.50:
 * Determine whether any of your Person class constructors should be explicit.
 * @see Person.h
 *
 * Exercise 7.51:
 * Why do you think vector defines its single-argument constructor as explicit, but string does not?
 * Such as a function like that:
 * int getSize(const std::vector<int>&);
 * if vector has not defined its single-argument constructor as explicit. we can use the function like:
 * getSize(34);
 * What is this mean? It's very confused.
 * But the std::string is different. In ordinary, we use std::string to replace const char *(the C language).
 * so when we call a function like that:
 * void setYourName(std::string); // declaration.
 * setYourName("pezy"); // just fine.
 *
 * it is very natural.
 *
 */

class NoDefault {
public:
    explicit NoDefault(int id) : id_(id) {}

private:
    int id_ = 0;
};

class C {
public:
    C() : noDefault_(0) {}
//    C() = default;note:
//    ‘C::C()’ is implicitly deleted because the default definition would be ill-formed:
private:
    NoDefault noDefault_;
};


/*
 * Exercise 7.52:
 * Using our first version of Sales_data from § 2.6.1 (p. 72),
 * explain the following initialization. Identify and fix any problems.
 *
 * if Sales_data is Aggregate Class, then ok;
 * Sales_data item = {"978-0590353403", 25, 15.99};
 * or SalesData item{"978-0590353403", 25, 15.99};
 */


class Debug {
public:

    constexpr Debug(bool b = true) : Debug(b, b, b) {}

    constexpr bool any() { return hw_ || io_ || other_; }

    constexpr Debug(bool hw, bool io, bool other) : hw_(hw), io_(io), other_(other) {}

    constexpr void setHw(bool b) { hw_ = b; }
    constexpr void setIo(bool b) { io_ = b; } // error: assignment of member ‘Debug::hw_’ in read-only object std=c11
    /*
     * c14 ok
     */
    constexpr void setOther(bool b) { other_ = b; }

private:
    bool hw_, io_, other_;
};


/*
 * Exercise 7.53:
 * Define your own version of Debug.
 * @see class Debug.
 *
 * Exercise 7.54:
 * Should the members of Debug that begin with set_ be declared as constexpr? If not, why not?
 * Answer:
 * in C++11, constexpr member functions are implicitly const, so the "set_xx" functions,
 * which will modify data members, cannot be declared as constexpr.
 * In C++14, this property no longer holds, so constexpr is suitable.
 *
 *
 * Exercise 7.55:
 * Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.
 * Answer:
 * no. std::string is not a literal type, and it can be verified by following codes:
 */




class Account {
public:
    void calculate() { amount += amount *interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

private:
    string owner;
    double amount = 1.2;
    static double interestRate;
    static constexpr int period = 10;
    double dailyTbl[period];
};

double Account::interestRate = 2.1;

void Account::rate(double newRate) {
    interestRate = newRate;
}


/*
 * Exercise 7.56:
 * What is a static class member? What are the advantages of static members? How do they differ from ordinary members?
 *
 * Answer:
 * A class member that is associated with the class, rather than with individual objects of the class type.
 * each object can no need to store a common data. And if the data is changed, each object can use the new value.
 * a static data member can have incomplete type.
 * we can use a static member as a default argument.
 *
 *
 *
 * Exercise 7.57:
 * Write your own version of the Account class.
 * @see class Account;
 *
 *
 * Exercise 7.58:
 * Which, if any, of the following static data member declarations and definitions are errors? Explain why.
 * @see class Example;
 */


class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

/*
 * Best Practices:
 * Even if a const static data member is initialized in the class body,
 * that member ordinarily should be defined outside the class definition.
 */

constexpr double Example::rate;
const int Example::vecSize;
vector<double> Example::vec(vecSize);




int main(int argc, char *argv[]) {
    Debug debug;
    C c;
    SalesData item{"978-0590353403", 25, 15.99};
    SalesData other("978-0590353403", 25, 15.99);
    print(cout, item) << endl;
    testingExplicitInitializing();
    X x(3);
    X xi;
    testingScreen();
    testingPersonReadAndPrint();
    transactionProcessing();
    return 0;
}
