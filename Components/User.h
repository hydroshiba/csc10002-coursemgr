#ifndef USER_H
#define USER_H

#include "Components.h"
#include "Name.h"

struct User {
private:
    uint64_t password;

    uint64_t hash(uint64_t left, uint64_t right);

    uint64_t hash(std::string str);

public:
    Name name;
    std::string ID;

    void setName(const std::string& first, const std::string& last);

    void setPassword(const std::string& str);

    bool isPassword(const std::string& str);

    uint64_t getHashedPass();
};

struct Staff : User {

};

bool operator==(const User& userA, const User& userB);

#endif // !USER_H