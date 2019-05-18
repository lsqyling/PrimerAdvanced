//
// Created by shiqing on 19-4-29.
//

#ifndef PRIMERADVANCED_PRINTFORMAT_H
#define PRIMERADVANCED_PRINTFORMAT_H

#include <iostream>


namespace self {
    template<typename Collection>
    std::ostream &printFormat(const Collection &co, unsigned wordsOfLine = 10, std::ostream &os = std::cout) {
        unsigned cnt = 0;
        for (const auto &elem : co) {
            os << elem << " ";
            if (++cnt % wordsOfLine == 0) os << '\n';
        }
        return os;
    }

}


#endif //PRIMERADVANCED_PRINTFORMAT_H
