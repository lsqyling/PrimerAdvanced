//
// Created by shiqing on 19-4-18.
//
#include "../common/CommonHeaders.h"
#include "Sales_item.h"


/*
 * Exercise 3.1:
 * Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with appropriate using declarations.
 *
 * already be done.
 */


void initializingStrings() {
    string s1;//default initialization; s1 is the empty string
    string s2 = s1;//s2 is a copy of  s1
    string s3 = "hiya";// s3 is a copy of the string literal
    string s4(10, 'c');// s4 is cccccccccc

    string s5 = "hiya";//copy initialization
    string s6("hiya");//direct initialization
    string s7(10, 'c');// direct initialization; s7 is cccccccccc


    string s8 = string(10, 'c');//copy initialization ,s8 is ccccccccccc
}


/*
 * Exercise 3.2:
 * Write a program to read the standard input a line at a time.
 * Modify your program to read a word at a time.
 * Answer:@see inAndOut();
 */
void inAndOut() {
    cout << "Enter two strings: " << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    cout << "continue..." << endl;
    string s;
    while (cin >> s && s[0] != 'n') {
        cout << s << endl;
    }
    cout << "continue...." << endl;
    string line;
    while (getline(cin, line) && line[0] != 'n') {
        cout << line << endl;
    }

}



/*
 * Exercise 3.3:
 * Explain how whitespace characters are handled in the string input operator and in the getline function.
 * For code like is >> s, input is separated by whitespaces while reading into string s.
 * For code like getline(is, s) input is separated by newline \n while reading into string s. Other whitespaces are ignored.
 * For code like getline(is, s, delim)input is separated by delim while reading into string s. All whitespaces are ignored.
 *
 */


/*
 * Exercise 3.4: Write a program to read two strings and report whether the
 * strings are equal. If not, report which of the two is larger. Now, change
 * the program to report whether the strings have the same length, and if
 * not, report which is longer.
 * Answer:@see compareStrings();
 */


void compareStrings() {
    cout << "Enter two strings:" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
        cout << s1 << endl;
    } else {
        cout << (s1 < s2 ? s2 : s1) << endl;
    }

    if (s1.size() < s2.size()) {
        cout << s2 << endl;
    }

}

/*
 * Exercise 3.5: Write a program to read strings from the standard input,
 * concatenating what is read into one large string. Print the concatenated
 * string. Next, change the program to separate adjacent input strings by a space.
 * Answer:@see joinStrings();
 */

void joinStrings() {
    cout << "please input words: " << endl;
    string s, out, separate;
    while (cin >> s && s[0] != 'n') {
        out += s;
        separate += (" " + s);
    }
    cout << out << endl;
    cout << separate << endl;

}


/*
 * Exercise 3.6:
 * Use a range for to change all the characters in a string to X.
 * Answer:@see charToX();
 */

/*
 * Exercise 3.7:
 * What would happen if you define the loop control variable in
 * the previous exercise as type char? Predict the results and then change your
 * program to use a char to see if you were right.
 * Answer:@see charToX();
 */

/*
 * Exercise 3.8:
 * Rewrite the program in the first exercise, first using a while
 * and again using a traditional for loop. Which of the three approaches do
 * you prefer and why?
 * Answer:@see charToX();
 */


void charToX() {
    cout << "Please input a world, and then look up output." << endl;
    string s;
    cin >> s;
    string cs(s), original(s);
    decltype(s.size()) n = 0;
    while (!s.empty() && n < s.size()) {
        s[n] = 'X';
        ++n;
    }
    for (auto &c : cs) {
        c = 'X';
    }

    cout << "inputs is " << original << ", result is " << s << endl;
    cout << "inputs is " << original << ", result is " << cs << endl;


}


/*
 * Exercise 3.9:
 * What does the following program do? Is it valid? If not, why not?
 * string s;
 * cout << s[0] << endl;
 * Answer:
 * This code was dereferencing and printing the first item stored in s.
 * Since s is empty, such operation is invalid, a.k.a. undefined behavior.
 */


/*
 * Exercise 3.10:
 * Write a program that reads a string of characters including
 * punctuation and writes what was read but with the punctuation removed.
 * @see interceptPunctuation();
 */

void interceptPunctuation() {
    cout << "please input a string of characters including punctuation?" << endl;
    string s, result;
    getline(cin, s);
    for (const auto c : s) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    cout << "\nthe original string is: \n" << s << "\nthe result is " << result << endl;
}


/*
 * Exercise 3.11:
 * Is the following range for legal? If so, what is the type of c?
 * const string s = "Keep out!";
 * for (auto &c : s) {  ...   }
 *
 * c is const char &.
 */



/*
 * Exercise 3.12:
 * Which, if any, of the following vector definitions are in error?
 * For those that are legal, explain what the definition does.
 * For those that are not legal, explain why they are illegal.
 * vector<vector<int>> ivec;         // legal(c++11), vectors.
 * vector<string> svec = ivec;       // illegal, different type.
 * vector<string> svec(10, "null");  // legal, vector have 10 strings: "null".
 */


/*
 * Exercise 3.13:
 * How many elements are there in each of the following vectors? What are the values of the elements?
 * vector<int> v1;         // size:0,  no values.
 * vector<int> v2(10);     // size:10, value:0
 * vector<int> v3(10, 42); // size:10, value:42
 * vector<int> v4{ 10 };     // size:1,  value:10
 * vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
 * vector<string> v6{ 10 };  // size:10, value:""
 * vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
 */


void initializingVectors() {
    vector<int> ivec;// ivec holds objects of type int
    vector<Sales_item> salesVec;// holds Sales_items
    vector<vector<string>> file;// vector whose elements are vectors

    vector<string> svec;
    vector<int> ivec2(ivec);// copy elements of ivec into ivec2
    vector<int> ivec3 = ivec2;//copy elements of ivec2 into ivec3;
//    vector<string> sevc1(ivec2);Error:svec1 holds strings, not ints

    vector<string> articles = {"a", "b", "c", "d"};
    vector<string> v1{"a", "an", "the", "people"};
//    vector<string> v2("a", "b", "c");Error:

    {
        vector<int> ivec(10, -1);// ten int elements, each initialized to -1
        vector<string> sevc(10, "hi");// ten string elements, each initialized to hi
    }

    {
        vector<int> ivec(10);// ten int elements,each initialized to 0
        vector<string> svec(10);// ten string elements ,each initialized to empty string
        vector<int> v1(10);
        vector<int> v2{10};
        vector<int> v3(10, 1);
        vector<int> v4{10, 1};

        vector<string> v5{"hi"};
//        vector<string> v6("hi");
        vector<string> v7{10};// v7 has ten default-initialized elements
        vector<string> v8{10, "hi"};//v8 has ten elements with value "hi"
    }
}

/*
 * Exercise 3.14:
 * Write a program to read a sequence of ints from cin and store those values in a vector.
 * Answer @see addNumbsToVector();
 */


void addNumbsToVector() {
    cout << "enter a set of integers: " << endl;
    vector<int> iv;
    int x = 0;
    while (cin >> x && x != -1) {
        iv.push_back(x);
    }
    for (auto &e : iv) {
        cout << e << " ";
    }
    cout << endl;
}


/*
 * Exercise 3.15:
 * Repeat the previous program but read strings this time.
 * Answer @see addStringsToVector();
 */


void addStringsToVector() {
    cout << "enter a set of strings: " << endl;
    vector<string> sv;
    string s;
    while (cin >> s && s[0] != 'n') {
        sv.push_back(s);
    }
    for (auto &e : sv) {
        cout << e << " ";
    }
    cout << endl;
}


/*
 * Exercise 3.16:
 * Write a program to print the size and contents of the
 * vectors from exercise 3.13. Check whether your answers to that exercise
 * were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you
 * were wrong.
 * already be done.
 */

/*
 * Exercise 3.17:
 * Read a sequence of words from cin and store the values a
 * vector. After you’ve read all the words, process the vector and change
 * each word to uppercase. Print the transformed elements, eight words to a line.
 *
 * Answer: @see toUpperFromVector();
 *
 */

void toUpperFromVector() {
    cout << "enter a sequence of words: " << endl;
    string s;
    vector<string> sv;
    while (cin >> s && s[0] != 'n') {
        sv.push_back(s);
    }
    for (auto &word : sv) {
        for (auto &c : word) {
            c = toupper(c);
        }
    }
    for (const auto &word : sv) {
        cout << word << endl;
    }
}


/*
 * Exercise 3.18:
 * Is the following program legal? If not, how might you fix it?
 * vector<int> ivec;
 * ivec[0] = 42;
 * vector<int> ivec = {42};
 */



/*
 * Exercise 3.19:
 * List three ways to define a vector and give it ten elements,
 * each with the value 42. Indicate whether there is a preferred way to do so and why.
 * vector<int> iv(10, 42);
 * vector<int> ivv = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
 * vector<int> ivvv;
 * for (int i = 0; i != 10; ++i) {
 *      ivvv.push_back(42);
 * }
 */


/*
 * Exercise 3.20:
 * Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements. Change your program so that it prints the sum of
 * the first and last elements, followed by the sum of the second and second-to-
 * last, and so on.
 * @see sumOfTwoElements();
 */


void sumOfTwoElements() {
    cout << "enter a set of integers: " << endl;
    vector<int> iv;
    int n;
    while (cin >> n && n != -1) {
        iv.push_back(n);
    }
    auto sz = iv.size();
    for (decltype(sz) i = 0; i < sz; ++i) {
        if (sz == 1) {
            cout << iv[i] << " ";
            break;
        }
        cout << iv[i] + iv[++i] << " ";
        if (i == sz - 2) {
            cout << iv[++i] << " ";
        }

    }
    cout << endl;

    for (decltype(sz) j = 0, k = sz - 1; j <= k; ++j, --k) {
        if (j == k) {
            cout << iv[j] << " ";
            break;
        }
        cout << iv[j] + iv[k] << " ";
    }
    cout << endl;


}

/*
 * Exercise 3.21:
 * Redo the first exercise from § 3.3.3 (p. 105) using iterators.
 * @see toUpperFirstParagraph();
 */



/*
 * Exercise 3.22:
 * Revise the loop that printed the first paragraph in text to
 * instead change the elements in text that correspond to the first paragraph
 * to all uppercase. After you’ve updated text, print its contents.
 * @see toUpperFirstParagraph();
 */



void toUpperFirstParagraph() {
    cout << "enter lines for text: " << endl;
    string line;
    vector<string> vs;
    while (getline(cin, line) && line[0] != 'n') {
        vs.push_back(line);
    }

    vector<string> result;
    bool flag = false;
    for (auto beg = vs.begin(); beg != vs.end() && !beg->empty(); ++beg) {
        for (auto b = beg->begin(); b != beg->end(); ++b) {
            if (isspace(*b) && isspace(*(b + 1))) {
                flag = true;
                break;
            }
            *b = toupper(*b);
        }
        if (flag) {
            break;
        }
        result.push_back(*beg);
    }

    for (auto beg = result.begin(); beg != result.end() && !beg->empty(); ++beg) {
        cout << *beg << " " << endl;
    }

}


/*
 * Exercise 3.23:
 * Write a program to create a vector with ten int elements.
 * Using an iterator, assign each element a value that is twice its current value.
 * Test your program by printing the vector.
 * @see toDouble();
 */


void toDouble() {
    vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto beg = iv.begin(); beg != iv.end(); ++beg) {
        *beg = *beg * 2;
    }
    for (const auto &i : iv) {
        cout << i << " ";
    }
    cout << endl;
}

/*
 * Exercise 3.24:
 * Redo the last exercise from § 3.3.3 (p. 105) using iterators.
 * Answer:Non-best practice,if you need best practices please check @sumOfTwoElements();
 */


/*
 * Exercise 3.25:
 * Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.
 * Answer:Non-best practice,if you need best practices please check @sumOfTwoElements();
 */


/*
 * Exercise 3.26:
 * In the binary search program on page 112, why did we write mid=beg+(end-beg)/2; instead of mid=(beg+end) /2;?
 * Answer: There's no operator + for adding two iterators.
 */

void initializingArrays() {
    unsigned cnt = 42;
    constexpr unsigned sz = 42;
    int array[10];
    int *parr[sz];
    string bad[cnt];// error: cnt is not a constant expression, but the compiler didn't report an error.

    int ia1[sz] = {0, 1, 2}; //The compiler performs value initialization. 0 1 2 0 0 ...
    for (int i = 0; i != sz; ++i) {
        cout << ia1[i] << " ";
    }
    cout << endl;

    int ia2[] = {0, 1, 3};
    int ia3[5] = {0, 1, 2};
    string a4[3] = {"hi", "bye"};
//    int ia5[2] = {0, 1 ,2};error: too many initializers for ‘int [2]’
    {
        char a1[] = {'C', '+', '+'};       // list initialization, no null
        char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
        char a3[] = "C++";                 // null terminator added
//        automatically
//        const char a4[6] = "Daniel";       // error: no space for the null!
        const char a4[7] = "Daniel";
    }

    {
        int a[] = {0, 1, 2};
//        int a2[] = a;cannot initialize one array with another
        int a2[3];
//        a2 = a;cannot assign one array to another
    }

    {
        int arr[10];
        int *ptr[10];//  ptrs is an array of ten pointers to int
//        int &refs[10];//  error: no arrays of references
        int (*Parry)[10] = &arr;//  Parry points to an array of ten ints
        int (&arrRef)[10] = arr;//  arrRef refers to an array of ten ints

        int *(&array)[10] = ptr;// array is a reference to an array of ten pointers
    }


    {
        int a[10];
        for (int i = 0; i != 10; ++i) {
            a[i] = i;
        }

        int copyArr[10] = {};
        for (int j = 0; j != 10; ++j) {
            copyArr[j] = a[j];
        }

        vector<int> iv(begin(a), end(a));
        for (auto &e : iv) {
            cout << e << " ";
        }
        cout << endl;
        for (const auto &p : a) {
            cout << p << " ";
        }
        cout << endl;
    }


}


/*
 * Exercise 3.27:
 * Assuming txt_size is a function that takes no arguments and returns an int value,
 * which of the following definitions are illegal? Explain why.
 * unsigned buf_size = 1024;
 * int ia[buf_size];   // illegal, The dimension value must be a constant expression.
 * int ia[4 * 7 - 14]; // legal
 * int ia[txt_size()]; // illegal, The dimension value must be a constant expression.
 * char st[11] = "fundamental";  // illegal, the string's size is 12.
 */



/*
 * Exercise 3.28:
 * What are the values in the following arrays?
 * string sa[10];      //all elements are empty strings
 * int ia[10];         //all elements are 0
int main()
{
    string sa2[10]; //all elements are empty strings
    int ia2[10];    //all elements are undefined
}
 */


/*
 * Exercise 3.29:
 * List some of the drawbacks of using an array instead of a vector.
 * Size is fixed at compiling time.
 * No API as that of vector.
 * Bug prone.
 */



/*
 * Exercise 3.30:
 * Identify the indexing errors in the following code:
 * constexpr size_t array_size = 10;
 * int ia[array_size];
 * for (size_t ix = 1; ix <= array_size; ++ix)
 * ia[ix] = ix;
 * Answer:
 * When ix equal to 10, the expression ia[ix] becomes a UB, as it is trying to dereference an element out of range.
 */


/*
 * Exercise 3.31:
 * Write a program to define an array of ten ints. Give each
 * element the same value as its position in the array.
 * @see initializingArrays();
 */


/*
 * Exercise 3.32:
 * Copy the array you defined in the previous exercise into
 * another array. Rewrite your program to use vectors.
 * @see initializingArrays();
 */

/*
 * Exercise 3.33:
 * What would happen if we did not initialize the scores array
 * in the program on page 116?
 *
 * Answer:1768841540 27750 258715648 1251937268 2 0 1 0 4201073 1 3174787314
 */



void countScores() {
    unsigned scores[11];
    unsigned grade;
    while (cin >> grade && grade != -1) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }
    for (auto &c : scores) {
        cout << c << " ";
    }
    cout << endl;
}

/*
 * Note:
 * In most expressions, when we use an object of array type, we are really
 * using a pointer to the first element in that array.
 */
void pointerToArrays() {
    string numbs[] = {"one", "two", "three", "four"};
    string *p = numbs; // or string *p = &numbs[0];
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia);//ia2 is an int* that points to the first element in ia

//    ia2 = 42;error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    ia3 = p;Error:cannot assign an int* to an array
    ia3[4] = 5;// ok:assigns the value of i to an element in ia3

    int arr[] = {0, 1, 2, 3, 4,  5, 6, 7, 8, 9};
    int *pp = arr;
    ++pp;
    cout << *pp << endl;

    int *e = &arr[10];
    for (int *b = arr; b != e; ++b) {
        cout << *b << " ";
    }
    cout << endl;

    int *beg = begin(ia);
    int *last = end(ia);


    int array[10];
    for (int *p = array; p != end(array); ++p) {
        *p = 0;
    }
    for (auto &e : array) {
        cout << e << " ";
    }
    cout << endl;


}


/*
 * Exercise 3.34:
 * Given that p1 and p2 point to elements in the same array, what does the following code do?
 * Are there values of p1 or p2 that make this code illegal?
 * p1 += p2 - p1;
 *
 * Answer:
 * It moves p1 with the offset p2 - p1. After this statement, p1 and p2 points to the same address.
 * Any legal value p1, p2 make this code legal.
 */


/*
 * Exercise 3.35:
 * Using pointers, write a program to set the elements in an array to zero.j
 * @see pointerToArrays();
 */


/*
 * Exercise 3.36:
 * Write a program to compare two arrays for equality.
 * Write a similar program to compare two vectors.
 *
 * @see compareIntArrays();
 */

bool compareIntArrays(int *a, int *b, int n) {
    for (int *i = a, *j = b; n > 0; --n) {
        if (*i++ != *j++) {
            return false;
        }
    }
    return true;
}


#include <cstring>

void cStyleStrings() {
    char ca[] = {'C', '+', '+'};
    cout << strlen(ca) << endl; //error: disaster: ca isn't null terminated,but the compiler didn't report the error;


    string s1 = "A string example";
    string s2 = "A different string";
    if (s1 < s2) cout << s1 << endl;
    const char cal[] = "A string example";
    const char ca2[] = "A different string";
//    if (cal < ca2) {} // undefined: compares two unrelated addresses

}


/*
 * Exercise 3.37:
 * What does the following program do?
 * const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
 * const char *cp = ca;
 * while (*cp) {
 * cout << *cp << endl;
 * ++cp;
 * }
 * Answer:
 * This code will print all characters in ca, afterwards as no \0 appended,
 * UB would happen.
 * For most cases, the while loop here won't be terminated as expected and many rubbish would be printed out.
 */


/*
 * Exercise 3.38:
 * In this section, we noted that it was not only illegal but
 * meaningless to try to add two pointers. Why would adding two pointers be meaningless?
 *
 * Answer:
 * Pointer addition is forbidden in C++, you can only subtract two pointers.
 * The reason for this is that subtracting two pointers gives a logically explainable result - the offset in memory between two pointers.
 * Similarly, you can subtract or add an integral number to/from a pointer, which means "move the pointer up or down".
 * Adding a pointer to a pointer is something which is hard to explain.
 * What would the resulting pointer represent?
 * If by any chance you explicitly need a pointer to a place in memory whose address is the sum of some other two addresses,
 * you can cast the two pointers to int, add ints, and cast back to a pointer.
 * Remember though, that this solution needs huge care about the pointer arithmetic and is something you really should never do.
 */



/*
 * Exercise 3.39:
 * Write a program to compare two strings.
 * Now write a program to compare the values of two C-style character strings.
 * @see compareCStyleStrings();
 */


/*
 * Exercise 3.40: Write a program to define two character arrays initialized
 * from string literals. Now define a third character array to hold the
 * concatenation of the two arrays. Use strcpy and strcat to copy the two
 * arrays into the third.
 * @see compareCStyleStrings();
 */
void compareCStyleStrings() {
    const char *s1 = "hello world", *s2 = "hello world yield";
    cout << (strcmp(s1, s2) >= 0 ? s1 : s2) << endl;
    string s3("hello world"), s4("hello world yield");
    cout << (s3 <= s4 ? s4 : s3) << endl;
    char s5[50];
    char *t = strcat(s5, s1);
    char *t1 = strcpy(s5, s2);
    strcpy(s5, t1);
    char *p = s5;
    while (*p) {
        cout << *p;
        ++p;
    }
    cout << endl;
    const char *str = s3.c_str(); //ok
}


void multidimensionalArrays() {
    int arr[10][20][30] = {11};
    int ia[3][4] = {
            {0, 1, 2,  3},
            {4, 5, 6,  7},
            {8, 9, 10, 11}
    };
    // explicitly initialize row 0; the remaining elements are value initialized
    int ix[3][4] = {0, 3, 6, 9};
//    initializes the elements of the first row. The remaining elements are initialized to 0.
    ia[2][3] = arr[0][0][0];
    int (&row)[4] = ia[1];// binds row to the second four-element array in ia

    constexpr size_t rowCnt = 3, colCnt = 4;
    int ib[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            ib[i][j] = i * rowCnt + j;
        }
    }

    size_t cnt = 0;
    for (auto &row : ib) {
        for (auto &col : row) {
            col = cnt;
            ++cnt;
        }
    }

    for (const auto &row : ib) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    int (*p)[4] = ia;// p points to an array of four ints
    p = &ia[2];// p now points to the last element in ia

    for (auto p = ia; p != ia + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/*
 * Exercise 3.43:
 * Write three different versions of a program to print the
 * elements of ia. One version should use a range for to manage the
 * iteration, the other two should use an ordinary for loop in one case using
 * subscripts and in the other using pointers. In all three programs write all the
 * types directly. That is, do not use a type alias, auto, or decltype to
 * simplify the code.
 *
 * @see multidimensionalArrays();
 */


/*
 * Exercise 3.44:
 * Rewrite the programs from the previous exercises using a
 * type alias for the type of the loop control variables.
 * @see multidimensionalArrays();
 */


/*
 * Exercise 3.45: Rewrite the programs again, this time using auto.
 * @see multidimensionalArrays();
 */


void applyStringsApi() {
    interceptPunctuation();
    charToX();
    joinStrings();
    compareStrings();
    inAndOut();
    initializingStrings();
    cStyleStrings();
    compareCStyleStrings();
}


void applyArrays() {
    initializingArrays();
    pointerToArrays();
    int a[] = {1, 2, 3}, b[] = {1, 2, 3};
    cout << compareIntArrays(a, b, 3) << endl;

    int a1[] = {1}, b1[] = {0};
    cout << compareIntArrays(a1, b1, 1) << endl;

}


void applyVectorsApi() {
    countScores();
    sumOfTwoElements();
    toUpperFromVector();
    initializingVectors();
    addNumbsToVector();
    addStringsToVector();
    toDouble();
    toUpperFirstParagraph();
}

int main() {
//    applyStringsApi();
    compareCStyleStrings();
    multidimensionalArrays();


    return 0;
}

