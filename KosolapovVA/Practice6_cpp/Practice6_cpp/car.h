#pragma once
#include "fio.h"

class Car
{
private:
    std::string car_num;
    std::string car_passport;
public:
    Car() = default;
    const Car& operator=(const Car&);
    friend std::ostream& operator<<(std::ostream&, const Car&);
    friend std::istream& operator>>(std::istream&, Car&);
};
