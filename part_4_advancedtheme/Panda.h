//
// Created by shiqing on 19-5-17.
//

#ifndef PRIMERADVANCED_PANDA_H
#define PRIMERADVANCED_PANDA_H

#include "../common/CommonHeaders.h"

namespace animal {

    class ZooAnimal {
    public:
        ZooAnimal() = default;

        ZooAnimal(string family) : familyName_(family) {}

    private:
        string familyName_;

    };


    class Bear : virtual public ZooAnimal {
    public:
        Bear() = default;
        Bear(string name, bool onExhibit, string familyName)
                : ZooAnimal(familyName), name_(name),
                  onExhibit_(onExhibit) {}

    private:
        bool onExhibit_ = false;
        string name_;
    };

    class Endangered : virtual public ZooAnimal {

    public:
        Endangered(int grade = critical) {}

        static enum {
            critical
        };
    private:


    };


    class Panda : public Bear, public Endangered {
    public:
        Panda(string name, bool onExhibit)
                : Bear(name, onExhibit, "Panda"),
                  Endangered(Endangered::critical) {}
        Panda() : Endangered(Endangered::critical) {}

    };


}


#endif //PRIMERADVANCED_PANDA_H
