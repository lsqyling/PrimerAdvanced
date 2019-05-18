//
// Created by shiqing on 18-12-9.
//

/**
 * chapter 7:模板术语
 *
 */

#include "UsefullFwd.h"



namespace ch7 {
    template<typename T1, typename T2>
    class MyClass {};

//    explict specialization
    template<> class MyClass<string, float> {};
    /**
     * Note:partial specialization --- 对于仍然具有模板参数的特化.
     *
     */
//    partial specialization
    template<typename T>
    class MyClass<T, T> {};

    template<typename T>
    class MyClass<int, T>{};

    template<typename T, int N>
    class ArrayInClass {
    public:
        T array[N];
    };


}

int main() {
//    模板实参必须是一个可以在编译期确定的模板实体或值
//    template-id,它指的是模板名称与“紧随其后的尖括号内部的所有实参”的组合
//    我们可以像对应的非模板实体使用这个template-id名称
    ch7::ArrayInClass<double, 7> ad;
    ad.array[0] = 1.0;
    cout << ad.array[0] << endl;

    return 0;
}


