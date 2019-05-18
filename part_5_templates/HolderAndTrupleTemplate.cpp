//
// Created by shiqing on 18-12-15.
//

/*
 * chapter20:holder and truple
 */


#include <algorithm>
#include "UsefullFwd.h"


namespace ch20 {

    template<typename>
    class Holder;

    template<typename>
    class Trule;


    template<typename T>
    class Holder {
    public:
        Holder() : ptr(nullptr) {}

        explicit Holder(T *p) : ptr(p) {}

        Holder(const Trule<T> &t) : ptr(t.ptr) {
            const_cast<Trule<T> &>(t).prt = nullptr;
        }

        Holder(Trule<T> &&t) : ptr(t.ptr) {
            t.ptr = nullptr;
        }

        Holder(const Holder &) = delete;

        Holder &operator=(const Holder &) = delete;

        ~Holder() { delete ptr; }

//        针对新指针的赋值运算符
        Holder &operator=(T *p) {
            delete ptr;
            ptr = p;
            return *this;
        }

        Holder &operator=(const Trule<T> &t) {
            delete ptr;
            ptr = t.ptr;
            const_cast<Trule<T> &>(t).ptr = nullptr;
            return *this;
        }

        Holder &operator=(Trule<T> &&t) {
            delete ptr;
            ptr = t.ptr;
            t.ptr = nullptr;
            return *this;
        }

//        针对指针的运算符
        T &operator*() const {
            return *ptr;
        }

        T *operator->() const {
            return ptr;
        }

//        获取所引用的对象（前提是该对象存在）
        T *get() const {
            return ptr;
        }

        T *release() {
            T *ret = ptr;
            ptr = nullptr;
            return ret;
        }

        void exchangeWith(Holder &h) {
            std::swap(ptr, h.ptr);
        }

        void exchangeWith(T *&p) {
            std::swap(ptr, p);
        }


    private:
        T *ptr;
    };


    template<typename T>
    class Trule {
        friend class Holder<T>;

    public:
//        构造函数，确保trule只能作为返回类型，用于将Holder
//        从被调用函数传递给调用函数
        Trule(Holder<T> &h) {
            ptr = h.get();
            h.release();
        }

        Trule(const Trule &t) : ptr(t.ptr) {
            const_cast<Trule<T> &>(t).ptr = nullptr;
        }

//        析构函数
        ~Trule() { delete ptr; }


        Trule(Trule &) = delete;

        Trule &operator=(Trule &) = delete;


    private:
        T *ptr;
    };

    class Something {
    };

    void readSomething(Something *x) {
        cout << "readSomething(): " << endl;
    }

    Trule<Something> loadSomething() {
        cout << "loadSomething(): " << endl;
        Holder<Something> result(new Something);
        readSomething(result.get());
        return result;
    }

    /*
     * 用于动态分配的对象的管理，一条普通的规则可以简单阐述如下：
     * 在一个应用程序中，对任何一个动态分配的对象，如果没有任何变量指向它，那么这个对象就应该被销毁，其占用的内存同时也应该
     * 被释放。显然，该policy 是正确的，各地的程序员也都曾经寻找过自动执行这种policy 的方式，然而，对policy 而言，难点在于确定没有任何
     * 变量指向这个特定的对象。
     */
    class CounterPolicy {
    public:
        CounterPolicy();

        CounterPolicy(const CounterPolicy &);

        ~CounterPolicy();

        CounterPolicy &operator=(const CounterPolicy &);

    };

    class StandardObjPolicy {
    public:
        template<typename T>
        void dispose(T *obj) {
            delete obj;
        }
    };

    class StandardArrayPolicy {
    public:
        template<typename T>
        void dispose(T *array) {
            delete[] array;
        }

    };


    template<typename T, typename CounterPolicy, typename ObjectPolicy = StandardObjPolicy>
    class CountingPtr : private CounterPolicy, private ObjectPolicy {
        CountingPtr() : objPointerTo_(nullptr) {}
        explicit CountingPtr(T *p) {
            init(p);
        }

        CountingPtr(const CountingPtr &cp) {
            attach(cp);
        }

        ~CountingPtr() {
            detach();
        }

        CountingPtr &operator=(T *p) {
            assert(p != objPointerTo_);
            detach();
            init(p);
            return *this;
        }

        CountingPtr &operator=(const CountingPtr &cp) {
            if (objPointerTo_ != cp.objPointerTo_) {
                detach();
                CounterPolicy::operator=(cp);
                ObjectPolicy::operator=(cp);
                attach(cp);
            }
            return *this;
        }

        T *operator->() const {
            return objPointerTo_;
        }

        T &operator*() const {
            return *objPointerTo_;
        }


    private:
//        辅助函数
        void init(T *p) {
            if (p) {
                CounterPolicy::init(p);
            }
            objPointerTo_ = p;
        }

        void attach(const CountingPtr &cp) {
            objPointerTo_ = cp.objPointerTo_;
            if (cp.objPointerTo_) {
                CounterPolicy::increment(cp.objPointerTo_);
            }
        }

        void detach() {
            if (objPointerTo_) {
                CounterPolicy::decrement(objPointerTo_);
                if (CounterPolicy::isZero(objPointerTo_)) {
                    CounterPolicy::dispose(objPointerTo_);
                    ObjectPolicy::dispose(objPointerTo_);
                }
            }
        }

    private:
        T *objPointerTo_;
    };


    class SimpleReferenceCount {
    public:
        template<typename T> void init(T *) {
            counter_ = new size_t(0);
        }
        template<typename T> void dispose(T*) {
            delete counter_;
        }
        template<typename T> void increment(T *) {
            ++*counter_;
        }
        template<typename T> void decrement(T *) {
            --*counter_;
        }

        template<typename T> bool isZero(T *) {
            return *counter_ == 0;
        }

    private:
        size_t *counter_;
    };


}

int main() {
    ch20::Holder<ch20::Something> ptr(ch20::loadSomething());

    return 0;
}

