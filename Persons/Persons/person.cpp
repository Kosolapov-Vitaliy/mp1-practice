#include "person.h"

TPerson::TPerson(const std::string& fn, const std::string& ln,
    const std::string& sn, const TDate& date)
{
    this->first_name = fn;
    this->last_name = ln;
    this->second_name = sn;
    this->birth = date;
}