#include <ctime>

#include "Date.h"

int Date::day() { return _day; }
int Date::month() { return _month; }
int Date::year() { return _year; }

void Date::setDay(int value) { _day = value; }
void Date::setMonth(int value) { _month = value; }
void Date::setYear(int value) { _year = value; }

Date::Date() {
    time_t info = time(NULL);
    tm* now = localtime(&info);
    _day = now->tm_mday;
    _month = now->tm_mon + 1;
    _year = now->tm_year + 1900;
}

Date::Date(int day, int month, int year) {
    _day = day;
    _month = month;
    _year = year;
}