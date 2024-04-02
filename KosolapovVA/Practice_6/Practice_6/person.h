#ifndef PERSON_H 
#define PERSON_H
#include "person.h"
#include "FIO.h"
#include "birthdate.h"

typedef struct
{
    Full_Name FIO;
    Birth_d birth;
    char* phone_num;
    char* empty;
}Person;

void read_person(const char* in_f, Person* p, int* i);
void write_person(char* o_f, Person* p);
void free_pers(Person* p);
#endif PERSON_H

