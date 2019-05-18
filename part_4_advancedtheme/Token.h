//
// Created by shiqing on 19-5-17.
//

#ifndef PRIMERADVANCED_TOKEN_H
#define PRIMERADVANCED_TOKEN_H

#include "../common/CommonHeaders.h"


namespace un {


    class Token {
    public:
        Token() : tok(INT), iVal_(0) {}
        Token(const Token &t) : tok(t.tok) { copyUnion(t); }
        Token(Token &&t) noexcept : tok(t.tok) { moveUnion(std::move(t));}
        Token &operator=(const Token &t);
        Token &operator=(Token &&t);

        ~Token() { if (tok == STR) sVal_.~string(); }

        Token &operator=(const string &s);
        Token &operator=(char c);
        Token &operator=(int i);
        Token &operator=(double d);



    private:
        enum EnValue{
            INT, CHAR, DBL, STR
        } tok;
        union {
            char cVal_;
            int iVal_;
            double dVal_;
            string sVal_;
        };

        void copyUnion(const Token &tok);
        void moveUnion(Token &&t) noexcept ;

    };


}


#endif //PRIMERADVANCED_TOKEN_H
