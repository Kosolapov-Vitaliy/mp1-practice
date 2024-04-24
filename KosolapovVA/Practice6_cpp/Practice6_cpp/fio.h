#pragma once
#include <iostream>
#include <locale>
#include <string>
#include <fstream>
class FIO {
private:
    std::string L_name;
    std::string name;
    std::string M_name;
public:
    const FIO& operator=(const FIO&);
    friend std::ostream& operator<<(std::ostream&, const FIO&);
    friend std::istream& operator>>(std::istream&, FIO&);
};