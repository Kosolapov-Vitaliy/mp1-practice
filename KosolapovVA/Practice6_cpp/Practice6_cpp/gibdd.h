#pragma once

#include "personal.h"
#include "car.h"

class BD
{
private:
    Person pers;
    Car car;
    int otd;
public:
    BD() = default;
    int check_otd(int ot);
    const BD& operator=(const BD&);
    friend std::ostream& operator<<(std::ostream&, const BD&);
    friend std::istream& operator>>(std::istream&, BD&);
};
