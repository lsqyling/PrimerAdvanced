//
// Created by shiqing on 19-4-23.
//

#ifndef PRIMERADVANCED_SCREENMANAGER_H
#define PRIMERADVANCED_SCREENMANAGER_H

#include "../common/CommonHeaders.h"
#include "Screen.h"


class ScreenManager {
public:

    using ScreenIndex = vector<Screen>::size_type ;

    void clear(ScreenIndex si);

    ScreenIndex addScreen(const Screen &s);


private:
    vector<Screen> screens = {Screen(24, 48, ' ')};
};




#endif //PRIMERADVANCED_SCREENMANAGER_H
