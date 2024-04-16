#ifndef BIRTTHDATE_H
#define BIRTTHDATE_H

#include "fio.h"

typedef struct
{
    int day;
    int month;
    int year;
}Birth_d;

void rread_br_d(char* str, Birth_d* d);
int check_date(const Birth_d* d);
void print_br_d(const char* o_f, Birth_d* d);

#endif BIRTTHDATE_H