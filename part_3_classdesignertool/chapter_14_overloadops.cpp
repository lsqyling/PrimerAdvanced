//
// Created by shiqing on 19-5-6.
//

#include <fstream>
#include "../common/CommonHeaders.h"

/*
 * Exercise 14.1: In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded
 * operators the same as the built-in operators?
 * Answer:
 * We can call an overloaded operator function directly.
 * An overloaded operator function must either be a member of a class or have at least one parameter of class type.
 * A few operators guarantee the order in which operands are evaluated. These overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.
 *
 *
 *
 * Exercise 14.2: Write declarations for the overloaded input, output, addition, and compound-assignment operators for Sales_data.
 * @see class sd::SalesData;
 *
 *
 * Exercise 14.3: Both string and vector define an overloaded == that can be used to compare objects of those types.
 * Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
 * (a) "cobble" == "stone" (b) svec1[0] == svec2[0] (c) svec1 == svec2 (d) svec1[0] == "stone"
 * Answer:a)neither b)string c)vector d)string
 *
 *
 * Exercise 14.4: Explain how to decide whether the following should be class members:
 * (a) % (b) %= (c) ++ (d) -> (e) << (f) && (g) == (h) ()
 * Answer:symmetrical no member, member, member, member, symmetrical no member, symmetrical no member, no member, member
 *
 *
 * Exercise 14.5: In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes.
 * Decide what, if any, overloaded operators your class should provide. (a) Book (b) Date (c) Employee (d) Vehicle (e) Object (f) Tree
 * Answer: @see Book;
 *
 *
 */


namespace ops {
    class Book {
        friend bool operator==(const Book &lhs, const Book &rhs);

        friend bool operator!=(const Book &lhs, const Book &rhs);

        friend std::ostream &operator<<(std::ostream &os, const Book &book);

    public:
        Book() = default;

        Book(string bkn, string author, string bookNo) : bookName_(bkn), authors_(author), bookNo_(bookNo) {}

    private:
        string bookName_;
        string authors_;
        string bookNo_;
    };

    bool operator==(const Book &lhs, const Book &rhs);

    bool operator!=(const Book &lhs, const Book &rhs);

    std::ostream &operator<<(std::ostream &os, const Book &book);

}


bool ops::operator==(const ops::Book &lhs, const ops::Book &rhs) {
    return lhs.bookNo_ == rhs.bookNo_
           && lhs.bookName_ == rhs.bookName_
           && lhs.authors_ == rhs.authors_;
}

bool ops::operator!=(const ops::Book &lhs, const ops::Book &rhs) {
    return !(lhs == rhs);
}

std::ostream &ops::operator<<(std::ostream &os, const ops::Book &book) {
    os << book.bookName_ << " " << book.bookNo_ << " " << book.authors_;
    return os;
}


void testingBookOps() {
    ops::Book book, bk("C++Primer", "Stanley", "ISBN 978-7-121-15535-2");
    cout << bk << endl;
    cout << (book == bk) << endl;
}


/*
 * Exercise 14.6: Define an output operator for your Sales_data class.
 * @see sd::SalesData.
 * Exercise 14.7: Define an output operator for you String class you wrote for the exercises in § 13.5 (p. 531).
 * @see sd::SalesData.
 * Exercise 14.8: Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).
 * @see class Book.
 */


/*
 * Exercise 14.9: Define an input operator for your Sales_data class.
 * @sd::SalesData;
 *
 * Exercise 14.10: Describe the behavior of the Sales_data input operator if given the following input:
 * (a) 0-201-99999-9 10 24.95 (b) 10 24.95 0-210-99999-9
 * Answer:a)correct b)incorrect
 *
 *
 * Exercise 14.11: What, if anything, is wrong with the following Sales_data input operator? What would happen
 * if we gave this operator the data in the
 * previous exercise?
 * Answer:yes, we will get an an empty SalesData.
 *
 *
 *
 * Exercise 14.12: Define an input operator for the class you used in exercise 7.40 from § 7.5.1 (p. 291).
 * Be sure the operator handles input errors.
 * Answer: Already be done.
 */


/*
 * Exercise 14.13: Which other arithmetic operators (Table 4.1 (p. 139)),
 * if any, do you think Sales_data ought to support? Define any you think the class should include.
 * yes, @see class sd::SalesData, += and + operators have been defined.
 *
 *
 *
 *
 * Exercise 14.14: Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?
 * if you are not sure, refer to this link @https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the
 *
 *
 *
 * Exercise 14.15: Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators?
 * If so, implement them. If not, explain why not.
 * Answer:Arithmetic operator implementations can quantify the amount of addition,
 * and there are no members in this class that can be quantified.
 */


/*
 * Exercise 14.16: Define equality and inequality operators for your StrBlob(§ 12.1.1, p. 456),
 * StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p.526), and String (§ 13.5, p. 531) classes.
 * @see class StrBlob.
 *
 * Exercise 14.17: Should the class you chose for exercise 7.40 from § 7.5.1(p. 291) define the equality operators?
 * If so, implement them. If not, explain why not.
 * yes, already be done.
 */



/*
 * Exercise 14.18: Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.
 * already be done.
 *
 * Exercise 14.19: Should the class you chose for exercise 7.40 from § 7.5.1(p. 291) define the relational operators?
 * If so, implement them. If not, explain why not.
 * yes, already be done.
 *
 */


/*
 * Exercise 14.20: Define the addition and compound-assignment operators for your Sales_data class.
 * @see class sd::SalesData.
 *
 *
 * Exercise 14.21: Write the Sales_data operators so that + does the actual addition and += calls +.
 * Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p.564).
 * @see https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the
 *
 *
 * Exercise 14.22: Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.
 * yes, already be done.
 *
 * Exercise 14.23: Define an initializer_list assignment operator for your version of the StrVec class.
 * @class Vector;
 *
 * Exercise 14.24: Decide whether the class you used in exercise 7.40 from §7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.
 * yes, already be done.
 *
 *
 * Exercise 14.25: Implement any other assignment operators your class should define. Explain which types should be used as operands and why.
 * yes, already be done.
 */

/*
 * Exercise 14.26: Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.
 * @see class String, StrBlobPtr etc.
 */



/*
 * Exercise 14.27: Add increment and decrement operators to your StrBlobPtr class.
 * yes, already be done. see class StrBlobPtr.
 *
 * Exercise 14.28: Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).
 * yes, already be done.
 *
 * Exercise 14.29: We did not define a const version of the increment and decrement operators. Why not?
 * yes, already be done.
 */



/*
 * Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22
 * from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must
 * return const references because the data member in constStrBlobPtr points to a const vector.
 * yes, @see class ConstStrBlob.
 *
 * Exercise 14.31: Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?
 * default behavior is ok.
 *
 *
 * Exercise 14.32: Define a class that holds a pointer to a StrBlobPtr.
 * Define the overloaded arrow operator for that class.
 * yes, @see StrBlobPtr.
 */


/*
 * Exercise 14.34: Define a function-object class to perform an if-then-else operation:
 * The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds,
 * it should return its second parameter; otherwise, it should return its third parameter.
 * @class IfThenElse.
 *
 *
 * Exercise 14.35: Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read.
 * If the read fails, return the empty string.
 * @see testingOps();
 *
 *
 * Exercise 14.36: Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.
 * @see testingOps();
 *
 * Exercise 14.37: Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all
 * instances of a given value in a sequence.
 * @see class testingOps();
 */


namespace ops {
    template<typename FirArg, typename SecArg, typename ThirdArg>
    struct IfThenElse {
        auto operator()(FirArg f, SecArg s, ThirdArg t) const {
            return f ? s : t;
        }
    };

    struct PrintString {

        string operator()(std::istream &is = cin) {
            string line;
            if (getline(is, line)) {
                return line;
            }

            return string();
        }
    };

    template<class FArg, class SArg>
    struct Equals {
        bool operator()(FArg first, SArg second) {
            return first == second;
        }
    };


}


const string tiny_text = "../../part_2_stdlib/tiny_text.txt";

void testingOps() {
    using namespace ops;
    IfThenElse<bool, int, int> ite;
    cout << ite(3 > 5, 3, 5) << endl;
    std::ifstream ifs(tiny_text);
    vector<string> lines;
    PrintString ps;
    string s;
    while (!(s = ps(ifs)).empty()) {
        lines.push_back(std::move(s));
    }

    for (const auto &item : lines) {
        cout << item << '\n';
    }
    Equals<int, int> equals;
    cout << equals(3, 5) << endl;
}


/*
 * Exercise 14.38: Write a class that tests whether the length of a given string matches a given bound.
 * Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.
 * @see class LengthOfString.
 *
 * Exercise 14.39: Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.
 * @testing testingLenghtOfCounts();
 *
 * Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of lambdas.
 * @see testingLenghtOfCounts();
 *
 * Exercise 14.41: Why do you suppose the new standard added lambdas? Explain when you would use
 * a lambda and when you would write a class instead.
 * @see testingLengthOfCounts():
 */
#include <map>

namespace ops {

    struct LengthOfString {
        int operator()(const string &s) const {
            return s.size();
        }
    };

    std::map<string, int> wordsCount(string filePath) {
        std::map<string, int> counts;
        std::ifstream ifs(filePath);
        string s;
        while (ifs >> s) {
            ++counts[s];
        }
        return counts;
    }

    std::map<int, int> lengthCounts(std::map<string, int> &m) {
        std::map<int, int> lenToCounts;
        LengthOfString lengthOfString;
        for (const auto &pair : m) {
            lenToCounts[lengthOfString(pair.first)] += pair.second;
        }
        return lenToCounts;
    }


    std::map<int, int> lengthCounts(string filePath) {
        std::map<int, int> counts;
        std::ifstream ifs(filePath);
        string s;
        while (ifs >> s) {
            ++counts[s.size()];
        }
        return counts;
    }


}

const string bigger_text = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";

void testingLenghtOfCounts() {
    auto m = ops::wordsCount(bigger_text);
    auto resultMap = ops::lengthCounts(m);
    for (const auto &pair : resultMap) {
        cout << "The length is: " << pair.first
             << " ,occurs " << pair.second
             << " times" << "\n";
    }
    cout << endl;
}

void testingLengthOfCountsSmart() {
    auto m = ops::lengthCounts(bigger_text);
    for (const auto &pair : m) {
        cout << "The length is: " << pair.first
             << " ,occurs " << pair.second
             << " times" << "\n";
    }
    cout << endl;
}


/*
 * Exercise 14.42: Using library function objects and adaptors, define an expression to
 * (a) Count the number of values that are greater than 1024
 * (b) Find the first string that is not equal to pooh
 * (c) Multiply all values by 2
 * Answer:a,GreaterThan b,ret c,Multiply
 *
 *
 * Exercise 14.43: Using library function objects, determine whether a given int value is divisible by any element in a
 * container of ints.
 * @see DivisibleInt.
 */


namespace ops {
    struct GreaterThan {
        bool operator()(int val, int limit = 1024) const {
            return val > limit;
        }
    };

    auto ret = [](const string &s) -> bool {
        return s == "pooh" ? true : false;
    };

    template<typename T>
    struct Multiply {
        T operator()(T t, T def = 2) {
            return t / def;
        }
    };

    template<typename Container>
    struct DivisibleInt {
        using Iterator = typename Container::iterator;

        bool operator()(Iterator beg, Iterator end, int given) const {
            while (beg != end) {
                if (given % *beg) {
                    return false;
                }
                ++beg;
            }
            return true;
        }
    };


}


void testingSeflOps() {
    ops::GreaterThan gt;
    cout << gt(100) << endl;
    cout << ops::ret("hello") << endl;
    ops::Multiply<int> multi;
    cout << multi(8) << endl;
    vector<int> vi{2, 3, 4, 5, 7, 9, 11};
    ops::DivisibleInt<vector<int>> di;
    cout << "-------------------------" << endl;
    cout << di(vi.begin(), vi.end(), 2 * 3 * 4 * 5 * 7 * 9 * 11) << endl;
}


/*
 * Exercise 14.44: Write your own version of a simple desk calculator that can handle binary operations.
 * @see class Calculator.
 */

namespace ops {
    class Calculator {
    public:
        Calculator(double a, double b, char op) : opsA_(a), opsB_(b), op_(op) {
            if (tables_.size()) return ;
            init();
        }
        double getEvaluation() const {
            auto it = tables_.find(op_);
            if (it != tables_.end()) {
                return it->second(opsA_, opsB_);
            }
            throw std::runtime_error("Sorry, there are no related operators.");
        }

    private:
        double opsA_, opsB_;
        char op_;
        static std::map<char, std::function<double (double, double)>> tables_;

        static void init() {
            tables_.insert({'+', [](double a, double b){ return a + b; }});
            tables_.insert({'-', [](double a, double b){ return a - b; }});
            tables_.insert({'*', [](double a, double b){ return a * b; }});
            tables_.insert({'/', [](double a, double b){ return a / b; }});
        }

    };

    std::map<char, std::function<double (double, double)>> Calculator::tables_;
}


void testingCalculator() {
    ops::Calculator c1(5, 4, '+');
    ops::Calculator c2(5, 4, '-');
    ops::Calculator c3(5, 4, '*');
    ops::Calculator c4(5, 4, '/');
    ops::Calculator c5(5, 4, '^');
    cout << c1.getEvaluation() << endl;
    cout << c2.getEvaluation() << endl;
    cout << c3.getEvaluation() << endl;
    cout << c4.getEvaluation() << endl;
    cout << c5.getEvaluation() << endl;
}


/*
 * Exercise 14.45: Write conversion operators to convert a Sales_data to string and to double.
 * What values do you think these operators should return?
 * @see class SalesData.
 *
 * Exercise 14.46: Explain whether defining these Sales_data conversion operators is a good idea and whether
 * they should be explicit.
 * Answer:It's a bad idea to do so, because these conversion is misleading.
 * explicit should be added to prevent implicit conversion.
 *
 *
 * Exercise 14.47: Explain the difference between these two conversion operators:
 * struct Integral {
 *      operator const int(); // meaningless, it will be ignored by compiler.
 *      operator int() const;
 * };
 * @see struct Integeral.
 *
 *
 * Exercise 14.48: Determine whether the class you used in exercise 7.40 from§ 7.5.1 (p. 291) should have a
 * conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.
 * yes, already be done.
 *
 *
 * Exercise 14.49: Regardless of whether it is a good idea to do so, define a conversion to bool for the class
 * from the previous exercise.
 * yes, already be done.
 */

namespace ops {
    struct Integral {
        explicit Integral(int val) : val_(val) {}
        operator const int() { return val_;}// meaningless, it will be ignored by compiler.
//        operator int() const { return val_; }// promising that this operator will not change the state of the obj
    private:
        int val_;
    };
}

void testingIntegral() {
    ops::Integral integral(3);
    cout << integral + 3 << endl;
}


/*
 * Exercise 14.50: Show the possible class-type conversion sequences for the initializations of ex1 and ex2.
 * Explain whether the initializations are legal or not.
 * Answer:
 * int ex1 = ldObj;    // error ambiguous: double or float?
 * float ex2 = ldObj;  // legal
 *
 * Exercise 14.51:
 * Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable
 * function is selected.
 * Answer:
 * best viable function: void calc(int). cause class-type conversion is the lowest ranked.
 * review the order:
 * exact match
 * const conversion
 * promotion
 * arithmetic or pointer conversion
 * class-type conversion
 *
 * Exercise 14.52:Which operator+, if any, is selected for each of the addition expressions?
 * List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:
 * Answer:ld = si + ld; is ambiguous. ld = ld + si can use both 1 and 2,
 * but 1 is more exactly. (in the 2, SmallInt need to convert to double)
 *
 *
 * Exercise 14.53:
 * Given the definition of SmallInt on page 588,
 * determine whether the following addition expression is legal. If so, what addition operator is used?
 * If not, how might you change the code to make it legal?
 * Answer:
 * SmallInt s1;
 * double d = s1 + SmallInt(3.14);
 *
 *
 */




int main(int argc, char *argv[]) {
    testingIntegral();
    testingCalculator();
    testingSeflOps();
    testingLenghtOfCounts();
    testingLengthOfCountsSmart();
    testingOps();
    testingBookOps();


    return 0;
}


