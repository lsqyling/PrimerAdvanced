//
// Created by shiqing on 18-10-9.
//

#ifndef PRIMER_TEXT_H
#define PRIMER_TEXT_H

#include <iostream>
#include <fstream>

using namespace std;

class Text {
protected:
    char *m_binaryStr;
    size_t m_length;
    size_t m_index;
public:
    Text(string path);

    void SetIndex(size_t index);

    virtual bool ReadOneChar(string &oneChar) = 0;

    size_t Size();

    virtual ~Text();
};


#endif //PRIMER_TEXT_H
