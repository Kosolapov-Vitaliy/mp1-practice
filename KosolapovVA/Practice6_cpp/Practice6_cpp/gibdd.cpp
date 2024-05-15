#include "gibdd.h"

const BD& BD:: operator=(const BD&bd)
{
    this->pers = bd.pers;
    this->car = bd.car;
    this->otd = bd.otd;
    return *this;
}

std::ostream& operator<<(std::ostream&out, const BD&bd)
{
    return out << bd.pers << bd.car << " " << bd.otd;
}

std::istream& operator>>(std::istream&in, BD&bd)
{
    return in >> bd.pers >> bd.car >> bd.otd;
}

int BD::check_otd(const int ot)
{
    if (ot == this->otd)
        return 1;        
    else return -1;
}