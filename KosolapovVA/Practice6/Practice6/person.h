#ifndef PERSON_H 
#define PERSON_H
#include "person.h"
#include "fio.h"
#include "birthdate.h"

typedef struct
{
    fio FIO;
    Birth_d birth;
    char* phone_num;
}Person;

void write_person(const char* o_f, Person* p);
void free_pers(Person* p);
#endif PERSON_H