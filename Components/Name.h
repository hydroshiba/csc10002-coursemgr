#ifndef NAME_H
#define NAME_H

#include "Components.h"

struct Name {
    std::string first, last;

    Name();
    Name(const std::string& nameLast, const std::string& nameFirst);

    void set(const std::string& nameLast, const std::string& nameFirst);

    std::string get();
};

bool operator==(const Name& nameA, const Name& nameB);

#endif