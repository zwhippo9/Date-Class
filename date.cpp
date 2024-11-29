#include "date.h"
#include <iostream>
#include <stdexcept>

//help check for leap year
bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//help for last day
  int Date::getLastDayOfMonth(int month, int year) const {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0;
    }
}

// default constructor
Date::Date() : month(1), day(1), year(1930) {}

// constructor with parameters
Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

void Date::setDate(int m, int d, int y) {
    if (m < 1 || m > 12) throw std::invalid_argument("Invalid month!");
    if (y < 1) throw std::invalid_argument("Invalid year!");

    int lastDay = getLastDayOfMonth(m, y);
    if (d < 1 || d > lastDay) throw std::invalid_argument("Invalid day!");

    month = m;
    day = d;
    year = y;
}

// mm//dd/yyyy
void Date::printFormat1() const {
    std::cout << month << "/" << day << "/" << year;
}

// month dd, yyyy
void Date::printFormat2() const {
    std::cout << month << "/" << day << "/" << year;
}

// dd month yyyy
void Date::printFormat3() const {
    static const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    std::cout << day << " " << months[month - 1] << " " << year;
}

// pre increment
Date Date::operator++() {
    int lastDay = getLastDayOfMonth(month, year);
    if (day < lastDay) {
        day++;
    } else {
        day = 1;
        if (month == 12) {
            month = 1;
            year++;
        } else {
            month++;
        }
    }
    return *this;
}

// post increment 
Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

// pre decrement
Date Date::operator--() {
    if (day == 1) {
        day--;
    } else {
        if (month == 1) {
            month = 12;
            year--;
        } else {
            month--;
        }
        day = getLastDayOfMonth(month, year);
    }
    return *this;
}

// post decrement
Date Date::operator--(int){
    Date temp = *this;
    --(*this);
    return temp;
}

int Date::operator-(const Date& other) const{
    return 0;
}

//stream
std::ostream& operaot<<(std::ostream& os, const Date& date) {
    date.printFormat2();
    return os:
}

std::istream& operator>>(std::istream& is, Date& date) {
              int m, d, y;
              std::cout << "Enter a date (month day year): ";
              is >> m >> d >> y;
              try {
                  date.setDate(m, d, y);
              } catch (const std::invalid_argument&) {
                  std::cout << "Invalid date!" << std::endl;
                  is.setstate(std::ios::failbit); 
  }
  return is;
}