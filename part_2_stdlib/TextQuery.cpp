//
// Created by shiqing on 19-5-4.
//

#include "TextQuery.h"

using std::unordered_map;
using std::set;
using std::pair;
using std::map;


extern const string txtq::text_content = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";

vector<string> txtq::parseTextToMap(string filePath, std::unordered_map<string, vector<int>> &txtToMap) {
    std::ifstream in(filePath, std::ifstream::in);
    vector<string> lineText;
    if (in) {
        string line, word;
        int lineNo = 0;
        while (getline(in, line)) {
            ++lineNo;
            lineText.push_back(line);
            std::istringstream iss(line);
            while (iss >> word) {
                txtToMap[word].push_back(lineNo);
            }
        }
    }
    return lineText;
}

void txtq::generateResultMap(std::unordered_map<string, vector<int>> &txtToMap,
                             std::unordered_map<string, std::pair<int, std::set<int>>> &resultMap) {
    for (const auto &pair : txtToMap) {
        string key = pair.first;
        int times = pair.second.size();
        resultMap.insert({key, {times, set<int>(pair.second.begin(), pair.second.end())}});
    }
}

void txtq::print(string sought, unordered_map<string, pair<int, set<int>>>::iterator it,
                 const vector<string> &content) {
    int times = it->second.first;
    cout << "\"" << sought << "\" occurs "
         << times << " " << makePlural("time", "s", times)
         << "\n" << endl;
    for (const auto &n : it->second.second) {
        cout << "\t(line " << n << ") "
             << content[n - 1] << endl;
    }
}

void txtq::runQueries() {
    unordered_map<string, vector<int>> txtToMap;
    unordered_map<string, pair<int, set<int>>> resultMap;
    auto vecText = parseTextToMap(text_content, txtToMap);
    generateResultMap(txtToMap, resultMap);
    while (true) {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || (s.size() == 1 && s[0] == 'q')) break;
        auto it = resultMap.find(s);
        if (it != resultMap.end()) {
            print(s, it, vecText);
        }
    }
}


/*
 * define static member
 */

std::map<string, int> txtq::TextQuery::counts_;


txtq::TextQuery::TextQuery(const string &fileName)
        : textLines_(std::make_shared<vector<string>>()),
          wordToSet_(std::make_shared<map<string, set<int>>>()) {
    init(fileName);
}

txtq::QueryResult txtq::TextQuery::query(string sought) {
    auto it = wordToSet_->find(sought);
    if (it != wordToSet_->end()) {
        return QueryResult(counts_[sought], sought, textLines_, it);

    }
    return txtq::QueryResult();
}

txtq::TextQuery &txtq::TextQuery::setFileName(const string &fileName) {
    init(fileName);
    return *this;
}

void txtq::TextQuery::init(const string &fileName) {
    std::ifstream in(fileName);
    if (!in) return;
    string line, word;
    int lineNo = 0;
    while (getline(in, line)) {
        textLines_->push_back(line);
        ++lineNo;
        std::istringstream iss(line);
        while (iss >> word) {
            ++counts_[word];
            (*wordToSet_)[word].insert(lineNo);
        }
    }
}

std::ostream &txtq::print(std::ostream &os, const QueryResult &qr) {
    if (qr.times_ == 0) return os;
    os << "\"" << qr.sought_ << "\" occurs "
         << qr.times_ << " " << makePlural("time", "s", qr.times_)
         << "\n" << endl;
    for (const auto &n : qr.it_->second) {
        os << "\t(line " << n << ") "
             << (*qr.textLinesPtr_)[n - 1] << endl;
    }
    return os;
}


void txtq::runQueriesForObj() {
    TextQuery textQuery(text_content);
    while (true) {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || (s.size() == 1 && s[0] == 'q')) break;
        QueryResult qr = textQuery.query(s);
        print(cout, qr);
    }
}
