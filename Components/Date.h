#ifndef DATE_H
#define DATE_H

#include "Components.h"

struct Date {
    unsigned short day, month;
    unsigned int year;

    Date(const unsigned short& newDay = 0, const unsigned short& newMonth = 0, const unsigned int& newYear = 0);

    void set(const unsigned short& newDay, const unsigned short& newMonth, const unsigned int& newYear);

    std::string get();
};

bool operator==(const Date& dateA, const Date& dateB);
#endif