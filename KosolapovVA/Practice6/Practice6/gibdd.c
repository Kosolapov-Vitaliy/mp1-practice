#include "gibdd.h"

void rread_info(char* str_g, I_gibdd* inf)
{
    int sz, i=0, j;
    char temp[240];
    sz = strlen(str_g);
    do
    {
        while (str_g[i] == ' ')
            i++;
        memset(temp,'\0', 240);
        j = 0;
        do {
            temp[j]=str_g[i];
            i++; j++;
        } while (str_g[i]!=' ');
        inf->pers.FIO.l_name = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while (str_g[i] != ' ');
        inf->pers.FIO.name = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++; 
        } while (str_g[i] != ' ');
        inf->pers.FIO.m_name = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while (str_g[i] != ' ');
        rread_br_d(temp, &inf->pers.birth);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while (str_g[i] != ' ');
        inf->pers.phone_num = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while (str_g[i] != ' ');
        inf->TS.car_num = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while (str_g[i] != ' ');
        inf->TS.passport = _strdup(temp);
        while (str_g[i] == ' ')
            i++;
        memset(temp, '\0', 240);
        j = 0;
        do {
            temp[j] = str_g[i];
            i++; j++;
        } while ((str_g[i] != ' ')&&(str_g[i] != '\n') && (str_g[i] != '\0'));
        inf->otd = atoi(temp);
    } while ((str_g[i] != '\n') && (str_g[i] != '\0'));
}

void write_info(char* o_f, I_gibdd* inf)
{
    write_person(o_f, &(inf->pers));
    write_car(o_f, &(inf->TS));
    FILE* f = fopen(o_f, "a");
    fprintf(f, "%d", inf->otd);
    fclose(f);
}
int check_all(const I_gibdd* inf)
{
    int flag = 0;
    flag = check_car(&inf->TS);
    if (flag != 0)
        return flag;
    flag = check_pers(&inf->pers);
    return flag;
}



void free_all(I_gibdd* ig)
{
    free_pers(&ig->pers);
    free_car(&ig->TS);
}