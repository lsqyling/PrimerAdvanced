//
// Created by shiqing on 19-5-2.
//
#include <fstream>
#include <random>
#include <cstring>
#include "../common/CommonHeaders.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "TextQuery.h"

/*
 * Exercise 12.1: How many elements do b1 and b2 have at the end of this code?
 * StrBlob b1;
 * {
 *      StrBlob b2 = {"a", "an", "the"};
 *      b1 = b2;
 *      b2.push_back("about");
 *  }
 *  Answer: b1.size() = 4, b2 out of scope.
 *
 *
 *
 *  Exercise 12.2: Write your own version of the StrBlob class including the const versions of front and back.
 *  @see class StrBlob.
 *
 *
 *
 *  Exercise 12.3: Does this class need const versions of push_back and
 *  pop_back? If so, add them. If not, why aren’t they needed?
 *  Answer:
 *  You can certainly do this if you want to, but there doesn't seem to be any logical reason.
 *  The compiler doesn't complain because this doesn't modify data (which is a pointer) but rather the thing data points to,
 *  which is perfectly legal to do with a const pointer. by David Schwartz.
 *
 *
 *
 *
 * Exercise 12.4: In our check function we didn’t check whether i was greater than zero. Why is it okay to omit that check?
 * Answer: The type of i is vector<string>::size_type which is unsigned.
 *
 *
 *
 * Exercise 12.5: We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and
 * cons of this design choice.
 * Answer:
 *Pros
 * The compiler will not use this constructor in an automatic conversion.
 * We can realize clearly which class we have used.
 *Cons
 * We always uses the constructor to construct a temporary StrBlob object.
 * cannot use the copy form of initialization with an explicit constructor. not easy to use.
 */




/*
 * Exercise 12.6: Write a function that returns a dynamically allocated vector of ints.
 * Pass that vector to another function that reads the standard input to give values to the elements.
 * Pass the vector to another function to print the values that were read.
 * Remember to delete the vector at the appropriate time.
 * @see printRawPointerToVec();
 *
 *
 * Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
 * @see printSharedPtrToVec();
 *
 *
 * Exercise 12.8: Explain what if anything is wrong with the following function.
 * bool b() {
 * int* p = new int;
 * // ...
 * return p;
 * }
 *
 * Answer: memory leak.
 *
 *
 * Exercise 12.9: Explain what happens in the following code:
 * int *q = new int(42), *r = new int(100); r = q;
 * auto q2 = make_shared<int>(42), r2 = make_shared<int>(100); r2 = q2;
 * Answer:
 * new int(42) can't be free.
 * legal.shared_ptr can be free.
 */

const string small_numbers_text = "../../part_2_stdlib/small_numbers.txt";

inline vector<unsigned> *makeRawVecObj() {
    return new vector<unsigned>;
}

vector<unsigned> *read(vector<unsigned> *vp) {
    if (!vp) return new vector<unsigned>;
    std::ifstream in(small_numbers_text);
    unsigned n;
    while (in >> n) {
        vp->push_back(n);
    }
    return vp;
}

void printRawPointerToVec(vector<unsigned> *vp) {
    if (!vp) return;
    int cnt = 0;
    for (const auto &item : *vp) {
        cout << item << " ";
        if (++cnt % 7 == 0) cout << "\n";
    }
    delete vp;
}


inline shared_ptr<vector<int>> makeSharedPtrToVector() {
    return std::make_shared<vector<int>>();
}

shared_ptr<vector<int>> read(shared_ptr<vector<int>> sharedPtr) {
    if (!sharedPtr) return std::make_shared<vector<int>>();
    std::ifstream in(small_numbers_text);
    int n;
    while (in >> n) {
        sharedPtr->push_back(n);
    }
    return sharedPtr;
}

void printSharedPtrToVec(shared_ptr<vector<int>> spv) {
    if (!spv) return;
    int cnt = 0;
    for (const auto &item : *spv) {
        cout << item << " ";
        if (++cnt % 7 == 0) cout << '\n';
    }
}


/*
 * Exercise 12.10: Explain whether the following call to the process function defined on page 464 is correct.
 * If not, how would you correct the call?
 * shared_ptr<int> p(new int(42)); process(shared_ptr<int>(p));
 * @see testingProcess();
 *
 * Exercise 12.11: What would happen if we called process as follows?
 * process(shared_ptr<int>(p.get()));
 * @see testingProcess();
 *
 *
 * Exercise 12.12: Using the declarations of p and sp explain each of the following calls to process.
 * If the call is legal, explain what it does. If the call is illegal, explain why:
 * auto p = new int();
 * auto sp = make_shared<int>();
 * (a) process(sp);
 * (b) process(new int());
 * (c) process(p);
 * (d) process(shared_ptr<int>(p));
 * @see testingProcess();
 *
 *
 * Exercise 12.13: What happens if we execute the following code?
 * auto sp = make_shared<int>();
 * auto p = sp.get();
 * delete p;
 * @see testingProcess();
 */


void process(std::shared_ptr<int> ptr) {
    std::cout << "inside the process function:" << ptr.use_count() << "\n";

}


void testingProcess() {
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));

//    process(shared_ptr<int>(p.get()));
//    cout << *p << endl; // memory leak.

    auto pi = new int();
    auto sp = std::make_shared<int>();

    process(sp);
//    process(pi);
//    process(new int());
    process(shared_ptr<int>(sp));
}


/*
 * Exercise 12.14: Write your own version of a function that uses a shared_ptr to manage a connection.
 * @see applyConn(destination &d);
 *
 * Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p.388) in place of the end_connection function.
 * @see applyConn(destination &d);
 *
 *
 */

struct destination {
};
struct connection {
};

connection connect(destination *) { return connection(); }

void disconnection(connection) {}

void closeConnection(connection *p) {
    disconnection(*p);
}

void applyConn(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, closeConnection);
    shared_ptr<connection> ps(&c, [](connection *p) { disconnection(*p); });
}

/*
 * Exercise 12.16: Compilers don’t always give easy-to-understand error messages
 * if we attempt to copy or assign a unique_ptr. Write a program that contains these errors to see
 * how your compiler diagnoses them.
 * Answer:
 * error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
 * [with _Tp = int; _Dp = std::default_delete<int>]’unique_ptr<int> up = pi;
 *
 *

 *
 *
 *
 * Exercise 12.17: Which of the following unique_ptr declarations are illegal or likely to result in subsequent
 * program error? Explain what the problem is with each one.
 * int ix = 1024, *pi = &ix, *pi2 = new int(2048); typedef unique_ptr<int> IntP;
 * (a) IntP p0(ix); Compile Error
 * (b) IntP p1(pi); runtime error
 * (c) IntP p2(pi2); danging pointer
 * (d) IntP p3(&ix); runtime error
 * (e) IntP p4(new int(2048)); Recommended
 * (f) IntP p5(p2.get()); runtime error: Operating system will throw double free or corruption.
 *
 *
 *
 * Exercise 12.18: Why doesn’t shared_ptr have a release member?
 * Answer:
 * Because other shared_ptr that points the same object can still delete this
 * object.Thus, it's meaningless to provide this member
 */

void testingUniquePtr() {
    int *p = new int(42);
    unique_ptr<int> pi(p);
//    unique_ptr<int> up = pi;
    cout << *pi.release() << endl;
    delete p;
}

/*
 * Exercise 12.19: Define your own version of StrBlobPtr and update your StrBlob class with the appropriate friend
 * declaration and begin and end members.
 * @see class StrBlob.
 *
 *
 * Exercise 12.20: Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr
 * to print each element in that StrBlob.
 * @see readIntoStrBlob.
 *
 *
 * Exercise 12.21: We could have written StrBlobPtr’s deref member as follows:
 * std::string& deref() const { return (*check(curr, "dereference past end"))[curr]; }
 * Which version do you think is better and why?
 * Answer:The original one is better, because it's more readable.
 *
 * Exercise 12.22: What changes would need to be made to StrBlobPtr to create a class that can be used with a const
 * StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob.
 * @see class ConstStrBlobPtr.
 */




const string tiny_text = "../../part_2_stdlib/tiny_text.txt";

void readIntoStrBlob() {
    std::ifstream in(tiny_text);
    string word;
    StrBlob sb;
    while (in >> word) {
        sb.pushBack(word);
    }
    auto strBlobPtr = sb.begin();
    try {
        while (true) {
            cout << strBlobPtr.deref() << " ";
            strBlobPtr.incr();
        }

    } catch (std::out_of_range &e) {
        cout << e.what() << endl;
    }
}


/*
 * Exercise 12.23: Write a program to concatenate two string literals, putting the result in a dynamically
 * allocated array of char. Write a program to concatenate two library strings that have the same value as the literals
 * used in the first program.
 * @see literalAJoinB();
 *
 *
 *
 * Exercise 12.24: Write a program that reads a string from the standard input into a dynamically allocated character array.
 * Describe how your program handles varying size inputs. Test your program by giving it a string of data that is longer
 * than the array size you’ve allocated.
 * @see storeRawMemory();
 *
 *
 * Exercise 12.25: Given the following new expression, how would you delete pa?
 * int *pa = new int[10];
 * Answer:delete [] pa;
 *
 *
 */

void literalAJoinB(char *s1, char *s2) {
    if (s1 && s2) {
        size_t n = std::strlen(s1) + std::strlen(s2);
        char *ch = new char[n + 1];
        char *cp = ch, *sp = s1;
        while (*sp) {
            *cp = *sp;
            ++cp, ++sp;
        }
        sp = s2;
        while (*sp) {
            *cp = *sp;
            ++cp, ++sp;
        }
        ch[n] = '\0';
        cout << "The result is: " << string(ch) << endl;
        delete[] ch;
    }
}

void literalAJoinB(const string &s1, const string &s2) {
    string r(s1);
    r.append(s2);
    cout << "The result is: " << r << endl;
}


void testingLiteralAJoinB() {
    string s1 = "hello,", s2 = "world!";
    char *c1 = "my,", *c2 = "dear!!";
    literalAJoinB(s1, s2);
    literalAJoinB(c1, c2);
}


void storeRawMemory() {
    std::ifstream in(tiny_text);
    string s;
    while (in >> s) {
        if (s.empty()) continue;
        char *str = new char[s.size() + 1];
        char *p = str;
        for (auto c : s) {
            *p = c;
            ++p;
        }
        str[s.size()] = '\0';
        cout << "The string you entered is: " << string(str) << endl;
        delete[] str;
    }
}

/*
 * Exercise 12.26:
 * Rewrite the program on page 481 using an allocator.
 * already be done.
 */


/*
 * Exercise 12.27: The TextQuery and QueryResult classes use only capabilities that we have already covered.
 * Without looking ahead, write your own versions of these classes.
 * @see class TextQuery.
 * @see QueryResult.
 *
 * Exercise 12.28: Write a program to implement text queries without defining classes to manage the data.
 * Your program should take a file and interact with a user to query for words in that file. Use vector, map, and set
 * containers to hold the data for the file and to generate the results for the queries.
 * @see class TextQuery.
 * @see QueryResult.
 *
 *
 * Exercise 12.29: We could have written the loop to manage the interaction with the user as a do while (§ 5.4.4, p. 189)
 * loop. Rewrite the loop to use a do while. Explain which version you prefer and why.
 * @see class TextQuery.
 * @see QueryResult.
 *
 */


/*
 * Exercise 12.30: Define your own versions of the TextQuery and QueryResult classes and execute the runQueries
 * function from § 12.3.1(p. 486).
 * @see class TextQuery.
 * @see QueryResult.
 *
 *
 *
 * Exercise 12.31: What difference(s) would it make if we used a vector instead of a set to hold the line numbers?
 * Which approach is better? Why?
 * @see class TextQuery.
 * @see QueryResult.
 *
 *
 *
 * Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a vector<string> to hold
 * the input file.
 * @see class TextQuery.
 * @see QueryResult.
 *
 *
 * Exercise 12.33: In Chapter 15 we’ll extend our query system and will need some additional members in the QueryResult class.
 * Add members named begin and end that return iterators into the set of line numbers returned by a given query,
 * and a member named get_file that returns a shared_ptr to the file in the QueryResult object.
 * @see class TextQuery.
 * @see QueryResult.
 *
 */

/*
 * also look up a procedural programming.
 */




int main(int argc, char *argv[]) {

    printRawPointerToVec(read(makeRawVecObj()));
    printSharedPtrToVec(read(makeSharedPtrToVector()));
    testingProcess();
    testingUniquePtr();
    readIntoStrBlob();
    testingLiteralAJoinB();
    storeRawMemory();
    txtq::runQueries();
    txtq::runQueriesForObj();

    return 0;
}
