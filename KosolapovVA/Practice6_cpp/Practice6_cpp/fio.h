#pragma once

#include <iostream>
#include <string>

class Fio {
private:
    std::string l_name;
    std::string name;
    std::string m_name;
public:
    /*
    Fio();
    ~Fio();
    */
    const Fio operator=(const Fio& f);
    friend std::istream& operator>>(std::istream& in, const Fio& f);
};