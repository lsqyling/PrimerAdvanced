//
// Created by shiqing on 19-5-10.
//

#ifndef PRIMERADVANCED_QUERYBASE_H
#define PRIMERADVANCED_QUERYBASE_H

#include "../common/CommonHeaders.h"
#include "Query.h"

namespace query {

    class QueryResult;

    class TextQuery;

    class QueryBase {
        friend class Query;

    protected:
        virtual ~QueryBase() = default;

    private:
        virtual QueryResult eval(const TextQuery &tq) const = 0;

        virtual string rep() const = 0;

    };


    class WordQuery : public QueryBase {
        friend class Query;

        WordQuery(const string &queryWord) : queryWord_(queryWord) {}

        QueryResult eval(const TextQuery &tq) const override;

        string rep() const override;

        string queryWord_;

    };


    class NotQuery : public QueryBase {
        friend Query operator~(const Query &rhs);

        NotQuery(const Query &q) : query_(q) {}

        string rep() const override;

        QueryResult eval(const TextQuery &tq) const override;

        Query query_;
    };

    inline Query operator~(const Query &rhs) {
        return std::shared_ptr<QueryBase>(new NotQuery(rhs));
    }


    class BinaryQuery : public QueryBase {
    protected:
        BinaryQuery(const Query &lhs, const Query &rhs, string opSym)
                : lhs_(lhs), rhs_(rhs), opSym_(opSym) {}

        string rep() const override final {
            return "(" + lhs_.rep() + " "
                   + opSym_ + " "
                   + rhs_.rep() + ")";
        }


        Query lhs_, rhs_;
        string opSym_;
    };

    class AndQuery : public BinaryQuery {
        friend Query operator&(const Query &lhs, const Query &rhs);
        AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}

        QueryResult eval(const TextQuery &tq) const ;
    };

    inline Query operator&(const Query &lhs, const Query &rhs) {
        return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
    }

    class OrQuery : public BinaryQuery {
        friend Query operator|(const Query &lhs, const Query &rhs);
        OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
        QueryResult eval(const TextQuery &tq) const;
    };

    inline Query operator|(const Query &lhs, const Query &rhs) {
        return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
    }



}


#endif //PRIMERADVANCED_QUERYBASE_H
