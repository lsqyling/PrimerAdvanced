//
// Created by shiqing on 19-5-10.
//

#include <fstream>
#include <sstream>
#include "TextQuery.h"

namespace query {

    std::map<string, int> TextQuery::wordCounts_;
    std::shared_ptr<vector<string>> TextQuery::lines_{std::make_shared<vector<string>>()};
    std::shared_ptr<std::map<string, std::set<int>>> TextQuery::keyToLineNos_{
            std::make_shared<std::map<string, std::set<int>>>()};


    TextQuery::TextQuery(const string &file) {
        if (!wordCounts_.empty()) return;
        init(file);
    }

    void TextQuery::init(const string &file) {
        std::ifstream ifs(file, std::ifstream::in);
        if (ifs) {
            int lineNo = 0;
            string line, word;
            while (getline(ifs, line)) {
                ++lineNo;
                lines_->push_back(line);
                std::istringstream iss(line);
                while (iss >> word) {
                    ++wordCounts_[word];
                    (*keyToLineNos_)[word].insert(lineNo);
                }
            }
        }
    }


    QueryResult TextQuery::query(string keyWord) const {
        auto it = keyToLineNos_->find(keyWord);
        if (it != keyToLineNos_->end()) {
            return QueryResult(lines_, std::make_shared<std::set<int>>(it->second), wordCounts_[keyWord]);
        }
        return QueryResult();
    }

    std::ostream &query::operator<<(std::ostream &os, const QueryResult &rq) {
        for (const auto &n : *rq.getLineNoSet()) {
            os << "(line " << n << ")\t" << (*rq.getFileLines())[n - 1] << "\n";
        }
        return os;
    }


    void runQueries() {
        TextQuery tq("../../part_3_classdesignertool/a little story");
        while (true) {
            cout << "Please enter the key words that you want to query: " << endl;
            string expression;
            while (!getline(cin, expression) || expression.empty());
            Convert convert(expression);
            Query q = convert.convertToQuery();
            QueryResult result = q.eval(tq);
            cout << "Executing Query for: " << q.rep() << "\n\n"
                 << q.rep() << " occurs " << result.getTimes() << " "
                 << makePlural("time", "s", result.getTimes()) << "\n"
                 << result << endl;

            cout << "please continue yes or no ?" << endl;
            string s;
            if (cin >> s && (s.size() == 2 && s[0] == 'n')) break;
        }
    }


}


