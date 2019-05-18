//
// Created by shiqing on 19-5-14.
//

#include <tuple>
#include <random>
#include <boost/tuple/tuple_io.hpp>
#include <bitset>
#include <regex>
#include <fstream>
#include "../common/CommonHeaders.h"


/*
 * Exercise 17.1: Define a tuple that holds three int values and initialize the members to 10, 20, and 30.
 * @namespace ch17_1;
 *
 * Exercise 17.2: Define a tuple that holds a string, a vector<string>, and a pair<string, int>.
 * @namespace ch17_1;
 *
 *
 * Exercise 17.3: Rewrite the TextQuery programs from § 12.3 (p. 484) to use a tuple instead of the QueryResult class.
 * Explain which design you think is better and why.
 * @namespace ch17_1;
 */
const string filePhone = "../../part_4_advancedtheme/phone";
namespace ch17_1 {


    template<typename Tuple, unsigned N>
    struct TuplePrint {
        static std::ostream &printTuple(std::ostream &os, const Tuple &tuple) {
            TuplePrint<Tuple, N - 1>::printTuple(os, tuple);
            os << std::get<N - 1>(tuple) << " ";
            return os;
        }
    };

    template<typename Tuple>
    struct TuplePrint<Tuple, 1> {
        static std::ostream &printTuple(std::ostream &os, const Tuple &tuple) {
            os << std::get<0>(tuple) << " ";
            return os;
        }
    };


    template<typename...Args>
    std::ostream &printTuple(std::ostream &os, const std::tuple<Args...> &tuple) {
        os << "{";
        TuplePrint<decltype(tuple), sizeof...(Args)>::printTuple(os, tuple);
        os << "}";
        return os;
    }


    void testingTuple() {
        std::tuple<int, int, int> threeI(10, 20, 30);
        printTuple(cout, threeI);
        cout << boost::make_tuple("InsideZhang", 23, "HeNan") << endl;
    }
}


/*
 * Exercise 17.4: Write and test your own version of the findBook function.
 * already done.
 * Exercise 17.5: Rewrite findBook to return a pair that holds an index and a pair of iterators.
 * already done.
 * Exercise 17.6: Rewrite findBook so that it does not use tuple or pair.
 * already done.
 * Exercise 17.7: Explain which version of findBook you prefer and why.
 * already done.
 * Exercise 17.8: What would happen if we passed Sales_data() as the third parameter to accumulate in the last code example in this section?
 * already done.
 *
 */


/*
 * Exercise 17.9: Explain the bit pattern each of the following bitset objects contains:
 * @see testingBitSet();
 */



/*
 * Exercise 17.10: Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a bitset that has a 1 bit in each position
 * corresponding to a number in this sequence. Default initialize another bitset and write a small program to turn on each of the appropriate bits.
 * @see testingBitSet();
 *
 *
 * Exercise 17.11: Define a data structure that contains an integral object to
 * track responses to a true/false quiz containing 10 questions. What changes, if any,
 * would you need to make in your data structure if the quiz had 100 questions?
 * Answer:unsigned , bisset<100>
 *
 * Exercise 17.12: Using the data structure from the previous question, write a function that takes a question number
 * and a value to indicate a true/false answer and updates the quiz results accordingly.
 * @see validate();
 * Exercise 17.13: Write an integral object that contains the correct answers for the true/false quiz.
 * Use it to generate grades on the quiz for the data structure from the previous two exercises.
 * already done.
 *
 */


namespace ch17_2 {
    void testingBitSet() {
        std::bitset<64> bitvec(32);
        std::bitset<32> bv(1010101);
        cout << bitvec << endl;
        cout << bv << endl;
        cout << bv[0] << endl;
        cout << 0xffffffffU << endl;

        std::bitset<22> ans;
        ans.set(1, 1);
        ans.set(2, 1);
        ans.set(3, 1);
        ans.set(5, 1);
        ans.set(8, 1);
        ans.set(13, 1);
        ans.set(21, 1);

        cout << ans << endl;
    }

    std::bitset<100> vi;

    bool validate(unsigned pos, bool val) {
        vi.set(pos, val);
        return vi[pos];
    }


}


/*
 * Exercise 17.14: Write several regular expressions designed to trigger various errors.
 * Run your program to see what output your compiler generates for each error.
 * @see namespace regx;
 *
 * Exercise 17.15: Write a program using the pattern that finds words that violate the “i before e except after c” rule.
 * Have your program prompt the user to supply a word and indicate whether the word is okay or not.
 * Test your program with words that do and do not violate the rule.
 * @see namespace regx;
 *
 *
 * Exercise 17.16: What would happen if your regex object in the previous program were initialized with "[^c]ei"?
 * Test your program using that pattern to see whether your expectations were correct.
 * @see namespace regx;
 *
 *
 *
 */


/*
 * Exercise 17.17: Update your program so that it finds all the words in an
 * input sequence that violiate the “ei” grammar rule.
 * @see useRegex();
 *
 * Exercise 17.18: Revise your program to ignore words that contain “ei” but are not misspellings, such as “albeit” and “neighbor.”
 * @see useRegex();
 *
 *
 */

namespace regx {
    void useRegex() {
        string pattern = "[[:alpha:]]*" + string("[^c]ei") + "[[:alpha:]]*";
        std::regex reg(pattern);
        string testStr = "receipt freind theif receive";
        std::smatch results;
        if (std::regex_search(testStr, results, reg)) {
            cout << results.str() << endl;
        }
        for (std::sregex_iterator it(testStr.begin(), testStr.cend(), reg), endIt; it != endIt; ++it) {
            cout << it->str() << endl;
        }
    }

    void matchCPlusPlusExtends() {
        try {
            string pattern = "[[:alnum:]]+\\.(cpp|cxx|cc)$";
            std::regex r(pattern, std::regex::icase);
            string fileName = "/home/shiqing/workspace/clion/PrimerAdvanced/part_4_advancedtheme/chapter_17_speciallib.cpp";
            std::smatch result;
            if (std::regex_search(fileName, result, r)) {
                cout << result.str() << endl;
            }
        } catch (std::regex_error e) {
            cout << e.what() << "\ncode: " << e.code() << endl;
        }

    }


    bool valid(const std::smatch &m) {
        if (m[1].matched) {
            return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
        } else {
            return !m[3].matched && m[4].str() == m[6].str();
        }
    }


    void searchMatchedPone() {
        string phonePattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(phonePattern);
        std::smatch m;
        string s;
        std::ifstream ifs(filePhone);
        while (getline(ifs, s) && s != "no") {
            for (std::sregex_iterator it(s.begin(), s.cend(), r), endIt; it != endIt; ++it) {
                if (valid(*it)) {
                    cout << "valid: " << it->str() << endl;
                } else {
                    cout << "not valid: " << it->str() << endl;
                }
            }
        }

    }


}

/*
 * Exercise 17.19: Why is it okay to call m[4].str() without first checking whether m[4] was matched?
 * Answer:
 * We expect that the two delimiters in m[4] and m[6] are the same.
 * If m[4](or m[6]) is mismatched, m[4].str()(or m[6].str() respectively)
 * returns an empty string which can also be compared with the other delimiter.
 *
 * Exercise 17.20: Write your own version of the program to validate phone nubers.
 * @searchMatchedPone();
 *
 * Exercise 17.21: Rewrite your phone number program from § 8.3.2 (p. 323) to use the valid function defined in this section.
 * @searchMatchedPone();
 *
 * Exercise 17.22: Rewrite your phone program so that it allows any number of whitespace characters to separate the three
 * parts of a phone number.
 * @searchMatchedPone();
 *
 *
 * Exercise 17.23: Write a regular expression to find zip codes. A zip code can have five or nine digits.
 * The first five digits can be separated from the remaining four by a dash.
 * @printPostalCode();
 */



/*
 * Exercise 17.24: Write your own version of the program to reformat phone numbers.
 * @namespace regx;
 *
 * Exercise 17.25: Rewrite your phone program so that it writes only the first phone number for each person.
 * @namespace regx;
 *
 *
 * Exercise 17.26: Rewrite your phone program so that it writes only the second and subsequent phone numbers for
 * people with more than one phone number.
 * @namespace regx;
 *
 *
 * Exercise 17.27: Write a program that reformats a nine-digit zip code as ddddd-dddd.
 * @namespace regx;
 *
 *
 */




namespace regx {

    using namespace std::regex_constants;

    bool validCode(const std::smatch &m) {
        if (m[2].matched) {
            return m[1].matched && m[3].matched;
        } else {
            return m[1].matched && (!m[3].matched || m[2].str() == m[3].str());
        }
    }

    void printPostalCode() {
        string postalCodePattern = "(\\d{5})([-])?(\\d{4})?";
        std::regex r(postalCodePattern);
        string s;
        std::ifstream ifs(filePhone);
        while (getline(ifs, s) && s != "no") {
            for (std::sregex_iterator it(s.begin(), s.end(), r), endIt; it != endIt; ++it) {
                if (validCode(*it)) {
                    cout << it->str() << endl;
                } else {
                    cout << it->prefix().str()
                         << "no validate: "
                         << it->str()
                         << it->suffix().str()
                         << endl;
                }
            }
        }
    }


    void writeFormatPhone() {
        std::ifstream ifs(filePhone, std::ifstream::in);
        string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(pattern);
        string format = "($2) $5-$7";
        std::ofstream ofs(filePhone + ".post");
        string line;
        while (getline(ifs, line)) {
            ofs << std::regex_replace(line, r, format) << "\n";
        }
    }


    void writeFormatPhoneNotNames() {
        std::ifstream ifs(filePhone, std::ifstream::in);
        string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(pattern);
        string format = "($2) $5-$7";
        std::ofstream ofs(filePhone + ".post.post");
        string line;
        while (getline(ifs, line)) {
            ofs << std::regex_replace(line, r, format, format_no_copy) << "\n";
        }
    }


    void writeOnePhone() {
        std::ifstream ifs(filePhone, std::ifstream::in);
        string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(pattern);
        string fmt = "($2) $5-$7";
        std::ofstream ofs(filePhone + ".post.post.post");
        string line;
        while (getline(ifs, line)) {
            int cnt = 0;
            for (std::sregex_iterator it(line.begin(), line.end(), r), endIt; it != endIt; ++it) {
                if (++cnt == 1) {
                    ofs << it->prefix().str();
                    ofs << it->format(fmt, format_default) << "\n";
                    break;
                }
            }
        }
    }


    void writeFromSecondPhone() {
        std::ifstream ifs(filePhone, std::ifstream::in);
        string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
        std::regex r(pattern);
        string fmt = "($2) $5-$7";
        std::ofstream ofs(filePhone + ".post.post.post.post");
        string line;
        while (getline(ifs, line)) {
            int cnt = 0;
            for (std::sregex_iterator it(line.begin(), line.end(), r), endIt; it != endIt; ++it) {
                auto tmp = it;
                if (++cnt == 1 && ++tmp == endIt) {
                    ofs << it->format(fmt, format_default) << "\n";
                } else {
                    ofs << it->format(fmt) << "\n";
                }
            }
        }
    }
}




/*
 * Exercise 17.28: Write a function that generates and returns a uniformly distributed random unsigned int each time it is called.
 * @generatePrimitiveNums();
 *
 * Exercise 17.29: Allow the user to supply a seed as an optional argument to the function you wrote in the previous exercise.
 * @generatePrimitiveNums();
 *
 *
 * Exercise 17.30: Revise your function again this time to take a minimum and maximum value for the numbers that the
 * function should return.
 * @generatePrimitiveNums();
 */



/*
 * Exercise 17.31: What would happen if we defined b and e inside the do loop of the game-playing program from this section?
 * @testingPlay():
 * Exercise 17.32: What would happen if we defined resp inside the loop?
 * @testingPlay():
 *
 * Exercise 17.33: Write a version of the word transformation program from §11.3.6 (p. 440) that allows multiple
 * transformations for a given word and randomly selects which transformation to apply.
 * @testingPlay():
 */


namespace stochastic {

    void generatePrimitiveNums() {
        static std::default_random_engine e;
        static std::uniform_int_distribution<unsigned> u(0, 9);
        for (int i = 0; i != 10; ++i) {
            cout << e() << " ";
        }
        cout << endl;
        cout << "e.max() = " << e.max() << ", e.min() = " << e.min() << endl;
        for (int j = 0; j != 10; ++j) {
            cout << u(e) << " ";
        }
        cout << endl;

    }


    void testingNormalDistribution() {
        static std::default_random_engine e;
        static std::normal_distribution<> n(4, 1.5);
        vector<unsigned> vals(9);
        for (size_t i = 0; i != 200; ++i) {
            unsigned v = lround(n(e));
            if (v < vals.size()) {
                ++vals[v];
            }
        }

        for (size_t j = 0; j != vals.size(); ++j) {
            cout << j << ": " << string(vals[j], '*') << endl;
        }

    }


    bool play(bool p) noexcept {
        static std::default_random_engine e;
        static std::bernoulli_distribution b;
        if (p) {
            cout << "my first" << endl;
        } else {
            cout << "you first " << endl;
        }
        return b(e);
    }

    void testingPlay() {
        string resp;
        static std::default_random_engine e;
        static std::bernoulli_distribution b;
        do {
            bool first = b(e);
            cout << (first ? "We go first" : "You get to go first") << endl;
            cout << (play(first) ? "Sorry, you lost" : "congrates, you won") << endl;
            cout << "play again? Enter 'yes' or 'no'" << endl;
        } while (cin >> resp && resp[0] != 'n');


    }
}


namespace cio {

    void testingStdin() {
        int i = 0, j = 0, k = 0;
        float fp1 = .0;
        char word1[20] = "", word2[20] = "";
//        string word1, word2;
//        k = scanf("%f %d %d %[a-z] %*1d %s", &fp1, &i, &j, word1, word2);
        k = scanf("%4f %4d %d %*d %[a-z] %*1d %[^o]", &fp1, &i, &j, word1, word2);
        printf("\nCount of values read = %d\n", k);
        printf("\nfp1 = %f i = %d j = %d", fp1, i, j);
        printf("\nword1 = %s word2 = %s\n", word1, word2);
    }


    void testingStdinAnother() {
        int i = 0, j = 0, k = 0;
        float fp1 = 0.0;
//        inputs:fp1=3.1415926i=78
        k = scanf("fp1=%9fi=%1d%d", &fp1, &i, &j);
        printf("\nCount of values read = %d", k);
        printf("\nfp1 = %f\ti = %d\tj = %d\n", fp1, i, j);
    }

    void testingStdinFloat() {
        float i = .0f, j = .0f, k = .0f;
        int kCnt = 0;
//        kCnt = scanf("%f %f %f", &i, &j, &k);
        kCnt = scanf("%e %g %f", &i, &j, &k);
        printf("\nCounts of vlaue read = %d", kCnt);
        printf("\ni = %f, j = %f, k = %f", i, j, k);
    }

    void testingStdout() {
        int i = 15, j = 345, k = 4567;
        long li = 56789L, lj = 678912L, lk = 23456789L;
        printf("\ni = %d\tj = %d\tk = %d\ti = %6.3d\tj = %6.3d\tk = %6.3d\n", i, j, k, i, j, k);
        printf("\ni = %-d\tj = %+d\tk = %-d\ti = %-6.3d\tj = %-6.3d\tk = %-6.3d\n", i, j, k, i, j, k);
        printf("\nli = %ld\tlj = %ld\tlk = %ld\n", li, lj, lk);
        printf("\nli = %ld\tlj = %ld\tlk = %ld\n", li, lj, lk);


        int m = 678;
//        Display format as heading then display the values
        printf("\n\n%%8d\t\t%%-8d\t\t%%08d\t\t%%-+8d");
        printf("\n%8d\t\t%-8d\t\t%08d\t\t%-+8d", k, k, k, k);


        float fp1 = 345.678f, fp2 = 1.234E6f;
        double fp3 = 234567898.0, fp4 = 11.22334455e-6;
        printf("\n\n%f    %+f    %-10.4f    %6.4f\n", fp1, fp2, fp3, fp4);
        printf("\n%e    %+E\n", fp1, fp2);
        printf("\n%f    %g    %#+f    %10.4g\n", fp3, fp3, fp3, fp4);

        char str[] = "Jabberwocky!\n";
        puts(str);
        char *cp = str;
        while (*cp) {
            putchar(*cp++);
        }

    }

    const char *fileSrcText = "../../part_2_stdlib/tiny_text.txt";
    const char *myFile = "../../part_4_advancedtheme/myfile.txt";
    void testingIOFile() {
//        open a file that existed or not
//        Open file myFile.txt to write it
        fopen(myFile, "w");
        const char *tmp = "../../part_4_advancedtheme/myfile_tmp.txt";
        const char *myCopy = "../../part_4_advancedtheme/myfile_copy.txt";
        fopen(tmp, "w");

//        rename file
        int flag = rename(tmp, myCopy);
        if (flag == 0) {
            printf("File renamed successfully.");
        }

//        first create a file
//        second remove it
        fopen(tmp, "w");
        remove(tmp);


        printf("\nEnter an interesting string.\n");
        FILE *filePtr = fopen(fileSrcText, "r");
        if (filePtr == NULL) {
            printf("Error opening %s for writig. program terminated", fileSrcText);
            abort();
        }

        int ch = 0;
        while ((ch = fgetc(filePtr)) != EOF) {
            putchar(ch);
        }
        fclose(filePtr);

        filePtr = fopen(myFile, "a");
        if (filePtr) {
            FILE *pf = fopen(fileSrcText, "r");
            if (pf) {
                while ((ch = fgetc(pf)) != EOF) {
                    fputc(ch, filePtr);
                }
                fclose(pf);
            }
            fclose(filePtr);
        }














    }




}


int main() {
    regx::writeFromSecondPhone();
    regx::writeOnePhone();
    regx::writeFormatPhoneNotNames();
    regx::writeFormatPhone();
    regx::printPostalCode();
    regx::searchMatchedPone();
    regx::matchCPlusPlusExtends();
    regx::useRegex();
    ch17_1::testingTuple();
    ch17_2::testingBitSet();
    for (int i = 0; i != 10; ++i) {
        stochastic::generatePrimitiveNums();
    }
    stochastic::testingNormalDistribution();
//    stochastic::testingPlay();
//    cio::testingStdin();
//    cio::testingStdinAnother();
    cio::testingStdout();
    cio::testingIOFile();
    return 0;
}
