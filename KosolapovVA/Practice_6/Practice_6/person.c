#include "person.h"

void read_person(char* in_f, Person* p, int *i)
{
    char buf[248];
    int  sz=0;
    read_fn(in_f, &(p->FIO), &*i);
    read_br_d(in_f, &(p->birth), &*i);
    FILE* f = fopen(in_f, "r");
    fseek(f, *i, SEEK_SET);
    fscanf(f, "%s", &buf);
    sz = strlen(buf);
    *i = *i + sz + 1;
    p->phone_num = (char*)malloc(sz * sizeof(p->phone_num));
    strcpy(&p->phone_num, &buf);
    fclose(f);
}

void write_person(char* o_f, Person *p)
{
    print_fn(o_f, &p->FIO);
    print_br_d(o_f, &p->birth);
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%s ", &p->phone_num);
    printf("Конец работы, номер занесен\n");
    fclose(f);
}

void check_pers(const Person* p)
{
    int flag = 0,sz;
    flag=check_date(&p->birth.day);
    sz = strlen(&(p->phone_num));
    if (sz == 12 || sz == 11)
        flag = flag;
    else
        flag = -3;
    return flag;
}

void free_pers(Person* p)
{
    free_nm(&p->FIO);
    free(p->phone_num);
}