//
// Created by shiqing on 19-4-17.
//

#include "../common/CommonHeaders.h"

/*
 * Exercise 2.1:
 * What are the differences between int, long, long long,
 * and short? Between an unsigned and a signed type? Between a float and a double?
 */

/*
 * Answer:
 * C++ guarantees short and int is at least 16 bits, long at least 32 bits, long long at least 64 bits.
 * The signed can represent positive numbers,
 * negative numbers and zero, while unsigned can only represent numbers no less than zero.
 * The C and C++ standards do not specify the representation of float, double and long double.
 * It is possible that all three implemented as IEEE double-precision.
 * Nevertheless, for most architectures (gcc, MSVC; x86, x64, ARM) float is indeed a IEEE single-precision floating point number (binary32), and double is a IEEE double-precision floating point number (binary64).
 *
Usage:

    Use int for integer arithmetic. short is usually too small and, in practice, long often has the same size as int. If your data values are larger than the minimum guaranteed size of an int, then use long long. (In a word: short < int < long < long long)

    Use an unsigned type when you know that the values cannot be negative. (In a word: no negative, unsigned.)

    Use double for floating-point computations; float usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines, double-precision operations are faster than single. The precision offered by long double usually is unnecessary and often entails considerable run-time cost. (In a word: float < double < long double)
 */


/*
 * Exercise 2.2:
 * To calculate a mortgage payment, what types would you use
 * for the rate, principal, and payment? Explain why you selected each type.
 */

/*
 * Answer:
 * use double, or also float.
 * The rate most like that: 4.50 % per year.
 * The principal most like that: $854.36 The payment most like that: $1, 142.36
 */

/*
 * Exercise 2.3
 * What output will the following code produce?
 */
void showResults() {
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;

    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;

    cout << 2 << "\115\12";
    cout << 2 << "\t\115\12";

}

/*
 * Exercise 2.4
 * Write a program to check whether your predictions were correct.
 * If not, study this section until you understand what the problem is.
 * Answer:already done.
 */


/*
 * Exercise 2.5

    Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

    (a) 'a', L'a', "a", L"a"
    (b) 10, 10u, 10L, 10uL, 012, 0xC
    (c) 3.14, 3.14f, 3.14L
    (d) 10, 10u, 10., 10e-2

(a): character literal, wide character literal, string literal, string wide character literal.

(b): int, unsigned int, long, unsigned long , octal, hexadecimal.

(c): double, float, long double.

(d): int, unsigned int, double, double.
 */


/*
 * Exercise 2.6
 * What, if any, are the differences between the following definitions:
 * int month = 9, day = 7;
 * int month = 09, day = 07;
 * The first line's integer is literal.
 * The second line:
 * int month = 09 is invalid, cause octal don't have digit 9.
 * day is octal.
 */

/*
 * Exercise 2.7

    What values do these literals represent? What type does each have?

    (a) "Who goes with F\145rgus?\012"
    (b) 3.14e1L
    (c) 1024f
    (d) 3.14L

(a): Who goes with Fergus?(new line) "string"

(b): 31.4 "long double"

(c): ERROR: The suffix f is valid only with floating point literals

(d): 3.14 "long double"

 */

/*
 * Exercise 2.8
 * Using escape sequences, write a program to print 2M followed by a newline.
 * Modify the program to print 2, then a tab, then an M, followed by a newline.
 */

//Warning
//        Initialization is not assignment. Initialization happens when a variable is given
//        a value when it is created. Assignment obliterates an object’s current value
//        and replaces that value with a new one.


/*
 * Exercise 2.9

    Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.

    (a) std::cin >> int input_value;
    (b) int i = { 3.14 };
    (c) double salary = wage = 9999.99;
    (d) int i = 3.14;

(a): error: expected '(' for function-style cast or type construction.

int input_value = 0;
std::cin >> input_value;

(b):---when you compile the code without the argument "-std=c++11", you will get the warning below: warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3. ---when you compile the code using "-std=c+11", you will get a error below: error: type 'double' cannot be narrowed to 'int' in initializer list ---conclusion: Obviously, list initialization becomes strict in c++11.

double i = { 3.14 };

(c): --if you declared 'wage' before, it's right. Otherwise, you'll get a error: error: use of undeclared identifier 'wage'

double wage;
double salary = wage = 9999.99;

(d): ok: but value will be truncated.

double i = 3.14;
 */


/*
 * Exercise 2.10
 * What are the initial values, if any, of each of the following variables?
 * global_str is global variable, so the value is empty string.
 * global_int is global variable, so the value is zero.
 * local_int is a local variable which is uninitialized, so it has a undefined value.
 * local_str is also a local variable which is uninitialized, but it has a value that is defined by the class.
 * So it is empty string.
 * PS: please read P44 in the English version, P40 in Chinese version to get more.
 * The note: Uninitialized objects of built-in type defined inside a function body have a undefined value.
 * Objects of class type that we do not explicitly initialize have a value that is defined by class.
 */


/*
 * Exercise 2.11: Explain whether each of the following is a declaration or a
definition:
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;
 */


/*
 * Exercise 2.12:
 * Which, if any, of the following names are invalid?
 * Answer:@see operateVariable();
 */

//extern int ix = 1024;定义，只能定义在函数外面在类内定义也是错误的  warning: ‘ix’ initialized and declared ‘extern’
void operateVariable() {
//    extern int ix = 1024;error: ‘ix’ has both ‘extern’ and initializer
    int iy;//定义；
    extern int iz;//declaration
//    int double = 3.14; double is keywords
    int _;
//    int catch-22;catch is keywords
//    int 1_or_2 = 1; error: expected unqualified-id before numeric constant
    double Double = 3.14;

}


/*
 * Exercise 2.13: What is the value of j in the following program?
 * Answer:j = 100;
 */

/*
 * Exercise 2.14:
 * Is the following program legal? If so, what values are printed?
 * Answer:100 45
 */

void useCompoundType() {
//    A reference defines an alternative name for an object. A reference type “refers to” another type.
    int ival = 1024;
    int &refVal = ival; // refVal refers to (is another name for) ival
//    int &refVal2;error: ‘refVal2’ declared as reference but not initialized
//    A reference is not an object. Instead, a reference is just another name for an already existing object.
    refVal = 2; // assigns 2 to the object to which refVal refers, i.e., to ival
    int ii = ival;  // same as ii = ival
    cout << "ii = " << ii << endl;
//     ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
    int &refVal3 = refVal;

//     initializes i from the value in the object to which refVal is bound
    int iref = refVal;
    int i = 1024, i2 = 2048; // i and i2 are both ints;
    int &r = i, r2 = i2; // r is a reference bound to i, r2 is an int;
    int i3 = 1024, &ri = i3; // i3 is an int, ri is reference bound i3;
    int &r3 = i3, &r4 = i2; // both r3 and r4 are references

//    int &refVal4 = 10;error: initializer must be an object
    double dval = 3.14;
//    int &refVal5 = dval;error: initializer must be an int object


}


/*
 * Exercise 2.15

    Which of the following definitions, if any, are invalid? Why?

    (a) int ival = 1.01;
    (b) int &rval1 = 1.01;
    (c) int &rval2 = ival;
    (d) int &rval3;

(a): valid.
(b): invalid. initializer must be an object.
(c): valid.
(d): invalid. a reference must be initialized.
 */


/*
 * Exercise 2.16

    Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

int i = 0, &r1 = i; double d = 0, &r2 = d;

    (a) r2 = 3.14159;
    (b) r2 = r1;
    (c) i = r2;
    (d) r1 = d;

(a): valid. let d equal 3.14159.
(b): valid. automatic convert will happen.
(c): valid. but value will be truncated.
(d): valid. but value will be truncated.

 */


/*
 * Exercise 2.17:
 * What does the following code print?
 * int i, &ri = i;
 * i = 5; ri = 10;
 * std::cout << i << " " << ri << std::endl;
 * Answer: 10 10
 */


void usedPointer() {
    int *ip1, *ip2; //both ip1 and ip2 are pointers to int
    double dp, *dp2; // dp2 is pointer to int , dp is a double
    int ival = 42;
    int *p = &ival; // p holds the address of ival; p is a pointer to ival
    double dval;
    double *pd = &dval;
    double *pd2 = pd;
//    int *pi = pd;error: cannot convert ‘double*’ to ‘int*’ in initialization
//    pi = &dval;error: cannot convert ‘double*’ to ‘int*’ in assignment
    long L = 1024L, *lp = nullptr;
    lp = &L;
    *lp = 32;

    cout << "L = " << L << ", *lp = " << *lp << endl;
    int i = 42, *pi = &i;
    *pi = *pi * *pi;
    cout << "i = " << i << ", *pi = " << *pi << endl;


    int k = 42;
    int *kp; // kp is pointer to int
    int *&r = kp;//r is a reference to the pointer kp;
    r = &k; //  r refers to a pointer; assigning &i to r makes p point to i
    *r = 0;//  dereferencing r yields i, the object to which p points; changes i to 0
}


/*
 * Exercise 2.18:
 * Write code to change the value of a pointer. Write code to
 * change the value to which the pointer points.
 * Answer:@see usedPointer();
 */

/*
 * Exercise 2.19: Explain the key differences between pointers and references.
 */
//definition:
//
//the pointer is "points to" any other type.
//
//the reference is "another name" of an object.
//key difference:
//
//a reference is another name of an already existing object. a pointer is an object in its own right.
//Once initialized, a reference remains bound to its initial object.
// There is no way to rebind a reference to refer to a different object.
// a pointer can be assigned and copied.
//a reference always get the object to which the reference was initially bound.
// a single pointer can point to several different objects over its lifetime.
//a reference must be initialized.
// a pointer need not be initialized at the time it is defined.

/*
 * Exercise 2.20:
 * What does the following program do?
 * Answer:@see usedPointer();
 *
 */


/*
 * Exercise 2.21:
 * Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
 * int i = 0;
 * (a) double* dp = &i;
 * (b) int *ip = i;
 * (c) int *p = &i;
 * (a): illegal, cannot initialize a variable of type 'double *' with an
 * rvalue of type 'int *'
 * (b): illegal, cannot initialize a variable of type 'int *' with an lvalue of type 'int'
 * (c): legal.
 */



/*
 * Exercise 2.22:
 * Assuming p is a pointer to int, explain the following code:
 * if (p) // ...
 * if (*p) // ...
 * if (p) // whether p is nullptr?
 * if (*p) // whether the value pointed by p is zero?
 */


/*
 * Exercise 2.23:
 * Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?
 * No. Because more information needed to determine whether the pointer is valid or not.
 */

/*
 * Exercise 2.24:
 * Why is the initialization of p legal but that of lp illegal?
 * int i = 42;
 * void *p = &i;
 * long *lp = &i;
 * Inherited from C, void* is a special pointer that may point to any type, hence the second line is legal.
 * For type safety, C++ forbids implicit conversions like long *lp = &i;, thus such code is illegal.
 */

// As we’ve seen, a variable definition consists of a base type and a list of declarators.


/*
 * Exercise 2.25:
 * Determine the types and values of each of the following variables.
 * (a) int* ip, i, &r = i;
 * (b) int i, *ip = 0;
 * (c) int* ip, ip2;
 * (a): ip is a pointer to int, i is an int, r is a reference to int i.
 * (b): ip is a valid, null pointer, and i is an int.
 * (c): ip is a pointer to int, and ip2 is an int.
 */

//We can make a variable unchangeable by defining the variable’s type as
//const:
/*
 * Note:
 * To share a const object among multiple files, you must define the variable as extern.
 * To define a single instance of a const variable, we use the keyword extern on
 * both its definition and declaration(s):
 */
extern const int bufSize;



/*
 * Exercise 2.26:
 * Which of the following are legal? For those that are illegal, explain why.
 * const int buf;      // illegal, buf is uninitialized const.
 * int cnt = 0;        // legal.
 * const int sz = cnt; // legal.
 * ++cnt;              // legal.
 * ++sz;               // illegal, attempt to write to const object(sz).
 */


/*
 * Exercise 2.27:
 * Which of the following initializations are legal? Explain why.
 * int i = -1, &r = 0;         // illegal, r must refer to an object.
 * int *const p2 = &i2;        // legal.
 * const int i = -1, &r = 0;   // legal.
 * const int *const p3 = &i2;  // legal.
 * const int *p1 = &i2;        // legal
 * const int &const r2;        // illegal, r2 is a reference that cannot be const.
 * const int i2 = i, &r = i;   // legal.
 */

/*
 * Exercise 2.28:
 * Explain the following definitions. Identify any that are illegal.
 * int i, *const cp;       // illegal, cp must initialize.
 * int *p1, *const p2;     // illegal, p2 must initialize.
 * const int ic, &r = ic;  // illegal, ic must initialize.
 * const int *const p3;    // illegal, p3 must initialize.
 * const int *p;           // legal. a pointer to const int.
 */


/*
 * Exercise 2.29:
 * Using the variables in the previous exercise, which of the following assignments are legal? Explain why.
 * i = ic;     // legal.
 * p1 = p3;    // illegal. p3 is a const pointer to const int.
 * p1 = &ic;   // illegal. ic is a const int.
 * p3 = &ic;   // illegal. p3 is a const pointer.
 * p2 = p1;    // illegal. p2 is a const pointer.
 * ic = *p3;   // illegal. ic is a const int.
 */


/*
 * Exercise 2.30:
 * For each of the following declarations indicate whether the object being declared has top-level or low-level const.
 * const int v2 = 0; int v1 = v2;
 * int *p1 = &v1, &r1 = v1;
 * const int *p2 = &v2, *const p3 = &i, &r2 = v2;
 * Answer: v2 is top-level const. p2 is low-level const. p3 is both low-level and top-level const. r2 is low-level const.
 */


/*
 * Exercise 2.31:
 * Given the declarations in the previous exercise determine whether the following assignments are legal.
 * Explain how the top-level or low-level const applies in each case.
 * r1 = v2; // legal, top-level const in v2 is ignored.
 * p1 = p2; // illegal, p2 has a low-level const but p1 doesn't.
 * p2 = p1; // legal, we can convert int* to const int*.
 * p1 = p3; // illegal, p3 has a low-level const but p1 doesn't.
 * p2 = p3; // legal, p2 has the same low-level const qualification as p3.
 */


/*
 * Exercise 2.32:
 * Is the following code legal or not? If not, how might you make it legal?
 * int null = 0, *p = null;illegal.
 * Answer:
 * int null = 0, *p = &null;
 * int null = 0, *p = nullptr;
 */



void constQualifier() {
//    bufSize = 512;error: assignment of read-only variable ‘bufSize’
    const int j = 42;
//    const int k;error: uninitialized const ‘k’ [-fpermissive]
    int i = 42;
    const int ci = i;
    int k = ci;
    cout << "const bufSize = " << bufSize << endl;

    const double pi = 3.14;
//    double *ptr = &pi;//Error:ptr is a plain pointer
    const double *ptr = &pi;
//    *ptr = 42;Error:cannot assign to *ptr
    double dval = 3.14;
    ptr = &dval;//ok,but can't change dval through ptr
    int errNumb = 0;
    int *const curErr = &errNumb; //curErr will always point to errNumb;
    const double *const ppi = &pi;//ppi is a const pointer to a const object

    const int max_files = 20;
    const int limit = max_files + 1;
    int staffSize = 27;

    constexpr int mf = 20;
    constexpr int li = mf + 1;

    const int *p = nullptr; //p is a pointer to a const int
    constexpr int *q = nullptr; // q is a const pointer to int

//    The difference is a consequence of the fact
//    that constexpr imposes a top-level const (§ 2.4.3, p. 63) on the objects it defines.


}


/*
 * Exercise 2.33:
 * Using the variable definitions from this section, determine what happens in each of these assignments:
 * a=42; // set 42 to int a.
 * b=42; // set 42 to int b.
 * c=42; // set 42 to int c.
 * d=42; // ERROR, d is an int *. correct: *d = 42;
 * e=42; // ERROR, e is an const int *. correct: e = &c;
 * g=42; // ERROR, g is a const int& that is bound to ci.
 */

/*
 * Exercise 2.34:
 * Write a program containing the variables and assignments from the previous exercise.
 * Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct.
 * If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.
 * already be done.
 */

/*
 * Exercise 2.35: Determine the types deduced in each of the following
 * definitions. Once you’ve figured out the types, write a program to see
 * whether you were correct.
 * @see typeInfers();
 */


/*
 * Exercise 2.36:
 * In the following code, determine the type of each variable and the value each variable has when the code finishes:
 * int a = 3, b = 4;
 * decltype(a) c = a;
 * decltype((b)) d = a;
 * ++c;
 * ++d;
 * c is an int, d is a reference of a. all their value are 4.
 */


/*
 * Exercise 2.37:
 * Assignment is an example of an expression that yields a reference type.
 * The type is a reference to the type of the left-hand operand. That is, if i is an int,
 * then the type of the expression i = x is int&. Using that knowledge,
 * determine the type and value of each variable in this code:
 * int a = 3, b = 4;
 * decltype(a) c = a;
 * decltype(a = b) d = a;
 * c is an int, d is a reference of int. the value: a=3, b=4, c=3, d=3
 *
 */


/*
 * Exercise 2.38:
 * Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype
 * will deduce the same type and an example where they will deduce differing types.
 * The way decltype handles top-level const and references differs subtly from the way auto does. Another important difference between decltype and auto
 * is that the deduction done by decltype depends on the form of its given expression.
 * so the key of difference is subtly and form.
 * int i = 0, &r = i;
 * // same
 * auto a = i;
 * decltype(i) b = i;
 * // different "c" will be int "d" will be int&
 * auto c = r;
 * decltype(r) d = r;
 */






/*
 * When we ask for a reference to an auto-deduced type, top-level consts in the initializer are not ignored.
 */
void typeInfers() {
    int i = 0, &r = i;
    auto a = r; // a is an int
    const int ci = i, &cr = ci;
    auto b = ci;//b is an int
    auto c = cr;//c is an int
    auto d = &i;//d is a pointer to i
    auto e = &ci;//e is a pointer to a const int
    const auto f = ci;// f is a const int
    auto &g = ci;// g is a const int & that is bound to ci;
//    auto &h = 42; Error:we can't bind a plain reference to a literal
    const auto &j = 42;// j is a const int&
    auto k = ci, &l = i;// k is  int , l is int&
    auto &m = ci, *p = &ci;//m is const int& ,p is a pointer to const int
//    auto &n = i, *p2 = &ci;error: type deduced from i is int; type deduced from &ci is const int


    a = 42; b = 42; c = 42;
//    d = 42; e = 42; g = 42;


    {
        const int i = 42;
        auto j = i;//j is an int
        const auto &k = i;//k is const int &
        auto *p = &i;// p is a pointer to const int
        const auto j2 = i, &k2 = i;//j2 is const int, k2 is const int&
    }

    {
        const int ci = 0, &cj = ci;
        decltype(ci) x = 0; // const int
        decltype(cj) y = x;// const int &
//        decltype(cj) z;error: ‘z’ declared as reference but not initialized

        int i = 42, *p = &i, &r = i;
        decltype(r + 0) b;//b is an int
//        decltype(*p) c; error: c is int& and must be initialized
//        decltype((i)) d;error: ‘d’ declared as reference but not initialized
        decltype(i) e; // ok: e is an (uninitialized) int
    }

    /*
     * Remember that decltype(( variable )) (note, double parentheses) is always
     * a reference type, but decltype( variable ) is a reference type only if variable
     * is a reference.
     */


}



/*
 * Exercise 2.39:
 * Compile the following program to see what happens when you forget the semicolon after a class definition.
 * Remember the message for future reference.
 * Answer:error: expected ‘;’ after struct definition
 */
//struct Foo {}


/*
 * Exercise 2.40:
 * Write your own version of the Sales_data class.
 * @see SalesData.h
 */

/*
 * Exercise 2.41:
 * Use your Sales_data class to rewrite the exercises in § 1.5.1(p. 22),
 * § 1.5.2(p. 24), and § 1.6(p. 25).
 * For now, you should define your Sales_data class in the same file as your main function.
 * @see SalesData.h
 */


/*
 * Exercise 2.42:
 * Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2(p. 76)
 * @see SalesData.h
 */



int main() {
    typeInfers();
    constQualifier();
    usedPointer();
    useCompoundType();
    showResults();
    return 0;
}