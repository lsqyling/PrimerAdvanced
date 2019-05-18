//
// Created by shiqing on 18-10-9.
//

#ifndef PRIMER_UTFTEXT_H
#define PRIMER_UTFTEXT_H

#include <string>
#include "Text.h"

using std::string;

class UtfText : public Text {
public:
    UtfText(string path);

    ~UtfText(void);

    bool ReadOneChar(string &oneChar);

private:
    size_t get_utf8_char_len(const char &byte);


};


#endif //PRIMER_UTFTEXT_H
