//
// Created by shiqing on 18-12-10.
//

#include "UsefullFwd.h"

/**
 * chapter10:实例化
 */

namespace ch10 {
    /*
     * On-Demand 实例化也称为隐式实例化或自动实例化
     *
     */
    template<typename T>
    class Safe {};

    template<int N>
    class Danger {
    public:
        typedef char Block[N];
    };

    template<typename T, int N>
    class Tricky {
    public:
        virtual ~Tricky(){}
        void noBodyHere(Safe<T> = 3);
        void inClass() {
            Danger<N> noBoomYet;
        }
        void error() { Danger<0> boom; }
        void unsafe(T (*p)[N]);
        T operator->();
        virtual Safe<T> suspect() { } //虚函数必须提供定义，否则的话就会引发一个链接期错误
        struct Nested {
            Danger<N> pfew;
        };

        union {
            int align;
            Safe<T> anonymous;
        };

    };




}

int main() {

    using namespace ch10;
    Tricky<int, 0> ok;

    return 0;
}
