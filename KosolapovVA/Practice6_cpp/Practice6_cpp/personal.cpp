#include "personal.h"


const Person& Person::operator=(const Person& d)
{
    this->fio = d.fio;
    this->birth = d.birth;
    this->phone = d.phone;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Person& d)
{
    out << d.fio << " " << d.birth << " " << d.phone << " ";
    return out;
}

std::istream& operator>>(std::istream& in, Person& d)
{
    std::string phone;
    in >> d.fio>> d.birth >> phone;
    if (size(phone) > 12 || size(phone) < 11)
        throw "Некорректный номер телефона";
    d.phone = phone;
    return in;
}
