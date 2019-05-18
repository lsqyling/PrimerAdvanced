//
// Created by shiqing on 19-4-21.
//
#include <random>
#include "../common/CommonHeaders.h"


/*
 * Exercise 5.1:
 * What is a null statement? When might you use a null statement?
 * Answer:
 * A null statement is the empty statement. like this:
 * ; // null statement
 */


/*
 * Exercise 5.2:
 * What is a block? When might you might use a block?
 * Answer:
 * A block is a (possibly empty) sequence of statements and declarations surrounded by a pair of curly braces.It's used when multiple statements are needed.For example:
 * while (val <= 10)
 * {
 * sum += val;
 * ++val;
 * }
 */


/*
 * Exercise 5.3:
 * Use the comma operator (§ 4.10, p. 157) to rewrite the
 * while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain
 * whether this rewrite improves or diminishes the readability of this code.
 * @see commaStatements();
 */

//Exercise 5.4:
//
//Explain each of the following examples, and correct any problems you detect.
//
//(a) while (string::iterator iter != s.end()) {  . . .  }
//(b) while (bool status = find(word)) {  . . . / } if (!status) { / . . .  }
//
//(a) Illegal declaration : string::iterator iter != s.end()
//
////corrrected as:
//std::string::iterator iter = s.begin();
//while (iter != s.end()) {  . . .  }
//
//(b) Variable status is only declared inside scope of while condition.
//
////corrrected as:
//bool status;
//while (status = find(word)) {  ...  }
//if (!status) {  ...  }



void commaStatements() {
    int sum = 0, n = 0;
    while (n <= 10) {
        sum += n;
        ++n;

        // sum += n, ++n;
    }
}


/*
 * Exercise 5.5:
 * Using an if–else statement, write your own version of the
 * program to generate the letter grade from a numeric grade.
 * @see scoreLevels();
 */

/*
 * Exercise 5.6:
 * Rewrite your grading program to use the conditional operator
 * (§ 4.7, p. 151) in place of the if–else statement.
 * @see scoreLevels();
 */


//Exercise 5.7:
//Correct the errors in each of the following code fragments:
//(a) if (ival1 != ival2) ival1 = ival2
//else ival1 = ival2 = 0;
//(b) if (ival < minval) minval = ival;
//occurs = 1;
//(c) if (int ival = get_value())
//cout << "ival = " << ival << endl;
//if (!ival)
//cout << "ival = 0\n";
//(d) if (ival = 0)
//ival = get_value();
//(a) if (ival1 != ival2) ival1 = ival2;  // Need to add semicolon.
//else ival1 = ival2 = 0;
//(b) if (ival < minval)                  // Braces needed to include both satetments in scope.
//{
//minval = ival;
//occurs = 1;
//}
//(c) if (int ival = get_value())         //Second if statement should be else-if.
//cout << "ival = " << ival << endl;
//else if (!ival)
//cout << "ival = 0\n";
//(d) if (ival == 0)                      //Expression changed from assignment to "equal to";
//ival = get_value();


/*
 * Exercise 5.8:
 * What is a “dangling else”? How are else clauses resolved in C++?
 * Answer:
 * Colloquial term used to refer to the problem of how to process nested
 * if statements in which there are more ifs than elses.
 * In C++, an else is always paired with the closest preceding unmatched if.
 */

string scoreLevels(unsigned score) {
    string letterGrade;
    const string sv[] = {"F", "D", "C", "B", "A", "A++"};
    if (score < 60) {
        letterGrade = sv[0];
    } else {
        letterGrade = sv[(score - 50) / 10];
        if (score != 100) {
            if (score % 10 > 7) {
                letterGrade += "+";
            } else if (score % 10 < 3) {
                letterGrade += "-";
            }
        }
    }

    return letterGrade;
}

void testingScoreLevels() {
    vector<string> sv;
    for (int i = 0; i != 101; ++i) {
        sv.push_back(scoreLevels(i));
    }
    for (const auto &e : sv) {
        cout << e;
    }
    cout << endl;
}


void caseStatements() {
    char ch;
    unsigned vowelCnt = 0, otherCnt = 0;
    while (cin >> ch && ch != 'n') {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt;
                break;
            case true:
//                string fileName;// error: control bypasses an implicitly initialized
//                int ival = 0;// error: control bypasses an explicitly initialized
                int jval;// ok: because jval is not initialized
                break;
            case false:
                jval = 0;//ok assign a value to jval

            default:
                ++otherCnt;
                break;
        }
    }

    cout << "Number of vowel is: " << vowelCnt << ", the other is: " << otherCnt << endl;
}

/*
 * Exercise 5.9:
 * Write a program using a series of if statements to count the
 * number of vowels in text read from cin.
 * @see countIfStatements();
 */



void countIfStatements() {
    char ch;
    unsigned vowelCnt = 0, otherCnt = 0;
    while (cin.get(ch) && ch != 'n') {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++vowelCnt;
        } else {
            ++otherCnt;
        }
    }
    cout << "Number of vowel is: " << vowelCnt << ", the other is: " << otherCnt << endl;
}


/*
 * Exercise 5.10:
 * There is one problem with our vowel-counting program as
 * we’ve implemented it: It doesn’t count capital letters as vowels. Write a
 * program that counts both lower- and uppercase letters as the appropriate
 * vowel—that is, your program should count both 'a' and 'A' as part of
 * aCnt, and so forth.
 * @see countVowel();
 */

/*
 * Exercise 5.11:
 * Modify our vowel-counting program so that it also counts the
 * number of blank spaces, tabs, and newlines read.
 * @see countVowel();
 */

void countVowel() {
    char ch;
    unsigned aVowelCnt = 0, eVowelCnt = 0, iVowelCnt = 0, oVowelCnt = 0, uVowelCnt = 0;
    unsigned spaceCnt = 0, nCnt = 0, tCnt = 0;
    while (cin.get(ch) && ch != 'N') {
        switch (ch) {
            case 'a':
            case 'A':
                ++aVowelCnt;
                break;
            case 'e':
            case 'E':
                ++eVowelCnt;
                break;
            case 'i':
            case 'I':
                ++iVowelCnt;
                break;
            case 'o':
            case 'O':
                ++oVowelCnt;
                break;
            case 'u':
            case 'U':
                ++uVowelCnt;
                break;
            case '\12':
                ++nCnt;
                break;
            case '\40':
                ++spaceCnt;
                break;
            case '\t':
            case '\v':
                ++tCnt;
                break;
            default:;
        }
    }
    cout << "Number of vowel a or A is: " << aVowelCnt << endl;
    cout << "Number of vowel e or E is: " << eVowelCnt << endl;
    cout << "Number of vowel i or I is: " << iVowelCnt << endl;
    cout << "Number of vowel o or O is: " << oVowelCnt << endl;
    cout << "Number of vowel u or U is: " << uVowelCnt << endl;
    cout << "Number of vowel space is: " << spaceCnt << endl;
    cout << "Number of vowel newline is: " << nCnt << endl;
    cout << "Number of vowel tab is: " << tCnt << endl;
}

/*
 * Exercise 5.12: Modify our vowel-counting program so that it counts the
 * number of occurrences of the following two-character sequences: ff, fl,
 * and fi.
 * @see countSequencesOfF();
 */

void countSequencesOfF() {
    vector<char> vi;
    char ch;
    while (cin.get(ch) && ch != 'N') {
        vi.push_back(ch);
    }
    auto beg = vi.begin();
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    while (beg != vi.end()) {
        if (*beg++ == 'f' && beg != vi.end()) {
            switch (*beg) {
                case 'f':
                    ++ffCnt, ++beg;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        }
    }
    cout << "The number ff is: " << ffCnt << endl;
    cout << "The number fi is: " << fiCnt << endl;
    cout << "The number fl is: " << flCnt << endl;
}


/*
 * Exercise 5.13:
 * Each of the programs in the highlighted text on page 184
 * contains a common programming error. Identify and correct each error.
 * already be done.
 */


/*
 * Exercise 5.14:
 * Write a program to read strings from standard input
 * looking for duplicated words. The program should find places in the input
 * where one word is followed immediately by itself. Keep track of the largest
 * number of times a single repetition occurs and which word is repeated. Print
 * the maximum number of duplicates, or else print a message saying that no
 * word was repeated.
 * @see countDuplicateWords();
 */

void countDuplicateWords() {
    string currWord;
    if (cin >> currWord && currWord[0] != 'N') {
        string nextWord, maxTimesWord;
        unsigned cnt = 1, maxCnt = 1;
        while (cin >> nextWord && nextWord[0] != 'N') {
            if (currWord == nextWord) {
                ++cnt;
                if (maxCnt < cnt) {
                    maxCnt = cnt;
                    maxTimesWord = nextWord;
                }
            } else {
                currWord = nextWord;
                cnt = 1;
            }
        }
        if (maxCnt > 1) {
            cout << "The most frequently occurring word in the sequence is: " << maxTimesWord
                    << ", and the times is: " << maxCnt << endl;
        } else {
            cout << "no word was repeated." << endl;
        }

    } else {
        cout << "no inputs!?" << endl;
    }
}


/*
 * Exercise 5.15:
 * Explain each of the following loops. Correct any problems you detect.
 * already be done.
 */

/*
 * Exercise 5.16:
 * The while loop is particularly good at executing while some condition holds;
 * for example, when we need to read values until end-of-file.
 * The for loop is generally thought of as a step loop: An index steps through a range of values in a collection.
 * Write an idiomatic use of each loop and then rewrite each using the other loop construct.
 * If you could use only one loop, which would you choose? Why?
 * answer:
 * I prefer for to while in such cases, because it's terse.
 * More importantly, object i won't pollute the external scope after it goes out of the loop.
 * It's a little bit easier to add new code into the external scope,
 * since it reduces the possibility of naming conflicts .That is, a higher maintainability.
 * Of course, this way makes the code a bit harder to read.
 */


/*
 * Exercise 5.17:
 * Given two vectors of ints, write a program to determine
 * whether one vector is a prefix of the other. For vectors of unequal
 * length, compare the number of elements of the smaller vector. For
 * example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
 * 8, respectively your program should return true.
 *
 */


bool isPrefixVec(const vector<int> &vt, const vector<int> &vs) {
    auto sz = vt.size();
    for (decltype(sz) i = 0; i != sz; ++i) {
        if (vt[i] != vs[i]) return false;
    }
    return true;
}


/*
 * Exercise 5.17:
 * Given two vectors of ints, write a program to determine
 * whether one vector is a prefix of the other. For vectors of unequal
 * length, compare the number of elements of the smaller vector. For
 * example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
 * 8, respectively your program should return true.
 * @see testingIsPrefixVec();
 */

void testingIsPrefixVec() {
    vector<int> vi = {0, 1, 2, 3}, vs = {0, 1, 2, 3, 5, 6, 7};
    cout << isPrefixVec(vi, vs) << endl;
}



/*
 * Exercise 5.18:
 * Explain each of the following loops. Correct any problems you detect.
(a) do { // added bracket.
        int v1, v2;
        cout << "Please enter two numbers to sum:" ;
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << endl;
    }while (cin);
(b) int ival;
    do {
        // . . .
    } while (ival = get_response()); // should not declared in this scope.
(c) int ival = get_response();
    do {
        ival = get_response();
    } while (ival); // ival is not declared in this scope.
 */


/*
 * Exercise 5.19:
 * Write a program that uses a do while loop to repetitively
 * request two strings from the user and report which string is less than
 * the other.
 * @see
 */

void printShortString() {
    string resp;
    do {
        cout << "enter two string s: " << endl;
        string s1, s2;
        cin >> s1 >> s2;
        cout << (s1.size() < s2.size() ? s1 : s2) << endl;
        cin >> resp;
    } while (!resp.empty() && resp[0] != 'n');
}

/*
 * Exercise 5.20:
 * Write a program to read a sequence of strings from the
 * standard input until either the same word occurs twice in succession or all
 * the words have been read. Use a while loop to read the text one word at a
 * time. Use the break statement to terminate the loop if a word occurs twice
 * in succession. Print the word if it occurs twice in succession, or else print a
 * message saying that no word was repeated.
 *
 */

void outputFirstRepeatWords() {
    string currWord;
    if (cin >> currWord && currWord != "No") {
        string nextWord;
        bool flag = false;
        while (cin >> nextWord && nextWord != "No") {
            if (!isupper(nextWord[0])) continue;
            if (currWord == nextWord/* && isupper(currWord[0])*/) {
                flag = true;
                break;
            }
            currWord = nextWord;
        }
        if (flag) cout << "the repeat word is: " << nextWord << endl;
        else cout << "no repeat word!!" << endl;
    } else {
        cout << "no inputs!?" << endl;
    }

}

/*
 * Exercise 5.21:
 * Revise the program from the exercise in § 5.5.1 (p. 191) so
 * that it looks only for duplicated words that start with an uppercase letter.
 * @see outputFirstRepeatWords();
 */



/*
 * Exercise 5.22:
 * The last example in this section that jumped back to begin
 * could be better written using a loop. Rewrite the code to eliminate the goto.
 * @see applyGoTo();
 */

void applyGoTo() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    begin:
    int sz = vi.size();
    if (sz <= 0) {
        goto begin;
    }
    int size;
    while ((size = vi.size()) <= 0);
}


/*
 * Exercise 5.23:
 * Write a program that reads two integers from the standard
 * input and prints the result of dividing the first number by the second.
 * @see tryArithmeticDivided();
 */


/*
 * Exercise 5.24:
 * Revise your program to throw an exception if the second
 * number is zero. Test your program with a zero input to see what happens on
 * your system if you don’t catch an exception.
 * @see tryArithmeticDivided();
 */

/*
 * Exercise 5.25:
 * Revise your program from the previous exercise to use a
 * try block to catch the exception. The catch clause should print a message
 * to the user and ask them to supply a new number and repeat the code inside the try.
 * @see tryArithmeticDivided();
 */
void tryArithmeticDivided() {
    cout << "enter two integers: " << endl;
    int numerator, denominator;
    cin >> numerator >> denominator;
    int result;
    try {
        if (!denominator) {
            throw std::runtime_error("Arithmetic exception, the denominator must be not zero.");
        }
        result = numerator / denominator;
        cout << "result = " << result << endl;
    } catch (std::runtime_error e) {
        cout << e.what() << endl;
    }
}





int main(int argc, char *argv[]) {
    tryArithmeticDivided();
    outputFirstRepeatWords();
    printShortString();
    testingIsPrefixVec();
    countDuplicateWords();
    countSequencesOfF();
    countVowel();
    caseStatements();
    countIfStatements();
    testingScoreLevels();
    commaStatements();
    return 0;
}
