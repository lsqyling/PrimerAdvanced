//
// Created by shiqing on 19-4-23.
//

#ifndef PRIMERADVANCED_SCREEN_H
#define PRIMERADVANCED_SCREEN_H

#include "../common/CommonHeaders.h"
class ScreenManager;
class Screen {
    friend class ScreenManager;
public:
    using Pos = string::size_type;

    Screen() = default;

    Screen(Pos wd, Pos ht, char c) : width_(wd), height_(ht), content_(wd * ht, c) {}

    Screen(Pos wd, Pos ht) : width_(wd), height_(ht), content_(wd * ht, ' ') {}

    char get() const { return content_[cursor_]; }

    char get(Pos r, Pos c) const {
        auto row = r * width_;
        return content_[row + c];
    }

    Screen &set(char c);

    Screen &set(Pos r, Pos c, char ch);

    Screen &move(Pos r, Pos c);

    Screen &display(std::ostream &os);

    const Screen &display(std::ostream &os) const;

    Pos size() const;

    Screen &clear(char c = bkground);


    void someMember() const;

private:
    void doDisplay(std::ostream &os) const {
        os << content_;
    }

    static const char bkground = ' ';

private:
    Pos width_ = 0;
    Pos height_ = 0;
    Pos cursor_ = 0;
    string content_;
//    may change even in a const object
    mutable size_t accessCtr_ = 0;


};

inline Screen::Pos Screen::size() const {
    return height_ * width_;
}

inline Screen &Screen::display(std::ostream &os) {
    doDisplay(os);
    return *this;
}

inline const Screen &Screen::display(std::ostream &os) const {
    doDisplay(os);
    return *this;
}

inline Screen &Screen::set(char c) {
    content_[cursor_] = c;
    return *this;
}

inline Screen &Screen::set(Screen::Pos r, Screen::Pos c, char ch) {
    auto row = r * width_;
    content_[row + c] = ch;
    return *this;
}

inline void Screen::someMember() const {
    ++accessCtr_;
}

inline Screen &Screen::move(Screen::Pos r, Screen::Pos c) {
    Pos row = r * width_;
    cursor_ = row + c;
    return *this;
}


#endif //PRIMERADVANCED_SCREEN_H
