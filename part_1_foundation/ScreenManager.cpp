//
// Created by shiqing on 19-4-23.
//

#include "ScreenManager.h"


void ScreenManager::clear(ScreenManager::ScreenIndex si) {
    Screen &s = screens[si];
    s.content_ = string(s.width_ * s.height_, ' ');

}


ScreenManager::ScreenIndex ScreenManager::addScreen(const Screen &s) {
    screens.push_back(s);
    return s.size() - 1;
}
