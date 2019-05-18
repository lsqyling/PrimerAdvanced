//
// Created by shiqing on 18-12-11.
//

/*
 * chapter15:trait and policy
 *
 */

#include <stack>
#include <assert.h>
#include "UsefullFwd.h"

namespace ch15 {
    template<typename T>
    class AccumulationTraits;

    template<>
    class AccumulationTraits<char> {
    public:
        typedef int AccT;
        static constexpr AccT zero = 0;
    };

    template<>
    class AccumulationTraits<short> {
    public:
        typedef int AccT;
        static constexpr AccT zero = 0;
    };

    template<>
    class AccumulationTraits<int> {
    public:
        typedef long AccT;
        static constexpr AccT zero = 0;
    };

    template<>
    class AccumulationTraits<unsigned> {
    public:
        typedef unsigned long AccT;
        static constexpr AccT zero = 0;
    };

    template<>
    class AccumulationTraits<float> {
    public:
        typedef double AccT;
        static constexpr AccT zero = 0;
    };

    template<typename T> using AccT = typename AccumulationTraits<T>::AccT;


    template<typename T>
    inline AccT<T> accum(const T *beg, const T *end) {
        AccT<T> total = AccumulationTraits<T>::zero;
        while (beg != end) {
            total += *beg;
            ++beg;
        }
        return total;
    }

    template<typename T, typename AT = AccT<T>>
    class Accum {
    public:
        static AT accum(const T *beg, const T *end) {
            AT total = AT();
            while (beg != end) {
                total += *beg;
                ++beg;
            }
            return total;
        }
    };

    template<typename T>
    inline AccT<T> accumOther(const T *beg, const T *end) {
        return Accum<T>::accum(beg, end);
    }

    namespace policy {
        class SumPolicy {
        public:
            template<typename T1, typename T2>
            static void accumulate(T1 &total, const T2 &value) {
                total += value;
            }
        };

        class MultiPolicy {
        public:
            template<typename T1, typename T2>
            static void accumulate(T1 &total, const T2 &value) {
                total *= value;
            }
        };
    }

    template<typename T, typename Policy = policy::SumPolicy, typename Traits = AccumulationTraits<T>>
    class Accumulate {
    public:
        using AccT = typename Traits::AccT;

        static AccT accum(const T *beg, const T *end, AccT initValue) {
            AccT total = initValue;
            while (beg != end) {
                Policy::accumulate(total, *beg);
                ++beg;
            }
            return total;
        }
    };

    template<typename T> using AccR = typename Accumulate<T>::AccT;

    template<typename T>
    inline AccR<T> accumMulti(const T *beg, const T *end, AccT<T> initValue = AccT<T>(1)) {
        return Accumulate<T, policy::MultiPolicy>::accum(beg, end, initValue);
    }


    /*
     * trait n(名词)：用来刻画一个事物的（与众不同）特性
     * policy n(名词):为了某种有益或有利的目的而采用的一系列动作。
     * policy 和 trait 具有很多共同点，但是policy 更加注重于行为，而trait则更加注重于类型
     *
     *
     * trait class : 是一种用于替代模板参数的类。作为一个类，它可以是有用的类型，也可以是常量；作为一个模板，
     * 它提供了一个一种实现“额外层次间接性”的途径，而正是这种“额外层次间接性”解决了所有软件问题。
     *
     */

    /*
     * 一般希望此函数返回结果是右值所以直接使用 auto 推断。
     */
    template<typename Iter>
    inline auto accum(Iter start, Iter end) {
        auto total = std::remove_reference_t<decltype(*start)>();
        while (start != end) {
            total += *start;
            ++start;
        }
        return total;
    }

    template<typename Container, typename Index>
    decltype(auto) authAndAccess(Container &&c, Index i) {
        return std::forward<Container>(c)[i];
    }

    template<typename T>
    class ElemT;

    template<typename T>
    class ElemT<vector<T>> {
    public:
        typedef T type;
    };

    template<typename T>
    class ElemT<list<T>> {
    public:
        typedef T type;
    };

    template<typename T>
    class ElemT<std::stack<T>> {
    public:
        typedef T type;
    };

    template<typename T> using ET = typename ElemT<T>::type;

    template<typename T>
    void printElementType(const T &c) {
        cout << "Container of "
             << typeid(ET<T>).name()
             << " elements.\n";
    }

    template<typename T>
    class IsClassT {
    private:
        typedef char One;
        typedef struct {
            char a[2];
        } Two;

        template<typename C>
        static One test(int C::*);

        template<typename C>
        static Two test(...);

    public:
        enum {
            Yes = sizeof(IsClassT<T>::test<T>(0)) == 1
        };
        enum {
            No = !Yes
        };
    };

    class MyClass {
    };

    struct MyStruct {
    };
    union MyUnion {
    };

    void myfunc() {};
    enum E {
        e1
    } e;

//    以模板实参的方式传递类型，并对该类型进行检查
    template<typename T>
    void check() {
        if (IsClassT<T>::Yes) {
            cout << " IsClassT " << endl;
        } else {
            cout << " !IsClassT " << endl;
        }
    }

    template<typename T>
    void checkT(T) {
        check<T>();
    }

    template<typename T>
    void apply(T &arg, void (*func)(T)) {
        func(arg);
    }

    void incr(int &a) {
        ++a;
    }

    void print(int a) {
        cout << a << endl;
    }

    template<typename T>
    class TypeOp {
    public:
        typedef T ArgT;
        typedef T BareT;
        typedef const T ConstT;
        typedef T &RefT;
        typedef T &RefBareT;
        typedef const T &RefConstT;
    };

    template<typename T>
    class TypeOp<const T> {
    public:
        typedef const T ArgT;
        typedef T BareT;
        typedef const T ConstT;
        typedef const T &RefT;
        typedef T &RefBareT;
        typedef const T &RefConstT;
    };

    template<typename T>
    class TypeOp<T &> {
    public:
        typedef T &ArgT;
        typedef typename TypeOp<T>::BareT BareT;
        typedef const T ConstT;
        typedef T &RefT;
        typedef typename TypeOp<T>::RefBareT RefBareT;
        typedef const T &RefConstT;
    };

    template<>
    class TypeOp<void> {
    public:
        typedef void ArgT;
        typedef void BareT;
        typedef const void ConstT;
        typedef void RefT;
        typedef void RefBareT;
        typedef void RefConstT;

    };

    template<typename T> using RefBareT = typename TypeOp<T>::RefBareT;
    template<typename T> using RefT = typename TypeOp<T>::RefT;


    template<typename T>
    void apply(RefT<T> arg, void (*func)(T)) {
        func(arg);
    }


    namespace promotion {
        template<typename T1, typename T2>
        class Promotion;

//        基本模板
        template<bool Boolean, typename Ta, typename Tb>
        class IfThenElse;

//        局部特化
        template<typename Ta, typename Tb>
        class IfThenElse<true, Ta, Tb> {
        public:
            typedef Ta ResultT;
        };

        template<typename Ta, typename Tb>
        class IfThenElse<false, Ta, Tb> {
        public:
            typedef Tb ResultT;
        };

        template<typename Ta, typename Tb> using RT = typename IfThenElse<sizeof(Tb) < sizeof(Ta), Ta, Tb>::ResultT;


        template<typename T>
        class PParam {
        public:
            typedef typename IfThenElse<sizeof(T) <= 2 * sizeof(void *), T, const T &>::ResultT Type;
        };

        template<typename T> using Type = typename IfThenElse<sizeof(T) <= 2 * sizeof(void *), T, const T &>::ResultT;


//       基本模板
        template<typename T, bool Bitwise>
        class BitOrClassCMS;

//        用于对象安全拷贝的局部特化
        template<typename T>
        class BitOrClassCMS<T, false> {
        public:
//            一项copy
            static void copy(Type<T> src, T *dest) {
                *dest = src;
            }

            static void copyN(const T *src, T *dst, size_t n) {
                for (int i = 0; i != n; ++i) {
                    dst[i] = src[i];
                }
            }

            static void copyInit(Type<T> src, void *dst) {
                //拷贝一项到未进行初始化的存储空间
                ::new(dst) T(src);
            }

            static void copyInitN(const T *src, T *dst, size_t n) {
                for (int i = 0; i != n; ++i) {
//                    :: . -> [] () () ++ -- typeid ++ -- ~ *! - + * &
                    ::new(&dst[i]) T(src[i]);
                }
            }

            static void swap(T *a, T *b) {
                T temp(*a);
                *a = *b;
                *b = temp;
            }

            static void swapN(T *a, T *b, size_t n) {
                for (int i = 0; i != n; ++i) {
                    T temp(a[i]);
                    a[i] = b[i];
                    b[i] = temp;
                }
            }

            static void move(T *src, T *dst) {
                assert(src != dst);
                *dst = *src;
                src->~T();
            }

            static void moveN(T *src, T *dst, size_t n) {
                assert(src != dst);
                for (int i = 0; i != n; ++i) {
                    dst[i] = src[i];
                    src[i].~T();
                }
            }

            static void moveInit(T *src, void *dst) {
                assert(src != dst);
                ::new(dst) T(*src);
                src->~T();
            }

            static void moveInitN(const T *src, T *dst, size_t n) {
                assert(src != dst);
                for (int i = 0; i != n; ++i) {
                    ::new (&dst[i]) T(src[i]);
                    src[i].~T();
                }
            }




        };


    }


}


int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    // average
    cout << "the average value of the integer value is "
         << ch15::accum(std::begin(nums), std::end(nums)) / 5
         << "\n";
    char name[] = "templates";
    cout << "the average value of the characters in "
         << ch15::accum(std::begin(name), std::end(name)) / (sizeof(name) - 1)
         << "\n";

    cout << ch15::accumOther(std::begin(nums), std::end(nums)) << endl;
    cout << ch15::accumOther(std::begin(name), std::end(name)) << endl;

    cout << ch15::accumMulti(std::begin(nums), std::end(nums));
    cout << ch15::accumMulti(std::begin(nums), std::end(nums));

    std::stack<bool> s;
    ch15::printElementType(s);

    cout << "int: ";
    ch15::check<int>();

    cout << "MyClass: ";
    ch15::check<ch15::MyClass>();

    cout << "MyStruct: ";
    ch15::MyStruct ms;
    ch15::checkT(ms);

    cout << "MyUnion: ";
    ch15::check<ch15::MyUnion>();

    cout << "enum: ";
    ch15::checkT(ch15::e);

    cout << "myfunc: ";
    ch15::checkT(ch15::myfunc);

    int x = 7;
    ch15::apply(x, ch15::print);

    ch15::apply(x, ch15::incr);


    return 0;
}

