#pragma once
#include "gibdd.h"
class BDLib
{
private:
    int count;
    BD* lib;
public:
    friend std::ostream& operator<<(std::ostream&, const BDLib&);
    friend std::istream& operator>>(std::istream&, BDLib&);
    const BDLib& operator=(const BDLib& s);
    BDLib check_lib( int otd);
    ~BDLib();
};