//
// Created by shiqing on 19-5-11.
//

#ifndef PRIMERADVANCED_VECTOR_H
#define PRIMERADVANCED_VECTOR_H

#include <memory>

namespace tem {

    namespace utility {

        template<typename InputIterator, typename OutIterator, typename T>
        void copyFromRight(InputIterator beg, InputIterator end, OutIterator it, const T &val);

        template<typename InputIterator, typename OutIterator>
        void copyFromLeft(InputIterator beg, InputIterator end, OutIterator start);

        template<typename Iterator>
        void destroyRange(Iterator beg, Iterator end);

        template<typename T>
        T *initializedOfValue(const T &val, size_t n, T *pos);

        template<typename Iterator, typename T>
        T *uninitializedCopy(Iterator beg, Iterator end, T *start);

        template<typename T>
        void constructAt(const T &t, T *pt);

        template<typename T, typename... Args>
        void constructAt(Args &&... args, T *pt);

        template<typename T>
        void destroyAt(T *pos);

        template<typename Iterator, typename T>
        T *uninitializedCopy(Iterator beg, Iterator end, T *start) {
            while (beg != end) {
                constructAt(*beg++, start++);
            }
            return start;
        }

        template<typename T>
        inline void constructAt(const T &t, T *pt) {
            new(pt) T(t);
        }

        template<typename T, typename... Args>
        inline void constructAt(Args &&... args, T *pt) {
            new(pt) T(std::forward<Args>(args)...);
        }


        template<typename T>
        inline void destroyAt(T *val) {
            val->~T();
        }


        template<typename T>
        T *initializedOfValue(const T &val, size_t n, T *pos) {
            for (size_t i = 0; i != n; ++i) {
                constructAt(val, pos++);
            }
            return pos;
        }

        template<typename InputIterator, typename OutIterator, typename T>
        void copyFromRight(InputIterator beg, InputIterator end, OutIterator it, const T &val) {
            while (end != beg) {
                *it-- = *--end;
            }
            constructAt(val, end);
        }

        template<typename InputIterator, typename OutIterator>
        void copyFromLeft(InputIterator beg, InputIterator end, OutIterator start) {
            while (beg != end) {
                *start++ = *beg++;
            }
        }

        template<typename Iterator>
        void destroyRange(Iterator beg, Iterator end) {
            for (; end != beg; --end) {
                destroyAt(end - 1);
            }
        }


    }


    template<typename, typename>
    struct Pair;

    template<typename>
    class Vector;

    template<typename T>
    bool operator==(const Vector<T> &lhs, const Vector<T> &rhs);

    template<typename T>
    bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs);

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Vector<T> &rhs);

    template<typename T>
    class Vector {
        friend bool operator==<T>(const Vector<T> &lhs, const Vector<T> &rhs);

        friend std::ostream &operator<<<T>(std::ostream &os, const Vector<T> &rhs);

        friend bool operator!=<T>(const Vector<T> &lhs, const Vector<T> &rhs);

    public:
        using SizeT = std::size_t;
        using ValueType = T;
        using RefType = T &;
        using RRefType = T &&;
        using ConstRefType = const T &;
        using Iterator = T *;
        using ConstIterator = const T *;

        Vector() : bufBegin_(nullptr), bufEnd_(nullptr), usageCapEnd_(nullptr) {}

        Vector(std::initializer_list<T> li);

        Vector(ConstRefType val, SizeT n);

        template<typename It>
        Vector(It beg, It end);

        Vector(const Vector &v);

        Vector(Vector &&v) noexcept;

        Vector &operator=(const Vector &v);

        Vector &operator=(Vector &&v) noexcept;

        virtual ~Vector();


        bool empty() const noexcept;

        SizeT size() const noexcept;

        SizeT capacity() const noexcept;

        Iterator begin() const noexcept;

        Iterator end() const noexcept;

        ConstIterator cbegin() const noexcept;

        ConstIterator cend() const noexcept;


        void pushBack(ConstRefType val);

        void pushBack(RRefType val);

        ValueType top() const noexcept;

        void popBack();

        void insert(Iterator pos, ConstRefType val);

        RefType operator[](SizeT index);

        void eraseAt(Iterator pos);

        void erase(Iterator first, Iterator last);

        void clear();

    private:
        Pair<T *, T *> allocateRawMemory(SizeT n);

        void deallocateRawMemory(T *start);

        void check();

        void adjustCapacity(SizeT n);



        /*          memory(heap)           */
        /*|**************|******************/
        /*|**************|******************|/
        /*|*/           /*|*/               /*|*/
        T *bufBegin_, *bufEnd_, *usageCapEnd_;


    };


    template<typename T1, typename T2>
    struct Pair {
        T1 first_;
        T2 second_;

        Pair(const T1 &first, const T2 &second) : first_(first), second_(second) {}

        Pair(T1 &&first, T2 &&second) : first_(std::move(first)), second_(std::move(second)) {}
    };

    template<typename T>
    bool operator==(const Vector<T> &lhs, const Vector<T> &rhs) {
        if (lhs.size() != rhs.size()) return false;
        for (size_t i = 0; i != lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) return false;
        }
        return true;
    }

    template<typename T>
    bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs) {
        return !(lhs == rhs);
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const Vector<T> &rhs) {
        for (auto pT = rhs.begin(); pT != rhs.end(); ++pT) {
            os << *pT << " ";
        }
        return os;
    }


    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> li) {
        auto pair = allocateRawMemory(li.size());
        bufBegin_ = pair.first_;
        bufEnd_ = utility::uninitializedCopy(li.begin(), li.end(), bufBegin_);
        usageCapEnd_ = pair.second_;
    }

    template<typename T>
    Vector<T>::Vector(ConstRefType val, Vector::SizeT n) {
        auto pair = allocateRawMemory(n);
        bufBegin_ = pair.first_;
        bufEnd_ = utility::initializedOfValue(val, n, bufBegin_);
        usageCapEnd_ = pair.second_;
    }

    template<typename T>
    template<typename It>
    Vector<T>::Vector(It beg, It end) {
        auto pair = allocateRawMemory(end - beg);
        bufBegin_ = pair.first_;
        bufEnd_ = utility::uninitializedCopy(beg, end, bufBegin_);
        usageCapEnd_ = pair.second_;
    }

    template<typename T>
    Vector<T>::Vector(const Vector &v) {
        auto pair = allocateRawMemory(v.size());
        bufBegin_ = pair.first_;
        bufEnd_ = utility::uninitializedCopy(v.begin(), v.end(), bufBegin_);
        usageCapEnd_ = pair.second_;
    }

    template<typename T>
    Vector<T>::Vector(Vector &&v) noexcept : bufBegin_(v.bufBegin_), bufEnd_(v.bufEnd_), usageCapEnd_(v.usageCapEnd_) {
        v.bufBegin_ = v.bufEnd_ = v.usageCapEnd_ = nullptr;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(const Vector &v) {
        if (this == &v) return const_cast<Vector<T> &>(v);
        clear();
        auto pair = allocateRawMemory(v.size());
        bufBegin_ = pair.first_;
        bufEnd_ = utility::uninitializedCopy(v.begin(), v.end(), bufBegin_);
        usageCapEnd_ = pair.second_;
        return *this;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(Vector &&v) noexcept {
        if (this == &v) return v;
        clear();
        bufBegin_ = v.bufBegin_;
        bufEnd_ = v.bufEnd_;
        usageCapEnd_ = v.usageCapEnd_;
        v.bufBegin_ = v.bufEnd_ = v.usageCapEnd_ = nullptr;
        return *this;
    }

    template<typename T>
    Vector<T>::~Vector() {
        clear();
    }

    template<typename T>
    inline bool Vector<T>::empty() const noexcept {
        return bufBegin_ == bufEnd_;
    }

    template<typename T>
    inline typename Vector<T>::SizeT Vector<T>::size() const noexcept {
        return bufEnd_ - bufBegin_;
    }


    template<typename T>
    inline typename Vector<T>::Iterator Vector<T>::begin() const noexcept {
        return bufBegin_;
    }

    template<typename T>
    inline typename Vector<T>::Iterator Vector<T>::end() const noexcept {
        return bufEnd_;
    }

    template<typename T>
    inline typename Vector<T>::ConstIterator Vector<T>::cbegin() const noexcept {
        return bufBegin_;
    }

    template<typename T>
    inline typename Vector<T>::ConstIterator Vector<T>::cend() const noexcept {
        return bufEnd_;
    }

    template<typename T>
    inline typename Vector<T>::SizeT Vector<T>::capacity() const noexcept {
        return usageCapEnd_ - bufBegin_;
    }

    template<typename T>
    void Vector<T>::check() {
        if (bufEnd_ == usageCapEnd_) {
            return adjustCapacity(2 * size());
        }
        if (4 * (bufEnd_ - bufBegin_) <= usageCapEnd_ - bufBegin_) {
            return adjustCapacity(capacity() / 2);
        }
    }


    template<typename T>
    void Vector<T>::adjustCapacity(Vector::SizeT n) {
        auto pair = allocateRawMemory(n);
        auto newBufEnd = utility::uninitializedCopy(bufBegin_, bufEnd_, pair.first_);
        utility::destroyRange(bufBegin_, bufEnd_);
        deallocateRawMemory(bufBegin_);
        bufBegin_ = pair.first_;
        bufEnd_ = newBufEnd;
        usageCapEnd_ = pair.second_;
    }


    template<typename T>
    void Vector<T>::pushBack(ConstRefType val) {
        check();
        utility::constructAt(val, bufEnd_++);
    }

    template<typename T>
    void Vector<T>::pushBack(RRefType val) {
        check();
        utility::constructAt(std::move(val), bufEnd_++);
    }

    template<typename T>
    typename Vector<T>::ValueType Vector<T>::top() const noexcept {
        return *(bufEnd_ - 1);
    }

    template<typename T>
    void Vector<T>::popBack() {
        utility::destroyAt(bufEnd_ - 1);
        --bufEnd_;
        check();
    }

    template<typename T>
    void Vector<T>::insert(Vector::Iterator pos, ConstRefType val) {
        SizeT n = pos - bufBegin_;
        check();
        utility::copyFromRight(bufBegin_ + n, bufEnd_, bufEnd_, val);
        ++bufEnd_;
    }

    template<typename T>
    typename Vector<T>::RefType Vector<T>::operator[](Vector::SizeT index) {
        return *(bufBegin_ + index);
    }

    template<typename T>
    void Vector<T>::eraseAt(Vector::Iterator pos) {
        if (pos == bufEnd_) return;
        auto tmp = pos;
        utility::copyFromLeft(++tmp, bufEnd_, pos);
        --bufEnd_;
        check();
    }

    template<typename T>
    void Vector<T>::erase(Vector::Iterator first, Vector::Iterator last) {
        SizeT n = last - first;
        utility::copyFromLeft(last, bufEnd_, first);
        bufEnd_ -= n;
        check();
    }

    template<typename T>
    void Vector<T>::clear() {
        for (; bufBegin_ != bufEnd_; --bufEnd_) {
            utility::destroyAt(bufEnd_ - 1);
        }
        deallocateRawMemory(bufBegin_);
        bufBegin_ = bufEnd_ = usageCapEnd_ = nullptr;
    }


    template<typename T>
    Pair<T *, T *> Vector<T>::allocateRawMemory(Vector::SizeT n) {
        if (n == 0) n = 1;
        T *mStartPtr = static_cast<T *>(::operator new(n * sizeof(T)));
        return {mStartPtr, mStartPtr + n};
    }

    template<typename T>
    void Vector<T>::deallocateRawMemory(T *start) {
        ::operator delete(start);
    }


}


#endif //PRIMERADVANCED_VECTOR_H
