#include "bithdate.h"


const Date& Date::operator=(const Date& d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.month;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
    if (d.day <= 9)
    {
        out << "0" << d.day << ".";
    }
    else
        out << d.day << ".";
    if (d.month <= 9)
    {
        out << "0" << d.month << ".";
    }
    else
        out << d.month << ".";
    out  << d.year << " "; 
    return out;
}

std::istream& operator>>(std::istream& in, Date& d )
{
    std::string buf;
    in >> buf; 
    int i = 0;
    std::string temp="      ";
    int j = 0;
    while (buf[i] != '.')
    {
        
        temp[j] = buf[i];
        i++;
        j++;
    }
    i++;
    j = 0; 
    d.day = stoi(temp); 
    temp = "      ";
    while (buf[i] != '.')
    {
        temp[j] = buf[i];
        i++;
        j++;
    }
    i++;
    j = 0;
    d.month = stoi(temp);
    temp = "      ";
    while (i<size(buf))
    {
        temp[j] = buf[i];
        i++;
        j++;
    }
    d.year = stoi(temp);
    return  in;
}
