#include "person.h"


void write_person(const char* o_f, Person* p)
{
    print_fio(o_f, &p->FIO);
    print_br_d(o_f, &p->birth);
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%s ", p->phone_num);
    fclose(f);
}

int check_pers(const Person* p)
{
    int flag = 0, sz;
    flag = check_date(&p->birth.day);
    sz = strlen(p->phone_num);
    if (sz == 12 || sz == 11)
        flag = flag;
    else
        flag = -3;
    return flag;
}

void free_pers(Person* p)
{
    free_fio(&p->FIO);
    free(p->phone_num);
}