#ifndef USER_H
#define USER_H

#include "Components.h"
#include "Name.h"

struct User {
private:
    uint64_t password;

    uint64_t hash(uint64_t left, uint64_t right) {
        left ^= right + 0x6969696969696969 + (left << 6) + (right << 9);
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

    std::string fullname() {
        return name.last + name.first;
    }

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

#endif // !USER_H

