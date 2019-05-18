//
// Created by shiqing on 19-5-4.
//

#ifndef PRIMERADVANCED_TEXTQUERY_H
#define PRIMERADVANCED_TEXTQUERY_H

#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../common/CommonHeaders.h"


namespace txtq {

    /*
     * A Text-Query Program:
     *
     * For example, we might read the file that contains the input for this chapter and look for the word element.
     * The first few lines of the output would be
     *
     * element occurs 112 times
     *
     * (line 36) A std::set element contains only a key;
     * (line 158) operator creates a new element
     * (line 160) Regardless of whether the element
     * (line 168) When we fetch an element from a map, we
     * (line 214) If the element is not found, find returns
     *
     * followed by the remaining 100 or so lines in which the word element occurs.
     */

    /*
     * 1:The first design uses a procedural programming approach.
     */


    extern const string text_content;

    vector<string> parseTextToMap(string filePath, std::unordered_map<string, vector<int>> &txtToMap);

    void generateResultMap(std::unordered_map<string, vector<int>> &txtToMap,
                           std::unordered_map<string, std::pair<int, std::set<int>>> &resultMap);

    string makePlural(string srcW, string suffix, int n);

    void print(string sought, std::unordered_map<string, std::pair<int, std::set<int>>>::iterator it,
               const vector<string> &content);

    void runQueries();


    /*
     * 2:The second design, using an object-oriented programming approach.
     */
    class QueryResult;

    class TextQuery {

    public:
        TextQuery() :
                textLines_(std::make_shared<vector<string>>()),
                wordToSet_(std::make_shared<std::map<string, std::set<int>>>()) {}

        TextQuery(const string &fileName);


        QueryResult query(string sought);

        TextQuery &setFileName(const string &fileName);


    private:
        static std::map<string, int> counts_;
        std::shared_ptr<vector<string>> textLines_;
        std::shared_ptr<std::map<string, std::set<int>>> wordToSet_;

        void init(const string &fileName);


    };

    class QueryResult {
        friend std::ostream &print(std::ostream &os, const QueryResult &qr);

    public:
        QueryResult() = default;

        QueryResult(int times, string sought,
                    std::shared_ptr<vector<string>> textLinesPtr,
                    std::map<string, std::set<int>>::iterator it)
                : times_(times), sought_(sought),
                  textLinesPtr_(textLinesPtr), it_(it) {}


    private:
        int times_ = 0;
        string sought_;
        std::shared_ptr<vector<string>> textLinesPtr_;
        std::map<string, std::set<int>>::iterator it_;

    };

    std::ostream &print(std::ostream &os, const QueryResult &qr);
    void runQueriesForObj();


}


inline string txtq::makePlural(string srcW, string suffix, int n) {
    return n <= 1 ? srcW : srcW + suffix;
}

#endif //PRIMERADVANCED_TEXTQUERY_H
