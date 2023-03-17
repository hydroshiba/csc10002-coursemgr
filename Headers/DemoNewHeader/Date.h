#ifndef DATE_H
#define DATE_H

#include "Components.h"

struct Date {
    unsigned short day, month;
    unsigned int year;

    Date(unsigned short newDay = 0, unsigned short newMonth = 0, unsigned int newYear = 0) :
        day{ newDay }, month{ newMonth }, year{ newYear } {}

    void set(unsigned short newDay, unsigned short newMonth, unsigned int newYear) {
        day = newDay;
        month = newMonth;
        year = newYear;
    }

    std::string get() {
        std::string strDay = std::to_string(day);
        if (day < 10) strDay = '0' + strDay;

        std::string strMonth = std::to_string(month);
        if (month < 10) strMonth = '0' + strMonth;

        std::string strYear = std::to_string(year);
        return strDay + '/' + strMonth + '/' + strYear;
    }
};

#endif
