#pragma once

#include "person.h"

class TPersonLibrary
{
private:
    int count;
    TPerson* persons;
public:
    TPersonLibrary();
    TPersonLibrary(int);
    TPersonLibrary(const std::string&);
    TPersonLibrary(const TPersonLibrary&);
    ~TPersonLibrary();
};
