//
// Created by shiqing on 19-5-10.
//

#ifndef PRIMERADVANCED_TEXTQUERY_H
#define PRIMERADVANCED_TEXTQUERY_H

#include "../common/CommonHeaders.h"
#include "QueryBase.h"

#include <map>
#include <set>


namespace query {

    const string text_path = "../../part_2_stdlib/5.Harry Potter and the Order of the Phoenix.txt";

    class QueryResult;

    class TextQuery {
    public:
        TextQuery(const string &file = text_path);

        QueryResult query(string keyWord) const;

        auto getFileLines() const noexcept {
            return lines_;
        }

    private:
        void init(const string &file);

        static std::map<string, int> wordCounts_;
        static std::shared_ptr<vector<string>> lines_;
        static std::shared_ptr<std::map<string, std::set<int>>> keyToLineNos_;
    };


    class QueryResult {
    public:

        QueryResult()
                : rFileLines_(std::make_shared<vector<string>>()), rLinesNo_(std::make_shared<std::set<int>>()) {}

        QueryResult(std::shared_ptr<vector<string>> fileLines, std::shared_ptr<std::set<int>> linesNo, int times)
                : rFileLines_(fileLines), rLinesNo_(linesNo), rTimes_(times) {}

        auto begin() const noexcept {
            return rLinesNo_->begin();
        }

        auto end() const noexcept {
            return rLinesNo_->end();
        }

        auto getFileLines() const noexcept {
            return rFileLines_;
        }

        auto getLineNoSet() const noexcept {
            return rLinesNo_;
        }

        int getTimes() const noexcept { return rTimes_; }

    private:
        std::shared_ptr<vector<string>> rFileLines_;
        std::shared_ptr<std::set<int>> rLinesNo_;
        int rTimes_ = 0;

    };

    inline string makePlural(string srcW, string suffix, int n) {
        return n > 1 ? srcW + suffix : srcW;
    }

    std::ostream &operator<<(std::ostream &os, const QueryResult &rq);

    void runQueries();


}


#endif //PRIMERADVANCED_TEXTQUERY_H
