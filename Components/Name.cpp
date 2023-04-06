#include "Name.h"

Name::Name(const std::string& nameLast, const std::string& nameFirst) :
    last{ nameLast }, first{ nameFirst } {}

void Name::set(const std::string& nameLast, const std::string& nameFirst) {
    last = nameLast;
    first = nameFirst;
}

std::string Name::get() {
    return last + " " + first;
}

bool operator==(const Name& nameA, const Name& nameB) {
    if (nameA.first != nameB.first) return false;
    if (nameA.last != nameB.last) return false;
    return true;
}