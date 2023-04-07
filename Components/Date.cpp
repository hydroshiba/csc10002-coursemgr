#include "Date.h"

Date::Date(const unsigned short& newDay, const unsigned short& newMonth, const unsigned int& newYear) :
    day{ newDay }, month{ newMonth }, year{ newYear } {}

void Date::set(const unsigned short& newDay, const unsigned short& newMonth, const unsigned int& newYear) {
    day = newDay;
    month = newMonth;
    year = newYear;
}

std::string Date::get() {
    std::string strDay = std::to_string(day);
    if (day < 10) strDay = '0' + strDay;

    std::string strMonth = std::to_string(month);
    if (month < 10) strMonth = '0' + strMonth;

    std::string strYear = std::to_string(year);
    return strDay + '/' + strMonth + '/' + strYear;
}

bool operator==(const Date& dateA, const Date& dateB) {
    if (dateA.day != dateB.day) return false;
    if (dateA.month != dateB.month) return false;
    if (dateA.year != dateB.year) return false;

    return true;
}