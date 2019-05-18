//
// Created by shiqing on 19-5-17.
//

#include "Token.h"


namespace un {

    Token &Token::operator=(const Token &t) {
        if (tok == STR && t.tok != STR) {
            sVal_.~string();
        }
        if (tok == STR && t.tok == STR) {
            sVal_ = t.sVal_;
        } else {
            copyUnion(t);
        }
        tok = t.tok;
        return *this;
    }


    Token &Token::operator=(Token &&t) {
        if (tok == STR && t.tok != STR) {
            sVal_.~string();
        }
        if (tok == STR && t.tok == STR) {
            sVal_ = std::move(t.sVal_);
        } else {
            moveUnion(std::move(t));
        }
        tok = t.tok;
        return *this;
    }

    Token &Token::operator=(const string &s) {
        if (tok == STR) {
            sVal_ = s;
        } else {
            new(&sVal_) string(s);
        }
        tok = STR;
        return *this;
    }

    Token &Token::operator=(char c) {
        if (tok == STR) {
            sVal_.~string();
        }
        cVal_ = c;
        tok = CHAR;
        return *this;
    }

    Token &Token::operator=(int i) {
        if (tok == STR) {
            sVal_.~string();
        }
        iVal_ = i;
        tok = INT;
        return *this;
    }

    Token &Token::operator=(double d) {
        if (tok == STR) {
            sVal_.~string();
        }
        dVal_ = d;
        tok = DBL;
        return *this;
    }

    void Token::copyUnion(const Token &t) {
        switch (t.tok) {
            case INT:
                iVal_ = t.iVal_;
                break;
            case CHAR:
                cVal_ = t.cVal_;
                break;
            case DBL:
                dVal_ = t.dVal_;
                break;
            case STR:
                new(&sVal_) string(t.sVal_);
                break;
        }

    }

    void Token::moveUnion(Token &&t) noexcept {
        switch (t.tok) {
            case INT:
                iVal_ = std::move(t.iVal_);
                break;
            case CHAR:
                cVal_ = std::move(t.cVal_);
                break;
            case DBL:
                dVal_ = std::move(t.dVal_);
                break;
            case STR:
                new(&sVal_) string(std::move(t.sVal_));
                break;
        }

    }


}