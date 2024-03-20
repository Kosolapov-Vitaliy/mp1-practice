#include <exception>
#include "date.h"

TDate::TDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int TDate::GetDay() const
{
    return this->day;
}

int TDate::GetMonth() const
{
    return this->month;
}

int TDate::GetYear() const
{
    return this->year;
}

void TDate::SetDay(int day)
{
    this->day = day;
}

void TDate::SetMonth(int month)
{
    this->month = month;
}

void TDate::SetYear(int year)
{
    this->year = year;
}
