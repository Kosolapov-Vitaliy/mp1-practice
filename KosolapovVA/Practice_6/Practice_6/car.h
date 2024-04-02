#ifndef CAR_H
#define CAR_H
#include "car.h"
#include "person.h"

typedef struct
{
    char* car_num;
    char* empty;
    char* passport;
}Car;

void read_car(char* in_f, Car* c, int* i);
void write_car(char* in_f, Car* c);
//void check_car(Car* c);
void free_car(Car* c);
#endif CAR_H
