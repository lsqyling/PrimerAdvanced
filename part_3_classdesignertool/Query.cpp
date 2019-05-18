//
// Created by shiqing on 19-5-10.
//

#include <sstream>
#include "Query.h"
#include "QueryBase.h"
#include "TextQuery.h"


query::QueryResult query::Query::eval(const query::TextQuery &tq) const {
    return basePtr_->eval(tq);
}

string query::Query::rep() const {
    return basePtr_->rep();
}

query::Query::Query(const string &word) : basePtr_(new WordQuery(word)) {}


query::Query query::Convert::convertToQuery() {
    string suffix = transformToRPN();
    std::istringstream iss(suffix);
    std::stack<Query> result;
    string word;
    while (iss >> word) {
        if (word == "&") {
            auto rq = result.top(); result.pop();
            auto lq = result.top(); result.pop();
            result.push(lq & rq);
        } else if (word == "|") {
            auto rq = result.top(); result.pop();
            auto lq = result.top(); result.pop();
            result.push(lq | rq);

        } else if (word == "~") {
            auto q = result.top(); result.pop();
            result.push(~q);
        } else {
            result.push(Query(word));
        }
    }
    return result.top();
}


const std::map<char, int> query::Convert::opChar2Rank{{'~',  0},
                                               {'&',  1},
                                               {'|',  2},
                                               {'(',  3},
                                               {')',  4},
                                               {'\0', 5}};
constexpr char query::Convert::CHARS[N_OP][N_OP];
