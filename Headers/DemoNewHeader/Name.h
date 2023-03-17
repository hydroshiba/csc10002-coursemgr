#ifndef NAME_H
#define NAME_H

#include "Components.h"

struct Name {
    std::string first, last;

    Name() {}
    Name(const std::string& nameLast, const std::string& nameFirst) :
        last{ nameLast }, first{ nameFirst } {}

    void set(const std::string& nameLast, const std::string& nameFirst) {
        last = nameLast;
        first = nameFirst;
    }

    std::string get() {
        return last + " " + first;
    }
};

#endif
