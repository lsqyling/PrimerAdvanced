//
// Created by shiqing on 19-5-10.
//

#include "QueryBase.h"
#include "TextQuery.h"


namespace query {


    QueryResult WordQuery::eval(const TextQuery &tq) const {
        return tq.query(queryWord_);
    }

    string WordQuery::rep() const {
        return queryWord_;
    }


    string NotQuery::rep() const {
        return "~(" + query_.rep() + ")";
    }

    QueryResult NotQuery::eval(const TextQuery &tq) const {
        QueryResult result = query_.eval(tq);
        auto tmp = std::make_shared<std::set<int>>();
        auto sz = result.getFileLines()->size();
        auto lineNoSet = result.getLineNoSet();
        for (decltype(sz) i = 0; i != sz; ++i) {
            auto it = lineNoSet->find(i + 1);
            if (it == lineNoSet->end()) {
                tmp->insert(i + 1);
            }
        }
        return QueryResult(tq.getFileLines(), tmp, tmp->size());
    }


    QueryResult AndQuery::eval(const TextQuery &tq) const {
        QueryResult left = lhs_.eval(tq), right = rhs_.eval(tq);
        auto tmp = std::make_shared<std::set<int>>();
        auto lLineNoSet = left.getLineNoSet(), rLineNoSet = right.getLineNoSet();
        auto sz = left.getFileLines()->size();
        auto lE = lLineNoSet->end(), rE = lLineNoSet->end();
        for (decltype(sz) i = 0; i != sz; ++i) {
            if (lLineNoSet->find(i + 1) != lE && rLineNoSet->find(i + 1) != rE) {
                tmp->insert(i + 1);
            }
        }
        return QueryResult(tq.getFileLines(), tmp, tmp->size());
    }


    QueryResult OrQuery::eval(const TextQuery &tq) const {
        QueryResult left = lhs_.eval(tq), right = rhs_.eval(tq);
        auto tmp = std::make_shared<std::set<int>>(left.getLineNoSet()->begin(), left.getLineNoSet()->end());
        tmp->insert(right.getLineNoSet()->begin(), right.getLineNoSet()->end());
        return QueryResult(tq.getFileLines(), tmp, tmp->size());
    }


}

