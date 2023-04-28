#ifndef NAME_H
#define NAME_H

#include "Components.h"

struct Name {
    std::string first, last;

    Name(const std::string& nameFirst = defaultStr, const std::string& nameLast = defaultStr);

    void set(const std::string& nameFirst, const std::string& nameLast);

    std::string get();
};

bool operator==(const Name& nameA, const Name& nameB);

#endif