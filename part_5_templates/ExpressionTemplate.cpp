//
// Created by shiqing on 18-12-14.
//
/**
 * chapter18:表达式模板
 * 表达式模板有时依赖与深层的嵌套模板实例化，而这种实例化又和template metaprogramming 中遇到的递归实例化非常相似，
 * 这两种技术都是为了支持高性能的数组操作，metaprogramming 主要用于小的、大小固定的数组，而表达式模板则使用与能够
 * 在运行期确定大小，中等大小的数组。
 *
 */

#include <arpa/nameser.h>
#include <cassert>
#include "UsefullFwd.h"


namespace ch18 {
    template<typename T>
    class SArray {
    public:
//        创建一个具有初始化值的数组
        explicit SArray(size_t s) : storage_(new T[s]), storageSize_(s) {
            init();
        }

        SArray(const SArray &rhs) : storage_(new T[rhs.size()]), storageSize_(rhs.size()) {
            copy(rhs);
        }

        ~SArray() {
            delete[] storage_;
        }


        size_t size() const {
            return storageSize_;
        }


        SArray &operator=(const SArray &rhs) {
            if (this != &rhs) {
                copy(rhs);
            }
            return *this;
        }

        T operator[](size_t idx) const {
            return storage_[idx];
        }

        T &operator[](size_t idx) {
            return storage_[idx];
        }

        SArray &operator+=(const SArray &rhs) {
            for (size_t i = 0; i != rhs.size(); ++i) {
                (*this)[i] += rhs[i];
            }
            return *this;
        }

        SArray &operator*=(const SArray &rhs) {
            for (size_t i = 0; i != rhs.size(); ++i) {
                (*this)[i] *= rhs[i];
            }
            return *this;
        }

        SArray &operator*=(const T &s) {
            for (size_t i = 0; i != size(); ++i) {
                (*this)[i] *= s;
            }
            return *this;
        }


    protected:
        void init() {
            for (size_t i = 0; i != storageSize_; ++i) {
                storage_[i] = T();
            }
        }

        void copy(const SArray &rhs) {
            assert(size() == rhs.size());
            for (size_t i = 0; i != size(); ++i) {
                storage_[i] = rhs.storage_[i];
            }
        }

    private:
        T *storage_;
        size_t storageSize_;
    };

    template<typename T>
    SArray<T> operator+(const SArray<T> &lhs, const SArray<T> rhs) {
        SArray<T> result(lhs.size());
        for (size_t i = 0; i != lhs.size(); ++i) {
            result[i] = lhs[i] + rhs[i];
        }
        return result;
    }

    template<typename T>
    SArray<T> operator*(const SArray<T> &lhs, const SArray<T> rhs) {
        SArray<T> result(lhs.size());
        for (size_t i = 0; i != lhs.size(); ++i) {
            result[i] = lhs[i] * rhs[i];
        }
        return result;
    }

    template<typename T>
    SArray<T> operator*(const T &s, const SArray<T> rhs) {
        SArray<T> result(rhs.size());
        for (size_t i = 0; i != rhs.size(); ++i) {
            result[i] = s * rhs[i];
        }
        return result;
    }

    template<typename T>
    struct Traits {
        typedef const T &ExprRef;
    };

    template<typename>
    class Scalar;

    template<typename T>
    struct Traits<Scalar<T>> {
        typedef Scalar<T> ExprRef;
    };


    template<typename T, typename OP1, typename OP2>
    class Add {
    public:
        Add(const OP1 &lhs, const OP2 &rhs) : op1(lhs), op2(rhs) {}

        constexpr T operator[](size_t idx) const {
            return op1[idx] + op2[idx];
        }


        constexpr size_t size() const {
            assert(op1.size() == 0 || op2.size() == 0
                   || op1.size() == op2.size());

            return op1.size() != 0 ? op1.size() : op2.size();
        }


    private:
        typename Traits<OP1>::ExprRef op1;
        typename Traits<OP2>::ExprRef op2;


    };


    template<typename T, typename OP1, typename OP2>
    class Multi {
    public:
        Multi(const OP1 &lhs, const OP2 &rhs) : op1(lhs), op2(rhs) {}

        constexpr T operator[](size_t idx) const {
            return op1[idx] * op2[idx];
        }


        constexpr size_t size() const {
            assert(op1.size() == 0 || op2.size() == 0
                   || op1.size() == op2.size());

            return op1.size() != 0 ? op1.size() : op2.size();
        }

    private:
        typename Traits<OP1>::ExprRef op1;
        typename Traits<OP2>::ExprRef op2;


    };


    template<typename T>
    class Scalar {
    public:
        Scalar(const T &v) : s(v) {}

        constexpr T operator[](size_t) const {
            return s;
        }

        constexpr size_t size() const {
            return 0;
        }

    private:
        const T &s;
    };


    template<typename T, typename Rep = SArray<T>>
    class Array {
    public:
        explicit Array(size_t sz) : exprRep_(sz) {}
        Array(const Rep &rb) : exprRep_(rb) {}
        Array &operator=(const Array &rhs) {
            assert(size() == rhs.size());
            for (size_t i = 0; i != rhs.size(); ++i) {
                exprRep_[i] = rhs[i];
            }
            return *this;
        }

        template<typename T2, typename Rep2>
        Array &operator=(const Array<T2, Rep2> &rhs) {
            for (int i = 0; i != rhs.size(); ++i) {
                exprRep_[i] = rhs[i];
            }
            return *this;
        }

        T operator[](size_t idx) const {
            return exprRep_[idx];
        }

        T &operator[](size_t idx) {
            assert(idx < size());
            return exprRep_[idx];
        }

        const Rep &rep() const {
            return exprRep_;
        }

        Rep &rep() { return exprRep_;}


        constexpr size_t size() const {
            return exprRep_.size();
        }
    private:
        Rep exprRep_;
    };




}

int main() {
    using namespace ch18;
    SArray<double> x(1000), y(1000);
    x = 1.2 * x + x * y;


    return 0;
}

