#include <stdio.h>
#include <windows.h>
#include <fileapi.h>
#include <string.h>

typedef struct
{
    char* name;
    ULONGLONG size;
} f_arr;

void path_adapting(char* path);
int check_path(char* path);


int main()
{
    system("chcp 1251");
    f_arr *files_arr;
    int work = 0;
    do {
        char path[255];
        int cfp;
        printf("1) Enter the path to the derrictory:\n");
        printf("2) Enter 1 if you want to finish:  \n");
        scanf("%s", &path);
        if (path[0] == '1') {
            break;
        }
        printf("%s", path);
        path_adapting(&path);
        cfp = check_path(&path);
        if (cfp == -1)
        {
            printf("The directory does not exist.Try again\n");
            continue;
        }
        cfp = count_files(&path);
        printf("%d", cfp);
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
int check_path(char *path)
{
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(path, &finddata);
    if (hFind == INVALID_HANDLE_VALUE) {

        return -1;
    }
    return ;
}
int count_files(char *path) 
{
    WIN32_FIND_DATAA finddata;
    HANDLE hFind = FindFirstFileA(path, &finddata);
    int count = -1;
    while (FindNextFileA(hFind, &finddata) != NULL)
    {
        count++;
    }
    return count;
}