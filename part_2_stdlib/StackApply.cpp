//
// Created by shiqing on 18-5-14.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include "StackApply.h"

using namespace std;

void StackApply::convert(Stack<char> &S, int n, int base) {
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6',
                           '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n) {
        S.push(digit[n % base]);
        n /= base;
    }
}

bool StackApply::paren(const char *exp, int lo, int hi) {
    Stack<char> S;
    for (int i = lo; i < hi; ++i) {
        if ('(' == exp[i]) S.push(exp[i]);
        else if (')' == exp[i] && !S.empty()) S.pop();
        else return false;
    }
    return S.empty();
}


char* StackApply::removeSpace(char* S) {
    char * t = S, *p = S;
    while (true) {
        while (isspace(*p)) p++;
        if ('\0' == *p) {
            *t = '\0';
            return S;
        }
        *t++ = *p++;
    }

}


/**
 * 对（已剔除白空格的）表达式exp求值，并转换为逆波兰式RPN
 * char EXP[] = "((0 + (1 + 23) / 4 * 5 * 67 - 8 + 9))";
 */
float StackApply::evaluate(char *exp, char *&RPN) {
    Stack<float> opNum; Stack<char> opChar;
    opChar.push('\0');
//    在运算符栈非空之前，逐个处理表达式中各字符
    while (!opChar.empty()) {
//        若当前字符为操作数，则读入操作数，并将其接至RPN末尾
        if (isdigit(*exp)) {
            readNumber(exp, opNum);
            append(RPN, opNum.top());
        } else {
            switch (orderBetween(opChar.top(), *exp)) {
//                栈顶运算符优先级更低时
                case '<':
                    opChar.push(*exp); exp++;
                    break;
//                优先级相等（当前运算符为右括号或者尾部哨兵'\0'）时
                case '=':
                    opChar.pop(); exp++;
                    break;
//                栈顶运算符优先级更高时，可实施相应的计算，并将结果重新入栈
                case '>': {
                    char opC = opChar.pop();
//                    栈顶运算符出栈并续接至RPN末尾
                    append(RPN, opC);
                    if ('!' == opC) {
//                        只需一个操作数
                        float num = opNum.pop();
                        opNum.push(calc(opC, num));
                    } else {
                        float num2 = opNum.pop(), num1 = opNum.pop();
                        opNum.push(calc(num1, opC, num2));
                    }
                    break;
                }
                default: exit(-1);
            }
        }
    }
    return opNum.pop();
}


void StackApply::transformToRPN(char* S, char* &RPN) {
    Stack<float> opNum; Stack<char> opChar;
    opChar.push('\0');
    while (!opChar.empty()) {
        if (isdigit(*S)) {
            readNumber(S, opNum);
            append(RPN, opNum.top());
        } else {
            switch (orderBetween(opChar.top(), *S)) {
                case '<':
                    opChar.push(*S); S++;
                    break;
                case '=':
                    opChar.pop(); S++;
                    break;
                case '>': {
                    append(RPN, opChar.pop());
                    break;
                }
                default: exit(-1);
            }
        }
    }
}

//将起始于exp的子串解析为数值，并存入操作数栈
void StackApply::readNumber(char* &exp, Stack<float> &s) {
    s.push(*exp - '0');
//    当前数位对应的数值进栈
    while (isdigit(*++exp)) {
        s.push(s.pop() * 10 + (*exp - '0'));
    }
//    此后非小数点，则意味着当前操作数解析完成
    if ('.' != *exp) return;
    int fraction = 1;
    while (isdigit(*++exp)) {
        s.push(s.pop() + (*exp - '0') * (fraction /= 10));
    }
}


char StackApply::orderBetween(char c1, char c2) {
    return CHARS[opChar2Rank(c1)][opChar2Rank(c2)];
}

void StackApply::append(char *&rpn, float num) {
//    将操作数接至RPN末尾
    int len = strlen(rpn);
    char buf[128];
    if (num != (int) num) {
        sprintf(buf, "%.6f \0", num);
    } else {
        sprintf(buf, "%d \0", (int) num);
    }
    rpn = (char *) realloc(rpn, sizeof(char) * (len + strlen(buf) + 1));
    strcat(rpn, buf);
}

void StackApply::append(char *&rpn, char opC) {
//    RPN当前长度（以'\0'结尾，长度n + 1）
    int n = strlen(rpn);
    rpn = (char *) realloc(rpn, sizeof(char) * (n + 3));
    sprintf(rpn + n, "%c ", opC);
    rpn[n + 2] = '\0';
}


Operator StackApply::opChar2Rank(char op) {
    switch (op) {
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '^': return POW;
        case '!': return FAC;
        case '(': return L_P;
        case ')': return R_P;
        case '\0':return EOE;
        default : exit(-1);
    }
}

float StackApply::calc(char op, float num) {
    switch (op) {
        case '!': {
            int n = (int)num;
            float f = 1;
            while (1 < n) {
                f *= n--;
            }
            return f;
        }
        default: exit(-1);
    }
}

float StackApply::calc(float num1, char op, float num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': {
            if (-1e-8 < num2 && num2 < 1e-8) {
                exit(-1);
            }
            return num1 / num2;
        }
        case '^': return pow(num1, num2);
        default: exit(-1);
    }
}



