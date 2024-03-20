#include <exception>
#include "library.h"

TPersonLibrary::TPersonLibrary()
{
    this->count = 0;
    this->persons = nullptr;
}

TPersonLibrary::TPersonLibrary(int count)
{
    this->count = count;
    this->persons = new TPerson[count];
}

TPersonLibrary::TPersonLibrary(const std::string&)
{
    throw std::exception("Not implemented");
}

TPersonLibrary::TPersonLibrary(const TPersonLibrary&)
{
    throw std::exception("Not implemented");
}

TPersonLibrary::~TPersonLibrary()
{
    if (this->persons != nullptr)
    {
        delete[] this->persons;
    }
}