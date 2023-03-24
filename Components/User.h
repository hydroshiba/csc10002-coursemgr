#ifndef USER_H
#define USER_H

#include "Components.h"
#include "Name.h"

struct User {
private:
    uint64_t password;

    uint64_t hash(uint64_t left, uint64_t right) {
        left ^= right + 0x6969696969696969 + (left >> 6) + (right << 9);
        return left;
    }

    uint64_t hash(std::string str) {
        uint64_t left = 0, right = 0;

        for (size_t i = 0; i < str.size(); ++i) {
            if (i & 1) left = hash(left, (uint64_t)str[i]);
            else right = hash(right, (uint64_t)str[i]);
        }

        return hash(left, right);
    }

public:
    Name name;
    std::string ID;

    void setName(const std::string& first, const std::string& last) {
        name.first = first;
        name.last = last;
    }

    void setPassword(const std::string& str) {
        password = hash(str);
    }

    bool isPassword(const std::string& str) {
        return (hash(str) == password);
    }

    uint64_t getHashedPass() {
        return password;
    }
};

struct Staff : User {

};

bool operator==(const User &userA, const User &userB) {
    if(userA.ID != userB.ID) return false;
    if(userA.name != userB.name) return false;
    return true;
}

#endif // !USER_H