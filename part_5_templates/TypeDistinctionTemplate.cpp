//
// Created by shiqing on 18-12-14.
//

/**
 * chapter19:类型区分
 *
 */

#include "UsefullFwd.h"

namespace ch19 {
//    基本模板：一般情况下，T 不是基本类型
    template<typename T>
    struct IsFundaT {
        enum { Yes = 0, No = 1 };
    };

//    用于特化基本类型的宏
#define MK_FUNDA_TYPE(T) \
    template<> struct IsFundaT<T> {\
        enum { Yes = 1, No = 0 };   \
    };

    MK_FUNDA_TYPE(void)
    MK_FUNDA_TYPE(char)
    MK_FUNDA_TYPE(signed char)
    MK_FUNDA_TYPE(unsigned char)
    MK_FUNDA_TYPE(wchar_t)

    MK_FUNDA_TYPE(signed short)
    MK_FUNDA_TYPE(unsigned short)
    MK_FUNDA_TYPE(signed int)
    MK_FUNDA_TYPE(unsigned int)
    MK_FUNDA_TYPE(long)
    MK_FUNDA_TYPE(unsigned long)
    MK_FUNDA_TYPE(long long)
    MK_FUNDA_TYPE(unsigned long long)
#if LONGLONG_EXISTS
    MK_FUNDA_TYPE(long long)
    MK_FUNDA_TYPE(unsigned long long)
#endif

    MK_FUNDA_TYPE(float)
    MK_FUNDA_TYPE(double)
    MK_FUNDA_TYPE(long double)

#undef MK_FUNDA_TYPE

    template<typename T>
    void test(const T &t) {
        if (IsFundaT<T>::Yes) {
            cout << "T is fundamental type " << endl;
        } else {
            cout << "T is no fundamental type" << endl;
        }
    }

    class MyClass {};

    template<typename T>
    class CompoundT {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0
        };
        typedef T BaseT;
        typedef T BottomT;
        typedef CompoundT<void> ClassT;
    };

    template<typename T>
    class CompoundT<T&> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 1, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0
        };

        typedef T BaseT;
        typedef typename CompoundT<T>::BottomT BottomT;
        typedef CompoundT<void> ClassT;
    };

    template<typename T>
    class CompoundT<T*> {
    public:
        enum {
            IsPtrT = 1, IsRefT = 0, IsArrayT = 0, IsFuncT = 0, IsPtrMemT = 0
        };

        typedef T BaseT;
        typedef typename CompoundT<T>::BottomT BottomT;
        typedef CompoundT<void> ClassT;

    };

    template<typename T, size_t N>
    class CompoundT<T[N]> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 1,
            IsFuncT = 0, IsPtrMemT = 0
        };

        typedef T BaseT;
        typedef typename CompoundT<T>::BottomT BottomT;
        typedef CompoundT<void> ClassT;
    };

    template<typename T, typename C>
    class CompoundT<T C::*> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 0,
            IsFuncT = 0, IsPtrMemT = 1
        };
        typedef T BaseT;
        typedef typename CompoundT<T>::BottomT BottomT;
        typedef C ClassT;
    };


    template<typename R>
    class CompoundT<R()> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 0,
            IsFuncT = 0, IsMemT = 0
        };
        typedef R BaseT();
        typedef R BottomT();
        typedef CompoundT<void> ClassT;
    };

    template<typename R, typename P1>
    class CompoundT<R(P1)> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 0,
            IsFuncT = 1, IsPtrMemT = 0
        };
        typedef R BaseT(P1);
        typedef R BottomT(P1);
        typedef CompoundT<void> ClassT;
    };

    template<typename R, typename P1>
    class CompoundT<R(P1, ...)> {
    public:
        enum {
            IsPtrT = 0, IsRefT = 0, IsArrayT = 0,
            IsFuncT = 0, IsPtrMemT = 0
        };
        typedef R BaseT(P1);
        typedef R BottomT(P1);
        typedef CompoundT<void> ClassT;
    };

    template<typename T>
    class IsFunctionT {

    private:
        typedef char One;
        typedef struct { char a[2];} Two;
        template<typename U> static One test(...);
        template<typename U> static Two test(U (*)[1]);


    public:
        enum {
            Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1
        };
        enum { No = !Yes };


    };






}


int main() {
    ch19::test(7);
    ch19::test(7LL);
    ch19::test(ch19::MyClass());
    return 0;
}

