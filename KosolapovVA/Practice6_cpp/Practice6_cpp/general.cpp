#include "general.h"
std::ostream& operator<<(std::ostream& out, const BDLib& bd)
{
    for (int i = 0; i < bd.count; i++)
    {
        out << bd.lib[i] << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, BDLib& bd)
{
    in >> bd.count;
    bd.lib = new BD[bd.count];
    for (int i = 0; i < bd.count; i++)
    {        
        in >> bd.lib[i];
    }
    return in;
}

BDLib BDLib::check_lib(int otd)
{
    BDLib temp;
    int j = 0, cout = 0;
    for (int i = 0; i < this->count; i++)
    {
        if (this->lib[i].check_otd(otd) == 1)
        {
            cout++;
        }
    }
    if (cout == 0)
    {
        throw "Данное отделение отсутсвует";
    }
    temp.count = cout;
    temp.lib = new BD[temp.count];
    for (int i = 0; i < this->count; i++)
    {
        if (this->lib[i].check_otd(otd) == 1)
        {
            temp.lib[j] = this->lib[i];
            j++;
        }
    }
    return temp;
}
