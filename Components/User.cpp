#include "User.h"

User::User(const Name& name, const std::string& ID, const std::string& passwordStr) {
    this->name = name;
    this->ID = ID;
    setPassword(passwordStr);
}

uint64_t User::hash(uint64_t left, uint64_t right) {
    left ^= right + 0x6969696969696969 + (left >> 6) + (right << 9);
    return left;
}

uint64_t User::hash(std::string str) {
    uint64_t left = 0, right = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        if (i & 1) left = hash(left, (uint64_t)str[i]);
        else right = hash(right, (uint64_t)str[i]);
    }

    return hash(left, right);
}

void User::setFirstName(const std::string& firstName) {
    this->name.first = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->name.last = lastName;
}


void User::setName(const std::string& first, const std::string& last) {
    name.first = first;
    name.last = last;
}

void User::setID(const std::string ID) {
    this->ID = ID;
}


void User::setPassword(const std::string& str) {
    password = hash(str);
}

bool User::isPassword(const std::string& str) {
    return (hash(str) == password);
}

uint64_t User::getHashedPass() {
    return password;
}

bool operator==(const User& userA, const User& userB) {
    if (userA.ID != userB.ID) return false;
    if (userA.name != userB.name) return false;
    return true;
}

Staff::Staff(const Name& name, const std::string& ID, const std::string& password) {
    this->name = name;
    this->ID = ID;
    setPassword(password);
}
