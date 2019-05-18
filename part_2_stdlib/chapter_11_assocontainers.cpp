//
// Created by shiqing on 19-4-28.
//

#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include "../common/CommonHeaders.h"
#include "PrintFormat.h"


const string text_file_path = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";
const string numbs_file_path = "../../part_2_stdlib/numbers.txt";
const string text = "    'Lovely evening!' shouted Uncle Vernon, waving at Mrs Number Seven opposite, who was glaring from behind her net curtains. 'Did you hear that car backfire just now? Gave Petunia and me quite a turn!'\n"
                    "    He continued to grin in a horrible, manic way until all the curious neighbours had disappeared from their various windows, then the grin became a grimace of rage as he beckoned Harry back towards him.\n"
                    "    Harry moved a few steps closer, taking care to stop just short of the point at which Uncle Vernon's outstretched hands could resume their strangling.\n"
                    "    'What the devil do you mean by it, boy?' asked Uncle Vernon in a croaky voice that trembled with fury.\n"
                    "    'What do I mean by what?' said Harry coldly. He kept looking left and right up the street, still hoping to see the person who had made the cracking noise.\n"
                    "    'Making a racket like a starting pistol right outside our - '\n"
                    "    'I didn't make that noise,' said Harry firmly.\n"
                    "    Aunt Petunia's thin, horsy face now appeared beside Uncle Vernon's wide, purple one. She looked livid.\n"
                    "    'Why were you lurking under our window?'";


/*
 * Exercise 11.1: Describe the differences between a map and a vector.
 * answer:
 * map is an associative container whereas vector is a sequence container;
 *
 *
 *
 * Exercise 11.2: Give an example of when each of list, vector, deque,
 * map, and set might be most useful.
 * Answer:
 * list : anytime when a doubly-linked list is required.
 * vector : anytime when a dynamic array is required.
 * deque : https://stackoverflow.com/questions/3880254/why-do-we-need-deque-data-structures-in-the-real-world
 * map : dictionary.
 * set : when to keep elements sorted and unique.
 *
 * Exercise 11.3: Write your own version of the word-counting program.
 * @see wordCounting();
 *
 *
 *
 *
 * Exercise 11.4: Extend your program to ignore case and punctuation. For example, “example.” “example,”
 * and “Example” should all increment the same counter.
 * @see wordCountingIgnoreCase();
 *
 *
 *
 */

string trimPunctAndContr(const string &word) {
    string s;
    for (auto &c : word) {
        if (isalpha(c)) {
            s.append(1, c);
        }
    }
    return s;
}

string toLowerCase(string srcStr) {
    for (auto &c : srcStr) {
        isupper(c) ? tolower(c) : c;
    }
    return srcStr;
}


void wordCounting() {
    std::ifstream in(text_file_path);
    string word;
    std::map<string, int> wordsMap;
    while (in >> word) {
        word = trimPunctAndContr(word);
        if (word.empty()) continue;
        ++wordsMap[word];
    }
    for (const auto &pair : wordsMap) {
        cout << "\"" << pair.first << "\"" << " occurs: "
             << pair.second << " times." << '\n';
    }
}

namespace self {

    template<typename _Arg1, typename _Arg2, typename _Result>
    struct binary_function {
        /// @c first_argument_type is the type of the first argument
        typedef _Arg1 first_argument_type;

        /// @c second_argument_type is the type of the second argument
        typedef _Arg2 second_argument_type;

        /// @c result_type is the return type
        typedef _Result result_type;
    };

    template<typename _Tp>
    struct Less : public binary_function<_Tp, _Tp, bool> {
        bool
        operator()(const _Tp &__x, const _Tp &__y) const { return __x < __y; }
    };

    template<>
    struct Less<string> : public binary_function<string, string, bool> {
        bool operator()(const string &__x, const string &__y) const {
            string copyS1 = trimPunctAndContr(__x), copyS2 = trimPunctAndContr(__y);
            return toLowerCase(copyS1) < toLowerCase(copyS2);
        }
    };
}


void wordCountingIgnoreCase() {
    std::ifstream in(text_file_path);
    string word;
    std::map<string, int, self::Less<string>> wordsMap;
    while (in >> word) {
        if (word.empty()) continue;
        ++wordsMap[word];
    }
    for (const auto &pair : wordsMap) {
        cout << "\"" << pair.first << "\"" << " occurs: "
             << pair.second << " times." << '\n';
    }
}


/*
 * Exercise 11.5: Explain the difference between a map and a set. When might you use one or the other?
 * Answer:
 * 1)A map is a collection of key–value pairs.
 * 2)In contrast, a set is simply a collection of keys. A set is most useful when we simply want to know
 * whether a value is present.
 *
 *
 *
 * Exercise 11.6: Explain the difference between a set and a list. When might you use one or the other?
 * Answer:
 * list is a sequential collection, a set is simply a collection of keys.
 *
 * Exercise 11.7: Define a map for which the key is the family’s last name and
 * the value is a vector of the children’s names. Write code to add new
 * families and to add new children to an existing family.
 * @see mappedFamilyNames();
 *
 *
 *
 * Exercise 11.8: Write a program that stores the excluded words in a vector instead of in a set.
 * What are the advantages to using a set?
 *
 * @see eliminateDups();
 *
 *
 */

void mappedFamilyNames() {
    std::map<string, vector<string>> familyNames;
    std::multimap<string, string> fs;

    familyNames["liu"] = {"shiqing", "yanling", "jiping"};
    familyNames["ni"] = {"shouying"};

    std::map<string, vector<std::pair<string, string>>> family;
    family["liu"] = {{"shiqing", "19870903"},
                     {"yling",   "19890525"}};
    fs.insert({"shiqing", "19870903"});
    fs.insert({"shiqing", "1987090301"});
    for (const auto &f : family) {
        cout << f.first << "---";
        for (const auto &item : f.second) {
            cout << item.first << "---" << item.second << "\n";
        }
    }

    for (const auto &item : familyNames) {
        cout << item.first << ": ";
        for (const auto &elem : item.second) {
            cout << elem << "-";
        }
        cout << '\n';
    }

    for (const auto &item : fs) {
        cout << item.first << ": ";
        for (const auto &elem : item.second) {
            cout << elem << "-";
        }
        cout << '\n';
    }
    cout << endl;
}

#include <algorithm>
#include <unordered_map>

void eliminateDups() {
    std::istringstream in(text);
    vector<string> vi;
    std::set<string> setStr;
    string word;
    while (in >> word) {
        vi.push_back(word);
        setStr.insert(word);
    }
    std::sort(vi.begin(), vi.end());
    std::unique(vi.begin(), vi.end());
    self::printFormat(vi) << endl;
    self::printFormat(setStr) << endl;
}


/*
 * Exercise 11.9: Define a map that associates words with a list of line numbers on which the word might occur.
 * @see mapToLines();
 *
 *
 * Exercise 11.10: Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int?
 * In each case, if not, why not?
 * yes, no;
 * vector<int>::iterator define the operator of '<', the other not.
 *
 *
 * Exercise 11.11: Redefine bookstore without using decltype.
 * @see wordCountingIgnoreCase();
 */


void mapToLines() {
    std::ifstream in(text_file_path);
    std::map<string, list<int>> wordsToLine;
    string line, word;
    int num = 0;
    while (getline(in, line) && !line.empty()) {
        ++num;
        std::istringstream lineStream(line);
        while (lineStream >> word) {
            wordsToLine[word].push_back(num);
        }
    }

    for (const auto &pair : wordsToLine) {
        cout << "the word is \"" << pair.first
             << "\"" << ", occurs: ";
        for (const auto &elem : pair.second) {
            cout << elem << " ";
        }
        cout << "\n";
    }
}


/*
 * Exercise 11.12: Write a program to read a sequence of strings and ints,
 * storing each into a pair. Store the pairs in a vector.
 * @see storePairsToVector();
 *
 *
 * Exercise 11.13: There are at least three ways to create the pairs in the program for the previous exercise.
 * Write three versions of that program, creating the pairs in each way.
 * Explain which form you think is easiest to write and understand, and why.
 * @see storePairsToVector();
 *
 * Exercise 11.14: Extend the map of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424)
 * by having the vector store a pair that holds a child’s name and birthday.
 *
 * @see mappedFamilyNames();
 *
 *
 */

void storePairsToVector() {
    vector<std::pair<string, long>> vec;
    std::ifstream in("../../part_2_stdlib/phone.data");
    string line;
    while (getline(in, line)) {
        std::istringstream ls(line);
        string s;
        long n;
        ls >> s >> n;
        if (ls) {
            vec.push_back({s, n});
            // std::pair(s, n); std::make_pair(s, n);
        }
    }

    for (const auto &item : vec) {
        cout << "{" << item.first << ", "
             << item.second << "}" << "\n";
    }
}

/*
 * Exercise 11.15: What are the mapped_type, key_type, and
 * value_type of a map from int to vector<int>?
 * Answer:vector<int>, const int, pair<const int, vector<int>>
 *
 *
 * Exercise 11.16: Using a map iterator write an expression that assigns a value to an element.
 * *map_it[word] = "string";
 *
 * Exercise 11.17: Assuming c is a multiset of strings and v is a vector of strings, explain the following calls.
 * Indicate whether each call is legal:
 * Answer:
 * @see testingVectorAndMultiSet();
 *
 *
 * Exercise 11.18: Write the type of map_it from the loop on page 430 without using auto or decltype.
 * Already be done.
 *
 * Exercise 11.19: Define a variable that you initialize by calling begin() on the multiset named bookstore from
 * § 11.2.2 (p. 425). Write the variable’s type without using auto or decltype.
 * Already be done.
 *
 *
 */

void testingVectorAndMultiSet() {
    vector<int> vi = {0, 1, 2, 3, 4, 6, 8, 10};
    std::multiset<int> si{1, 3, 5, 7, 9};
    std::copy(vi.begin(), vi.end(), std::inserter(si, si.end())); //legal
//    std::copy(vi.begin(), vi.end(), std::back_inserter(si)); //legal: invalid initialization of non-const reference of type
    std::copy(si.begin(), si.end(), std::inserter(vi, vi.end())); // legal
    std::copy(si.begin(), si.end(), std::back_inserter(vi)); // legal
    for (const auto &item : vi) {
        cout << item << " ";
    }
    cout << endl;
    for (const auto &item2 : si) {
        cout << item2 << " ";
    }
    cout << endl;
}


/*
 * Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting.
 * Which program do you think is easier to write and read? Explain your reasoning.
 * @see rewriteWordsCount();
 *
 * Exercise 11.21: Assuming word_count is a map from string to size_t and word is a string, explain the following loop:
 * while (cin >> word)
 * ++word_count.insert({word, 0}).first->second;
 * Answer:
 * <==> ++word_count[word];
 *
 * Exercise 11.22: Given a map<string, vector<int>>, write the types used as an argument and as the return value for
 * the version of insert that inserts one element.
 * Answer:
 * {"string", {int, int, int};
 * std::pair<map<string, vector<int>>>,
 *
 *
 * Exercise 11.23: Rewrite the map that stored vectors of children’s names with a key that is the family last name
 * for the exercises in § 11.2.1 (p. 424) to use a multimap.
 * @see mappedFamilyNames();
 */


void rewriteWordsCounts() {
    std::istringstream in(text);
    string word;
    std::map<string, size_t> mappedCounts;
    while (in >> word) {
        auto mapIt = mappedCounts.insert({word, 1});
        if (!mapIt.second) {
            ++mapIt.first->second;
        }
    }
    for (const auto &pair : mappedCounts) {
        cout << "\"" << pair.first << "\""
             << " occurs: " << pair.second << "\n";
    }
    cout << endl;
}


/*
 * Exercise 11.24: What does the following program do?
 * map<int, int> m; m[0] = 1;
 * Answer: <===> m.insert({0, 1});
 *
 *
 * Exercise 11.25: Contrast the following program with the one in the previous
 * vector<int> v; v[0] = 1;
 * Answer:error.
 *
 * Exercise 11.26: What type can be used to subscript a map? What type does the subscript operator return?
 * Give a concrete example—that is, define a map and then write the types that can be used to subscript
 * the map and the type that would be returned from the subscript operator.
 * Answer: 1)no const can be used to subscript a map.2) already be value initialized of mapped_type& obj.
 *
 * std::map<string, size_it> wordsCount;
 * ++wordsCount["string"];
 */



/*
 * Exercise 11.27: What kinds of problems would you use count to solve? When might you use find instead?
 * Answer:
 * I would use count to deal with multimap or multi multiset.
 * As for the associative container that have unique key, I would use find instead of count.
 *
 * Exercise 11.28: Define and initialize a variable to hold the result of calling find on a map from string to vector of int.
 * Answer:
 * std::map<std::string, std::vector<int>> m{ { "Alan",{ 1,2,3,4,5, } },{ "John",{ 1,5,6,7,8 } } };
 * td::map<std::string, std::vector<int>>::iterator it = m.find("Alan");
 *
 * Exercise 11.29: What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?
 * Answer:
 * If the element is not in the multimap, then lower_bound and upper_bound will return equal iterators; both will
 * refer to the point at which the key can be inserted without  disrupting the order.
 * If no matching element is found, then both the first and second iterators refer to the position where this key can be inserted.
 *
 *
 *
 * Exercise 11.30: Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.
 * Answer:
 * pos                     a pair
 * pos.first               the iterator refering to the first element with the matching key
 * pos.first->second       the value part of the key-value of the first element with the matching key
 *
 *
 * Exercise 11.31: Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that
 * element. Be sure your program works correctly if the element you look for is not in the map.
 * @see findAndErase();
 *
 *
 * Exercise 11.32: Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.
 * @see findAndErase();
 */


/*
 * Exercise 11.33: Implement your own version of the word-transformation program.
 * @see processTransWords();
 *
 *
 * Exercise 11.34: What would happen if we used the subscript operator instead of find in the transform function?
 * Answer:it will cause wrong.
 *
 *
 * Exercise 11.35: In buildMap, what effect, if any, would there be from rewriting
 * trans_map[key] = value.substr(1);
 * as trans_map.insert({key, value.substr(1)})?
 * already be done.
 *
 *
 * Exercise 11.36: Our program does no checking on the validity of either
 * input file. In particular, it assumes that the rules in the transformation file are
 * all sensible. What would happen if a line in that file has a key, one space,
 * and then the end of the line? Predict the behavior and then check it against your version of the program.
 * yes, already be done.
 */

const string rule_path = "../../part_2_stdlib/rules_word.txt";
const string to_trans_text = "../../part_2_stdlib/to_tans_text";
std::map<string, string> makeRulesMap(const string &path) {
    std::map<string, string> rules;
//    std::unordered_map<string, string> rules;
    std::ifstream in(path, std::ifstream::in);
    if (in) {
        string line, key, value;
        while (getline(in, line)) {
            std::istringstream is(line);
            is >> key >> value;
            if (is.eof()) {
                rules.insert({key, value});
            }
        }
    }
    return rules;
}


void processTransWords() {
    auto rulesMap = makeRulesMap(rule_path);
    std::ifstream in(to_trans_text);
    string line, word;
    std::list<string> outText;
    while (getline(in, line)) {
        std::istringstream is(line);
        while (is >> word) {
            auto it = rulesMap.find(word);
            if (it != rulesMap.end()) {
                outText.push_back(rulesMap[word]);
            } else {
                outText.push_back(word);
            }
            outText.push_back(" ");
        }
        outText.push_back("\n");
    }
    for (const auto &item : outText) {
        cout << item;
    }
}


void findAndErase() {
    std::multimap<string, string> authorOfWorks;
    authorOfWorks.insert({"Barth, John", "Sot-Weed Factor"});
    authorOfWorks.insert({"Barth, John", "Lost in the Funhouse"});
    authorOfWorks.insert({"Stanley", "C++ Primer"});
    auto it = authorOfWorks.find("Stanley");
    if (it != authorOfWorks.end()) {
        authorOfWorks.erase(it);
    }
    for (const auto &item : authorOfWorks) {
        cout << item.first << ":" << item.second << endl;
    }
}

/*
 * Exercise 11.37: What are the advantages of an unordered container as compared to the ordered version of
 * that container? What are the advantages of the ordered version?
 * Answer:
 *
    Ordered Associative Container
        Standard Traversal encounters elements in sorted order
        Order predicate may be specified
        Default order predicate is "less than", defined using operator< for the element type
        Popular implementations: OrderedVector, BinarySearchTree
        Search operations required to have O(log n) runtime
        Insert, Remove operations should either be seldom used or have O(log n) runtime
    Unordered Associative Container
        Standard Traversal encounters elements in unspecified order
        Search, Insert, Remove operations should have average-case constant runtime
        Popular implementations use hashing

 *
 *
 *
 * Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and word- transformation (§ 11.3.6, p. 440)
 * programs to use an unordered_map.
 * @see processTransWords();
 *
 */




int main(int argc, char *argv[]) {
    testingVectorAndMultiSet();
    mapToLines();
    wordCounting();
    wordCountingIgnoreCase();
    mappedFamilyNames();
    eliminateDups();
    storePairsToVector();
    rewriteWordsCounts();
    findAndErase();
    processTransWords();


    return 0;
}


