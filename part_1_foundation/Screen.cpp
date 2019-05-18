//
// Created by shiqing on 19-4-23.
//

#include "Screen.h"

const char Screen::bkground;


Screen &Screen::clear(char c) {
    content_ = string(width_ * height_, c);
    return *this;
}

