//
// Created by shiqing on 19-4-27.
//

#include <algorithm>
#include <fstream>
#include <sstream>
#include "../common/CommonHeaders.h"
#include "../part_1_foundation/SalesData.h"


/*
 * Exercise 10.1:
 * The algorithm header defines a function named count
 * that, like find, takes a pair of iterators and a value. count returns a count
 * of how often that value appears. Read a sequence of ints into a vector
 * and print the count of how many elements have a given value.
 * @see testingFindCounts();
 *
 * Exercise 10.2:
 * Repeat the previous program, but read values into a list of strings.
 * @see testingFindCounts();
 *
 */

const string text_file_path = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";
const string mark_file_path = "../../part_2_stdlib/mark.data";
const string numbs_file_path = "../../part_2_stdlib/numbers.txt";



void testingFindCounts() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 3, 3, 3};
    auto cnt = std::count(vi.begin(), vi.end(), 3);
    cout << "The number of times the number 3 appears is: " << cnt << endl;
    vector<string> vs = {"hello", "how", "now", "world", "word", "what", "how"};
    cnt = std::count(vs.begin(), vs.end(), "how");
    cout << "the string of 'how' appears is: " << cnt << endl;
}


/*
 * Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
 * @see accumulateInts();
 *
 *
 * Exercise 10.4: Assuming v is a vector<double>, what, if anything, is
 * wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
 * @see accumulateInts();
 *
 * Exercise 10.5: In the call to equal on rosters, what would happen if both
 * rosters held C-style strings, rather than library strings?
 * @see accumulateInts();
 */


void accumulateInts() {
    vector<int> vi = {0, 1, 3, 4, 5, 6, 7, 8, 9};
    int sum = std::accumulate(vi.cbegin(), vi.cend(), 0);
    cout << "sum = " << sum << endl;
    vector<double> vd = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    auto sumD = std::accumulate(vd.cbegin(), vd.cend(), 0);
    cout << "sumD = " << sumD << '\n';
    sumD = std::accumulate(vd.cbegin(), vd.cend(), 0.0);
    cout << "sumD = " << sumD << endl;

    vector<const char *> roster = {"hello", "world", "!!", "oh", "my", "dear!!"};
    list<string> roster1 = {"hello", "world", "!!", "oh", "my", "dear!!"};

    bool flag = std::equal(roster.cbegin(), roster.cend(), roster1.cbegin());
    cout << "flag = " << flag << endl;
}


/*
 * Exercise 10.6: Using fill_n, write a program to set a sequence of int values to 0.
 * @see changeableContains();
 *
 * Exercise 10.7: Determine if there are any errors in the following programs
 * and, if so, correct the error(s):
 * vector<int> vec; list<int> lst; int i;
 * while (cin >> i)
 * lst.push_back(i);
 * copy(lst.cbegin(), lst.cend(), vec.begin()); //std::back_inserter(vec);
 * (b)
 * vector<int> vec;
 * vec.reserve(10); // reserve is covered in § 9.4 (p. 356) //wrong: vec.resize(10);
 * fill_n(vec.begin(), 10, 0);
 *
 *
 * Exercise 10.8: We said that algorithms do not change the size of the
 * containers over which they operate.Why doesn't the use of back_inserter invalidate this claim?
 *
 * Answer:
 * Inserters like back_inserter is part of <iterator> rather than <algorithm>.
 */

void changeableContains() {
    vector<int> vi{0, 2, 3, 5, 5, 6, 8, 9};
    std::fill_n(vi.begin(), vi.size(), 0);
    for (const auto &item : vi) {
        cout << item << " ";
    }
    cout << '\n';
}

/*
 * Exercise 10.9: Implement your own version of elimDups. Test your
 * program by printing the vector after you read the input, after the call to
 * unique, and after the call to erase.
 * @see elimDups();
 *
 * Exercise 10.10: Why do you think the algorithms don’t change the size of containers?
 * Answer:
 * The library algorithms operate on iterators, not containers. Therefore, an
 * algorithm cannot (directly) add or remove elements.
 */


bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &vs) {
    std::sort(vs.begin(), vs.end());
    auto it = std::unique(vs.begin(), vs.end());
    vs.erase(it, vs.end());
}


/*
 * Exercise 10.11: Write a program that uses stable_sort and isShorter
 * to sort a vector passed to your version of elimDups. Print the vector to
 * verify that your program is correct.
 * @see elimDups();
 *
 *
 * Exercise 10.12: Write a function named compareIsbn that compares the
 * isbn() members of two Sales_data objects. Use that function to sort a
 * vector that holds Sales_data objects.
 *
 *
 *
 * Exercise 10.13:
 * The library defines an algorithm named partition that
 * takes a predicate and partitions the container so that values for which the
 * predicate is true appear in the first part and those for which the predicate is
 * false appear in the second part. The algorithm returns an iterator just past
 * the last element for which the predicate returned true. Write a function that
 * takes a string and returns a bool indicating whether the string has five
 * characters or more. Use that function to partition words. Print the elements
 * that have five or more characters.
 * @see partitionByFunc();
 */

void elimDupsOther(vector<string> &vs) {
    std::sort(vs.begin(), vs.end(), isShorter);
    auto it = std::unique(vs.begin(), vs.end());
    vs.erase(it, vs.end());
}

bool compareIsbn(const SalesData &lhs, const SalesData &rhs) {
    return lhs.isbn() < rhs.isbn();
}

void testingSortSalesData() {
    vector<SalesData> vs = {SalesData("0-201-78345-X"), SalesData("0-201-78345-XX"),
                            SalesData("0-201-78345-XY"), SalesData("0-201-789345-X")};
    std::sort(vs.begin(), vs.end(), compareIsbn);
    for (const auto &elem : vs) {
        print(cout, elem) << " ";
    }
    cout << endl;
}


void testingElimDups() {
    testingSortSalesData();
    vector<string> vs = {"hi", "world", "my", "my", "baby", "baby"};
    elimDups(vs);
    for (const auto &elem : vs) {
        cout << elem << " ";
    }
    cout << '\n';
    vs.push_back("Jag");
    vs.push_back("hi");

    elimDupsOther(vs);
    for (const auto &elem : vs) {
        cout << elem << " ";
    }
    cout << endl;
}

bool greaterThanFiveChars(const string &s) {
    return s.size() >= 25;
}

void partitionByFunc() {
    std::ifstream in(text_file_path, std::ifstream::in);
    vector<string> words;
    string s;
    while (in >> s) {
        words.push_back(s);
    }
    auto it = std::partition(words.begin(), words.end(), greaterThanFiveChars);
    int cnt = 0;
    for (auto beg = words.begin(); beg != it; ++beg) {
        cout << *beg << " ";
        ++cnt;
        if (cnt % 2 == 0) cout << '\n';
    }
    cout << endl;
}

/*
 * Exercise 10.14: Write a lambda that takes two ints and returns their sum.
 * @see mathLambdas();
 *
 *
 * Exercise 10.15: Write a lambda that captures an int from its enclosing
 * function and takes an int parameter. The lambda should return the sum of
 * the captured int and the int parameter.
 * @see mathLambdas();
 *
 *
 * Exercise 10.16: Write your own version of the biggies function using lambdas.
 * @see @biggest();
 *
 * Exercise 10.17: Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
 * lambda in the call to sort instead of the compareIsbn function.
 * @see biggest();
 *
 * Exercise 10.18: Rewrite biggies to use partition instead of find_if.
 * We described the partition algorithm in exercise 10.13 in § 10.3.1 (p.387).
 * @see biggest();
 *
 * Exercise 10.19: Rewrite the previous exercise to use stable_partition,
 * which like stable_sort maintains the original element order in the
 * partitioned sequence.
 * @see biggest();
 */


void mathLambdas() {
    auto add = [](int a, int b) { return a + b; };
    auto subtract = [](auto a, auto b) { return a - b; };
    auto multiply = [](auto a, auto b) { return a * b; };
    auto divided = [](auto a, auto b) { return a / b; };

    cout << add(3, 5) << '\n'
         << subtract(3, 5) << '\n'
         << multiply(3, 5) << '\n'
         << divided(3, 5) << endl;

    int a = 3;
    auto addCapture = [a](int b) { return a + b; };
    cout << addCapture(5) << endl;
}

void biggest(vector<string> &vs, size_t sz) {
    std::sort(vs.begin(), vs.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    std::unique(vs.begin(), vs.end());
    std::stable_sort(vs.begin(), vs.end());
    auto it = std::partition(vs.begin(), vs.end(), [sz](const string &s) { return s.size() > sz; });
//    or it = std::find_if(vs.begin(), vs.end(), [sz](const auto &s) { return s.size() > sz; });
    size_t cnt;
    for (auto beg = vs.begin(); beg != it; ++beg) {
        cout << *beg << " ";
        ++cnt;
        if (cnt % 5 == 0) cout << '\n';
    }
    cout << endl;
}

const string text = "    'Lovely evening!' shouted Uncle Vernon, waving at Mrs Number Seven opposite, who was glaring from behind her net curtains. 'Did you hear that car backfire just now? Gave Petunia and me quite a turn!'\n"
                    "    He continued to grin in a horrible, manic way until all the curious neighbours had disappeared from their various windows, then the grin became a grimace of rage as he beckoned Harry back towards him.\n"
                    "    Harry moved a few steps closer, taking care to stop just short of the point at which Uncle Vernon's outstretched hands could resume their strangling.\n"
                    "    'What the devil do you mean by it, boy?' asked Uncle Vernon in a croaky voice that trembled with fury.\n"
                    "    'What do I mean by what?' said Harry coldly. He kept looking left and right up the street, still hoping to see the person who had made the cracking noise.\n"
                    "    'Making a racket like a starting pistol right outside our - '\n"
                    "    'I didn't make that noise,' said Harry firmly.\n"
                    "    Aunt Petunia's thin, horsy face now appeared beside Uncle Vernon's wide, purple one. She looked livid.\n"
                    "    'Why were you lurking under our window?'";

void testingBiggest() {
    std::istringstream in(text);
    vector<string> vs;
    string s;
    while (in >> s) {
        vs.push_back(s);
    }
    biggest(vs, 5);
}

vector<string> of(const string &text) {
    std::istringstream in(text);
    vector<string> vs;
    string s;
    while (in >> s) {
        vs.push_back(s);
    }
    return vs;
}

void testingCountIf() {
    vector<string> vs = of(text);
    int le = 6;
    auto sz = std::count_if(vs.begin(), vs.end(), [=](const auto &s) { return s.size() > le;});
    cout << "The count number of words longer than 6 is: " << sz << endl;
}

void decreaseLocal() {
    int i = 10;
    auto f = [i]() mutable -> bool {
        if(!i) return true;
        --i;
        return false;
    };
}


/*
 * Exercise 10.22: Rewrite the program to count words of size 6 or less using
 * functions in place of the lambdas.
 * @see countByLambdas();
 *
 * Exercise 10.23: How many arguments does bind take?
 * Answer:
 * Assuming the function to be bound have n parameters, bind take n + 1 parameters.
 * The additional one is for the function to be bound itself.
 *
 * Exercise 10.24: Use bind and check_size to find the first element in a
 * vector of ints that has a value greater than the length of a specified string value.
 * @see findIfByBind();
 *
 *
 * Exercise 10.25: In the exercises for § 10.3.2 (p. 392) you wrote a version
 * of biggies that uses partition. Rewrite that function to use check_size and bind.
 * @see biggestByBind();
 *
 *
 */

#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool greaterThanSpecStr(const string &s, string tar) {
    return s.size() > tar.size();
}

void findIfByBind() {
    vector<string> vs = of(text);
    auto it = std::find_if(vs.begin(), vs.end(), std::bind(greaterThanSpecStr, _1, "hello"));
    if (it != vs.end()) {
        cout << "the first words greater is " << *it << endl;
    }
}

void countByLambdas() {
    vector<string> vs = of(text);
    size_t sz = 6;
    auto cnt = std::count_if(vs.begin(), vs.end(), [=](const auto &s){ return s.size() <= sz; });
    cout << cnt << endl;
}


void biggestByBind() {
    vector<string> vs = of(text);
    std::sort(vs.begin(), vs.end());
    auto it = std::unique(vs.begin(), vs.end(), bind(greaterThanSpecStr, _1, "hello"));
    std::for_each(it, vs.end(), [](const auto &s) { cout << s << " ";});
}

/*
 * Exercise 10.26: Explain the differences among the three kinds of insert iterators.
 * Answer:
 * back_inserter uses push_back.
 * front_inserter uses push_front.
 * insert uses insert
 * This function takes a second argument, which must be an iterator into the given container.
 * Elements are inserted ahead of the element denoted by the given iterator.
 *
 *
 * Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library
 * defines function named unique_copy that takes a third iterator denoting a
 * destination into which to copy the unique elements. Write a program that
 * uses unique_copy to copy the unique elements from a vector into an initially empty list.
 * @see uniqueCopyByInserter();
 *
 *
 *
 * Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
 * into three other containers. Use an inserter, a back_inserter, and a
 * front_inserter, respectivly to add elements to these containers. Predict
 * how the output sequence varies by the kind of inserter and verify your
 * predictions by running your programs.
 * @see usedInserter();
 *
 */

void usedInserter() {
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> first, second, third;
    std::copy(vi.begin(), vi.end(), std::back_inserter(first));
    std::copy(vi.begin(), vi.end(), std::inserter(second, second.begin()));
    std::copy(vi.begin(), vi.end(), std::front_inserter(third));
    for (const auto &elem : first) {
        cout << elem << " ";
    }
    cout << '\n';
    for (const auto &elem : second) {
        cout << elem << " ";
    }
    cout << '\n';
    for (const auto &elem : third) {
        cout << elem << " ";
    }
    cout << endl;

}

void uniqueCopyByInserter() {
    vector<string> vs = of(text);
    list<string> li;
    std::unique_copy(vs.begin(), vs.end(), std::front_inserter(li));
    int cnt = 0;
    for (const auto &item : li) {
        cout << item << " ";
        ++cnt;
        if (cnt % 7 == 0) cout << '\n';
    }
    cout << endl;
}

/*
 * Exercise 10.29: Write a program using stream iterators to read a text file into a vector of strings.
 * @see testingIOStreamIterator();
 *
 * Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
 * of integers from the standard input, sort them, and then write them back to the standard output.
 * @see usedIOStreamIterator();
 *
 *
 * Exercise 10.31: Update the program from the previous exercise so that it
 * prints only the unique elements. Your program should use unqiue_copy (§10.4.1, p. 403).
 * @see usedIOStreamIterator();
 *
 *
 *
 * Exercise 10.32: Rewrite the bookstore problem from § 1.6 (p. 24) using a
 * vector to hold the transactions and various algorithms to do the processing.
 * Use sort with your compareIsbn function from § 10.3.1 (p. 387) to
 * arrange the transactions in order, and then use find and accumulate to do the sum.
 * already be done.
 *
 *
 * Exercise 10.33: Write a program that takes the names of an input file and
 * two output files. The input file should hold integers. Using an
 * istream_iterator read the input file. Using ostream_iterators, write
 * the odd numbers into the first output file. Each value should be followed by a
 * space. Write the even numbers into the second file. Each of these values
 * should be placed on a separate line.
 * @see findOddsAndEven();
 *
 */

#include <iterator>


void testingIOStreamIterator() {
    std::ifstream in(text_file_path);
    std::istream_iterator<string> strIter(in);
    std::istream_iterator<string> eof;
    vector<string> vs;
    while (strIter != eof) {
        vs.push_back(*strIter++);
    }
    cout << "vs.size() = " << vs.size() << endl;
}

bool readMark() {
    std::ifstream in(mark_file_path);
    unsigned n = -1;
    bool flag = false;
    if (in >> n) {
        if (!n) flag = true;
        ++n;
    }
    std::ofstream out(mark_file_path);
    out << n;
    return flag;
}


void writeNumbers() {
    std::ofstream out(numbs_file_path, std::ofstream::app);
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned > u(0, 1 << 31);

    if (out && readMark()) {
        for (int i = 1; i != (1 << 16); ++i) {
            out << u(e) << " ";
            if (i % 20 == 0) out << '\n';
        }
    }
}

void usedIOStreamIterator() {
    std::ifstream in(numbs_file_path);
    std::istream_iterator<long> itIn(in);
    std::istream_iterator<long> eof;
    vector<long> vi;
    while (itIn != eof) {
        vi.push_back(*itIn++);
    }
    std::sort(vi.begin(), vi.end());
    std::ostream_iterator<long> outIter(cout, " ");
    std::copy(vi.begin(), vi.end(), outIter);
    cout << endl;
    std::unique_copy(vi.begin(), vi.end(), outIter);
    cout << endl;
}


void findOddsAndEven() {
    std::ifstream in(numbs_file_path);
    std::ofstream outOdds("../../part_2_stdlib/numb_odds.txt"), outEven("../../part_2_stdlib/numb_even.txt");
    std::ostream_iterator<unsigned > iterOutOdds(outOdds, " "), iterOutEven(outEven, "\n");
    std::istream_iterator<unsigned > iterIn(in), eof;
    while (iterIn != eof) {
        if (*iterIn & 1) {
            *iterOutOdds++ = *iterIn;
        } else {
            *iterOutEven++ = *iterIn;
        }
        ++iterIn;
    }
}

/*
 * Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
 * @see reversePrint();
 *
 * Exercise 10.35: Now print the elements in reverse order using ordinary iterators.
 * @see reversePrint();
 *
 * Exercise 10.36: Use find to find the last element in a list of ints with value 0.
 * @see reversePrint();
 *
 * Exercise 10.37: Given a vector that has ten elements, copy the elements from positions 3 through 7
 * in reverse order to a list.
 * @see reversePrint();
 */

void reversePrint() {
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto rbeg = vi.rbegin(); rbeg != vi.rend(); ++rbeg) {
        cout << *rbeg << " ";
    }
    cout << endl;

    for (auto end = vi.end() - 1; end != vi.begin() - 1; --end) {
        cout << *end << " ";
    }
    cout << endl;

    auto it = std::find(vi.rbegin(), vi.rend(), 0);
    if (it != vi.rend()) {
        cout << *it << endl;
    }

    list<int> li;
    std::copy(vi.begin() + 2, vi.begin() + 6, std::front_inserter(li));
    std::for_each(li.begin(), li.end(),[](const auto &s) { cout << s << " ";});
}


/*
 * Exercise 10.38: List the five iterator categories and the operations that each supports.
 * Answer:
 * Input iterators : ==, !=, ++, *, ->
 * Output iterators : ++, *
 * Forward iterators : ==, !=, ++, *, ->
 * Bidirectional iterators : ==, !=, ++, --, *, ->
 * Random-access iterators : ==, !=, <, <=, >, >=, ++, --, +, +=, -, -=, -(two iterators), *, ->, iter[n] == * (iter + n)
 *
 *
 * Exercise 10.39: What kind of iterator does a list have? What about a vector?
 * Answer:
 * list have the Bidirectional iterators. vector have the Random-access iterators.
 *
 * Exercise 10.40: What kinds of iterators do you think copy requires? What about reverse or unique?
 * copy : first and second are Input iterators, last is Output iterators.
 * reverse : Bidirectional iterators.
 * unique : Forward iterators.
 */


/*
 * Exercise 10.41: Based only on the algorithm and argument names, describe the operation that
 * the each of the following library algorithms performs:
 *
 * Answer:
 * replace(beg, end, old_val, new_val); // replace the old_elements in the input range as new_elements.
 * replace_if(beg, end, pred, new_val); // replace the elements in the input range which pred is true as new_elements.
 * replace_copy(beg, end, dest, old_val, new_val); // copy the new_elements which is old_elements in the input range into dest.
 * replace_copy_if(beg, end, dest, pred, new_val); // copy the new_elements which pred is true in the input range into dest.
 */



/*
 * Exercise 10.42: Reimplement the program that eliminated duplicate words
 * that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
 *
 */

void elimDupsByList() {
    vector<string> vs = of(text);
    list<string> li;
    std::copy(vs.begin(), vs.end(), std::back_inserter(li));
    li.sort();
    li.unique();
    int cnt = 0;
    for (const auto &elem : li) {
        cout << elem << " ";
        if (++cnt % 10 == 0) cout << '\n';
    }
    cout << endl;
}






int main(int argc, char *argv[]) {
    findOddsAndEven();
    writeNumbers();
    usedIOStreamIterator();
    testingIOStreamIterator();
    usedInserter();
    uniqueCopyByInserter();
    biggestByBind();
    findIfByBind();
    countByLambdas();
    decreaseLocal();
    accumulateInts();
    testingFindCounts();
    changeableContains();
    testingElimDups();
    partitionByFunc();
    mathLambdas();
    testingBiggest();
    testingCountIf();
    reversePrint();
    elimDupsByList();


    return 0;
}


