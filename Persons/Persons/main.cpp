#include <iostream>
#include <exception>
#include "date.h"
#include "person.h"
#include "library.h"

void TestTDate();
void TestTPerson();
void TestTLibrary();

int main()
{
    TestTDate();
    TestTPerson();
    TestTLibrary();
    return 0;
}

void TestTDate()
{
    try
    {
        TDate date(1, 1, 2024);
        std::cout << date;
        date.SetDay(2);
        date.SetMonth(3);
        date.SetYear(2024);
        std::cout << date;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void TestTPerson()
{
    try
    {
        TPerson person("Name", "Familia", "Otchestvo", TDate(1, 1, 2020));
        std::cout << person;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void TestTLibrary()
{
    try
    {
        TPersonLibrary lib(10);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}