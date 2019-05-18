//
// Created by shiqing on 19-4-23.
//

#include <fstream>
#include <sstream>
#include "../common/CommonHeaders.h"



/*
 * Exercise 8.1:
 * Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file.
 * The function should print what it reads to the standard output. Reset the stream so that it is valid
 * before returning the stream.
 * @see resetPrint();
 *
 */

/*
 * Exercise 8.2: Test your function by calling it, passing cin as an argument.
 * @see resetPrint();
 */


/*
 * Exercise 8.3: What causes the following while to terminate?
 * while(cin >> i) {}
 *
 * Answer:putting cin in an error state cause to terminate. such as eofbit, failbit and badbit.
 */


std::istream &resetPrint(std::istream &is) {
    int c;
    while ((c = is.get()) != EOF) {
        cout << static_cast<char>(c);
    }
    is.clear();
    return is;
}

/*
 * Exercise 8.4:
 * Write a function to open a file for input and read its contents
 * into a vector of strings, storing each line as a separate element in the vector.
 * @see storeFilesInVector();
 *
 *
 *
 *
 * Exercise 8.5:
 * Rewrite the previous program to store each word in a
 * separate element.
 * @see storeFilesInVector();
 *
 *
 *
 * Exercise 8.6:
 * Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file.
 * Pass the name of the file as an argument to main (§ 6.2.5, p. 218).
 * already be done.
 *
 */

/*
 * Exercise 8.7:
 * Revise the bookstore program from the previous section to write its output to a file.
 * Pass the name of that file as a second argument to main.
 * @see storeFilesInVectorAndWrite();
 *
 *
 * Exercise 8.8:
 * Revise the program from the previous exercise to append its
 * output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.
 *
 * @see storeFilesInVectorAndWrite();
 *
 *
 */

void storeFilesInVectorAndWrite() {
    string filePath = "../../part_2_stdlib/chapter_8_io.cpp";
    std::ifstream ifs(filePath, std::ifstream::in);
    vector<string> lines;
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            lines.push_back(line);
        }
    }
    ifs.close();
    ifs.open(filePath, std::ifstream::in);
    vector<string> words;
    if (ifs) {
        string s;
        while (ifs >> s) {
            words.push_back(s);
        }
    }
    auto end = filePath.find_last_of('.');
    std::ofstream out(filePath.substr(0, end) + ".txt", std::ofstream::app);
    for (const auto &item : lines) {
        out << item << '\n';
    }
    for (const auto &word : words) {
        out << word << " ";
    }
    out << endl;
}

/*
 * Exercise 8.9:
 * Use the function you wrote for the first exercise in § 8.1.2
 * (p.314) to print the contents of an istringstream object.
 *
 * @see printBySstream();
 */
void printBySstream() {
    string s("hello, world!");
    std::istringstream in(s);
    string ts;
    while (in >> ts) {
        cout << ts << " ";
    }
    cout << endl;
}


/*
 * Exercise 8.10:
 * Write a program to store each line from a file in a vector<string>. Now use an istringstream to read each element from
 * the vector a word at a time.
 * @see storeVectorAndPrint();
 */

/*
 * Exercise 8.11:
 * The program in this section defined its istringstream
 * object inside the outer while loop. What changes would you need to make if
 * record were defined outside that loop? Rewrite the program, moving the
 * definition of record outside the while, and see whether you thought of all
 * the changes that are needed.
 * @see storeVectorAndPrint();
 *
 */


void storeVectorAndPrint() {
    string filePath = "../../part_2_stdlib/chapter_8_io.cpp";
    std::ifstream ifs(filePath, std::ifstream::in);
    vector<string> lines;
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            lines.push_back(line);
        }
    }
//    Note the difference between "lineStream" written inside the loop and outside the loop.
    std::istringstream lineStream;
    for (const auto &line : lines) {
        string word;
        lineStream.str(line);
        while (lineStream >> word) {
            cout << word << " ";
        }
        cout << '\n';
        lineStream.clear();
    }
    cout << std::flush;
}


/*
 * Exercise 8.12: Why didn’t we use in-class initializers in PersonInfo?
 * Answer:
 * Cause we need a aggregate class here. so it should have no in-class initializers.
 *
 */

struct PersonInfo {
    string name;
    vector<string> phones;
};

string formatStr(const string &s) {
    if (!s.empty()) {
        std::ostringstream os(s);
        os << "+86" << s;
        return os.str();
    }
    return s;
}


bool valid(const string &phone) {
    return !phone.empty();
}


void processingPhones() {
    string filePath = "../../part_2_stdlib/phone.data";
    std::ifstream ifs(filePath, std::ifstream::in);
    vector<PersonInfo> persons;
    if (ifs) {
        std::istringstream lineStream;
        string line;
        while (getline(ifs, line)) {
            lineStream.str(line);
            PersonInfo personInfo;
            lineStream >> personInfo.name;
            string phone;
            while (lineStream >> phone) {
                personInfo.phones.push_back(phone);
            }
            persons.push_back(personInfo);
            lineStream.clear();
        }
    } else {
        std::cerr << "file is open incorrectly!?" << endl;
    }

    auto end = filePath.find_last_of('.');
    std::ofstream os(filePath.substr(0, end) + "_new.txt");
    for (const auto &entry : persons) {
        std::ostringstream badNums, formatted;
        for (const auto &phone : entry.phones) {
            if (!valid(phone)) {
                badNums << " " << phone;
            } else {
                formatted << "\t" << formatStr(phone);
            }

        }
        if (badNums.str().empty()) {
            os << entry.name << formatted.str() << '\n';
        } else {
            std::cerr << "input error: " << entry.name
                      << " invalid numbers " << badNums.str()
                      << endl;
        }
    }

}


/*
 * Exercise 8.13:
 * Rewrite the phone number program from this section to read from a named file rather than from cin.
 *
 * @see processingPhones();
 *
 *
 *
 * Exercise 8.14:
 * Why did we declare entry and nums as const auto &?
 * Answer:
 * cause they are all class type, not the built-in type. so reference more effective.
 * output shouldn't change their values. so we added the const.
 */




int main(int argc, char *argv[]) {
    processingPhones();
//    resetPrint(cin);
    storeVectorAndPrint();
    printBySstream();
    storeFilesInVectorAndWrite();


    return 0;
}