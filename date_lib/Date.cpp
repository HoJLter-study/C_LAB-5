#include <iostream>
#include "Date.h"


uint8_t daysInMonth(uint8_t month, uint16_t year) {
    switch (month) {
    case 1: return 31;
    case 2: return year % 4 ? 28 : 29;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}


Date::Date() : day(1), month(1), year(1970) {};
Date::Date(uint8_t d, uint8_t m, uint16_t y) {
    if (d < 1 || m < 1 || m > 12 || d > daysInMonth(m, y)) {
        throw std::invalid_argument("[ERROR] Invalid date");
    }

    day = d;
    month = m;
    year = y;
};

bool Date::operator>(const Date& arg) {
    if (year > arg.year) return true;
    if (year < arg.year) return false;

    if (month > arg.month) return true;
    if (month < arg.month) return false;

    return day > arg.day;
}

bool Date::operator<(const Date& arg) {
    if (year < arg.year) return true;
    if (year > arg.year) return false;

    if (month < arg.month) return true;
    if (month > arg.month) return false;

    return day < arg.day;
}

bool Date::operator<=(const Date& arg) {
    return (*this) < arg || (*this) == arg;
}
bool Date::operator>=(const Date& arg) {
    return (*this) > arg || (*this) == arg;
}

bool Date::operator==(const Date& arg) {
    if (year == arg.year && month == arg.month && day == arg.day)
        return true;
    return false;
}

bool Date::operator!=(const Date& arg) {
    if (year != arg.year || month != arg.month || day != arg.day)
        return true;
    return false;
}

bool Date::isStudyTime() {
    if ((*this >= Date(1, 9, year) && *this <= Date(31, 12, year)) ||
        (*this >= Date(9, 2, year) && *this <= Date(12, 6, year)))
        return true;

    return false;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::setDay(uint8_t d) {
    if (d < 1 || d > daysInMonth(this->month, this->year)) {
        throw std::invalid_argument("[ERROR] Invalid date");
    }
    this->day = d;
}

void Date::setMonth(uint8_t m) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("[ERROR] Invalid date");
   }
    this->month = m;
}

void Date::setYear(uint16_t y) {
    this->year = y;
}

std::ostream& operator<< (std::ostream& output, Date& arg) {
    if (arg.getDay() < 10) {
        output << '0';
    }
    output << arg.getDay() << '.';

    if (arg.getMonth() < 10) {
        output << '0';
    }
    output << arg.getMonth() << '.' << arg.getYear();
    return output;
}

std::istream& operator>> (std::istream& input, Date& arg) {
    Date temp;

    int day, month, year;
    input >> day >> month >> year;
    temp.setDay(day);
    temp.setMonth(month);
    temp.setYear(year);

    arg = temp;
    return input;
}
