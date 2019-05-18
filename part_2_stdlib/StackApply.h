//
// Created by shiqing on 18-5-14.
//

#ifndef DSA_STACKAPPLY_H
#define DSA_STACKAPPLY_H
#include "Stack.h"


#define N_OP 9
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符
typedef enum {ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator;

//运算符优先等级 [栈顶] [当前]
const char CHARS[N_OP][N_OP] = {
        /*              |-------------------- 当 前 运 算 符 --------------------| */
        /*              +      -      *      /      ^      !      (      )      \0 */
        /* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
        /* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
        /* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
        /* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
        /* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
        /* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
        /* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
        /* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
        /* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};



class StackApply {
public:
//    进制转换
    static void convert(Stack<char> &S, int n, int base);

//    括号匹配 exp[lo, hi)
    static bool paren(const char exp[], int lo, int hi);

//    栈混洗 (stack permutation)


//    算数表达式求值问题
    /**
     * 求值算法 = 栈 + 线性扫描
     * 1.中缀表达式
     */
    static float evaluate(char *exp, char* &RPN);

    /**
     * 逆波兰表达式
     * RPN - Reverse Polish Notation
     *
     * infix =>>> RPN ?
     */

    /**
     * remove space.
     */
    static char *removeSpace(char* S);
    static void transformToRPN(char *S, char *&RPN);


private:
    /**
     * 私有辅助函数
     */
    static void readNumber(char* &exp, Stack<float> &stack);

    static char orderBetween(char c1, char c2);

    static void append(char *&rpn, float num);
    static void append(char *&rpn, char opC);

    static Operator opChar2Rank(char op);

    static float calc(char op, float num);

    static float calc(float num1, char op, float num2);

};




#endif //DSA_STACKAPPLY_H
