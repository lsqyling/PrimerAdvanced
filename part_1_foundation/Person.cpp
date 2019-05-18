//
// Created by shiqing on 19-4-23.
//

#include "Person.h"


std::istream &p::read(std::istream &is, Person &person) {
    is >> person.name_ >> person.address_;
    return is;
}

std::ostream &p::print(std::ostream &os, const Person &person) {
    os << person.name_ << " "
       << person.address_;
    return os;
}




