//
// Created by shiqing on 18-12-15.
//
/*
 * chapter21:tuple
 *
 */

#include <initializer_list>
#include <utility>
#include <type_traits>
#include "UsefullFwd.h"


namespace ch21 {
    template<typename T1, typename T2>
    class Duo {
    public:
        typedef T1 FirstType;
        typedef T2 SecondType;
        enum {
            N = 2
        };

        Duo() : first(), second() {}

        Duo(const T1 &a, const T2 &b) : first(a), second(b) {}

        template<class U1, class U2, class = typename
        std::enable_if<std::__and_<std::is_convertible<U1, T1>,
                std::is_convertible<U2, T2>>::value>::type>
        constexpr Duo(U1 &&x, U2 &&y)
                : first(std::forward<U1>(x)), second(std::forward<U2>(y)) {}


        template<typename U1, typename U2, typename = typename
        std::enable_if_t<std::__and_<std::is_convertible<U1, T1>,
                std::is_convertible<U2, T2>>::value> >
        constexpr Duo &operator=(Duo<U1, U2> &&d) {
            first = std::forward(d.first);
            second = std::forward(d.second);
            return *this;
        };

//        用于访问域的函数



        T1 first;
        T2 second;
    };

    template<typename T1, typename T2, typename U1, typename U2>
    inline bool operator==(const Duo<T1, T2> &d1, const Duo<U1, U2> &d2) {
//        == 优先级高于 &&
        return (d1.first == d2.first) && (d1.second == d2.second);
    }

    template<typename T1, typename T2, typename U1, typename U2>
    inline bool operator!=(const Duo<T1, T2> &d1, const Duo<U1, U2> &d2) {
        return !(d1 == d2);
    }

    template<typename T1, typename T2>
    inline Duo<T1, T2> makeDuo(const T1 &t1, const T2 &t2) {
        return {t1, t2};
    }

    template<typename T1, typename T2>
    inline Duo<T1, T2> makeDuo(T1 &&t1, T2 &&t2) {
        return {std::move(t1), std::move(t2)};
    }


    template<typename B1, typename B2, typename B3>
    class Duo<B1, Duo<B2, B3>> {
    public:
        typedef B1 T1;
        typedef Duo<B2, B3> T2;
        enum {
            N = Duo<B2, B3>::N + 1
        };
    };


    template<int N, typename T>
    class DuoT {
    public:
        typedef void ResultT;
    };

    template<typename A, typename B>
    class DuoT<1, Duo<A, B>> {
    public:
        typedef A ResultT;
    };

    template<typename A, typename B>
    class DuoT<2, Duo<A, B>> {
    public:
        typedef B ResultT;
    };

    template<int N, typename A, typename B, typename C>
    class DuoT<N, Duo<A, Duo<B, C>>> {
    public:
        typedef A ResultT;
    };

    template<typename A, typename B, typename C>
    class DuoT<2, Duo<A, Duo<B, C>>> {
    public:
        typedef B ResultT;
    };





}

int main() {
    ch21::Duo<int, int> duo = {0, 1};
    std::pair<double, int> p = {0.1, 0};
    return 0;
}

