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

    User(const Name& name = { defaultStr, defaultStr }, const std::string& ID = defaultStr, const std::string& passwordStr = "123456");

    void setFirstName(const std::string& firstName);

    void setLastName(const std::string& lastName);

    void setName(const std::string& first, const std::string& last);

    void setPassword(const std::string& str);

    void setPassWordUpLoad(const std::string& passwordInFile);

    bool isPassword(const std::string& str);

    void setID(const std::string ID);

    uint64_t getHashedPass();
};

struct Staff : public User {
    Staff(const Name& name = { defaultStr, defaultStr }, const std::string& ID = defaultStr, const std::string& password = "123456");
};

bool operator==(const User& userA, const User& userB);

#endif // !USER_H