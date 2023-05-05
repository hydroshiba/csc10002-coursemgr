#include "Name.h"

Name::Name(const std::string& nameFirst, const std::string& nameLast) :
    last{ nameLast }, first{ nameFirst } {}

void Name::set(const std::string& nameFirst, const std::string& nameLast) {
    last = nameLast;
    first = nameFirst;
}

std::string Name::get() const {
    return first + " " + last;
}

bool operator==(const Name& nameA, const Name& nameB) {
    if (nameA.first != nameB.first) return false;
    if (nameA.last != nameB.last) return false;
    return true;
}