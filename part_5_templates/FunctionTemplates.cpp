//
// Created by shiqing on 18-12-6.
//
/**
 * 2.1 初探函数模板
 * please check @function max()
 * Note:当使用模板函数，并且引发模板实例化的时候，编译器需要查看模板的定义。这就不同与普通函数中编译和链接之间的区别，
 * 只需要查看函数的声明就可以顺利通过编译.
 * Deduction:尽量使用简洁并单参版本的max() 就是一个很不错的实践.
 *
 * Overload:改变参数的数目或者显式地指定模板的参数.
 *
 *
 *
 *
 *
 *
 */

#include <cstring>
#include "UsefullFwd.h"

//the max of int
inline const int &max(const int &a, const int &b) {
    return a < b ? b : a;
}

//any type the max of
template<typename T>
inline const T &max(const T &a, const T &b) {
    return a < b ? b : a;
}

//三个任意类型的最大者
template<typename T>
inline const T &max(const T &a, const T &b, const T &c) {
    return max(max(a, b), c);
}

template<typename T>
inline const T *&max(const T *&a, const T *&b) {
    return *a < *b ? b : a;
}

inline const char *&max(const char *&a, const char *&b) {
    return strcmp(a, b) < 0 ? b : a;
}




int main(int argc, char *argv[]) {
    int i = 42;
    printf("The two Number is max of : %d\n", max(5, i));
    double f1 = 3.4, f2 = -6.7;
    printf("the two floats max of is %f\n", max(f1, f2));


    string s1("mathematics"), s2("math");
    printf("two string max of is %s\n", ::max(s1, s2).c_str());

    max(4, 7); // ok
//    max(4, 4.2); ERROR:first int, second double
//    solution:
    max(static_cast<double>(4), 4.2);
    max<double>(4, 4.2);

    max(7, 42, 68);//3 个参数的模板
    max('a', 'b');// max<char>
    max(7, 42); // max(int, int) 非模板
    max<>(7, 42); // max<int>
    max<double>(7, 42); //max<double>
    max('a', 42); // max(int, int)


    int b = 42, a = 7;
    max(a, b); // max(int, int)

    string s("hey"), t("you");
    ::max(s, t);//








    return 0;
}