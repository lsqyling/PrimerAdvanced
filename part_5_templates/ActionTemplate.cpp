//
// Created by shiqing on 18-12-9.
//

/**
 * chapter 6:模板实战
 * 1.包含模型和显示实例化的做法
 * stack.h stackdef.h stackdef.h 中#include "stack.h" ，包含模型中直接使用#include "stackdef.h"
 * 显式实例化 使用#include "stackdef.h" stack_inst.cpp 中显式实例化stack,在客户端中使用#include "stack.h"
 * 详见：c++ templates 图6.2
 *
 * 2.分离模型
 * 模板声明使用export ,定义在cpp文件中
 * Note:export 关键字位于template 前，不能和inline 一起使用
 *
 *
 *
 */

#include "UsefullFwd.h"
#include <algorithm>
#include <functional>

class SortTrace {
    friend bool operator<(const SortTrace &lhs, const SortTrace &rhs);

public:
    static long creations() {
        return nCreated_;
    }

    static long destructions() {
        return nDestroyed_;
    }

    static long assigns() {
        return nAssigned_;
    }

    static long comparisons() {
        return nCompared_;
    }

    static long maxLives() {
        return nMaxLived_;
    }

//    构造函数
    SortTrace(int v = 0) : value(v), generation(1) {
        ++nCreated_;
        updateMaxLive();
        std::cerr << "SortTracer #" << nCreated_
                  << ", created generation " << generation
                  << " (total: " << nCreated_ - nDestroyed_
                  << ")\n";
    }

    SortTrace(const SortTrace &rhs) : value(rhs.value), generation(rhs.generation + 1) {
        ++nCreated_;
        updateMaxLive();
        std::cerr << "SortTrace #" << nCreated_
                  << " (total: " << nCreated_ - nDestroyed_
                  << ")\n";
    }

    ~SortTrace() {
        ++nDestroyed_;
        updateMaxLive();
        std::cerr << "SortTrace generation " << generation
                  << " destroyed (total: "
                  << nCreated_ - nDestroyed_
                  << ")\n";
    }

    SortTrace &operator=(const SortTrace &rhs) {
        ++nAssigned_;
        std::cerr << "SortTrace assignment #" << nAssigned_
                  << " (generation " << generation
                  << " = " << rhs.generation
                  << ")\n";
        value = rhs.value;
    }

    int val() const { return value; }


private:
    int value;//to be sorted nums;
    int generation; //产生copy 的份数
    static long nCreated_;
    static long nDestroyed_;
    static long nAssigned_;
    static long nCompared_;
    static long nMaxLived_;

    static void updateMaxLive() {
        if (nCreated_ - nDestroyed_ > nMaxLived_) {
            nMaxLived_ = nCreated_ - nDestroyed_;
        }
    }

};

long SortTrace::nCreated_ = 0;
long SortTrace::nDestroyed_ = 0;
long SortTrace::nAssigned_ = 0;
long SortTrace::nCompared_ = 0;
long SortTrace::nMaxLived_ = 0;


bool operator<(const SortTrace &lhs, const SortTrace &rhs) {
    ++SortTrace::nCompared_;
    std::cerr << "SortTrace comparison #" << SortTrace::nCompared_
              << " (generation " << lhs.generation
              << " < " << rhs.generation
              << ")\n";
    return lhs.value < rhs.value;
}


int main(int argc, char *argv[]) {
    list<string> coll = {"hello", "world", "!"};
    auto pos = std::find_if(coll.begin(), coll.end(), [](const string &s) { return s < string("xyz"); });
    cout << "pos = " << *pos << endl;

    SortTrace input[] = {7, 3, 5, 6, 4, 2, 0, 1, 9, 8, 11, 17, 13, 14, 16, 3};
    for (auto beg = std::begin(input); beg != std::end(input); ++beg) {
        std::cerr << beg->val() << " ";
    }
    cout << endl;

    // 获取初始状态
    long createdAtStart = SortTrace::creations();
    long maxLivesAtStart = SortTrace::maxLives();
    long assignedAtStart = SortTrace::assigns();
    long comparedAtStart = SortTrace::comparisons();

//    执行算法
    std::cerr << "----[ Start std::sort() ]-----------------------------\n";
    std::sort(std::begin(input), std::end(input));
    std::cerr << "----[ End std::sort() ]-------------------------------\n";

    for (auto beg = std::begin(input); beg != std::end(input); ++beg) {
        std::cerr << beg->val() << " ";
    }
    std::cerr << "\n\n";

//    最后输出报告
    std::cerr << "std::sort() of " << (std::end(input) - std::begin(input)) << " SortTrace's"
            << " was performed by: \n"
            << SortTrace::creations() - createdAtStart
            << " temporary tracers\n"
            << "up to "
            << SortTrace::maxLives()
            << " tracers at the same times ("
            << maxLivesAtStart << " before)\n"
            << SortTrace::assigns() - assignedAtStart
            << " assignments\n"
            << SortTrace::comparisons() - comparedAtStart
            << " comparisons\n\n";



    return 0;

}
