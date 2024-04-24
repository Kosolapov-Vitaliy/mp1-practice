#pragma once
#include "fio.h"

class Date {
private:
    int day;
    int month;
    int year;
public:
    const Date& operator=(const Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
};
