#ifndef DATE_H
#define DATE_H

#include "Components.h"

struct Date {
    unsigned short day, month;
    unsigned int year;

    Date(unsigned short newDay = 0, unsigned short newMonth = 0, unsigned int newYear = 0);

    void set(unsigned short newDay, unsigned short newMonth, unsigned int newYear);

    std::string get();
};

bool operator==(const Date& dateA, const Date& dateB);
#endif