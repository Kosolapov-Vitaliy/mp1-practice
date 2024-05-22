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
    std::string car_num, car_passport;
    in >> car_num >> car_passport;
    if (size(car_num) > 9 || size(car_num) < 8)
        throw std::exception("Некорректный номер автомобиля");
    if (size(car_passport) != 10)
        throw std::exception( "Некорректный номер тех.паспорта");
    car.car_num = car_num;
    car.car_passport = car_passport;
    return in;
}