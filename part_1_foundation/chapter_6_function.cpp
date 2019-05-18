//
// Created by shiqing on 19-4-21.
//
#include <assert.h>
#include "../common/CommonHeaders.h"
#include "Chapter6.h"
//#define NDEBUG
/*
 * Exercise 6.1:
 * What is the difference between a parameter and an argument?
 * Answer:
 * Parameters: Local variable declared inside the function parameter list.
 * they are initialized by the arguments provided in the each function call.
 * Arguments: Values supplied in a function call that are used to initialize the function's parameters.
 */


/*
 * Exercise 6.2:
 * (a) string f() {  // return should be string, not int
 * string s;// ...
 * return s;
 * }
 * (b) void f2(int i) {    // function needs return type//
 * (c) int calc(int v1, int v2) {  }  // parameter list cannot use same name twice
 * (d) double square (double x) { return x * x; }  // function body needs braces
 */


/*
 * Exercise 6.3: Write and test your own version of fact.
 */

int factorial(int n) {
    if (!n) return 1;
    int res = 1;
    while (n) {
        res *= n--;
    }
    return res;
}

/*
 * Exercise 6.4:
 * Write a function that interacts with the user, asking for a
 * number and generating the factorial of that number. Call this function from main.
 *
 */

void testingFactorial() {
    cout << "enter a number and generating the factorial is: " << endl;
    int n;
    cin >> n;
    cout << "the factorial is: " << factorial(n) << endl;
}


/*
 * Exercise 6.5: Write a function to return the absolute value of its argument.
 */

int absOfNum(int x) {
    return x < 0 ? -x : x;
}


/*
 * Exercise 6.6;
 * local variable: Variables defined inside a block;
 * parameter: Local variables declared inside the function parameter list
 * local static variable: local static variable（object）
 * is initialized before the first time execution passes through the object’s definition.
 * Local statics are not destroyed when a function ends;
 * they are destroyed when the program terminates.
 * @see accumulate();
 */

size_t accumulate(size_t n) {
    static size_t sum = 0;
    sum += n;
    return sum;
}


/*
 * Exercise 6.7:
 * Write a function that returns 0 when it is first called and the
 * generates numbers in sequence each time it is called again.
 *
 */

/*
 * Exercise 6.8:
 * Write a header file named Chapter6.h that contains
 * declarations for the functions you wrote for the exercises in § 6.1 (p. 205).
 *
 * Answer:
 * already be done.
 */



size_t countCalls() {
    static size_t cnt = 0;
    return cnt++;
}

void testingCountCalls() {
    for (int i = 0; i != 10; ++i) {
        cout << countCalls() << " ";
    }
    cout << endl;
}


void testingAccumulate() {
    for (int i = 0; i != 10; ++i) {
        cout << accumulate(i) << " ";
    }
    cout << endl;
}

/*
 * Exercise 6.10:
 * Using pointers, write a function to swap the values of two
 * ints. Test the function by calling it and printing the swapped values.
 * @see swapByPointer();
 */

void swapByPointer(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void testingSwapByPointer() {
    int a = 5, b = 4;
    swapByPointer(&a, &b);
    cout << "a = " << a << ", b= " << b << endl;
}

/*
 * Exercise 6.11: Write and test your own version of reset that takes a reference.
 */

void reset(int &i) {
    i = 0;
}

void testingReset() {
    int n = 5;
    reset(n);
    cout << "n = " << n << endl;
}

/*
 * Exercise 6.12:
 * Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
 * to use references instead of pointers to swap the value of two ints. Which
 * version do you think would be easier to use and why?
 */

void swapByReference(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void testingSwapByReference() {
    int a = 5, b = 4;
    swapByReference(a, b);
    cout << "a = " << a << ", b = " << b << endl;
}


/*
 * Exercise 6.13:
 * Assuming T is the name of a type, explain the difference
 * between a function declared as void f(T) and void f(T&).
 *
 * Answer:
 * void f(T) pass the argument by value. nothing the function does to the parameter can affect the argument.
 * void f(T&) pass a reference, will be bound to whatever T object we pass.
 */

/*
 * Exercise 6.14:
 * Give an example of when a parameter should be a reference
 * type. Give an example of when a parameter should not be a reference.
 *
 * a parameter should be a reference type:
 * void reset(int &i){
 *      i = 0;
 * }
 *
 * a parameter should not be a reference:
 * void print(std::vector<int>::iterator begin, std::vector<int>::iterator end){
 *      for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
 *          std::cout << *iter << std::endl;
 *      }
 */

/*
 * Exercise 6.15:
 * why is s a reference to const but occurs is a plain reference?
 * Because s should not be changed by this function, but occurs result must be calculated by the function.
 * Why are these parameters references, but the char parameter c is not?
 * Because c may be a temp varable, such as find_char(s, 'a', occurs)
 * What would happen if we made s a plain reference? What if we made occurs a reference to const
 * s could be changed in the function, and occurs would not be changed. so occurs = 0; is an error.
 */


/*
 * Exercise 6.16:
 * The following function, although legal, is less useful than it
 * might be. Identify and correct the limitation on this function:
 * bool is_empty(string& s) { return s.empty(); }
 *
 * Answer:parameter should be const string &s
 */

/*
 * Exercise 6.17:
 * Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do
 * the parameters you used in these functions have the same type? If so, why?
 * If not, why not?
 *
 * @see isContainsCapitalLetters();
 * @see toLower();
 */

bool isContainsCapitalLetters(const string &s) {
    for (const auto &e : s) {
        if (isupper(e)) {
            return true;
        }
    }
    return false;
}

void toLower(string &s) {
    for (auto &e : s) {
        e = tolower(e);
    }
}


/*
 * Exercise 6.18: Write declarations for each of the following functions. When
 * you write these declarations, use the name of the function to indicate what
 * the function does.
 * (a) A function named compare that returns a bool and has two parameters
 * that are references to a class named matrix.
 * (b) A function named change_val that returns a vector<int> iterator
 * and takes two parameters: One is an int and the other is an iterator for a
 * vector<int>.
 */


class Matrix;

bool compare(const Matrix &m1, const Matrix &m2);

vector<int>::iterator change_val(int, vector<int>::iterator);


/*
 * Exercise 6.19:
 * Given the following declarations, determine which calls are
 * legal and which are illegal. For those that are illegal, explain why.
 * already be done.
 */


/*
 * Exercise 6.20:
 * When should reference parameters be references to const?
 * What happens if we make a parameter a plain reference when it could be a
 * reference to const?
 * Answer:
 * If we can use const, just use it.
 * If we make a parameter a plain reference when it could be a reference to const, the reference value maybe changed.
 */



/*
 * Regardless of appearances, these declarations are equivalent: Each declares a function
 * with a single parameter of type const int*.
 */
void printArr(const int *a) {};
//void print(const int a[]){};error: redefinition of ‘void print(const int*)’
//void print(const int a[10]){};error: redefinition of ‘void print(const int*)’

void testingPrintArr() {
    int i = 0, j[2] = {0, 1};
    printArr(&i);//ok &i is int *
    printArr(j);//// ok: j is converted to an int* that points to j[0]

}

/*
 * Exercise 6.21:
 * Write a function that takes an int and a pointer to an int
 * and returns the larger of the int value or the value to which the pointer
 * points. What type should you use for the pointer?
 * @see maxNumOf();
 */
int maxNumOf(int x, int *p) {
    if (p) {
        return x > *p ? x : *p;
    }
    return x;
}


/*
 * Exercise 6.22: Write a function to swap two int pointers.
 * @see swapPointer();
 */

void swapPointer(int *&a, int *&b) {
    int *p = b;
    b = a;
    a = p;
}


/*
 * Exercise 6.23: Write your own versions of each of the print functions
 * presented in this section. Call each of these functions to print i and j
 * defined as follows:
 * int i = 0, j[2] = {0, 1};
 * @see printOwn();
 */

void printOwn(int *beg, int *end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}


/*
 * Exercise 6.24:
 * Explain the behavior of the following function. If there are
 * problems in the code, explain what they are and how you might fix them.
 * void print(const int ia[10]){
 *      for (size_t i = 0; i != 10; ++i)
 *          cout << ia[i] << endl;
 * }
 * Answer:
 * In this question, const int ia[10] is actually same as const int*,
 * and the size of the array is irrelevant.
 * we can pass const int ia[3] or const int ia[255], there are no differences.
 * If we want to pass an array which size is ten, we should use reference like that:
 */



void testingAboveTwoFunctions() {
    int x = 3, y = 5, *p = &y;
    cout << maxNumOf(x, p) << endl;

    int *px = &x;
    swapPointer(px, p);
    cout << "*px = " << *px << ", *p = " << *p << endl;
    int i = 0, j[2] = {0, 1};
    cout << "------------------------" << endl;
    printOwn(&i, &i);
    printOwn(j, j + 2);
    cout << "------------------------" << endl;
}

/*
 * Exercise 6.25:
 * Write a main function that takes two arguments.
 * Concatenate the supplied arguments and print the resulting string.
 * @see main();
 */


/*
 * Exercise 6.26:
 * Write a program that accepts the options presented in this
 * section. Print the values of the arguments passed to main.
 * @see main();
 */


/*
 * Exercise 6.27:
 * Write a function that takes an initializer_list<int>
 * and produces the sum of the elements in the list.
 * @see sumOfInitializerList();
 */

void sumOfInitializerList(std::initializer_list<int> nums) {
    int sum = 0;
    for (const auto &item : nums) {
        sum += item;
    }
    cout << "the sum of the initializer list is: " << sum << endl;
}

void testingSumOfInitializerList() {
    sumOfInitializerList({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

}


/*
 * Exercise 6.28:
 * In the second version of error_msg that has an ErrCode
 * parameter, what is the type of elem in the for loop?
 * Answer:
 * const string &
 */


/*
 * Exercise 6.29:
 * When you use an initializer_list in a range for
 * would you ever use a reference as the loop control variable? If so, why? If
 * not, why not?
 * Answer:
 * Depends on the type of elements of initializer_list. When the type is PODType, reference is unnecessary.
 * Because POD is cheap to copy(such as int). Otherwise, Using reference(const) is the better choice.
 */


/*
 * Exercise 6.30:
 * Error (Clang):
 * Non-void function 'str_subrange' should return a value. // error #1
 * Control may reach end of non-void function. // error #2
 *
 */


/*
 * Exercise 6.31: When is it valid to return a reference? A reference to const?
 * Answer:
 * when you can find the preexisting object that the reference refered.
 */


/*
 * Exercise 6.32:
 * Indicate whether the following function is legal. If so, explain
 * what it does; if not, correct any errors and then explain it.
 * Answer:
 * legal, it gave the values (0 ~ 9) to array ia.
 */



bool strSubRange(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) {
        return s1 == s2;
    }
    auto sz = s1.size() < s2.size() ? s1.size() : s2.size();
    for (decltype(sz) i = 0; i != sz; ++i) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}


/*
 * Exercise 6.33: Write a recursive function to print the contents of a vector.
 * @see printRecursiveVec();
 */

void printRecursiveVec(vector<int>::iterator it, vector<int>::iterator end) {
    if (it == end) return;
    cout << *it << " ";
    return printRecursiveVec(++it, end);
}

void testingPrintRecursiveVec() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
#ifndef NDEBUG
    cout << "the size of the vector is: "
         << vi.size() << endl;
    cout << "Info: " << __FILE__ << " : in function "
         << __func__ << " at line " << __LINE__ << '\n'
         << "\tCompiled on " << __DATE__
         << " at " << __TIME__ << '\n';
#endif
    printRecursiveVec(vi.begin(), vi.end());
}

/*
 * Exercise 6.34:
 * When the recursion termination condition becomes var != 0, two situations can happen :
 * case 1 : If the argument is positive, recursion stops at 0.
 * (Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1.
 * In terms of programming languages learning, such subtle difference probably looks quite trivial.
 * In algorithms analysis and proof, however, this extra step may be super important.)
 * case 2 : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.
 */

/*
 * Exercise 6.35: In the call to fact, why did we pass val - 1 rather than val--?
 * Answer:
 * Multiplication operators do not specify the order of evaluation.
 * Expressions that act on the same object at the same time cause inconsistencies in object values.
 */


/*
 * Declaring a Function That Returns a Pointer to an Array
 * for example:
 * Type (*function(parameter_list))[dimension]
 */

int array[10];

int (*returnArrayPointer(int x, int *p))[10] {
    return &array;
}

/*
 * Exercise 6.36:
 * Write the declaration for a function that returns a reference
 * to an array of ten strings, without using either a trailing return,
 * decltype, or a type alias.
 */

string (&returnArrayRef(const string &s))[10];

/*
 * Exercise 6.37:
 * Write three additional declarations for the function in the previous exercise.
 * One should use a type alias, one should use a trailing
 * return, and the third should use decltype. Which form do you prefer and why?
 *
 */

auto returnArrayRef(const string &s) -> string (&)[10];

using StrRef = string (&)[10];

//typedef string (&StrRef)[10];
StrRef returnArrayRef(const string &s);

string strArr[10];

decltype(strArr) &returnArrayRef(const string &s);

/*
 * Exercise 6.38: Revise the arrPtr function on to return a reference to the array.
 * @see above.
 */


/*
 * Exercise 6.39:
 * Explain the effect of the second declaration in each one of
 * the following sets of declarations. Indicate which, if any, are illegal.
 * Answer:
 * (a) legal, repeated declarations(without definition) are legal in C++
 * (b) illegal, only the return type is different
 * (c) legal, the parameter type is different and return type is changed
 */

/*
 * Exercise 6.40: Which, if either, of the following declarations are errors? Why?
 * Answer:
 * (a) no error
 * (b) Missing default argument on parameter 'wd', 'bckgrnd'.
 */


/*
 * Exercise 6.41:
 * Which, if any, of the following calls are illegal? Why? Which,
 * if any, are legal but unlikely to match the programmer’s intent? Why?
 * Answer:
 * (a) illegal. No matching function for call to 'init'.
 * (b) legal, and match.
 * (c) legal, but not match. wd whould be setting to '*'.
 */



/*
 * Exercise 6.42:
 * Give the second parameter of make_plural (§ 6.3.2, p.224) a default argument of 's'.
 * Test your program by printing singular and
 * plural versions of the words success and failure.
 * @see makePlural();
 */


string makePlural(int crl, const string &s, const string &e = "s") {
    return crl > 1 ? s + e : s;
}

void testingMakePlural() {
    string word("success"), other("failure");
    cout << makePlural(2, other);
    cout << makePlural(2, word, "es");
}

/*
 * Exercise 6.43: Which one of the following declarations and definitions would
 * you put in a header? In a source file? Explain why.
 * Answer:
 * Both two should put in a header.
 * (a) is an inline function.
 * (b) is the declaration of useful function. we always put them in the header.
 */


/*
 * Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
 * @see isShorter();
 */

/*
 * Exercise 6.45:
 * Review the programs you’ve written for the earlier exercises
 * and decide whether they should be defined as inline. If so, do so. If not,
 * explain why they should not be inline.
 * Answer:
 * For example, the function arrPtr in [Exercise 6.38](# Exercise-638) and make_plural
 * in [Exercise 6.42](# Exercise-642) should be defined as inline.
 * But the function func in [Exercise 6.4](# Exercise-64) shouldn't.
 * It is not that small and it's only being called once.
 * Hence, it will probably not expand as inline.
 */
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

/*
 * Exercise 6.46:
 * Would it be possible to define isShorter as a constexpr?
 * If so, do so. If not, explain why not.
 * Answer:
 * Because std::string::size() is not a constexpr function and s1.size() == s2.size() is not a constant expression.
 */
//error: call to non-constexpr function
/*
constexpr bool isShorterOther(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}
*/

void testingIsShorter() {
    string s1("hello"), s2("world!");
    cout << isShorter(s1, s2) << endl;
//    cout << isShorterOther(s1, s2) << endl;
}

/*
 * Exercise 6.47:
 * Revise the program you wrote in the exercises in § 6.3.2 (p.228)
 * that used recursion to print the contents of a vector to conditionally
 * print information about its execution. For example, you might print the size of
 * the vector on each call. Compile and run the program with debugging
 * turned on and again with it turned off.
 * @see testingPrintRecursiveVec();
 */


/*
 * Exercise 6.48: Explain what this loop does and whether it is a good use of
 * assert:
 *
 * Answer:
 * This loop let user input a word all the way until the word is sought.
 * It isn't a good use of assert. because if user begin to input a word,
 * the cin would be always have content. so the assert would be always true.
 * It is meaningless. using assert(s == sought) is better.
 */

void f() {
    cout << "f()" << endl;
}

void f(int) {
    cout << "f(int)" << endl;
}
void f(int, int) {
    cout << "f(int, int)" << endl;
}

void f(double, double = 3.14) {
    cout << "f(double, double = 3.14)" << endl;
}

/*
 * Exercise 6.49: What is a candidate function? What is a viable function?
 * candidate function:
 * Set of functions that are considered when resolving a function call.
 * (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)
 *
 * viable function:
 * Subset of the candidate functions that could match a given call.
 * It have the same number of parameters as arguments to the call,
 * and each argument type can be converted to the corresponding parameter type.
 */


/*
 * Exercise 6.50: Given the declarations for f from page 242, list the viable
 * functions, if any for each of the following calls. Indicate which function is the
 * best match, or if the call is illegal whether there is no match or why the call
 * is ambiguous.
 *
 * @see testingOverload();
 */


/*
 * Exercise 6.51:
 * Write all four versions of f. Each function should print a
 * distinguishing message. Check your answers for the previous exercise. If your
 * answers were incorrect, study this section until you understand why your
 * answers were wrong.
 *
 * @see testingOverload();
 */

void testingOverload() {
//    f(2.25, 42);error: call of overloaded ‘f(double, int)’ is ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}

/*
 * Exercise 6.52:
 * Answer:
 * (a) Match through a promotion
 * (b) Arithmetic type conversion
 */

/*
 * Exercise 6.53
 * (a)
 * int calc(int&, int&); // calls lookup(int&)
 * int calc(const int&, const int&); // calls lookup(const int&)
 *
 * (b)
 * int calc(char*, char*); // calls lookup(char*)
 * int calc(const char*, const char*); // calls lookup(const char *)
 *
 * (c)
 * illegal. both calls lookup(char*)
 */

/*
 * Exercise 6.54:
 * Write a declaration for a function that takes two int
 * parameters and returns an int, and declare a vector whose elements have
 * this function pointer type.
 *
 * @see testingFuncPtr();
 *
 */


/*
 * Exercise 6.55:
 * Write four functions that add, subtract, multiply, and divide
 * two int values. Store pointers to these values in your vector from the
 * previous exercise.
 *
 * @see testingFuncPtr();
 */

/*
 * Exercise 6.56: Call each element in the vector and print their result.
 *
 * @see testingFuncPtr();
 */

int addNumbs(int x, int y) {
    return x + y;
}

int subtractNumbs(int x, int y) {
    return x - y;
}

int multiplyNumbs(int x, int y) {
    return x * y;
}

int divideNumbs(int x, int y) {
    assert(y != 0);
    return x / y;
}

int funcTemplate(int a, int b) {
    cout << "funcTemplate(int, int)" << endl;
    return a + b;
}


void testingFuncPtr() {
    using FP = int (*)(int, int);
    FP fp = funcTemplate;
    vector<FP> vp = {addNumbs, subtractNumbs, multiplyNumbs, divideNumbs};
    for (const auto &f : vp) {
        cout << f(8, 4) << " ";
    }
    cout << endl;
}


int main(int argc, char *argv[]) {
    testingFuncPtr();
    testingOverload();
    testingIsShorter();
    testingMakePlural();
    cout <<endl;
    cout << "-------------------------" << endl;
    testingPrintRecursiveVec();
    cout << "-------------------------" << endl;
    cout << endl;
    testingSumOfInitializerList();
    for (int i = 1; i != argc; ++i) {
        cout << string(argv[i]) << " ";
    }
    cout << endl;
    string s;
    for (int j = 1; j != argc; ++j) {
        s += string(argv[j]);
    }
    cout << s << endl;
    testingAboveTwoFunctions();
    testingSwapByReference();
    testingReset();
    testingSwapByPointer();
    testingCountCalls();
    testingAccumulate();
    testingFactorial();
    return 0;
}