//
// Created by shiqing on 19-5-4.
//


#include <chrono>
#include <algorithm>
#include <set>
#include "../common/CommonHeaders.h"


/*
 * Exercise 13.1: What is a copy constructor? When is it used?
 * Answer:
 * A copy constructor is a constructor which first parameter is a reference to the class type and any additional
 * parameters have default values.
 * When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.
 *
 *
 * Define variables using an =
 * Pass an object as an argument to a parameter of nonreference type
 * Return an object from a function that has a nonreference return type
 * Brace initialize the elements in an array or the members of an aggregate class
 * Some class types also use copy initialization for the objects they allocate.
 *
 *
 *
 * Exercise 13.2: Explain why the following declaration is illegal:
 * Sales_data::Sales_data(Sales_data rhs);
 * Answer:
 * If declaration like that, the call would never succeed to call the copy constructor,
 * Sales_data rhs is an argument to a parameter, thus, we'd need to use the copy constructor to copy the argument,
 * but to copy the argument, we'd need to call the copy constructor, and so on indefinitely.
 *
 * Exercise 13.3: What happens when we copy a StrBlob? What about StrBlobPtrs?
 * answer:
 * when we copy a StrBlob, the shared_ptr member's use_count add one.
 * when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)
 *
 *
 * Exercise 13.4: Assuming Point is a class type with a public copy constructor, identify each use of the copy
 * constructor in this program
 * Point global;
 * Point foo_bar(Point arg<1>) {
 *      Point local = arg<2>, *heap = new Point(global)<3>;
 *      *heap = local;Point pa[ 4 ] = { <4>local, <5>*heap };
 *      return *heap;<6>
 * }
 *
 *
 * Exercise 13.5: Given the following sketch of a class, write a copy constructor that copies all the members.
 * Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps points,
 * rather than copying ps itself.
 *
 *
 *
 *
 */

class HasPtr {
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const string &s = string(), int n = 0) : ps(new string), i(n) {}

//    copy constructor
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}

    HasPtr &operator=(const HasPtr &hp);

    ~HasPtr() {
        delete ps;
    }


    /*
     * error: use of overloaded operator '='
     * is ambiguous (with operand types 'HasPtr' and 'typename remove_reference<HasPtr &>::type'
     */
//    HasPtr &operator=(HasPtr hp);



private:
    string *ps;
    int i = 0;
};

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return *lhs.ps < *rhs.ps || (!(*lhs.ps < *rhs.ps) && lhs.i < rhs.i);
}


inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    cout << "HasPtr::swap()" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

/*HasPtr &HasPtr::operator=(HasPtr hp) {
//    These operators use a technique known as copy and swap. This technique swaps the left-
//    hand operand with a copy of the right-hand operand:
    swap(*this, hp);
    return *this;
}*/


HasPtr &HasPtr::operator=(const HasPtr &hp) {
    auto tmp = new string(*hp.ps);
    delete ps;
    ps = tmp;
    i = hp.i;
    return *this;
}


/*
 * Exercise 13.6: What is a copy-assignment operator? When is this operator used?
 * What does the synthesized copy-assignment operator do? When is it synthesized?
 * Answer:
 * 1)The copy-assignment operator is function named operator= and takes an argument of the same type as the class.
 * 2)This operator is used when assignment occurred.
 * 3)The synthesized copy-assignment operator assigns each nonstatic member of the right-hand object to corresponding
 * member of the left-hand object using the copy-assignment operator for the type of that member.
 * 4)It is synthesized when the class does not define its own.
 *
 *
 * Exercise 13.7: What happens when we assign one StrBlob to another? What about StrBlobPtrs?
 * Answer:In both cases, shallow copy will happen. All pointers point to the same address.
 * The use_count changed the same as 13.3.
 *
 *
 * Exercise 13.8: Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499).
 * As with the copy constructor, your assignment operator should copy the object to which ps points.
 * @see class HasPtr.
 *
 *
 */


/*
 * Exercise 13.9: What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
 * Answer:
 * The destructor is a member function with the name of the class prefixed by a tilde(~).
 * As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined
 * to disallow objects of the type from being destoryed. Otherwise, the synthesized destructor has an empty function body.
 * The compiler defines a synthesized destructor for any class that does not define its own destructor.
 *
 *
 *
 * Exercise 13.10: What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
 * Answer:
 * When a StrBlob object destroyed, the use_count of the dynamic object will decrement.
 * It will be freed if no shared_ptr to that dynamic object.
 * When a StrBlobPter object is destroyed the object dynamically allocated will not be freed.
 *
 *
 *
 * Exercise 13.11: Add a destructor to your HasPtr class from the previous exercises.
 * Already be done.
 *
 * Exercise 13.12: How many destructor calls occur in the following code fragment?
 * bool fcn(const Sales_data *trans, Sales_data accum) {
 *      Sales_data item1(*trans), item2(accum);
 *      return item1.isbn() != item2.isbn();
 * }
 *
 * Answer:3 times. There are accum, item1 and item2.
 *
 *
 * Exercise 13.13: A good way to understand copy-control members and constructors is to define a simple class with these
 * members in which each member prints its name:
 *
 * struct X {
 *      X() {std::cout << "X()" << std::endl; }
 *      X(const X&) {std::cout << "X(const X&) << std::endl; }
 * };
 * Add the copy-assignment operator and destructor to X and write a program using X objects in various ways:
 * Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth.
 * Study the output until you are certain you understand when and why each copy-control member is used. As you read the output,
 * remember that the compiler can omit calls to the copy constructor.
 *
 * Answer:
 * @see struct X;
 */

namespace t {
    struct X {
        X() { cout << "X()" << endl; }

        X(const X &x) { cout << "X(const X &x)" << endl; }

        X(X &&x) { cout << "X(X &&x)" << endl; }

        X &operator=(const X &x) {
            cout << "operator=(const X &x)" << endl;
            return *this;
        }

        X &operator=(X &&x) {
            cout << "operator=(X &&x)" << endl;
            return *this;
        }

        ~X() { cout << "~X()" << endl; }
    };
}


void testingCopyControl() {
    using namespace t;
    X x;
    X x1(std::move(x));
    X x2 = x1;
    X x3;
    x3 = x2;
}


/*
 * Exercise 13.14: Assume that numbered is a class with a default constructor that generates a unique serial number
 * for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-
 * control members and given the following function:
 * void f (numbered s) { cout << s.mysn << endl; }
 *
 * what output does the following code produce?
 * numbered a, b = a, c = b; f(a); f(b); f(c);
 * @see class Numbered.
 *
 *
 * Exercise 13.15: Assume numbered has a copy constructor that generates a new serial number.
 * Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?
 * @see Class Numbered;
 *
 * Exercise 13.16: What if the parameter in f were const numbered&? Does that change the output?
 * If so, why? What output gets generated?
 * @see Class Numbered;
 *
 *
 * Exercise 13.17: Write versions of numbered and f corresponding to the previous three exercises and check whether
 * you correctly predicted the output.
 * @see Class Numbered;
 *
 *
 */


namespace t {
    class Numbered {
        friend std::ostream &operator<<(std::ostream &os, const Numbered &num);

    public:
        Numbered() : timestamp_(generateTimestamp()) {}

        Numbered(const Numbered &num) : timestamp_(generateTimestamp()) {}

        Numbered &operator=(const Numbered &num) {
            timestamp_ = generateTimestamp();
            return *this;
        }


    private:
        long timestamp_ = 0;


        static long generateTimestamp();
    };

    inline long Numbered::generateTimestamp() {
        return std::chrono::system_clock::now()
                .time_since_epoch()
                .count();
    }

    std::ostream &operator<<(std::ostream &os, const Numbered &num) {
        os << num.timestamp_;
        return os;
    }

    void f(Numbered s) {
        cout << s << endl;
    }

    struct NoDtor {
        NoDtor() = default;

        ~NoDtor() = delete;
    };


}


void testingClassOfNumbered() {
//    t::NoDtor d;error: attempt to use a deleted function
    t::NoDtor *p = new t::NoDtor;
//    delete p;error: attempt to use a deleted function
    t::Numbered a, b = a, c = b;
    t::f(a);
    t::f(b);
    t::f(c);
}


/*
 * Exercise 13.18: Define an Employee class that contains an employee name and a unique employee identifier.
 * Give the class a default constructor and a constructor that takes a string representing the employee’s name.
 * Each constructor should generate a unique ID by incrementing a static data member.
 * @see class Employee.
 *
 *
 * Exercise 13.19: Does your Employee class need to define its own versions of the copy-control members?
 * If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.
 * Answer:not, Copying a employee is illogical.
 *
 *
 * Exercise 13.20: Explain what happens when we copy, assign, or destroy objects of our TextQuery
 * and QueryResult classes from § 12.3 (p. 484).
 * Answer:
 * The member (smart pointer and container) will be copied.
 *
 * Exercise 13.21: Do you think the TextQuery and QueryResult classes need to define their own versions of
 * the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these
 * classes require.
 * Answer:No need. because, the default behavior is reasonable.
 */


namespace t {
    class Employee {
    public:
        Employee() : id_(getTimestamp()) {}

        Employee(string name) : name_(name), id_(getTimestamp()) {}

        Employee(const Employee &e) = delete;

        Employee &operator=(const Employee &e) = delete;

    private:
        string name_;
        string id_;

        static string getTimestamp();
    };

    string Employee::getTimestamp() {
        long n = std::chrono::system_clock::now().time_since_epoch().count();
        return std::to_string(n);
    }

}


/*
 * Exercise 13.22: Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of
 * the string to which the objects point. We’ll show the definitions of the copy-control members in the next section.
 * However, you already know everything you need to know to implement these members.
 * Write the HasPtr copy constructor and copy-assignment operator before reading on.
 * already be done.
 *
 */


/*
 * Exercise 13.23: Compare the copy-control members that you wrote for the solutions to the previous section’s exercises
 * to the code presented here. Be sure you understand the differences, if any, between your code and ours.
 * Answer:yes.
 *
 *
 * Exercise 13.24: What would happen if the version of HasPtr in this section didn’t define a destructor?
 * What if HasPtr didn’t define the copy constructor?
 * Answer:If HasPtr didn't define a destructor, a memory leak would occur, compiler synthesized destructor does not manage
 * dynamic memory. If HasPtr didn't define the copy constructor, we would get pointer-like copy behaviour.
 * The ps pointer would be copied to the left hand side, but ps in the lhs and the rhs would still point to the
 * same string on the heap.
 *
 * Exercise 13.25: Assume we want to define a version of StrBlob that acts like a value.
 * Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector.
 * Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor.
 * Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.
 * Answer:
 * Copy constructor and copy-assignment operator should dynamically allocate memory for its own ,
 * rather than share the object with the right hand operand. StrBlob is using smart pointers which can be managed with
 * synthesized destructor, If an object of StrBlob is out of scope, the destructor
 * for std::shared_ptr will be called automatically to free the memory dynamically allocated when the use_count goes to 0.
 *
 * Exercise 13.26: Write your own version of the StrBlob class described in the previous exercise.
 *
 * Answer:already be done.
 */


/*
 * Exercise 13.27: Define your own reference-counted version of HasPtr.
 * @see class HasPtrActLIkePointer.
 *
 *
 * Exercise 13.28: Given the following classes, implement a default constructor and the necessary copy-control members.
 * @see TreeNode.
 *
 *
 */

namespace t {
    class HasPtrActLikePointer {
    public:
        HasPtrActLikePointer(const string &s = string()) : pStr_(new string(s)), i_(0), pCnt_(new size_t(1)) {}

        HasPtrActLikePointer(const HasPtrActLikePointer &rhs);

        HasPtrActLikePointer &operator=(const HasPtrActLikePointer &rhs);

        ~HasPtrActLikePointer();

    private:
        string *pStr_;
        int i_ = 0;
//        reference count
        size_t *pCnt_;
    };

    HasPtrActLikePointer::HasPtrActLikePointer(const HasPtrActLikePointer &rhs)
            : pStr_(rhs.pStr_), i_(rhs.i_), pCnt_(rhs.pCnt_) {
        ++*pCnt_;
    }

    HasPtrActLikePointer &HasPtrActLikePointer::operator=(const HasPtrActLikePointer &rhs) {
//        We do so by incrementing the count in rhs before decrementing the count in the left-hand object.
        ++*rhs.pCnt_;
        if (--*pCnt_ == 0) {
            delete pStr_;
            delete pCnt_;
        }
        pStr_ = rhs.pStr_;
        pCnt_ = rhs.pCnt_;
        i_ = rhs.i_;
        return *this;
    }

    HasPtrActLikePointer::~HasPtrActLikePointer() {
        if (--*pCnt_ == 0) {
            delete pStr_;
            delete pCnt_;
        }
    }


    class TreeNode {
    public:
        TreeNode(const string &s = string(), int cnt = 0)
                : value_(s), count_(cnt), left_(nullptr), right_(nullptr), pCnt_(new size_t(1)) {}

        TreeNode(string v, int cnt, TreeNode *l, TreeNode *r)
                : value_(v), count_(cnt), left_(l), right_(r), pCnt_(new size_t(1)) {}

        TreeNode(const TreeNode &tn)
                : value_(tn.value_), count_(tn.count_), left_(tn.left_), right_(tn.right_), pCnt_(tn.pCnt_) {
            ++*pCnt_;
        }

        TreeNode &operator=(const TreeNode &tn);

        ~TreeNode() {
            if (--*pCnt_ == 0) {
                delete pCnt_;
                left_ = nullptr;
                right_ = nullptr;
            }
        }


    private:
        string value_;
        int count_ = 0;
        TreeNode *left_;
        TreeNode *right_;
        size_t *pCnt_;
    };


    TreeNode &TreeNode::operator=(const TreeNode &tn) {
        ++*tn.pCnt_;
        if (--*pCnt_ == 0) {
            delete pCnt_;
        }
        value_ = tn.value_;
        count_ = tn.count_;
        left_ = tn.left_;
        right_ = tn.right_;
        pCnt_ = tn.pCnt_;
        return *this;
    }


}

void testingTreeNode() {
    t::TreeNode tn("A", 0);
    t::TreeNode tn1("B", 1, &tn, nullptr);
    t::TreeNode tn2("C", 2, &tn, &tn1);
    tn2 = tn;
}

/*
 * Exercise 13.29: Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.
 * Answer:
 * swap(lhs.ps, rhs.ps); feed the version : swap(std::string*, std::string*) and swap(lhs.i, rhs.i);
 * feed the version : swap(int, int). Both them can't call swap(HasPtr&, HasPtr&).
 * Thus, the calls don't cause a recursion loop.
 *
 * Exercise 13.30: Write and test a swap function for your value like version of HasPtr.
 * Give your swap a print statement that notes when it is executed.
 * Answer:already be done.
 *
 *
 *
 * Exercise 13.31: Give your class a < operator and define a vector of HasPtrs.
 * Give that vector some elements and then sort the vector. Note when swap is called.
 * Answer:@see class HasPtr.
 *
 *
 *
 * Exercise 13.32: Would the pointer like version of HasPtr benefit from defining a swap function?
 * If so, what is the benefit? If not, why not?
 * Answer:
 * Essentially, the specific avoiding memory allocation is the reason why it improve performance.
 * As for the pointerlike version, no dynamic memory allocation anyway. Thus, a specific version for
 * it will not improve the performance.
 */


void testingSwapAndOperatorLess() {
    HasPtr hp("hello", 3), h1("world", 2);
    vector<HasPtr> vi;
    vi.push_back(h1);
    vi.push_back(hp);
    std::sort(vi.begin(), vi.end());
}



/*
 * Exercise 13.33: Why is the parameter to the save and remove members of Message a Folder&?
 * Why didn’t we define that parameter as Folder? Or const Folder&?
 * Answer:
 * Because these operations must also update the given Folder.
 * Updating a Folder is a job that the Folder class controls through its addMsg and remMsg members,
 * which will add or remove a pointer to a given Message, respectively.
 *
 * Exercise 13.34: Write the Message class as described in this section.
 * @see class Message.
 *
 * Exercise 13.35: What would happen if Message used the synthesized versions of the copy-control members?
 * Answer:
 * some existing Folders will out of sync with the Message after assignment.
 *
 *
 * Exercise 13.36: Design and implement the corresponding Folder class. That class should hold a set that points to
 * the Messages in that Folder.
 * @see class Folder.
 *
 * Exercise 13.37: Add members to the Message class to insert or remove a given Folder* into folders.
 * These members are analogous to Folder’s addMsg and remMsg operations.
 * @see class Folder.
 *
 *
 * Exercise 13.38: We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?
 * Answer:
 * The copy and swap is an elegant way when working with dynamicly allocated memory. In the Message class ,
 * nothing is allocated dynamically. Thus using this idiom makes no sense and will make it more complicated to
 * implement due to the pointers that point back.
 *
 */

namespace mf {
    class Folder;

    class Message {
    public:
        Message(const string &s = string()) : content_(s) {}

        Message(const Message &m);

        Message &operator=(const Message &m);

        ~Message();

        void add(Folder &f);

        void remove(Folder &f);


    private:
        string content_;
        std::set<Folder *> folders_;


        void addToFolders(const Message &m);

        void removeAllFolders();
    };

    class Folder {
    public:
        void addMsg(Message *m);

        void removeMeg(Message *m);

    private:
        std::set<Message *> messages;
    };

    void Folder::addMsg(Message *m) {
        messages.insert(m);
    }

    void Folder::removeMeg(Message *m) {
        messages.erase(m);
    }


    Message::Message(const Message &m) : content_(m.content_), folders_(m.folders_) {
        addToFolders(m);
    }

    Message &Message::operator=(const Message &m) {
        removeAllFolders();
        content_ = m.content_;
        folders_ = m.folders_;
        addToFolders(m);
        return *this;
    }

    Message::~Message() {
        removeAllFolders();
    }

    void Message::add(Folder &f) {
        folders_.insert(&f);
        f.addMsg(this);

    }

    void Message::remove(Folder &f) {
        folders_.erase(&f);
        f.removeMeg(this);
    }

    void Message::addToFolders(const Message &m) {
        for (auto &f : m.folders_) {
            f->addMsg(this);
        }
    }

    void Message::removeAllFolders() {
        for (auto &f : folders_) {
            f->removeMeg(this);
        }
    }


}


/*
 * Exercise 13.39: Write your own version of StrVec, including versions of reserve, capacity (§ 9.4, p. 356),
 * and resize (§ 9.3.5, p. 352).
 * @see class sona::Vector.
 *
 * Exercise 13.40: Add a constructor that takes an initializer_list<string> to your StrVec class.
 * @see class sona::Vector.
 *
 *
 * Exercise 13.41: Why did we use postfix increment in the call to construct inside push_back?
 * What would happen if it used the prefix increment?
 * @see class sona::Vector.
 *
 *
 * Exercise 13.42: Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResult
 * classes (§ 12.3,p. 484).
 * @see class sona::Vector.
 *
 *
 * Exercise 13.43: Rewrite the free member to use for_each and a lambda (§ 10.3.2, p. 388) in place of the for loop to
 * destroy the elements. Which implementation do you prefer, and why?
 * @see class sona::Vector.
 *
 *
 * Exercise 13.44: Write a class named String that is a simplified version of the library string class.
 * Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string.
 * Use an allocator to allocate memory that your String class uses.
 * @see class sona::Vector.
 *
 */


/*
 * Exercise 13.45: Distinguish between an rvalue reference and an lvalue reference.
 * Answer:
 * lvalue reference: reference that can bind to an lvalue. (Regular reference)
 * rvalue reference: reference to an object that is about to be destroyed
 *
 *
 * Exercise 13.46: Which kind of reference can be bound to the following initializers?
 * int f();
 * vector<int> vi(100);
 * int &&r1 = f();
 * int &r2 = vi[0];
 * int &r3 = r1;
 * int &&r4 = vi[0] * f();
 *
 * Exercise 13.47: Give the copy constructor and copy-assignment operator in your String class from exercise 13.44
 * in § 13.5 (p. 531) a statement that prints a message each time the function is executed.
 * already be done.
 *
 * Exercise 13.48: Define a vector<String> and call push_back several times on that vector.
 * Run your program and see how often Strings are copied.
 * already be done.
 */

/*
 * Exercise 13.49: Add a move constructor and move-assignment operator to your StrVec, String, and Message classes.
 *
 *
 *
 * Exercise 13.50: Put print statements in the move operations in your String class and rerun the program from exercise
 * 13.48 in § 13.6.1 (p.534) that used a vector<String> to see when the copies are avoided.
 *
 *
 * Exercise 13.51: Although unique_ptrs cannot be copied, in § 12.1.5 (p.471) we wrote a clone function that returned
 * a unique_ptr by value. Explain why that function is legal and how it works.
 *
 *
 *
 * Exercise 13.52: Explain in detail what happens in the assignments of the HasPtr objects on page 541.
 * In particular, describe step by step what happens to values of hp, hp2, and of the rhs parameter in the HasPtr assignment operator.
 *
 *
 *
 * Exercise 13.53: As a matter of low-level efficiency, the HasPtr assignment operator is not ideal.
 * Explain why. Implement a copy-assignment and move- assignment operator for HasPtr and compare the operations
 * executed in your new move-assignment operator versus the copy-and-swap version.
 *
 *
 * Exercise 13.54: What would happen if we defined a HasPtr move- assignment operator but did not change the copy-and-swap operator?
 * Write code to test your answer.
 *
 *
 *
 *
 */


//string &rHello(const string &) &;error: non-member function cannot have '&' qualifier

namespace tf {
    class Foo {
    public:
        Foo sorted() const &;

        Foo sorted() &&;

    private:
        vector<int> data;
    };

    Foo Foo::sorted() const &{
        Foo ret(*this);
        std::sort(ret.data.begin(), ret.data.end());
        return *this;
    }

    Foo Foo::sorted() &&{
        std::sort(data.begin(), data.end());
        return *this;
    }


}


/*
 * Exercise 13.55: Add an rvalue reference version of push_back to your StrBlob.
 * Answer:
 * already be done.
 *
 * Exercise 13.56: What would happen if we defined sorted as:
 * Foo Foo::sorted() const & {
 *      Foo ret(*this);
 *      return ret.sorted();
 * }
 * Answer:
 * the code will be trapped into a recursion and causes a deadly stack overflow.
 *
 *
 * Exercise 13.57: What if we defined sorted as:
 * Foo Foo::sorted() const & { return Foo(*this).sorted(); }
 * Answer:ok, it will call the move version.
 *
 *
 *
 * Exercise 13.58: Write versions of class Foo with print statements in their sorted functions to test your answers to
 * the previous two exercises.
 * yes, already be done.
 *
 */












int main(int argc, char *argv[]) {

    testingCopyControl();
    testingClassOfNumbered();
    testingTreeNode();
    testingSwapAndOperatorLess();


    return 0;
}

