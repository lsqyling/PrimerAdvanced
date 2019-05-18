//
// Created by shiqing on 19-5-11.
//


#include <sstream>
#include "../common/CommonHeaders.h"
#include "../part_1_foundation/SalesData.h"
#include "Vector.h"
#include "String.h"

/*
 * Exercise 16.1: Define instantiation.
 * Answer:
 * When the compiler instantiates a template, it creates a new “instance” of
 * the template using the actual template argument(s) in place of the
 * corresponding template parameter(s).
 *
 * Exercise 16.2: Write and test your own versions of the compare functions.
 * @see compareOwn()
 *
 * Exercise 16.3: Call your compare function on two Sales_data objects to
 * see how your compiler handles errors during instantiation.
 * @see testingCompareSalesData();
 *
 * Exercise 16.4: Write a template that acts like the library find algorithm. The function will need two template
 * type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use
 * your function to find a given value in a vector<int> and in a list<string>.
 * @see tp::find();
 *
 * Exercise 16.5: Write a template version of the print function from § 6.2.4(p. 217) that takes a reference to
 * an array and can handle arrays of any size and any element type.
 * @tp::printArray();
 *
 *
 * Exercise 16.6: How do you think the library begin and end functions that take an array argument work?
 * Define your own versions of these functions.
 * @tp::begin, cbegin, end cend
 *
 * Exercise 16.7: Write a constexpr template that returns the size of a given array.
 * @see tp::sizeOfArray(arr)
 *
 * Exercise 16.8: In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer
 * using != to using <. Explain the rationale for this habit.
 * Answer: generally, most of classes has defined '!='.
 */


namespace tp {
    template<typename T>
    int compareOwn(const T &t1, const T &t2) {
        if (t1 < t2) return -1;
        if (t2 < t1) return 1;
        return 0;
    }

    template<typename Iterator, typename V>
    Iterator find(Iterator beg, Iterator end, const V &v) {
        for (; beg != end; ++beg) {
            if (v == *beg) return beg;
        }
        return end;
    }

    template<typename T, unsigned M>
    void printArray(const T(&array)[M]) {
        for (int i = 0; i != M; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    template<typename T, unsigned M>
    inline T *begin(const T (&arr)[M]) {
        return arr;
    }

    template<typename T, unsigned M>
    inline T *end(const T(&arr)[M]) {
        return &arr[M];
    }


    template<typename T, unsigned M>
    inline const T *cbegin(const T (&arr)[M]) {
        return arr;
    }

    template<typename T, unsigned M>
    inline const T *cend(const T(&arr)[M]) {
        return &arr[M];
    }

    template<typename T, unsigned M>
    inline unsigned sizeOfArray(const T(&arr)[M]) {
        return M;
    }


}


/*
 * Exercise 16.9: What is a function template? What is a class template?
 * Answer:
 * A function template is a formula from which we can generate type-specific
 * versions of that function.
 *
 * A class template is a blueprint for generating classes. Class templates
 * differ from function templates in that the compiler cannot deduce the
 * template parameter type(s) for a class template. Instead, as we’ve seen
 * many times, to use a class template we must supply additional information
 * inside angle brackets following the template’s name (§ 3.3, p. 97).
 *
 * Exercise 16.10: What happens when a class template is instantiated?
 * Answer:
 * The compiler uses these template arguments to instantiate a specific
 * class from the template.
 *
 * Exercise 16.11: The following definition of List is incorrect. How would you fix it?
 * @see namespace e_16;
 */


namespace e_16 {
    template<typename>
    class ListItem;

    template<typename T>
    class List {
    public:
        List<T>();

        List<T>(const List<T> &);

        List<T> &operator=(const List<T> &);

        ~List();

        void insert(ListItem<T> *ptr, T val);

    private:
        ListItem<T> *front, *end;
    };


}


void testingFind() {
    vector<string> vi = {"hello", "world", "hi"};
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    cout << *tp::find(vi.begin(), vi.end(), "hi") << endl;
    cout << (tp::find(li.begin(), li.end(), 10) == li.end()) << endl;
}


void testingCompareSalesData() {
    cout << tp::compareOwn("hello", "world") << endl; //notice the difference between the function.
    cout << tp::compareOwn<string>("hello", "world") << endl;

//    cout << compareOwn(SalesData("ISBN 1580383438"), SalesData("ISBN 78490278407")) << endl;
//     error: invalid operands to binary expression ('const SalesData' 'const SalesData')
}

/*
 * Exercise 16.12: Write your own version of the Blob and BlobPtr
 * templates. including the various const members that were not shown in the text.
 * @see tem::Vector<T>;
 *
 * Exercise 16.13: Explain which kind of friendship you chose for the equality and relational
 * operators for BlobPtr.
 * @see tem::Vector<T>;
 *
 *
 * Exercise 16.14: Write a Screen class template that uses nontype
 * parameters to define the height and width of the Screen.
 * @see tem::Vector<T>;
 *
 *
 * Exercise 16.15: Implement input and output operators for your Screen
 * template. Which, if any, friends are necessary in class Screen to make the
 * input and output operators work? Explain why each friend declaration, if any, was needed.
 * @see tem::Vector<T>;
 *
 *
 * Exercise 16.16: Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.
 * @see tem::Vector<T>;
 */


namespace test {

    using namespace tem;

    void testingVectorInterface() {
        Vector<int> vi;
        for (int i = 0; i != 1027; ++i) {
            vi.pushBack(i);
        }

        for (int j = 1; j != 1021; ++j) {
            vi.eraseAt(vi.end() - 1);
        }


        for (int k = 7; k != 1027; ++k) {
            vi.insert(vi.end(), k);
        }

        vi.erase(vi.begin() + 7, vi.end());

        vi.pushBack(8);

        for (int l = 9; l != 1027; ++l) {
            vi.pushBack(std::move(l));
        }

//        vi.erase(vi.begin() + 8, vi.end());

//        vi.clear();

        cout << "vi.top = " << vi.top() << endl;
        for (int m = 9; m != 1027; ++m) {
            vi.popBack();
        }

        cout << vi << endl;


        Vector<string> vs = {"hi", "world", "!!"};
        vs.popBack();
        vs.insert(vs.end(), "my");
        vs.eraseAt(vs.end() - 1);
        vs.pushBack("my");
        vs.erase(vs.end() - 1, vs.end());
        cout << vs << endl;


        Vector<string> vcs = vs;
        cout << vcs << endl;

        Vector<int> vci;
        vci = vi;
        cout << vci << endl;
        Vector<int> rval(std::move(vi));
        cout << rval << endl;

        rval = std::move(vci);
        cout << rval << endl;

        cout << rval.size() << rval.capacity() << endl;

    }
}


/*
 * Exercise 16.17: What, if any, are the differences between a type parameter
 * that is declared as a typename and one that is declared as a class?
 * When must typename be used?
 * Answer:
 * There is no difference. typename and class are interchangeable in the
 * declaration of a type template parameter.
 * You do, however, have to use class (and not typename) when declaring a
 * template template parameter.
 *
 *
 * Exercise 16.18: Explain each of the following function template declarations
 * and identify whether any are illegal. Correct each error that you find.
 * already done.
 *
 *
 *
 * Exercise 16.19: Write a function that takes a reference to a container and
 * prints the elements in that container. Use the container’s size_type and
 * size members to control the loop that prints the elements.
 * @see namespace ch_19;
 *
 * Exercise 16.20: Rewrite the function from the previous exercise to use
 * iterators returned from begin and end to control the loop.
 * @see namespace ch_19;
 */

namespace ch_19 {
    template<class Container>
    void printContainer(const Container &cont) {
        for (auto begin = cont.begin(); begin != cont.end(); ++begin) {
            cout << *begin << " ";
        }
        cout << endl;
    }

    template<typename Container>
    void printContainerNotType(const Container &cont) {
        using SizeT = typename Container::size_type;
        for (SizeT i = 0; i != cont.size(); ++i) {
            cout << cont[i] << " ";
        }
        cout << endl;
    }


    void testingPrintContainer() {
        vector<int> vi = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10};
        printContainer(vi);
        printContainerNotType(vi);
    }


}


namespace test {
    using namespace tem;

    void testingString() {
        String s = "hello world";
        cout << s << endl;

        String ss(s);
        cout << ss << endl;

        String s1;
        cout << s1 << endl;

    }

}



/*
 * Exercise 16.21: Write your own version of DebugDelete.
 * @see namespace ch_21::DugDelete;
 *
 *
 * Exercise 16.22: Revise your TextQuery programs from § 12.3 (p. 484) so
 * that the shared_ptr members use a DebugDelete as their deleter (§12.1.4, p. 468).
 * already done.
 *
 *
 * Exercise 16.23: Predict when the call operator will be executed in your
 * main query program. If your expectations and what happens differ, be sure you understand why.
 * already done.
 *
 *
 * Exercise 16.24: Add a constructor that takes two iterators to your Blob template.
 * already done.
 */

namespace ch_21 {

    struct DugDelete {

        DugDelete(std::ostream &os = cout) : os_(os) {}

        template<typename T>
        void operator()(T *p) const {
            os_ << "deleting unique_ptr" << endl;
            delete p;
        }

    private:
        std::ostream &os_;
    };


    void testingDugDelete() {
        DugDelete d;
        double *p = new double;
        d(p);
    }

}

/*
 *
 * Exercise 16.25: Explain the meaning of these declarations:
 * Answer:
 * extern template class vector<string>;
 * instantiation declaration. The definition of it is somewhere else;
 *
 * template class vector<Sales_data>;
 * instantiation definition. The compiler will generate codes for it.
 *
 *
 * Exercise 16.26: Assuming NoDefault is a class that does not have a
 * default constructor, can we explicitly instantiate vector<NoDefault>? If
 * not, why not?
 * @see http://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co
 *
 * Exercise 16.27: For each labeled statement explain what, if any,
 * instantiations happen. If a template is instantiated, explain why; if not,
 * explain why not.
 * @see namespace ch_27;
 *
 *
 *
 */
namespace ch_27 {
    template<typename T>
    class Stack {
    };

    void f(Stack<char>) {}

    class Exercise {
        const Stack<double> &rsd;
        Stack<int> si;

        Exercise(const Stack<double> &s = Stack<double>()) : rsd(s) {}
    };

    void testing() {
        Stack<char> *sc = new Stack<char>;
        f(*sc);
        int iObj = sizeof(Stack<char>);
        cout << "sizeof(Stack<char>) = " << iObj << ", sizeof(String) = " << sizeof(tem::String) << endl;
//        virtual function will creat virtual function table, size 8,so 3*8 + 8 = 32;
        cout << "sizeof(string) = " << sizeof(string) << endl;
        cout << "share_ptr<int> = " << sizeof(shared_ptr<int>) << endl;
        cout << "unique_ptr<int> = " << sizeof(unique_ptr<int>) << endl;
    }
}


/*
 * Exercise 16.28:Write your own versions shared_ptr and unique_ptr.
 * already done.
 *
 *
 * Exercise 16.29: Revise your Blob class to use your version of
 * shared_ptr rather than the library version.
 * already done.
 *
 * Exercise 16.30: Rerun some of your programs to verify your shared_ptr
 * and revised Blob classes. (Note: Implementing the weak_ptr type is
 * beyond the scope of this Primer, so you will not be able to use the BlobPtr class with your revised Blob.)
 * already done.
 *
 *
 * Exercise 16.31: Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.
 * already done.
 */


namespace deduction {
    template<typename T>
    void fobj(T, T) {}

    template<typename T>
    void fref(const T &, const T &) {}

    void testingDeduction() {
        string s1("a value");
        const string s2("another value");
        fobj(s1, s2);
        fref(s1, s2);

        int a[10];
        int b[42];
        fobj(a, b);
//        fref(a, b);error: no matching function for call to 'fref'
    }


}


/*
 * Exercise 16.32: What happens during template argument deduction?
 * Answer:
 * The process of determining the template arguments from the function arguments
 * is known as template argument deduction. During template argument deduction,
 * the compiler uses types of the arguments in the call to find the template
 * arguments that generate a version of the function that best matches the given call.
 *
 * Exercise 16.33: Name two type conversions allowed on function arguments
 * involved in template argument deduction.
 * Answer:
 * • const conversions: A function parameter that is a reference (or pointer)
 * to a const can be passed a reference (or pointer) to a nonconst object(§ 4.11.2, p. 162).
 *
 * • Array- or function-to-pointer conversions: If the function parameter is
 * not a reference type, then the normal pointer conversion will be applied
 * to arguments of array or function type. An array argument will be converted
 * to a pointer to its first element. Similarly, a function argument will be
 * converted to a pointer to the function’s type (§ 4.11.2, p. 161).
 *
 *
 * Exercise 16.34: Given only the following code, explain whether each of
 * these calls is legal. If so, what is the type of T? If not, why not?
 * Answer:a)illegal b)legal
 *
 * Exercise 16.35: Which, if any, of the following calls are errors? If the call is
 * legal, what is the type of T? If the call is not legal, what is the problem?
 * Answer:already done.
 *
 *
 * Exercise 16.36: What happens in the following calls:
 * Answer:already done.
 *
 */


/*
 * Exercise 16.37: The library max function has two function parameters and
 * returns the larger of its arguments. This function has one template type parameter.
 * Could you call max passing it an int and a double? If so, how? If not, why not?
 * @see namespace ch_37;
 *
 * Exercise 16.38: When we call make_shared (§ 12.1.1, p. 451), we have to
 * provide an explicit template argument. Explain why that argument is needed and how it is used.
 * @see share_ptr<int>(),should give the first args.
 *
 *
 * Exercise 16.39: Use an explicit template argument to make it sensible to pass two string literals to
 * the original version of compare from § 16.1.1 (p.652).
 * @see compare(const T1 &t1, const T2 &t2);
 *
 */


namespace ch_37 {
    void testingMax() {
        int i = 10;
        double x = 9.9999999;
//        template<typename T> const T &max(const T &, const T &)
//        cout << std::max(i, x) << endl;because max has only one template args
        cout << std::max(i, static_cast<int>(x)) << endl;

        std::shared_ptr<int> pi = std::make_shared<int>(0);
    }


    template<typename T1, typename T2>
    int compare(const T1 &t1, const T2 &t2) {
        if (t1 < t2) return -1;
        if (t2 < t1) return 1;
        return 0;
    }


}


namespace ch_40 {
    template<typename It>
    auto fcn(It beg, It end) -> decltype(*beg + 0) {
        return *beg;
    }


    template<typename T>
    auto sum(T a, T b) -> decltype(a + b) {
        return a + b;
    }

    void testingFcn() {
        vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        cout << fcn(vi.begin(), vi.end()) << endl;
    }


}

/*
 * Exercise 16.40: Is the following function legal? If not, why not? If it is
 * legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?
 * @see value type.
 *
 * Exercise 16.41: Write a version of sum with a return type that is
 * guaranteed to be large enough to hold the result of the addition.
 * @namespace ch_48::testingFcn();
 */



/*
 * Exercise 16.42: Determine the type of T and of val in each of the following calls:
 * already done.
 *
 * Exercise 16.43: Using the function defined in the previous exercise, what
 * would the template parameter of g be if we called g(i = ci)?
 * already done.
 *
 * Exercise 16.44: Using the same three calls as in the first exercise,
 * determine the types for T if g’s function parameter is declared as T (notT&&).
 * What if g’s function parameter is const T&?
 * already done.
 *
 * Exercise 16.45: Given the following template, explain what happens if we call g on a literal value such as 42.
 * What if we call g on a variable of type int?
 * already done.
 *
 */

/*
 * Exercise 16.46: Explain this loop from StrVec::reallocate in § 13.5 (p.530):
 * Answer:
 * Binding an rvalue reference to an lvalue gives code that operates on the rvalue reference permission to clobber the lvalue.
 */


/*
 * Exercise 16.47: Write your own version of the flip function and test it by
 * calling functions that have lvalue and rvalue reference parameters.
 * Answer: @see namespace ch_47;
 *
 */




namespace ch_47 {

    template<typename T>
    inline T &&forward(std::remove_reference_t<T> &t) noexcept {
        return static_cast<T &&>(t);
    }

    template<typename T>
    inline T &&forward(std::remove_reference_t<T> &&t) noexcept {
        return static_cast<T &&>(t);
    }


    template<typename T>
    std::remove_reference_t<T> &&move(T &&t) {
        return static_cast<std::remove_reference_t<T> &&>(t);
    }


    template<typename F, typename T1, typename T2>
    void flip(F f, T1 &&t1, T2 &&t2) {
        f(ch_47::forward<T2>(t2), ch_47::forward<T1>(t1));
    }


    void g(int a, int &v) {
        cout << a << ++v << endl;
    }


    void testingMoveAndForward() {
        int j = 4;
        flip(g, j, 3);
        cout << "j = " << j << endl;
        string s("hello");
        string s2 = ch_47::move(s);
        cout << s2 << s << endl;


    }


}


/*
 * Exercise 16.48: Write your own versions of the debug_rep functions.
 * @namespace ch_48;
 *
 * Exercise 16.49: Explain what happens in each of the following calls:
 * @see namespace ch_48;
 *
 *
 * Exercise 16.50: Define the functions from the previous exercise so that they
 * print an identifying message. Run the code from that exercise. If the calls
 * behave differently from what you expected, make sure you understand why.
 * @see namespace ch_48;
 */


namespace ch_48 {
    template<typename T>
    string debugRep(const T &t) {
        std::ostringstream oss;
        oss << t;
        return oss.str();
    }


    template<typename T>
    string debugRep(T *t) {
        std::ostringstream ret;
        if (t) {
            ret << "Pointer: " << t;
            ret << " " << debugRep(*t);
        } else {
            ret << " null pointer";
        }
        return ret.str();
    }

    void testingDebugResp() {
        string *sp, s("hello world");
        sp = &s;
        string *rawPs = nullptr;
        debugRep(sp);
        debugRep(rawPs);
//        delete sp; delete rawPs; Memory that is not dynamically allocated cannot "delete" this pointer.

        const string *csp = &s;
        cout << debugRep(csp) << endl;
    }


    template<typename T>
    void f(T t) {
        cout << "f(T t)" << endl;
    }

    template<typename T>
    void f(const T *) {
        cout << "f(const T *)" << endl;
    }

    template<typename T>
    void g(T t) {
        cout << "g(T t)" << endl;
    }

    template<typename T>
    void g(T *) {
        cout << "g(T *)" << endl;
    }

    void testingCalls() {
        int i = 42, *p = &i;
        const int ic = 0, *p2 = &ic;
        g(42);
        g(p);
        g(ic);
        g(p2);//g(T t) T::int;g(T *)T::int  ;g(T t) ignore cont T::int;g(T *)T::const int *;
        f(42);
        f(p);
        f(ic);
        f(p2);//f(T t) T::int;f(T t)T::int *;f(T t) T::int;f(const int *)T::int
    }

}


/*
 * Exercise16.51: Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.
 * @see ch_51::testingFoo();
 *
 * Exercise 16.52: Write a program to check your answer to the previous question.
 * @see ch_51::testingFoo();
 *
 */


namespace ch_51 {
    template<typename T, typename... Args>
    void foo(const T &t, const Args &...args) {
        cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
        cout << "sizeof...(args) = " << sizeof...(args) << endl;
    }

    void testingFoo() {
        int i = 0;
        double d = 3.14;
        string s = "how now brown cow";
        foo(i, s, 42, d);
        foo(s, 42, "hi");
        foo(d, s);
        foo("hi");
    }


    template<typename T>
    void print(const T &t) {
        cout << t << " " << endl;
    }

    template<typename T, typename... Args>
    void print(const T &t, const Args &...args) {
        cout << t << " ";
        return print(args...);
    }


    template<typename...Args>
    void errorMsg(const Args &...args) {
        return print(args...);
    }


    void testingPrint() {
        int i = 42;
        double d = 3.14;
        long l = 123L;
        string s = "hello";
        print(42, i, d, l, s);
        errorMsg(42, i, d, l, s);
    }


}

/*
 * Exercise 16.53: Write your own version of the print functions and test them by printing one, two, and five arguments,
 * each of which should have different types.
 * @see ch_51::testingPrint();
 *
 * Exercise 16.54: What happens if we call print on a type that doesn’t have an << operator?
 * Answer:error T didn't define operator<<.
 *
 *
 * Exercise 16.55: Explain how the variadic version of print would execute if we declared the nonvariadic version of
 * print after the definition of the variadic version.
 * Answer:infinite inclusive.
 *
 */


/*
 * Exercise 16.56: Write and test a variadic version of errorMsg.
 * @see ch_51::errorMsg();
 *
 * Exercise 16.57: Compare your variadic version of errorMsg to the error_msg function in § 6.2.6 (p. 220).
 * What are the advantages and disadvantages of each approach?
 * Answer:
 * The error_msg takes initializer_list as the argument. So only the elements
 * stored in it must be the same or at least convertible. In contrast, the variadic
 * version provides better flexibility.
 *
 *
 */



namespace ch_58 {
    template<typename T, typename...Args>
    shared_ptr<T> makeSharedPtr(Args &&...args) {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }

    void testingMakeSharedPtr() {
        auto ip = makeSharedPtr<int>(0);
        auto vp = makeSharedPtr<vector<string>>(10, "hi");
        for (const auto &item : *vp) {
            cout << item << " ";
        }
        cout << endl;
    }


}


/*
 * Exercise 16.58: Write the emplace_back function for your StrVec class and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).
 * already done.
 *
 * Exercise 16.59: Assuming s is a string, explain svec.emplace_back(s).
 * Answer:it can use move constructor;
 *
 *
 * Exercise 16.60: Explain how make_shared (§ 12.1.1, p. 451) works.
 * already done.
 * Exercise 16.61: Define your own version of make_shared.
 * @see ch_58::testingMakeSharedPtr();
 *
 */

namespace ch_63 {

    template<typename T, class Container>
    auto print(const T &val, const Container &c) {
        auto it = c.end();
        for (auto begin = c.begin(); begin != c.end(); ++begin) {
            if (*begin == val) {
                it = begin;
            }
            cout << *begin << " ";
        }
        cout << endl;
        return it;
    }


    template<>
    auto print(const char * const &s, const vector<const char*> &c) {
        auto it = c.end();
        for (auto wrapIter = c.begin(); wrapIter != c.end(); ++wrapIter) {
            if (*wrapIter == s) {
                it = wrapIter;
            }
            cout << *wrapIter << " ";
        }
        cout << endl;
        return it;
    }






    void testingPrint() {
        vector<int> vi = {0, 1, 2, 3, 5, 6, 7, 8};
        list<double> ld = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10};
        vector<const char*> vp = {"hi", "world", "my", "dear"};
        print(9.10, ld);
        print(8, vi);
        const char *p = "hi";
        print(p, vp);
    }





}

/*
 * Exercise 16.62: Define your own version of hash<Sales_data> and
 * define an unordered_multiset of Sales_data objects. Put several transactions into the container
 * and print its contents.
 * yes, already done.
 *
 * Exercise 16.63: Define a function template to count the number of occurrences of a given value in a vector.
 * Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings.
 * @see ch_63::testingPrint();
 *
 *
 * Exercise 16.64: Write a specialized version of the template from the previous exercise to handle vector<const char*>
 * and a program that uses this specialization.
 * @see ch_63::testingPrint();
 *
 * Exercise 16.65: In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and the
 * other a char* parameter. Rewrite these functions as specializations.
 * yes, already.
 *
 * Exercise 16.66: What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining
 * specializations?
 * Answer:
 * Overloading changes the function match.
 *
 * Exercise 16.67: Would defining these specializations affect function matching for debug_rep? If so, how? If not, why not?
 * Won't change.
 * Answer:
 * Specializations instantiate a template; they do not overload it. As a result,
 * specializations do not affect function matching.
 */






int main() {
    ch_63::testingPrint();
    ch_58::testingMakeSharedPtr();
    ch_51::testingPrint();
    ch_51::testingFoo();
    ch_48::testingCalls();
    ch_48::testingDebugResp();
    ch_47::testingMoveAndForward();
    ch_40::testingFcn();
    ch_37::testingMax();
    deduction::testingDeduction();
    ch_27::testing();
    ch_21::testingDugDelete();
    ch_19::testingPrintContainer();
    test::testingString();
    test::testingVectorInterface();

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    tp::printArray(arr);
    testingFind();
    testingCompareSalesData();
    cout << tp::sizeOfArray(arr) << endl;


    using PtrInt = int *;
    PtrInt a, b;
    a = new int(42);
    b = new int(21);

    cout << *a << *b << endl;
    delete a;
    delete b;

    return 0;
}

