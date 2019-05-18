//
// Created by shiqing on 18-10-9.
//

#ifndef PRIMER_GBKTEXT_H
#define PRIMER_GBKTEXT_H


#include "Text.h"

class GbkText : public Text {
public:
    GbkText(string path);

    ~GbkText(void);

    bool ReadOneChar(string &oneChar);


};


#endif //PRIMER_GBKTEXT_H
