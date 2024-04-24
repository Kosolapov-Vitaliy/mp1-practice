#include "car.h"

const Car& Car::operator=(const Car&car)
{
    this->car_num = car.car_num;
    this->car_passport = car.car_passport;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Car&car)
{
    return out << car.car_num << " " << car.car_passport << " ";
}

std::istream& operator>>(std::istream& in, Car& car)
{
    return in >> car.car_num >> car.car_passport;
}