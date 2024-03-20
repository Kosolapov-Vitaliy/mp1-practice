#pragma once

#include <string>
#include "date.h"

class TPerson
{
private:
    TDate birth;
    std::string first_name;
    std::string last_name;
    std::string second_name;
public:
    TPerson() {};
    TPerson(const std::string&, const std::string&, const std::string&,
            const TDate&);
    // TODO: Set methods
    friend std::ostream& operator<<(std::ostream& out, const TPerson& p)
    {
        out << p.first_name << " " << p.second_name << " " <<
            p.last_name << " " << p.birth << std::endl;
        return out;
    }
};
