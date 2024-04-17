#include "fio.h"
#include <iostream>
const  Fio  Fio:: operator=(const Fio& f)
{
    this->l_name = f.l_name;
    this->name = f.name;
    this->m_name = f.m_name;
}

std::istream& Fio:: operator>>(std::istream& in, const Fio& f)
{

}