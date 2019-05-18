//
// Created by shiqing on 18-10-9.
//

#ifndef PRIMER_TEXTFACTORY_H
#define PRIMER_TEXTFACTORY_H


#include "Text.h"

class TextFactory {
public:
    static Text *CreateText(string textCode, string path);
};


#endif //PRIMER_TEXTFACTORY_H
