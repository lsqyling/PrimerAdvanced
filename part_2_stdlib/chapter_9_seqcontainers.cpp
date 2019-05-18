// Created by shiqing on 19-4-24.
//

#include <array>
#include <fstream>
#include <sstream>
#include "../common/CommonHeaders.h"
#include "StackApply.h"

/*
 * Exercise 9.1:
 * Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?
 * Explain the rationale for your choice.
 * If there is no reason to prefer one or another container, explain why not.
 *
 * (a) Read a fixed number of words, inserting them in the container
 * alphabetically as they are entered. We’ll see in the next chapter that
 * associative containers are better suited to this problem.
 * Answer:Should be used vector.1)read in the words 2) sort of by alphabetically
 *
 * (b) Read an unknown number of words. Always insert new words at the
 * back. Remove the next value from the front.
 * Answer:deque
 *
 * (c) Read an unknown number of integers from a file. Sort the numbers and
 * then print them to standard output.
 * Answer:vector
 */


/*
 * Exercise 9.2: Define a list that holds elements that are deques that hold ints.
 * Answer: list<deque<int>> ld;
 */

/*
 * Exercise 9.3: What are constrains on the iterators that form iterator ranges?
 * Answer:
 * Two iterators, begin and end, form an iterator range, if
 * • They refer to elements of, or one past the end of, the same container, and
 * • It is possible to reach end by repeatedly incrementing begin. In other
 * words, end must not precede begin.
 */

/*
 * Note: Returns the current iterator if found, otherwise returns the trailing iterator.
 */
auto find(vector<int>::iterator beg, vector<int>::iterator end, int n) -> vector<int>::iterator {
    while (beg != end) {
        if (*beg == n) {
            return beg;
        }
        ++beg;
    }
    return end;
}


/*
 * Exercise 9.4: Write a function that takes a pair of iterators to a
 * vector<int> and an int value. Look for that value in the range and return
 * a bool indicating whether it was found.
 * @see find(...);
 *
 *
 * Exercise 9.5: Rewrite the previous program to return an iterator to the
 * requested element. Note that the program must handle the case where the
 * element is not found.
 * @find();
 *
 */


/*
 * Exercise 9.6: What is wrong with the following program? How might you correct it?
 * list<int> li;
 * auto iter1 = li.begin();
 * while (iter1 != li.end()) {
 *      li.push_back(0);
 * }
 */


/*
 * Exercise 9.7: What type should be used as the index into a vector of ints?
 * Answer:vector<int>::reference rToE;
 *
 *
 * Exercise 9.8:
 * What type should be used to read elements in a list of strings? To write them?
 * list<int>::const_iterator kIter;
 * list<int>::iterator iter;
 */


/*
 * Exercise 9.9: What is the difference between the begin and cbegin functions?
 * Answer:
 * 'begin()' returns iterator, cbegin returns const_iterator;
 *
 * Exercise 9.10: What are the types of the following four objects?
 *
 * vector<int> v1;
 * const vector<int> v2;
 * auto it1 = v1.begin(), vector<int>::iterator
 * it2 = v2.begin(); const_iterator
 * auto it3 = v1.cbegin(), const_iterator
 * it4 = v2.cbegin(); const_iterator
 */

// 0 0 0 0 0 0 0 0 0 0 default initialization, out of block.
std::array<int, 10> tenArr;


/*
 * Exercise 9.11: Show an example of each of the six ways to create and
 * initialize a vector. Explain what values each vector contains.
 * @see testingInitializingOfContains();
 *
 *
 * Exercise 9.12:
 * Explain the differences between the constructor that takes a
 * container to copy and the constructor that takes two iterators.
 * Answer:
 * 1)The constructor that takes another container as an argument
 * (excepting array) assumes the container type and element type of both containers are identical.
 * It will also copy all the elements of the received container into the new one:
 * 2)The constructor that takes two iterators as arguments does not require the container types to be identical.
 * Moreover, the element types in the new and original containers can differ as long as it is possible to convert
 * the elements we’re copying to the element type of the container we are initializing.
 * It will also copy only the object delimited by the received iterators.
 *
 *
 *
 * Exercise 9.13:
 * How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.
 *
 * @see testingInitializingOfContains();
 */


void testingInitializingOfContains() {
    std::array<int, 10> arr; // default initializing . in block
    for (const auto &item : arr) {
        cout << item << " ";
    }
    cout << endl;

    vector<int> vi;
    vector<int> vi1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    vector<int> vi1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; equivalent
    vector<int> vi2(vi1);
    vector<int> vi3(vi1.begin(), vi1.end());
    vector<int> vi4(10);
    vector<int> vi5(10, 0);

    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> vd(li.begin(), li.end());
    vector<double> vd1(vi1.begin(), vi1.end());

    list<char *> words = {"hello", "world"};
    vector<string> copyWords;
    copyWords.assign(words.begin(), words.end());

}

/*
 * Exercise 9.14: Write a program to assign the elements from a list of
 * char* pointers to C-style character strings to a vector of strings.
 * @see testingInitializingContains();
 */




/*
 * Exercise 9.15: Write a program to determine whether two vector<int>s are equal.
 * @see compareVectors();
 *
 * Exercise 9.16: Repeat the previous program, but compare elements in a
 * list<int> to a vector<int>.
 * @see compareVectorAndList()
 *
 * Exercise 9.17:
 * Assuming c1 and c2 are containers, what (if any)
 * constraints does the following usage place on the types of c1 and c2?
 * if (c1 < c2)
 * First, there must be the identical container and same type holded. Second,
 * the type held must support relational operation.
 * Both c1 and c2 are the containers except the unordered associative containers.
 *
 */

bool compareVectors(const vector<int> &v1, const vector<int> &v2) {
    return v1 == v2;
}

bool compareVectorAndList(const vector<int> &v, const list<int> &li) {
    if (v.size() != li.size()) return false;
    auto sz = v.size();
    auto begV = v.begin();
    auto begL = li.begin();
    for (decltype(sz) i = 0; i != sz; ++i) {
        if (*begV != *begL) {
            return false;
        }
        ++begV;
        ++begL;
    }
    return true;
}


/*
 * Exercise 9.18: Write a program to read a sequence of strings from the
 * standard input into a deque. Use iterators to write a loop to print the
 * elements in the deque.
 * @see readStringsAndPrint();
 *
 *
 * Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the changes you needed to make.
 * @see readStringsAndPrint();
 *
 * Exercise 9.20:
 * Write a program to copy elements from a list<int> into two deques.
 * The even-valued elements should go into one deque and the odd ones into the other.
 * @see printOddAndEvenNumbs();
 *
 *
 *
 * Exercise 9.21: Explain how the loop from page 345 that used the return from insert to add elements
 * to a list would work if we inserted into a vector instead.
 * Answer:
 * It's the same.
 * The first call to insert takes the string we just read and puts it in front of the element denoted by iter.
 * The value returned by insert is an iterator referring to this new element.
 * We assign that iterator to iter and repeat the while, reading another word. As long as there are words to insert,
 * each trip through the while inserts a new element ahead of iter and reassigns to iter the location of the
 * newly inserted element. That element is the (new) first element.
 * Thus, each iteration inserts an element ahead of the first element in the vector.
 *
 *
 *
 * Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the following program?
 * How might you correct the problem(s)?
 * @see insertBeforeNum();
 */

void readStringsAndPrint() {
    cout << "enter a sequence of strings: " << '\n';
    string s;
    deque<string> ds;
    list<string> ls;
    while (cin >> s && s[0] != 'N') {
        ds.push_back(s);
        ls.push_back(s);
    }
    for (auto iter = ds.begin(); iter != ds.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << '\n';
    for (auto iter = ls.begin(); iter != ls.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}


void insertBeforeNum() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 3;
    auto beg = vi.begin();
    auto mid = vi.begin() + vi.size() / 2;
    while (beg != mid) {
        if (*beg == val) {
            beg = vi.insert(beg, 2 * val);
            mid = vi.begin() + vi.size() / 2;
        }
        ++beg;
    }
    for (const auto &item : vi) {
        cout << item << " ";
    }
    cout << endl;
}


void printOddAndEvenNumbs() {
    insertBeforeNum();
    list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> even;
    deque<int> odd;
    for (const auto &n : li) {
        if (n & 1) {
            odd.push_back(n);
        } else {
            even.push_back(n);
        }
    }
    cout << "the odd nums: ";
    for (const auto &e : even) {
        cout << e << " ";
    }
    cout << '\n';
    cout << "the even nums: ";
    for (const auto &e : odd) {
        cout << e << " ";
    }
    cout << endl;
}


/*
 * Exercise 9.23:
 * In the first program in this section on page 346, what would
 * the values of val, val2, val3, and val4 be if c.size() is 1?
 * Answer:1111
 *
 *
 * Exercise 9.24:
 * Write a program that fetches the first element in a vector using at, the subscript operator,
 * front, and begin. Test your program on an empty vector.
 * @see accessElements();
 *
 */

void accessElements() {
    vector<int> vi = {1};
    auto val1 = *vi.begin(), val2 = vi.front();
    auto val3 = *--vi.end(), val4 = vi.back();
    cout << val1 << val2 << val3 << val4
         << vi[0] << vi.at(0) << '\n';
}


/*
 * Exercise 9.25: In the program on page 349 that erased a range of
 * elements, what happens if elem1 and elem2 are equal? What if elem2 or
 * both elem1 and elem2 are the off-the-end iterator?
 * Answer:
 * if elem1 and elem2 are equal, nothing happened.
 * if elem2 is the off-the-end iterator, it would delete from elem1 to the end.
 * if both elem1 and elem2 are the off-the-end iterator, nothing happened too.
 *
 *
 *
 * Exercise 9.26: Using the following definition of ia, copy ia into a vector
 * and into a list. Use the single-iterator form of erase to remove the elements
 * @see eraseNumbs();
 */


void eraseNumbs() {
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vi(std::begin(a), std::end(a));
    list<int> li(std::begin(a), std::end((a)));
    auto begV = vi.begin();
    while (begV != vi.end()) {
        if (!(*begV & 1)) {
            begV = vi.erase(begV);
        } else {
            ++begV;
        }
    }
    auto iter = li.begin();
    while (iter != li.end()) {
        if (*iter & 1) {
            iter = li.erase(iter);
        } else {
            ++iter;
        }
    }

    for (const auto &item : vi) {
        cout << item << " ";
    }
    cout << '\n';
    for (const auto &e : li) {
        cout << e << " ";
    }
    cout << endl;

}


/*
 * Exercise 9.27: Write a program to find and remove the odd-valued
 * elements in a forward_list<int>.
 * @see eraseOddNumsInForwardList();
 *
 *
 *
 *
 * Exercise 9.28: Write a function that takes a forward_list<string> and
 * two additional string arguments. The function should find the first string
 * and insert the second immediately following the first. If the first string is
 * not found, then insert the second string at the end of the list.
 * @see findInsert();
 */

void eraseOddNumbsInForwardList() {
    forward_list<int> fi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fi.before_begin();
    auto curr = fi.begin();
    while (curr != fi.end()) {
        if (*curr & 1) {
            curr = fi.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
    for (const auto &item : fi) {
        cout << item << " ";
    }
    cout << endl;
}


auto findInsert(forward_list<string> &fls, string found, string inserted) {
    auto it = fls.begin();
    auto prev = fls.before_begin();
    while (it != fls.end()) {
        if (*it == found) {
            return fls.insert_after(it, inserted);
        } else {
            prev = it;
            ++it;
        }
    }
    if (it == fls.end()) {
        return fls.insert_after(prev, inserted);
    }
}


void testingFindInsert() {
    forward_list<string> fl{"hi", "how", "what", "about", "my", "dear"};
    cout << *findInsert(fl, "dear", "!!") << endl;
    cout << *findInsert(fl, "say", "too!");

}


/*
 * Exercise 9.29: Given that vec holds 25 elements, what does
 * vec.resize(100) do? What if we next wrote vec.resize(10)?
 * Answer:
 * vec.resize(1000) // adds 75 elements of value 0 to the back of vec
 * vec.resize(10) // erases 90 elements from the back of vec
 *
 *
 *
 *
 * Exercise 9.30: What, if any, restrictions does using the version of resize
 * that takes a single argument place on the element type?
 * answer:
 * If the container holds elements of a class type and resize adds elements
 * we must supply an initializer or the element type must have a default constructor.
 */



/*
 * Exercise 9.31:
 * The program on page 354 to remove even-valued elements
 * and duplicate odd ones will not work on a list or forward_list. Why?
 * Revise the program so that it works on these types as well.
 * @see removeEvenAndDuplicateOdds();
 *
 *
 *
 * Exercise 9.32: In the program on page 354 would it be legal to write the call
 * to insert as follows? If not, why not?
 * Answer:
 * The results of the program depend on the order of evaluation,
 * and the results of different compiler implementations may differ.
 *
 *
 *
 *
 *
 * Exercise 9.33: In the final example in this section what would happen if we
 * did not assign the result of insert to begin? Write a program that omits
 * this assignment to see if your expectation was correct.
 * Answer:Will put the program into an infinite loop, bad idea, saving the value of the end iterator.
 *
 *
 * Exercise 9.34: Assuming vi is a container of ints that includes even and
 * odd values, predict the behavior of the following loop. After you’ve analyzed
 * this loop, write a program to test whether your expectations were correct.
 *
 * @see duplicateOddsInVector();
 */


void removeEvenAndDuplicateOdds() {
    forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while (curr != fl.end()) {
        if (*curr & 1) {
            curr = fl.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        } else {
            curr = fl.erase_after(prev);
        }
    }
    for (const auto &item : fl) {
        cout << item << " ";
    }
    cout << endl;
}

void duplicateOddsInVector() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = vi.begin();
    while (it != vi.end()) {
        if (*it & 1) {
            it = vi.insert(it, *it);
            ++it;
        }
        ++it;
    }
    for (const auto &item : vi) {
        cout << item << " ";
    }
    cout << endl;
}


/*
 * Exercise 9.35:
 * Explain the difference between a vector’s capacity and its size.
 * Answer:
 * 1)The size of a container is the number of elements it already holds;
 * 2)The capacity is how many elements it can hold before more space must be allocated.
 *
 *
 * Exercise 9.36: Can a container have a capacity less than its size?
 * Answer: cannot.
 *
 *
 * Exercise 9.37:
 * Why don’t list or array have a capacity member?
 * Answer:
 * list does not hold elements contiguously. array has the fixed size statically.
 *
 * Exercise 9.38: Write a program to explore how vectors grow in the library you use.
 * answer:already be done.
 *
 *
 * Exercise 9.39: Explain what the following program fragment does:
 */

void testingCapacityAndResize() {
    vector<int> vi;
    vi.reserve(1024);
    cout << vi.capacity() << endl;
    for (int i = 0; i != 1048; ++i) {
        vi.push_back(i);
    }
    vi.resize(vi.size() + vi.size() / 2);
    cout << vi.capacity() << endl;

}


/*
 * Exercise 9.41: Write a program that initializes a string from a vector<char>.
 *
 * @see testingReadStrings();
 *
 * Exercise 9.42: Given that you want to read a character at a time into a
 * string, and you know that you need to read at least 100 characters, how
 * might you improve the performance of your program?
 * @see testingReadStrings();
 */


void testingReadStrings() {
    vector<char> vc = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    string s;
    s.reserve(100);
    for (const auto &item : vc) {
        s.push_back(item);
    }
    cout << s << endl;
}


/*
 * Exercise 9.43: Write a function that takes three strings, s, oldVal, and
 * newVal. Using iterators, and the insert and erase functions replace all
 * instances of oldVal that appear in s by newVal. Test your function by
 * using it to replace common abbreviations, such as “tho” by “though” and
 * “thru” by “through”.
 * @see changeToString()
 *
 *
 *
 *
 *
 * Exercise 9.44:
 * Rewrite the previous function using an index and replace.
 * @see changeToStringByIndex();
 *
 *
 *
 * Exercise 9.45:
 * Write a funtion that takes a string representing a name
 * and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
 * suffix, such as “Jr.” or “III”. Using iterators and the insert and append
 * functions, generate and return a new string with the suffix and prefix
 * added to the given name.
 * @see completedNameByReplace();
 *
 *
 *
 *
 * Exercise 9.46: Rewrite the previous exercise using a position and length to
 * manage the strings. This time use only the insert function.
 * @see completedNameByInsert();
 */

string completedNameByReplace(string srcName, string prefix, string suffix) {
    auto it = srcName.begin();
    srcName.insert(it, prefix.begin(), prefix.end());
    srcName.append(suffix);
    return srcName;
}


string completedNameByInsert(string srcName, string prefix, string suffix) {
    srcName.insert(0, prefix);
    srcName.insert(srcName.size(), suffix);
    return srcName;
}

void testingCompletedName() {
    string srcName = "John", prefix = "Mr.", suffix = "Jr.";
    cout << completedNameByReplace(srcName, prefix, suffix) << endl;
    srcName = "Lucy", prefix = "Mrs.", suffix = ".III";
    cout << completedNameByInsert(srcName, prefix, suffix) << endl;
}


void changeToStringByIndex(string &s, string oldVal, string newVal) {
    for (decltype(s.size()) i = 0; i != s.size();) {
        while (i != s.size() && s[i] != oldVal[0]) {
            ++i;
        }
        decltype(oldVal.size()) j, oSZ = oldVal.size();
        for (j = 0; j != oSZ;) {
            if (s[i] == oldVal[j]) {
                ++i;
                ++j;
            } else {
                break;
            }
        }
        if (j == oSZ) {
            s.replace(i - oSZ, oSZ, newVal);
        }
        j = 0;
    }
}


void changeToStringByIterator(string &s, string oldVal, string newVal) {
    auto itS = s.begin(), itO = oldVal.begin();
    while (itS != s.end()) {
        while (itS != s.end() && *itS != *itO) {
            ++itS;
        }
        while (itO != oldVal.end()) {
            if (*itS == *itO) {
                ++itS;
                ++itO;
            } else {
                break;
            }
        }
        if (itO == oldVal.end()) {
            itS = s.erase(itS - oldVal.size(), itS);
            itS = s.insert(itS, newVal.begin(), newVal.end());
        }
        itO = oldVal.begin();
    }
}

void testingChangeToString() {
    string s = "It is a very very  Mad World, Mad World !!";
    string oldVal = "World", newVal = "Man";
    changeToStringByIterator(s, oldVal, newVal);
    cout << s << endl;
    oldVal = "Man", newVal = "World";
    changeToStringByIndex(s, oldVal, newVal);
    cout << s << endl;
}


/*
 * Exercise 9.47: Write a program that finds each numeric character and then
 * each alphabetic character in the string "ab2c3d7R4E6". Write two
 * versions of the program. The first should use find_first_of, and the
 * second find_first_not_of.
 * @see findCharsAndNumbsByFindFirstOf();
 * @see findCharsAndNumbsByFindNotFirstOf();
 *
 *
 *
 * Exercise 9.48: Given the definitions of name and numbers on page 365,
 * what does numbers.find(name) return?
 * Answer:string::npos;
 *
 *
 *
 *
 * Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter
 * extends above the middle of the line. A letter has a descender if, as with p or g,
 * part of the letter extends below the line. Write a program that reads a file
 * containing words and reports the longest word that contains neither
 * ascenders nor descenders.
 * @see longestDwarfWords();
 *
 */

inline string processWord(string &s) {
    string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string::size_type b, e;
    if ((b = s.find_first_of(alpha)) == string::npos || (e = s.find_last_of(alpha)) == string::npos) {
        return string();
    }
    if (e - b + 1 == s.size()) {
        return s;
    }
    return s.substr(b, e - b + 1);
}

void testingProcessWord() {
    string word = "....////hello.....";
    cout << processWord(word) << endl;
}

string longestDwarfWords() {
    string filePath = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";
    std::ifstream in(filePath, std::ifstream::in);
    vector<string> words;
    string word;
    while (in >> word) {
        words.push_back(word);
    }
    string ascender = "bdfhl", descender = "gjpqy";
    string::size_type maxLen = 0, posA, posD;
    string longest;
    for (auto &word : words) {
        word = processWord(word);
        bool flag = ((posA = word.find_first_of(ascender)) == string::npos)
                    && ((posD = word.find_first_of(descender)) == string::npos);
        if (flag) {
            maxLen < word.size() ? (longest = word, maxLen = word.size()) : maxLen;
        }
    }
    cout << "The longest word that meets the criteria is: " << longest << endl;
    return longest;
}


void findCharsAndNumbsByFindFirstOf() {
    string src = "ab2c3d7R4E6", nums = "0123456789", alpha = "abcdRE";
    string::size_type pos = 0;
    string numsIndex, alphaIndex;
    while ((pos = src.find_first_of(nums, pos)) != string::npos) {
        numsIndex += std::to_string(pos);
        ++pos;
    }
    cout << "the numbs of index is: " << numsIndex << '\n';
    pos = 0;
    while ((pos = src.find_first_of(alpha, pos)) != string::npos) {
        alphaIndex += std::to_string(pos);
        ++pos;
    }
    cout << "the alpha of index is: " << alphaIndex << '\n';
}


void findCharsAndNumbsByFindNotFirstOf() {
    string src = "ab2c3d7R4E6", nums = "0123456789", alpha = "abcdRE";
    string::size_type pos = 0;
    string numsIndex, alphaIndex;
    while ((pos = src.find_first_not_of(alpha, pos)) != string::npos) {
        numsIndex += std::to_string(pos);
        ++pos;
    }
    cout << "the numbs of index is: " << numsIndex << '\n';
    pos = 0;
    while ((pos = src.find_first_not_of(nums, pos)) != string::npos) {
        alphaIndex += std::to_string(pos);
        ++pos;
    }
    cout << "the alpha of index is: " << alphaIndex << '\n';
}


/*
 * Exercise 9.50: Write a program to process a vector<string>s whose
 * elements represent integral values. Produce the sum of all the elements in
 * that vector. Change the program so that it sums of strings that represent
 * floating-point values.
 * @see calculateOfStringInts();
 *
 *
 *
 *
 * Exercise 9.51: Write a class that has three unsigned members
 * representing year, month, and day. Write a constructor that takes a string
 * representing a date. Your constructor should handle a variety of date
 * formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
 * @see class Date;
 */




struct Tuple {
    unsigned year;
    unsigned month;
    string monthStr;
    unsigned day;
};

inline bool isLeapYear(unsigned year) {
    bool flag = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    return flag;
}

bool valid(Tuple date) {
    if (isLeapYear(date.year)) {
        switch (date.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return date.day <= 31;
            case 2:
                return date.day <= 29;
            case 4:
            case 6:
            case 9:
            case 11:
                return date.day <= 30;
            default:
                return false;
        }
    } else {
        switch (date.month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return date.day <= 31;
            case 2:
                return date.day <= 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return date.day <= 30;
            default:
                return false;
        }
    }
}

inline bool isContainsAlpha(string dateStr) {
    for (auto c : dateStr) {
        if (isalpha(c)) {
            return true;
        }
    }
    return false;
}

inline string removePunctuation(string src) {
    for (auto &c : src) {
        if (ispunct(c)) {
            c = ' ';
        }
    }
    return src;
}

inline string removeCntr(string src) {
    for (auto &c : src) {
        if (!isalnum(c)) {
            c = ' ';
        }
    }
    return src;
}

Tuple parsing(string dateStr) {
    Tuple dateTuple;
    if (isContainsAlpha(dateStr)) {
        string newDateStr = removePunctuation(dateStr);
        std::istringstream strIn(newDateStr);
        if (strIn >> dateTuple.monthStr >> dateTuple.day >> dateTuple.year) {
            return dateTuple;
        } else {
            throw std::invalid_argument("The date string entered is malformed!!");
        }
    } else {
        string newDate = removeCntr(dateStr);
        std::istringstream strIn(newDate);
        if (strIn >> dateTuple.day >> dateTuple.month >> dateTuple.year) {
            return dateTuple;
        } else {
            throw std::invalid_argument("The date string entered is malformed!!");
        }
    }
}


inline Tuple translationMonthOfString(Tuple tp) {
    vector<string> monthVec = {
            "NULL",
            "Jan. January", "Feb. February", "Mar. March",
            "Apr. April", "May", "Jun. June",
            "Jul. Jy. July", "Aug. August", "Sep. September",
            "Oct. October", "Nov. November", "Dec. December"

    };
    tp.month = 0;
    auto sz = monthVec.size();
    string::size_type pos;
    for (decltype(sz) i = 1; i != sz; ++i) {
        if ((pos = monthVec[i].find(tp.monthStr)) != string::npos) {
            tp.month = i;
            break;
        }
    }
    return tp;
}


namespace self {
    class Date {
        friend std::ostream &operator<<(std::ostream &os, const Date &date);

    public:

        Date() = default;

        Date(string dateStr);

    private:
        unsigned year_ = 1970U;
        unsigned month_ = 1U;
        unsigned day_ = 1U;
    };

    std::ostream &operator<<(std::ostream &os, const Date &date);

}

std::ostream &self::operator<<(std::ostream &os, const self::Date &date) {
    os << "date: {day = " << date.day_
       << ", month = " << date.month_
       << ", year = " << date.year_
       << "}";
    return os;
}


Tuple parsingDateStr(string dateStr) {
    Tuple dateTuple = parsing(dateStr);
    if (dateTuple.monthStr.empty()) {
        if (valid(dateTuple)) {
            return dateTuple;
        } else {
            throw std::invalid_argument("The date of num is Wrong!!");
        }
    } else {
        Tuple new_ = translationMonthOfString(dateTuple);
        if (valid(new_)) {
            return new_;
        } else {
            throw std::invalid_argument("The date of num is Wrong!!");
        }
    }
}

self::Date::Date(string dateStr) {
    Tuple tp = parsingDateStr(dateStr);
    year_ = tp.year;
    month_ = tp.month;
    day_ = tp.day;
}



void testingNewDate() {
    using self::Date;
    Date date3("Jan 1 1900");
    Date date1("January 1, 1900");
    Date date2("1/1/1900");
    Date date4("May,,,29, 1958");
    cout << date1 << endl;
    cout << date2 << endl;
    cout << date3 << endl;
    cout << date4 << endl;

}


int calculateOfStringInts(const vector<string> &vs) {
    if (vs.empty()) return 0;
    int sum = 0;
    for (const auto &s : vs) {
        sum += std::stoi(s);
    }
    return sum;
}

double calculateOfStringDouble(const vector<string> &vs) {
    if (vs.empty()) return .0;
    double sum = 0.0;
    for (const auto &d : vs) {
        sum += std::stod(d);
    }
    return sum;
}


void testingCalculateOfString() {
    vector<string> vs = {"12", "90", "3.00", "5.0", "7", "8", "42"};
    cout << calculateOfStringDouble(vs) << endl;
    cout << calculateOfStringInts(vs) << endl;
}


void testingStack() {
    //    brackets match
    char exp[] = "(()(())())";
    bool b = StackApply::paren(exp, 0, 10);
    cout << endl <<  "b = " <<  b << endl;


    char *RPN = (char*) malloc(sizeof(char) * 1); RPN[0] = '\0';
    char EXP[] = "((0 + (1 + 23) / 4 * 5 * 67 - 8 + 9))";
    char * NONSpaceExp = StackApply::removeSpace(EXP);
    cout << "NONSpaceExp = " << NONSpaceExp << endl;


    float R = StackApply::evaluate(NONSpaceExp, RPN);
    cout << "EXP = " << R << endl;
    cout << "RPN = " << RPN << endl;

    char *rpn = (char*) malloc(sizeof(char) * 1); rpn[0] = '\0';
    char Expression[] = "((0 + (1 + 23) / 4 * 5 * 67 - 8 + 9))";
    char *expression = StackApply::removeSpace(Expression);
    StackApply::transformToRPN(expression, rpn);
    cout << "rpn = " << rpn << endl;
}

int main(int argc, char *argv[]) {
    testingStack();
    testingNewDate();
    testingCalculateOfString();
    testingProcessWord();
    longestDwarfWords();
    findCharsAndNumbsByFindFirstOf();
    findCharsAndNumbsByFindNotFirstOf();
    testingCompletedName();
    testingChangeToString();
    testingReadStrings();
    testingCapacityAndResize();
    duplicateOddsInVector();
    removeEvenAndDuplicateOdds();
    testingFindInsert();
    eraseOddNumbsInForwardList();
    eraseNumbs();
    accessElements();
    printOddAndEvenNumbs();
    readStringsAndPrint();
    testingInitializingOfContains();
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "vi.capacity() = " << vi.capacity() << endl;
    list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 0};
    cout << compareVectorAndList(vi, li) << endl;


    return 0;
}
