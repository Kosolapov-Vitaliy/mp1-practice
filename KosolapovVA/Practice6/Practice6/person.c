#include "person.h"

void read_person(char* in_f, Person* p, int* i)
{
    char buf[248];
    int  sz = 0, j=*i;
    read_fio( &(p->FIO), in_f, &j);
    read_br_d(in_f, &(p->birth), &j);
    FILE* f = fopen(in_f, "r");
    *i = j;
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", &buf);
    fclose(f);
    sz = strlen(buf);
    *i = *i + sz + 1;
    p->phone_num = _strdup(buf);
}

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