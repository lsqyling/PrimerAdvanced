//
// Created by shiqing on 18-11-9.
//

#ifndef PRIMER_RVECTOR_H
#define PRIMER_RVECTOR_H

#include <memory>
#include <cstddef>

namespace sona {

    template<typename T1, typename T2>
    struct Pair {
        T1 first;
        T2 second;

        Pair(const T1 &first, const T2 &second);

        Pair(T1 &&first, T2 &&second);
    };

    template<typename T, typename... Args>
    void constructAt(T *ptr, Args &&...args);


    template<typename T>
    void constructAt(T *ptr, const T &value);

    template<typename T>
    void destroyAt(T *value);

    template<typename Iterator>
    void destroyRange(Iterator first, Iterator last);

    template<typename InputIterator, typename OutputIterator>
    OutputIterator uninitializedCopy(InputIterator first,
                                     InputIterator last,
                                     OutputIterator dFirst);

    template<typename Iterator, typename Predicate>
    Iterator removeIf(Iterator first, Iterator last, Predicate pred);

    template<typename InputIterator, typename OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last, OutputIterator dFirst);

    template<typename InputIterator, typename OutputIterator>
    OutputIterator rCopy(InputIterator rFirst, InputIterator rLast, OutputIterator dRFirst);




    template<typename T>
    class Vector {
    public:
        typedef T ValueType;
        typedef T &ReferenceType;
        typedef const T &ConstReferenceType;
        typedef T *PointerType;
        typedef std::size_t SizeType;

        typedef T *Iterator;
        typedef const T *ConstIterator;

        Vector();

        Vector(const Vector<T> &another);

        Vector(Vector<T> &&another) noexcept;

        template<typename It>
        Vector(It b, It e);

        Vector(std::initializer_list<T> il);

        ~Vector();

        bool isEmpty() const noexcept;

        bool isNotEmpty() const noexcept;

        SizeType size() const noexcept;

        Iterator begin() noexcept;

        Iterator end() noexcept;

        ConstIterator cBegin() const noexcept;

        ConstIterator cEnd() const noexcept;

        void pushBack(ConstReferenceType t);

        void popBack();

        void insert(Iterator pos, ConstReferenceType value);

        ReferenceType operator[](SizeType index);

        void eraseAt(Iterator pos);

        void erase(Iterator first, Iterator last);

        void clear();

    private:
        Pair<T *, T *> allocateRawMemory(SizeType n);

        void deallocateRawMemory(PointerType start);

        Iterator mBufBegin;
        Iterator mBufEnd;
        Iterator mBufUsageEnd;
    };
}

/////////////////////////////
/// IMPLEMENTATIONS /////
/////////////////////////////

template<typename T1, typename T2>
sona::Pair<T1, T2>::Pair(const T1 &first, const T2 &second) : first(first), second(second) {}

template<typename T1, typename T2>
sona::Pair<T1, T2>::Pair(T1 &&first, T2 &&second)
        : first(std::move(first)), second(std::move(second)) {}

template<typename InputIterator, typename OutputIterator>
OutputIterator sona::rCopy(InputIterator rFirst, InputIterator rLast, OutputIterator dRFirst) {
    for (; rFirst != rLast; --rFirst, --dRFirst)
        *dRFirst = *rFirst;
    return dRFirst;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator sona::copy(InputIterator first, InputIterator last, OutputIterator dFirst) {
    for (; first != last; ++first, ++dFirst)
        *dFirst = *first;
    return dFirst;
}

template<typename Iterator, typename Predicate>
Iterator sona::removeIf(Iterator first, Iterator last, Predicate pred) {
    Iterator dFirst = first;
    for (; first != last; ++first) {
        if (!pred(*first)) {
            *dFirst = *first;
            ++dFirst;
        }
    }
    return dFirst;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator sona::uninitializedCopy(InputIterator first, InputIterator last, OutputIterator dFirst) {
    for (; first != last; ++first, ++dFirst)
        constructAt(&(*dFirst), *first);
    return dFirst;
}

template<typename Iterator>
void sona::destroyRange(Iterator first, Iterator last) {
    for (; first != last; ++first)
        destroyAt(&(*first));
}

template<typename T>
void sona::destroyAt(T *value) {
    value->~T();
}


template<typename T>
void sona::constructAt(T *ptr, const T &value) {
//    place new
    new(ptr) T(value);
}

template<typename T, typename... Args>
void sona::constructAt(T *ptr, Args &&... args) {
//    place new
    new(ptr) T(std::forward<Args>(args)...);
}


template<typename T>
sona::Pair<T *, T *> sona::Vector<T>::allocateRawMemory(SizeType n) {
    if (n == 0) n = 1;
    auto *memoryStartPoint = static_cast<T *>(::operator new(n * sizeof(T)));
    return Pair<T *, T *>(memoryStartPoint, memoryStartPoint + n);
}

template<typename T>
void sona::Vector<T>::deallocateRawMemory(PointerType start) {
    ::operator delete(start);
}

template<typename T>
void sona::Vector<T>::clear() {
    erase(begin(), end());
}

template<typename T>
void sona::Vector<T>::erase(Iterator first, Iterator last) {
    Iterator newEnd = copy(last, end(), first);
    destroyRange(newEnd, end());
    mBufUsageEnd = newEnd;
}


template<typename T>
void sona::Vector<T>::eraseAt(Iterator pos) {
    erase(pos, pos + 1);
}

// FIXME Ask ICEY about this
template<typename T>
typename sona::Vector<T>::ReferenceType sona::Vector<T>::operator[](SizeType index) {
    return *(mBufBegin + index);
}

template<typename T>
void sona::Vector<T>::insert(Iterator pos, ConstReferenceType value) {
    pushBack(T());
    rCopy(end() - 2, pos - 1, end() - 1);
    *pos = value;
}

template<typename T>
void sona::Vector<T>::popBack() {
    mBufUsageEnd--;
    destroyAt(mBufUsageEnd);
}

template<typename T>
void sona::Vector<T>::pushBack(ConstReferenceType t) {
    if (mBufUsageEnd == mBufEnd) {
        Pair<T *, T *> newBuf = allocateRawMemory(size() * 2);
        Iterator newEnd = uninitializedCopy(cBegin(), cEnd(), newBuf.first);
        deallocateRawMemory(mBufBegin);
        mBufBegin = newBuf.first;
        mBufEnd = newBuf.second;
        mBufUsageEnd = newEnd;
    }
    constructAt(mBufUsageEnd, t);
    mBufUsageEnd++;
}

template<typename T>
typename sona::Vector<T>::ConstIterator sona::Vector<T>::cEnd() const noexcept {
    return mBufUsageEnd;
}

template<typename T>
typename sona::Vector<T>::ConstIterator sona::Vector<T>::cBegin() const noexcept {
    return mBufBegin;
}

template<typename T>
typename sona::Vector<T>::Iterator sona::Vector<T>::end() noexcept {
    return mBufUsageEnd;
}

template<typename T>
typename sona::Vector<T>::Iterator sona::Vector<T>::begin() noexcept {
    return mBufBegin;
}

template<typename T>
typename sona::Vector<T>::SizeType sona::Vector<T>::size() const noexcept {
    return mBufUsageEnd - mBufBegin;
}

template<typename T>
bool sona::Vector<T>::isNotEmpty() const noexcept {
    return !isEmpty();
}

template<typename T>
bool sona::Vector<T>::isEmpty() const noexcept {
    return mBufBegin == mBufEnd;
}

template<typename T>
sona::Vector<T>::Vector(sona::Vector<T> &&another) noexcept
        : mBufBegin(another.mBufBegin),
          mBufEnd(another.mBufEnd),
          mBufUsageEnd(another.mBufUsageEnd) {
    another.mBufBegin = nullptr;
    another.mBufEnd = nullptr;
    another.mBufUsageEnd = nullptr;
}

template<typename T>
sona::Vector<T>::Vector(const sona::Vector<T> &another) {
    Pair<T *, T *> buffer = allocateRawMemory(another.size());
    uninitializedCopy(another.cBegin(), another.cEnd(), mBufBegin);
    mBufBegin = buffer.first;
    mBufEnd = buffer.second;
    mBufUsageEnd = buffer.second;
}

template<typename T>
template<typename It>
sona::Vector<T>::Vector(It b, It e) {
    Pair<T *, T *> buffer = allocateRawMemory(e - b);
    uninitializedCopy(b, e, mBufBegin);
    mBufBegin = buffer.first;
    mBufEnd = buffer.second;
    mBufUsageEnd = buffer.second;
}

template<typename T>
sona::Vector<T>::Vector(std::initializer_list<T> il) {
    Pair<T *, T *> buffer = allocateRawMemory(il.size());
    mBufBegin = buffer.first;
    uninitializedCopy(il.begin(), il.end(), mBufBegin);
    mBufEnd = buffer.second;
    mBufUsageEnd = buffer.second;
}

template<typename T>
sona::Vector<T>::~Vector() {
    for (T *rawIt = mBufBegin; rawIt != mBufEnd; ++rawIt) {
        destroyAt(rawIt);
    }
    deallocateRawMemory(mBufBegin);
}

template<typename T>
sona::Vector<T>::Vector() : mBufBegin(nullptr),
                            mBufEnd(nullptr),
                            mBufUsageEnd(nullptr) {}


#endif //PRIMER_VECTOR_H
