//
// Created by shiqing on 19-4-23.
//

#ifndef PRIMERADVANCED_PERSON_H
#define PRIMERADVANCED_PERSON_H

#include "../common/CommonHeaders.h"


namespace p {
    class Person {
        friend std::istream &read(std::istream &is, Person &person);

        friend std::ostream &print(std::ostream &os, const Person &person);

    public:

        Person() = default;

        Person(string name) : Person(name, "Resident Address: ") {}

        Person(string name, string address) : name_(name), address_(address) {}

        string getName() const {
            return name_;
        }

        string getAddress() const {
            return address_;
        }

    private:
        string name_;
        string address_;

    };

    std::istream &read(std::istream &is, Person &person);

    std::ostream &print(std::ostream &os, const Person &person);

}

#endif //PRIMERADVANCED_PERSON_H
