#pragma once
#include "bithdate.h"

class Person {
private:
    FIO fio;
    Date birth;
    std::string phone;
public:
    const Person& operator=(const Person&);
    friend std::ostream& operator<<(std::ostream&, const Person&);
    friend std::istream& operator>>(std::istream&, Person&);
};
