#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <fileapi.h>
#include <string.h>

typedef struct
{
    char* name;
    long size;
} f_arr;

void path_adapting(char *path);
int count_files(char *path);
f_arr* take_f_path(char* way, int cfp);
void copy(f_arr* Arr, f_arr* Copy_Arr, int cfp);
void quick_sort(long* size_arr, f_arr* Copy_Arr, int cfp);
void bubble_sort(f_arr* Copy_Arr, int cfp);
void insert_sort(f_arr* Copy_Arr, int cfp);
void take_size_arr(long* size_arr, f_arr* Copy_Arr, int cfp);
void swap_ch(char x, char y);
void swap_l(long x, long y);
void pr_files(f_arr* Copy_Arr, int cfp);

int main()
{
    system("chcp 1251");
    f_arr *files_arr;
    int work = 0;
    do {
        char path[255];
        int cfp;
        printf("1) Enter the path to the derrictory:\n");
        printf("2) Enter 0 if you want to finish:  \n");
        scanf("%s", &path);
        if (path[0] == '0') 
        {
            printf("End");
            break;
        }
        printf("%s", path);
        path_adapting(&path);
        cfp = count_files(&path);
        if (cfp == -1)
        {
            printf("The directory does not exist. Try again\n");
            continue;
        }
        if (cfp == 0)
        {
            printf("The directory is empty\n");
            continue;
        }
        printf("%d", cfp);
        files_arr = take_f_path(&path, cfp);
        do {
            int metod;
            printf("Select the sorting method: 1)bubble, 2)inserts, 3)quick\n");
            printf("Enter 0 if you want to change the directory:  \n");
            do {
                scanf("%d", &metod);
                if (metod >= 0 && metod <= 3)
                {
                    break;
                }
                printf("Error, try again");
            } while (metod < 0 || metod >3);
            if (metod == 0)
            {
                break;
            }
            f_arr* copy_farr = (f_arr*)malloc(cfp * sizeof(f_arr));
            copy(&files_arr, &copy_farr, cfp);
            long* size_arr = (long*)malloc(cfp * sizeof(long));
            take_size_arr(&size_arr, &copy_farr, cfp);
            switch (metod)
            {
            case 1:
                bubble_sort( &copy_farr, cfp);
                break;
            case 2:
                insert_sort(&copy_farr, cfp);
                break;
            case 3:
                quick_sort(&size_arr, &copy_farr, cfp);
                break;
            }
            pr_files(copy_farr, cfp);
            free(copy_farr);
            free(size_arr);
        } while (1);
        free(files_arr);
    } while (1);
    return 0;
}

void path_adapting(char *path)
{
    int ln = strlen(path);
    if (path[ln - 1] != '*') {
        path[ln] = '\\';
        path[ln + 1] = '*';
        path[ln + 2] = '\0';
    }
    printf("%s", path);
}
int count_files(char *path) 
{
    WIN32_FIND_DATAA fdata;
    HANDLE hFind = FindFirstFileA(path, &fdata);
    int count = -1;
    while (FindNextFileA(hFind, &fdata) != NULL)
    {
        count++;
    }
    return count;
}
f_arr* take_f_path(char* path, int cfp)
{
    int i = 0;
    f_arr* Arr;
    WIN32_FIND_DATAA fdata;
    HANDLE hFind = FindFirstFileA(path, &fdata);
    Arr = (f_arr*)malloc(cfp * sizeof(f_arr));
    do {
        char* filename = fdata.cFileName;
        long filesize = fdata.nFileSizeLow;
        Arr[i].name = _strdup(fdata.cFileName);
        Arr[i].size = filesize;
        i++;
    } while (FindNextFileA(hFind, &fdata) != NULL);
    FindClose(hFind);
    return Arr;
}
void take_size_arr(long* size_arr, f_arr* Copy_Arr, int cfp)
{
    int i = 0;
    for (i; i < cfp; i++)
    {
        size_arr[i] = Copy_Arr[i].size;
    }
}
void copy(f_arr* Arr, f_arr* Copy_Arr, int cfp)
{
    int i = 0;
    for (i; i < cfp; i++)
    {
        Copy_Arr[i].name = Arr[i].name;
        Copy_Arr[i].size = Arr[i].size;
    }
}
void quick_sort(long* size_arr, f_arr* Copy_Arr,int cfp)
{
    int i = 0, j = cfp - 1;
    long pivot;
    pivot = size_arr[(cfp-1)/2];
    while (i < j)
    {
        while (Copy_Arr[i].size < pivot)
        {
            i++;
        }
        while (Copy_Arr[j].size > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap_l(size_arr[i], size_arr[j]);
            swap_l(Copy_Arr[i].size, Copy_Arr[j].size);
            swap_ch(Copy_Arr[i].name, Copy_Arr[j].name);
            i++, j--;
        }
    }
    if (j > 0)
    {
        quick_sort(size_arr[0], Copy_Arr, j);
    }
    if (i < cfp - 1)
    {
        quick_sort(size_arr[i], Copy_Arr, cfp - i - 1);
    }
}
void bubble_sort(f_arr* Copy_Arr, int cfp)
{
    int i, j;
    long k;
    char* n;
    for (i = 0; i < cfp; i++)
    {
        for (j = 1; j < cfp - i; j++)
        {
            if (Copy_Arr[j].size < Copy_Arr[j-1].size)
            {
                k = Copy_Arr[j].size;
                n = Copy_Arr[j].name;
                Copy_Arr[j].size = Copy_Arr[j-1].size;
                Copy_Arr[j].name = Copy_Arr[j-1].name;
                Copy_Arr[j - 1].size = k;
                Copy_Arr[j - 1].name = n;
            }
        }
    }
}
void insert_sort(f_arr* Copy_Arr, int cfp)
{
    int  i, j;
    long k;
    char n;
    for (i = 1; i < cfp; i++)
    {
        n = Copy_Arr[i].name;
        k = Copy_Arr[i].size;
        j = i - 1;
        while ((j >= 0) && (Copy_Arr[j].size > k))
        {
            Copy_Arr[j + 1].size = Copy_Arr[j].size;
            Copy_Arr[j + 1].name = Copy_Arr[j].name;
            Copy_Arr[j].size = k;
            Copy_Arr[j].name = n;
            j--;
        }
    }
}
void pr_files(f_arr* Copy_Arr, int cfp)
{
    int i = 0;
    for (i; i < cfp+2; i++) 
    {
        printf("%s %d\n", Copy_Arr[i].name, Copy_Arr[i].size);
    }
}
void swap_l(long x, long y)
{
    long temp;
    temp = y;
    y = x;
    x = temp;
}
void swap_ch(char x, char y)
{
    char temp;
    temp = y;
    y = x;
    x = temp;
}