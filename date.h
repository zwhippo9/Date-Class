#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

class Date {
private:
    int month;
    int day;
    int year;

//leap year test
    bool isLeapYear(int year) const;

//last day of the month test
    int getLastDayOfMonth(int month, int year) const;

public:
    Date();
    Date(int m, int d, int y);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void setDate(int m, int d, int y);

//print functions
    void printFormat1() const; // mm/dd/yyyy
    void printFormat2() const; // month day, year
    void printFormat3() const; // day month year

    Date operator++();
    Date operator++(int);
    Date operator--();
    Date operator--(int);  
    int operator-(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif