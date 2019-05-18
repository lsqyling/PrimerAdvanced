//
// Created by shiqing on 19-4-19.
//

#include <random>
#include "../common/CommonHeaders.h"
#include "Sales_item.h"

/*
 * Exercise 4.1:
 * What is the value returned by 5 + 10 * 20/2?
 * Answer:
 * 105
 */


/*
 * Exercise 4.2:
 * Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
 * vec.begin() //=> *(vec.begin())
 * vec.begin() + 1 //=> (*(vec.begin())) + 1
 */


/*
 * Exercise 4.3:
 * Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization.
 * This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the
 * language by the programmer.Do you consider that an acceptable trade-off? Why or why not?
 * Answer:
 * No. IMHO, such design cannot improve performance siginificantly, but it can make bugs very tricky to handle.
 */


/*
 * Exercise 4.4:
 * Parenthesize the following expression to show how it is evaluated.
 * Test your answer by compiling the expression (without parentheses) and printing its result.
 * Answer:91
 */


/*
 * Exercise 4.5:
 * Determine the result of the following expressions.
 * -30 * 3 + 21 / 5  // -90+4 = -86
 * -30 + 3 * 21 / 5  // -30+63/5 = -30+12 = -18
 * 30 / 3 * 21 % 5   // 10*21%5 = 210%5 = 0
 * -30 / 3 * 21 % 4  // -10*21%4 = -210%4 = -2
 */


/*
 * Exercise 4.6:
 * Write an expression to determine whether an int value is even or odd.
 * Answer:
 * i & 0x1
 */



/*
 * Exercise 4.7:
 * What does overflow mean? Show three expressions that will overflow.
 *
 * from the book:
 * Some arithmetic expressions yield undefined results.
 * Some of these undefined espressions are due to the nature of mathematics-for example,
 * division by zero. Others are undefined due to the nature of computers-for example,
 * due to overflow. Overflow happens when a value is computed that is outside the range of values that the type can represent.
 * short svalue = 32767; ++svalue; // -32768
 * unsigned uivalue = 0; --uivalue;  // 4294967295
 * unsigned short usvalue = 65535; ++usvalue;  // 0
 */


/*
 * Exercise 4.8:
 * Explain when operands are evaluated in the logical AND, logical OR, and equality operators.
 * from the book:
 * The logical AND and OR operators always evaluate their left operand before the right. Moreover,
 * the right operand is evaluated if and only if the left operand does not determine the result.
 * This strategy is known as short-circuit evaluation.
 * logical AND : the second operand is evaluated if and only if the left side is true.
 * logical OR : the second operand is evaluated if and only if the left side is false
 * equality operators == : undefined.
 *
 */


/*
 * Exercise 4.9:
 * Explain the behavior of the condition in the following if:
 * const char *cp = "Hello World";
 * if (cp && *cp)
 * cp is a pointer to const char *, and it's not a nullptr. true.
 * *cp is a const char: 'H', and it is explicit a nonzero value. true.
 * true && true -> true.
 */


/*
 * Exercise 4.10:
 * Write the condition for a while loop that would read ints from the standard
 * input and stop when the value read is equal to 42.
 * int i = 0;
 * while(cin >> i && i != 42)
 */

/*
 * Exercise 4.11:
 * Write an expression that tests four values, a, b, c, and d, and ensures that a is greater
 * than b, which is greater than c, which is greater than d.
 * a>b && b>c && c>d
 */


/*
 * Exercise 4.12:
 * Assuming i, j, and k are all ints, explain what i != j < k means.
 * i != j < k is equivalent to i != (j < k).
 */


/*
 * Exercise 4.13: What are the values of i and d after each assignment?
 * int i;   double d;
 * (a) d = i = 3.5;
 * (b) i = d = 3.5;
 *
 * Answer:
 * (a)i = 3;d = 3;
 * (b)i = 3;d = 3.5;
 */

/*
 * Exercise 4.14:
 * Explain what happens in each of the if tests:
 * if (42 = i)   // complie error: expression is not assignable
 * if (i = 42)   // true.
 */

/*
 * Exercise 4.15:
 * The following assignment is illegal. Why? How would you correct it?
 * double dval; int ival; int *pi;
 * dval = ival = pi = 0;
 * // pi is a pointer to int.
 * // can not assign to 'int' from type 'int *'
 * // correct it:
 * dval = ival = 0;
 * pi = 0;
 */

/*
 * Exercise 4.16:
 * Although the following are legal, they probably do not behave as the programmer expects.
 * Why? Rewrite the expressions as you think they should be.
 * if (p = getPtr() != 0)
 * if (i = 1024)
 * // why? always true. use an assigment as a condition.
 * // correct it
 * if ((p=getPtr()) != 0)
 * if (i == 1024)
 */


/*
 * Exercise 4.17:
 * Explain the difference between prefix and postfix increment.
 * See: What is the difference between ++i and i++
 */

/*
 * Exercise 4.18:
 * What would happen if the while loop on page 148 that prints
 * the elements from a vector used the prefix increment operator?
 * Answer:
 * It will print from the second element and dereference v.end() at last, which is a UB.
 */


/*
 * Exercise 4.19:
 * Given that ptr points to an int, that vec is a vector, and that ival is an int,
 * explain the behavior of each of these expressions.
 * Which, if any, are likely to be incorrect? Why? How might each be corrected?
 *
 * Answer:
 * ptr != 0 && *ptr++  // check ptr is not a nullptr, and then check the pointer value.
 * ival++ && ival // check ival, and then check ival+1 whether equal zero.
 * vec[ival++] <= vec[ival] // incorrect. It is an **undefined behavior.**
 * // correct:
 * vec[ival] <= vec[ival+1]
 */


/*
 * Exercise 4.20:
 * Assuming that iter is a vector::iterator, indicate which, if any, of the following expressions are legal.
 * Explain the behavior of the legal expressions and why those that aren’t legal are in error.
 * *iter++;  // return *iter, then ++iter.
 * (*iter)++;  // illegal, *iter is a string, cannot increment value.
 * *iter.empty() // illegal, iter should use '->' to indicate whether empty.
 * iter->empty();  // indicate the iter' value whether empty.
 * ++*iter;        // illegal, string have not increment.
 * iter++->empty();  // return iter->empty(), then ++iter.
 */

/*
 * Exercise 4.21:
 * Write a program to use a conditional operator to find the
 * elements in a vector<int> that have odd value and double the value of
 * each such element.
 *
 * Answer:
 * @see oddToDouble();
 */

void oddToDouble() {
    vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &e : iv) {
        e & 1 ? e *= 2 : e;
    }
    for (const auto &e : iv) {
        cout << e << " ";
    }
    cout << endl;
}


/*
 * Exercise 4.22: Extend the program that assigned high pass, pass, and fail
 * grades to also assign low pass for grades between 60 and 75 inclusive. Write
 * two versions: One version that uses only conditional operators; the other
 * should use one or more if statements. Which version do you think is easier
 * to understand and why?
 *
 * Answer:
 * @see expressions();
 */


/*
 * Exercise 4.23:
 * The following expression fails to compile due to operator precedence.
 * Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
 * string s = "word";
 * string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
 * Operator Precedence: ?: < + Fix it:
 * string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
 *
 */

void expressions() {
    int i = 0;
    /*
     * For operators that do not specify evaluation order, it is an error for an expression to
     * refer to and change the same object.
     */
    cout << i << " " << ++i << endl; //undefined
    int ival1 = 21 / 6;
    int ival2 = 21 / 7;
    int ival = 42;
    double dval = 3.14;
//    ival % dval;error: floating-point operand
    cout << (21 % 6) << endl;
    cout << (21 % 7) << endl;
    cout << (-21 % -8) << endl;
    cout << (21 % -5) << endl;
    cout << (21 / 6) << endl;
    cout << (21 / 7) << endl;
    cout << (-21 / -8) << endl;
    cout << (21 / -5) << endl;

    short shortValue = 32767;
    cout << "++shortValue = " << ++shortValue << endl;
    unsigned uV = 0;
    cout << "--uV = " << --uV << endl;
    unsigned short usV = 65535;
    cout << "++usV = " << ++usV << endl;

    {
        cout << "------------------------" << endl;
        int i;
        double d;
        d = i = 3.5;
        cout << i << d << endl;
        i = d = 3.5;
        cout << i << d << endl;

    }

    std::default_random_engine e;
    std::normal_distribution<> u(75, 5);
    int grade = u(e);

    string finalGrade = grade > 90 ? "high pass" : (grade < 60 ? "fail" : (grade < 75 ? "low pass" : "pass"));
    string finalGradeOther;
    if (grade > 90) finalGradeOther = "high pass";
    else if (grade > 75) finalGradeOther = "pass";
    else if (grade > 60) finalGradeOther = "low pass";
    else finalGradeOther = "fail";

}


/*
 * Exercise 4.24:
 * Our program that distinguished between high pass, pass,
 * and fail depended on the fact that the conditional operator is right associative.
 * Describe how that operator would be evaluated if the operator were left associative.
 * if the operator were left associative.
 * finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
 * would same as :
 * finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
 * if grade > 90, first conditional operator's result is high pass. so the finalgrade is always fail.
 * It's contradictory obviously.
 */


/*
 * Exercise 4.25:
 * What is the value of ~'q' << 6 on a machine with 32-bit
 * ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the
 * bit pattern 01110001?
 * Answer:-7296
 */


/*
 * Exercise 4.26:
 * In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?
 * The C++ standard does not specify the size of integral types in bytes,
 * but it specifies minimum ranges they must be able to hold. The minimum range of unsigned int is 0 to 65535.
 * Since some implementations use only the minimum 16 bits for unsigned int,
 * this could cause undefined behavior.
 */

/*
 * Exercise 4.27:
 * What is the result of each of these expressions?
 * unsigned long ul1 = 3, ul2 = 7;
 * ul1 & ul2 // == 3
 * ul1 | ul2 // == 7
 * ul1 && ul2 // == true
 * ul1 || ul2 // == true
 */


/*
 * Exercise 4.28: Write a program to print the size of each of the built-in types.
 * @see sizeOfOperand();
 */

/*
 * Exercise 4.29:
 * Predict the output of the following code and explain your reasoning.
 * Now run the program. Is the output what you expected? If not, figure out why.
 * @see sizeOfOperand();
 */

/*
 * Exercise 4.30:
 * Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
 * sizeof x + y      // (sizeof x)+y . "sizeof" has higher precedence than binary `+`.
 * sizeof p->mem[i]  // sizeof(p->mem[i])
 * sizeof a < b      // sizeof(a) < b
 * sizeof f()        //If `f()` returns `void`, this statement is undefined, otherwise it returns the size of return type.
 */



/*
 * Exercise 4.31:
 * The program in this section used the prefix increment and decrement operators.
 * Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions?
 * Rewrite the program using postfix operators.
 * postfix will copy itself as return, then increment or decrement. prefix will increment or decrement first,
 * and return itself. so prefix is more effective in this program.(reduce one copy space.)
 * We use prefix and not postfix, just because of the Advice: Use Postfix Operators only When Necessary on §4.5.
 * Increment and Decrement Operators.
 * Advice: Use Postfix Operators only When Necessary
 * Readers from a C background might be surprised that we use the prefix increment in the programs we've written.
 * The reason is simple: The prefix version avoids unnecessary work. It increments the value and returns the incremented version.
 * The postfix operator must store the original value so that it can return the unincremented value as its result.
 * If we don’t need the unincremented value, there’s no need for the extra work done by the postfix operator.
 * For ints and pointers, the compiler can optimize away this extra work. For more complicated iterator types,
 * this extra work potentially might be more costly. By habitually using the prefix versions,
 * we do not have to worry about whether the performance difference matters.
 * Moreover—and perhaps more importantly—we can express the intent of our programs more directly.
 * So, it's just a good habits. And there are no changes if we have to be made to use the postfix versions.
 * Rewrite:
 * for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
 * ivec[ix] = cnt;
 * This is not an appropriate example to discuss the difference of prefix and postfix.
 */


/*
 * Exercise 4.33:
 * Using Table 4.12 (p. 166) explain what the following expression does:
 * someValue ? ++x, ++y : --x, --y
 * Because of the most lowest precedence of the comma operator, the expression is same as:
 * (someValue ? ++x, ++y : --x), --y
 * If someValue is true, then ++x, and the result is y, if someValue is false, then --x, and the result is --y. so it is also same as:
 * someValue ? (++x, y) : (--x, --y);
 * Even though the result has nothing to do with x, the evaluation of someValue does effect the operation on x.
 */

void commaOperand() {
    vector<int> iv = {1, 2, 3, 4, 5, 6};

    auto cnt = iv.size();
    for (decltype(iv.size()) i = 0; i != iv.size(); ++i, --cnt) {
        iv[i] = cnt;
    }

    for (auto &e : iv) {
        cout << e << " ";
    }
    cout << endl;
}

void sizeOfOperand() {

    Sales_item item, *p;
    int *ip;
    double *dp;
    cout << "sizeof(Sales_item) = " << sizeof(Sales_item) << endl;
    cout << "sizeof(item) = " << sizeof(item) << endl;
    cout << "sizeof(p) = " << sizeof(p) << endl;
    cout << "sizeof(*p) = " << sizeof(*p) << endl;
    cout << "sizeof(string) = " << sizeof(string) << endl;
    cout << "sizeof(ip) = " << sizeof(ip) << endl;
    cout << "sizeof(dp) = " << sizeof(dp) << endl;
    cout << "------------------------" << endl;
    cout << sizeof(bool) << endl;
    cout << "------------------------" << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(signed char) << endl;
    cout << sizeof(unsigned char) << endl;
    cout << sizeof(wchar_t) << endl;
    cout << sizeof(char16_t) << endl;
    cout << sizeof(char32_t) << endl;
    cout << "------------------------" << endl;

    cout << sizeof(short) << endl;
    cout << sizeof(unsigned short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(unsigned) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(unsigned long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(unsigned long long) << endl;
    cout << "------------------------" << endl;

    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long double) << endl;
    cout << "------------------------" << endl;
//    cout << sizeof(void) << endl; warning: invalid application of ‘sizeof’ to a void type [-Wpointer-arith]

    {
        int x[10];
        int *p = x;
        cout << sizeof(x) / sizeof(*x) << endl;
        cout << sizeof(p) / sizeof(*p) << endl;

    }
}


/*
 * Exercise 4.34:
 * Given the variable definitions in this section, explain what conversions take place in the following expressions:
 * (a) if (fval) (b) dval = fval + ival; (c) dval + ival * cval;
 * Remember that you may need to consider the associativity of the operators.
 * if (fval) // fval converted to bool
 * dval = fval + ival; // ival converted to fval, then the result of fval add ival converted to double.
 * dval + ival * cval; // cval converted to int, then that int and ival converted to double.
 */


/*
 * Exercise 4.35:
 * Given the following definitions,
 * char cval; int ival; unsigned int ui; float fval; double dval;
 * identify the implicit type conversions, if any, taking place:
 * cval = 'a' + 3; // 'a' promoted to int, then the result of ('a' + 3)(int) converted to char.
 * fval = ui - ival * 1.0; // ival converted to double , ui also converted to double. then that double converted(by truncation) to float.
 * dval = ui * fval; // ui promoted to float. then that float converted to double.
 * cval = ival + fval + dval;  // ival converted to float, then that float and fval converted to double. At last, that double converted to char(by truncation).
 */


/*
 * Exercise 4.36:
 * Assuming i is an int and d is a double write the expression i *= d so that it does integral,
 * rather than floating-point, multiplication.
 * i *= static_cast<int>(d);
 */


/*
 * Exercise 4.37:
 * Rewrite each of the following old-style casts to use a named cast:
 * @see explicitCast();
 */


/*
 * Exercise 4.38:
 * Explain the following expression:
 * double slope = static_cast<double>(j/i);
 * Answer:
 * j/i is an int(by truncation), then converted to double and assigned to slope.
 */


void explicitCast() {
    int i, j;
    double slope = static_cast<double>(i) / j;
    double d;
    void *p = &d;
    double *dp = static_cast<double*>(p);

    const char *cp = "hello world";
    char *ptr = const_cast<char*>(cp);
//    char *q = static_cast<char*>(cp);error: invalid static_cast from type ‘const char*’ to type ‘char*’
    static_cast<string>(cp);
    int *ip;
    char *pi = reinterpret_cast<char*>(ip);


    {
        int i; double d;
        const string *ps;
        char *pc;
        void *pv;
        i *= static_cast<int>(d);

        pv = const_cast<string*>(ps);
        i = reinterpret_cast<long>(pc);
        pv = &d;
        pc = static_cast<char*>(pv);
    }


}


int main(int argc, char *argv[]) {
    expressions();
    oddToDouble();
    sizeOfOperand();
    commaOperand();

    return 0;
}



