#include"fio.h"

const FIO& FIO:: operator=(const FIO& f)
{
    this->L_name = f.L_name;
    this->name = f.name;
    this->M_name = f.M_name;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const FIO& f)
{
    return out << f.L_name << " " << f.name << " " << f.M_name << " ";
}

std::istream& operator>>(std::istream& in, FIO& f)
{
    return in >> f.L_name >> f.name >> f.M_name;
}