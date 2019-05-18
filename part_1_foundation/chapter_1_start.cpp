//
// Created by shiqing on 19-4-11.
//


#include "../common/CommonHeaders.h"
#include "Sales_item.h"


/*
 *  exercise_1.1: .cc .cxx .cpp .cp .C 为通用的文件后缀名约定 头文件有.h .H .hpp .hxx
 *
 *  exercise_1.2: return -1; g++ -o compile_test chapter_1_start.cpp ./compile_test echo $? 255
 *  return -2; 254 ....
 *
 *
 *
 */


void sumOfNums() {
    cout << "Enter two numbers:" << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2
         << " is " << v1 + v2 << endl;

}

/*
 * Exercise 1.3: Write a program to print Hello, World on the standard output.
 */
void sayHello() {
    cout << "Hello, World" << endl;
}

/*
 *  Exercise 1.4:
 *  Our program used the addition operator, +, to add two numbers.
 *  Write a program that uses the multiplication operator, *, to print the product instead.
 */
void multiOfNums() {
    cout << "Enter two numbers: " << endl;
//    初始化一个变量就是在变量创建的同时为它赋予一个值
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    cout << "The multiply of " << v1 << " and " << v2
         << " is " << v1 * v2 << endl;

}

/*
 * Exercise 1.5:
 * We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.
 */
void rewrite() {
    cout << "Enter two numbers: " << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    cout << "The multiply of";
    cout << v1;
    cout << " and ";
    cout << v2;
    cout << " is ";
    cout << v1 * v2;
    cout << endl;
}


/*
 * Exercise 1.6: Explain whether the following program fragment is legal.
    std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;


    If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?
    Answer: the program is not legal, The output operators of the second and third rows lack the output object on the left.
 */

/*
 * Exercise 1.7: Compile a program that has incorrectly nested comments.
 *  /*
     * 注释对/* */ /*不能嵌套
 * error: stray  ‘\344’ in program
 */



//Exercise 1.8: Indicate which, if any, of the following output statements are
//legal:
//
//
//std::cout << "/*";
//std::cout << "*/";
//std::cout << /* "*/" */;
//std::cout << /*  "*/" /* "/*"  */;
//
//After you’ve predicted what will happen, test your answers by compiling a
//program with each of these statements. Correct any errors you encounter.

//Answers:
//cout << "/*";
//cout << "*/";
//cout << /* "*/" */";
//cout << /* "*/" /* "/*" */;

/*
 * Exercise 1.9: Write a program that uses a while to sum the numbers from 50 to 100.
 */

void sumOf50_100() {
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout << "Sum the numbers from 50 and 100 is " << sum << endl;
}

/*
 * Exercise 1.10:
 * In addition to the ++ operator that adds 1 to its operand,
 * there is a decrement operator (--) that subtracts 1. Use the decrement
 * operator to write a while that prints the numbers from ten down to zero.
 */

void printTenToOne() {
    int val = 10;
    while (0 <= val) {
        cout << val << " ";
        --val;
    }
    cout << endl;
}

/*
 * Exercise 1.11:
 * Write a program that prompts the user for two integers.
 * Print each number in the range specified by those two integers.
 */

void printRangeNums() {
    cout << "Enter two numbers: " << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    if (v2 < v1) {
        std::swap(v1, v2);
    }
    while (v1 <= v2) {
        cout << v1 << " ";
        ++v1;
    }
    cout << endl;
}


/*
 * Exercise 1.12: What does the following for loop do? What is the final value of sum?


    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;

   Answer: 0

 */

/*
 * Exercise 1.13: Rewrite the exercises from § 1.4.1 (p. 13) using for loops.
 */

void sumOf50_100UseFor() {
    int sum = 0;
    for (int i = 50; i <= 100; ++i) {
        sum += i;
    }
    cout << "Sum the numbers from 50 and 100 is " << sum << endl;
}

void printTenToOneUseFor() {
    for (int i = 10; i != -1; --i) {
        cout << i << " ";
    }
    cout << endl;
}

void printRangeNumsUseFor() {
    int v1 = 0, v2 = 0;
    cout << "Enter two numbers:" << endl;
    cin >> v1 >> v2;
    if (v2 < v1) {
        std::swap(v1, v2);
    }
    for (; v1 <= v2; ++v1) {
        cout << v1 << " ";
    }
    cout << endl;
}

/*
 * Exercise 1.14:
 * Compare and contrast the loops that used a for with those
 * using a while. Are there advantages or disadvantages to using either form?
 * Answer:
 * In our while loop we used the variable val to control how many times we executed
 * the loop. We tested the value of val in the condition and incremented val in the while body.
 * This pattern—using a variable in a condition and incrementing that variable in the
 * body—happens so often that the language defines a second statement, the for
 * statement, that abbreviates(简化) code that follows this pattern.
 */


/*
 * Exercise 1.15:
 * Write programs that contain the common errors discussed in
 * the box on page 16. Familiarize yourself with the messages the compiler generates.
 */


/*
 * Exercise 1.16:
 * Write your own version of a program that prints the sum of
 * a set of integers read from cin.
 */
void sumOfNumsFromCin() {
    int val = 0, sum = 0;
    while (cin >> val) {
        sum += val;
    }
    cout << "the sum of nums from cin is " << sum << endl;
}


void countOrderedNums() {
    cout << "please enter a set of ordered numbers: " << endl;
    int currVal = 0, val = 0;
    if (cin >> currVal) {
        int cnt = 1;
        while (cin >> val) {
            if (val == currVal) {
                ++cnt;
            } else {
                cout << currVal << " occurs "
                     << cnt << " times." << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs "
             << cnt << " times." << endl;
    }
}

/*
 * Exercise 1.17: What happens in the program presented in this section if the
 * input values are all equal? What if there are no duplicated values?
 * answer:correct behavior
 */

/*
 * Exercise 1.18: Compile and run the program from this section giving it only
 * equal values as input. Run it again giving it values in which no number is repeated.
 * answer:correct behavior
 */

/*
 * Exercise 1.19:
 * Revise the program you wrote for the exercises in § 1.4.1 (p.13)
 * that printed a range of numbers so that it handles input in which the first number is smaller than the second.
 * answer: already done.
 */


/*
 *Exercise 1.20:
 * http://www.informit.com/title/032174113 contains a copy of
 * Sales_item.h in the Chapter 1 code directory. Copy that file to your
 * working directory. Use it to write a program that reads a set of book sales transactions,
 * writing each transaction to the standard output.
 * answer: function @addSameSaleItems();
 */


/*
 * Exercise 1.21:
 * Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.
 * Exercise 1.22:
 * Write a program that reads several transactions for the same ISBN .
 * Write the sum of all the transactions that were read.
 * answer: function @addSameSaleItems();
 */




void addSameSaleItems() {
    Sales_item item, total;
    while (cin >> item) {
        total += item;
    }
    cout << total << endl;
}

/*
 * Exercise 1.23:
 * Write a program that reads several transactions and counts
 * how many transactions occur for each ISBN .
 * Exercise 1.24:
 * Test the previous program by giving multiple transactions
 * representing multiple ISBN s. The records for each ISBN should be grouped together.
 * answer:@function countOrderedSaleItems();
 */
void countOrderedSaleItems() {
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (trans.isbn == total.isbn) {
                total += trans;
            } else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        std::cerr << "No data?!" << endl;
    }

}

/*
 * Exercise 1.25: Using the Sales_item.h header from the Web site,
 * compile and execute the bookstore program presented in this section.
 *
 * answer:already done.
 */





int main() {
//    addSameSaleItems();
    countOrderedNums();
    sumOfNumsFromCin();
    printRangeNums();
    printRangeNumsUseFor();
    printTenToOne();
    printTenToOneUseFor();
    sumOf50_100();
    sumOf50_100UseFor();
    sayHello();
    sumOfNums();
    multiOfNums();
    rewrite();
    return 0;
}
