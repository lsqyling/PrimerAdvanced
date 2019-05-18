//
// Created by shiqing on 18-12-13.
//

#include "UsefullFwd.h"

/**
 * chapter17:template metaprogramming
 * 模板实例化是一种基本的递归语言机制，可以用于在编译期执行复杂的计算，
 * 因此，这种随着模板实例化所出现的编译期计算通常就称为 template metaprogramming
 *
 */


namespace ch17 {
//    计算3的N次方的基本模板
    template<int N>
    class Pow3 {
    public:
        enum : unsigned long long {
            result = 3 * Pow3<N - 1>::result
        };
    };

//    结束递归的全局特化
    template<>
    class Pow3<0> {
    public:
        /*
         * 如果我们没有指定enum的潜在类型，默认情况下限定作用域的enum 成员类型是int。
         * 对于不限定作用域的枚举类型来说，其成员不存在默认类型，我们只知道成员的潜在类型足够大，肯定能容纳枚举值
         */
        enum : unsigned long long {
            result = 1ULL
        };
    };

    /*
     * Pow3<>模板（包含它的特化）就成为一个template metaprogramming
     */

    struct TrueConstans {
        enum {
            Three = 3
        };
        static int constexpr Four = 4;
    };

    template<int N, unsigned W = 3>
    class Pow_3 {
    public:
        static unsigned long long constexpr result = W * Pow_3<N - 1>::result;
    };

    template<>
    class Pow_3<0> {
    public:
        static unsigned long long constexpr result = 1ULL;
    };


    void foo(const int &v) {
        cout << "value : " << v << endl;
    }

    template<int N, int LO = 0, int HI = N>
    class Sqrt {
    public:
//        计算中点
        enum {
            mid = (LO + HI + 1) / 2
        };

        enum {
            result = (N < mid * mid) ? Sqrt<N, LO, mid - 1>::result : Sqrt<N, mid, HI>::result
        };
    };

//    局部特化，使用LO == HI
    template<int N, int M>
    class Sqrt<N, M, M> {
    public:
        enum {
            result = M
        };

    };


    template<bool Boolean, typename Ta, typename Tb>
    struct CondiExpr;

    template<typename Ta, typename Tb>
    struct CondiExpr<true, Ta, Tb> {
        typedef Ta ResultT;
    };

    template<typename Ta, typename Tb>
    struct CondiExpr<false, Ta, Tb> {
        typedef Tb ResultT;
    };

    template<bool Boolean, typename Ta, typename Tb> using RCondiExpr = typename CondiExpr<Boolean, Ta, Tb>::ResultT;


    /*
     * 采用CondiExpr 模板，只有在查找SubT::result 的时候，才会完全实例化SubT所代表的类型，基于这中策略，我们的实例化体的数量
     * 得以趋向与logN,当N变得很大时，该策略将大大减少metaprogramming 的开销
     */
    template<int N, int LO = 0, int HI = N>
    class SqrtSmart {
    public:
        enum {
            mid = (LO + HI + 1) / 2
        };
        using SubT = RCondiExpr<(N < mid * mid), SqrtSmart<N, LO, mid - 1>, SqrtSmart<N, mid, HI>>;
        enum {
            result = SubT::result
        };
    };

    template<int N, int S>
    class SqrtSmart<N, S, S> {
    public:
        enum {
            result = S
        };
    };


    template<typename T, typename U>
    struct Doublify {
    };

    template<int N>
    struct Trouble {
        typedef Doublify<typename Trouble<N - 1>::LongType, typename Trouble<N - 1>::LongType> LongType;
    };

    template<>
    struct Trouble<0> {
        typedef double LongType;
    };

    template<typename T>
    inline T dotProduct(int dim, T *a, T *b) {
        T result = T();
        for (int i = 0; i != dim; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }


    template<int DIM, typename T>
    class DotProduct {
    public:
        static T result(T *a, T *b) {
            return *a * *b + DotProduct<DIM - 1, T>::result(a + 1, b + 1);
        }
    };

    template<typename T>
    class DotProduct<1, T> {
    public:
        static T result(T *a, T *b) {
            return *a * *b;
        }
    };

    template<int DIM, typename T>
    inline T dotProductOther(T *a, T *b) {
        return DotProduct<DIM, T>::result(a, b);
    }

    template<int p, int i>
    class IsPrime {
    public:
        enum { prime = (p == 2) || (p % i && IsPrime<(i > 2) ? p : 0, i-1>::prime) };
    };

    template<>
    class IsPrime<0, 0> {
    public:
        enum { prime = 1 };
    };

    template<>
    class IsPrime<0, 1> {
    public:
        enum { prime = 1 };
    };

    template<int i>
    class D {
    public:
        D(int) { };
    };

    template<int i>
    class PrimePrint {
    public:
        PrimePrint<i-1> a; // 分别实例化是一个独立的对象，对象是完全类型的，非模板类是不可以的
        enum {
            prime = IsPrime<i, i-1>::prime
        };

        void f() {
            D<i> d = prime ? 1 : 0;
            a.f();
        }
    };

    template<>
    class PrimePrint<1> {
    public:
        enum { prime = 0 };
        void f() {
            D<1> d = prime ? 1 : 0;
        }
    };



}


int main() {
    cout << "Pow3<3>::result = " << ch17::Pow3<3>::result << endl;
    cout << "Pow_3<3>::result = " << ch17::Pow_3<3>::result << endl;

    ch17::foo(ch17::Pow_3<7>::result);
    cout << "Sqrt<16>::result = " << ch17::Sqrt<16>::result << endl;
    cout << "Sqrt<25>::result = " << ch17::Sqrt<25>::result << endl;
    cout << "Sqrt<9>::result = " << ch17::Sqrt<9>::result << endl;
    cout << "Sqrt<625>::result = " << ch17::Sqrt<625>::result << endl;
    cout << "Sqrt<1>::result = " << ch17::Sqrt<1>::result << endl;

    cout << "SqrtSmart<16>::result = " << ch17::SqrtSmart<16>::result << endl;
    cout << "SqrtSmart<25>::result = " << ch17::SqrtSmart<25>::result << endl;
    cout << "SqrtSmart<9>::result = " << ch17::SqrtSmart<9>::result << endl;
    cout << "SqrtSmart<625>::result = " << ch17::SqrtSmart<625>::result << endl;
    cout << "SqrtSmart<1>::result = " << ch17::SqrtSmart<1>::result << endl;

//    相当低效，复杂度为2的N次方，避免在模板实参中使用递归嵌套的实例化
    ch17::Trouble<2>::LongType ouch;

    int a[3] = {1, 2, 3};
    int b[3] = {5, 6, 7};
    cout << "dotProduct(3,a,b) = " << ch17::dotProduct(3, a, b) << endl;
    cout << "dotProduct(3,a,a) = " << ch17::dotProduct(3, a, a) << endl;

    ch17::PrimePrint<18> primePrint;
    primePrint.f();


    return 0;


}
