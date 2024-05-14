#include "bithdate.h"


Date :: Date(int day, int month, int year)
{
    if (year > 2024)
        throw "Некорректный год";
    if (month > 12 || month <= 0)
        throw "Некорректный месяц";
    if (day<=0||((day>31)||((day>30)&&(month == 4|| month == 6|| month == 9|| month == 11))))
        throw "Некорректный день";
    if (month == 2)
    {
        if (day > 29)
            throw "Некорректный день";
        else if ((day>28)&&(((year%4!=0)||(year%100==0))&&(year%400!=0)))
            throw "Некорректный день";
    }
    this->day = day;
    this->month = month;
    this->year = year;
}

const Date& Date::operator=(const Date& d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
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
    std::string temp="      ";
    int j = 0, i = 0;
    while (buf[i] != '.')
    {
        
        temp[j] = buf[i];
        i++;
        j++;
    }
    i++;
    j = 0; 
    int t_day;
    t_day = stoi(temp);
    temp = "      ";
    while (buf[i] != '.')
    {
        temp[j] = buf[i];
        i++;
        j++;
    }
    i++;
    j = 0;
    int t_month;
    t_month = stoi(temp);
    temp = "      ";
    while (i<size(buf))
    {
        temp[j] = buf[i];
        i++;
        j++;
    }
    int t_year;
    t_year = stoi(temp);
    d = Date{ t_day, t_month, t_year };
    return  in;
}
