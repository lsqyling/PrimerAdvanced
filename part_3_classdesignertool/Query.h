//
// Created by shiqing on 19-5-10.
//

#ifndef PRIMERADVANCED_QUERY_H
#define PRIMERADVANCED_QUERY_H

#include <stack>
#include <map>
#include "../common/CommonHeaders.h"

namespace query {
    class QueryResult;

    class TextQuery;

    class QueryBase;

    class Query {
        friend Query operator~(const Query &rhs);

        friend Query operator&(const Query &lhs, const Query &rhs);

        friend Query operator|(const Query &lhs, const Query &rhs);

    public:
        Query(const string &word);

        QueryResult eval(const TextQuery &tq) const;

        string rep() const;


    private:
        std::shared_ptr<QueryBase> basePtr_;

        Query(std::shared_ptr<QueryBase> basePtr) : basePtr_(basePtr) {}
    };


    class Convert {
    public:
        Convert(const string &expr) : queryStr_(expr) {}

        Query convertToQuery();

    private:

        string transformToRPN() {
            const char *s = removeSpaces(queryStr_).c_str();
            std::stack<char> opChar;
            std::stack<string> operand;
            string rpn;
            opChar.push('\0');
            while (!opChar.empty()) {
                if (isalpha(*s)) {
                    readString(s, operand);
                    rpn += operand.top() + " ";
                } else {
                    switch (orderBetween(opChar.top(), *s)) {
                        case '<':
                            opChar.push(*s);
                            ++s;
                            break;
                        case '=':
                            opChar.pop();
                            ++s;
                            break;
                        case '>':
                            rpn.append(" ");
                            rpn.insert(rpn.end(), opChar.top());
                            rpn.append(" ");
                            opChar.pop();
                            break;
                        default:
                            exit(-1);
                    }
                }
            }
            return rpn;
        }

        string removeSpaces(string srcW) {
            string r;
            for (auto c : srcW) {
                if (!isspace(c)) {
                    r.insert(r.end(), c);
                }
            }
            return r;
        }


        void readString(const char *&s, std::stack<string> &operand) {
            string word;
            while (isalpha(*s)) {
                word.push_back(*s);
                ++s;
            }
            operand.push(word);
        }

        static char orderBetween(char c1, char c2) {
            return CHARS[opChar2Rank.at(c1)][opChar2Rank.at(c2)];
        }

        static const std::map<char, int> opChar2Rank;
        string queryStr_;
        constexpr static unsigned N_OP = 6;
        //运算符优先等级 [栈顶] [当前]
        constexpr static char CHARS[N_OP][N_OP] = {
                /*~    &     |    (    ) '\0'*/
                /*~*/ {'>', '>', '>', '<', '>', '>'},
                /*&*/
                      {'<', '>', '>', '<', '>', '>'},
                /*|*/
                      {'<', '>', '>', '<', '>', '>'},
                /*(*/
                      {'<', '<', '<', '<', '=', ' '},
                /*)*/
                      {' ', ' ', ' ', ' ', ' ', ' '},
                /*'\0'*/
                      {'<', '<', '<', '<', ' ', '='}
        };

    };





}


#endif //PRIMERADVANCED_QUERY_H
