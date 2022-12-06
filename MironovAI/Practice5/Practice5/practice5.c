#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <corecrt_wstring.h>
#define N 100
typedef unsigned long long ull;
typedef long long ll;


void insert_sort(ull a[],int *hlp, int n[]);
void bubble_sort(ull a[], int *hlp, int n[]);
void merge(ull a[], int *hlp, int l, int r, int m);
void merge_sort(ull a[],int *hlp, int n);
void dir(wchar_t** wnames, ull* sze, time_t* tme1,int *hlp, int n);
int indir(wchar_t** wnames, WIN32_FIND_DATA* names, ull* sze, time_t* tme, ull* tme1, wchar_t* first_path, wchar_t* first_name, wchar_t* path, int last_free_place, int *hlp);
time_t filetime_to_timet(const FILETIME ft);
wchar_t* newpath(wchar_t* copypath, wchar_t* name);

time_t filetime_to_timet(const FILETIME ft)
{
	ULARGE_INTEGER ll;
	ll.LowPart = ft.dwLowDateTime;
	ll.HighPart = ft.dwHighDateTime;
	return ll.QuadPart / 10000000ULL - 11644473600ULL;
}




int main() {

	time_t* tme1 = (char*)malloc(N * sizeof(char*));
	int* hlp = (int*)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		hlp[i] = i;
	}
	char* nme = (char*)malloc(N * sizeof(char*));
	ull* sze = (ull*)malloc(N * sizeof(ull*));
	ull* tme = (ull*)malloc(N * sizeof(ull*));
	for (int j = 0; j < N; j++) {
		sze[j] = 0;
		tme[j] = 0;
	}

	int i = 0, k = 0;
	char* a = (char*)malloc(MAX_PATH - 3);
	char* a1 = (char*)malloc(MAX_PATH);
	


	setlocale(LC_ALL, "rus");
	wchar_t **wnames = (wchar_t**)malloc(N*sizeof(wchar_t**));
	for (int i = 0; i < N; i++) {
		wnames[i] = (wchar_t*)malloc(N * sizeof(wchar_t));
		wnames[i] = L"Empty";
	}
	WIN32_FIND_DATA names[N];
	WIN32_FIND_DATA fdata;
	HANDLE hfile;
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	wchar_t* cpypath = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));


	//check input path
	do {
		printf("Input a closed path: \n");
		printf("Be careful. If did not input a path like this: 'C:\\...\\...\\', you can have a problems \n");
		//Preparing path � wchar_t
		//In C we dont have "gets" idk why also we need to input a string with spaces, we cant do this with scanf()
		gets_s(a, 260);


		
		printf("%s \n", a);
		mbstowcs(cpypath, a, strlen(a) + 1);
		strcat(a, "*.*");
		mbstowcs(path, a, strlen(a) + 1);
		wprintf(path);
		printf("  [--------------PATH------------]\n");
		wprintf(cpypath);
		printf("  [----------CPYPATH------------] \n");
		hfile = FindFirstFile(path, &fdata);
		



	} while (hfile == INVALID_HANDLE_VALUE);

	printf("Your path : %s \n", a);
	printf("Data in your directory: \n");
	wchar_t* temp_path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t*));
	do {
		if (i == 0 || i == 1) {
			i++;
			continue;
		}
		names[i] = fdata;



		
		
		//wprintf(temp_path);
		if (names[i].nFileSizeLow == 0) {
			temp_path = newpath(cpypath, names[i].cFileName);
			int c = indir(wnames, names, sze, tme,tme1,cpypath,names[i].cFileName, temp_path, i + k, hlp);
			if (c > 0) k += c;
			continue;
			
		}
		
		//File name
		printf("Name:    ");

		
		wnames[i+k] = names[i].cFileName;
		wprintf(wnames[i + k]);

		//File size
		printf(" %10c    Size (bites): %u        ", ' ', names[i].nFileSizeLow);
		sze[i+k] = names[i].nFileSizeLow;
		//File creation time
		time_t* time1 = filetime_to_timet(names[i].ftCreationTime);
		printf("%10c Created time:  %s     \n", ' ', ctime(&time1));

		ull a = names[i].ftCreationTime.dwHighDateTime;
		ull b = names[i].ftCreationTime.dwLowDateTime;
		ull tm = a << 32 | b;
		tm /= 10000000;
		tme[i+k] = tm;

		tme1[i + k] = time1;

		i++;
	} while (FindNextFile(hfile, &fdata) != NULL);


	if (i+k <= 2) {
		printf("I guess your directory is empty or u did input a wrong path. Try again :) ");
		return 1;
	}

	printf("\n !!!     I hope you knows that a folders is a links, they have no size. You need to input right path if u want to know size of folders.  !!!\n");
	
	
	while (1) {





		//Input user data
		int sr;
		printf("Input a sorted method: \n Input 1 for  insert sort \n Input 2 for bubble sort \n Input 3 for merge sort \n ");
		do {
			scanf("%d", &sr);
		} while ((sr != 1) && (sr != 2) && (sr != 3));

		int wsr;
		printf("What i need to sort? \n Input 1 for sort size of files \n Input 2 for sort creation time \n ");
		do {
			scanf("%d", &wsr);
		} while ((wsr != 1) && (wsr != 2));

		
		if (sr == 1) {

			if (wsr == 1) {
				
				clock_t begin = clock();
				insert_sort(sze, hlp, i+k);
				clock_t end = clock();

				
				dir(wnames, sze, tme1, hlp, i+k);
				long double q = end;
				q /= 1000000;
				
				printf("Time of insert sort: %lf.\n", q);
			}
			if (wsr == 2) {


				clock_t begin = clock();
				insert_sort(tme, hlp, i+k);
				clock_t end = clock();


				printf("Sorted array: \n");
				dir(wnames, sze, tme1, hlp, i+k);

				long double q = end;
				q /= 1000000;
				printf("Time of insert sort: %lf.\n", q);
			}

		}
		if (sr == 2) {

			if (wsr == 1) {
				clock_t begin = clock();
				bubble_sort(sze, hlp, i+k);
				clock_t end = clock();


				printf("Sorted array: \n");
				dir(wnames, sze, tme1, hlp, i+k);
				long double q = end;
				q /= 1000000;

				printf("Time of Bubble_sort: %lf.\n", q);
			}
			if (wsr == 2) {
				clock_t begin = clock();
				bubble_sort(tme, hlp, i+k);
				clock_t end = clock();


				printf("Sorted array: \n");
				dir(wnames, sze, tme1, hlp, i);
				long double q = end;
				q /= 1000000;

				printf("Time of Bubble_sort: %lf.\n", q);
			}

		}

		if (sr == 3) {

			if (wsr == 1) {
				clock_t begin = clock();

				merge_sort(sze, hlp, 0, i + k - 1);
				clock_t end = clock();
				
				
				printf("Sorted array: \n");
				dir(wnames, sze, tme1, hlp, i+k);
				long double q = end;
				q /= 1000000;

				printf("Time of Bubble_sort: %lf.\n", q);
			}
			if (wsr == 2) {
				clock_t begin = clock();
				merge_sort(tme, hlp, 0, i + k - 1);
				clock_t end = clock();


				printf("Sorted array: \n");
				dir(wnames, sze, tme1, hlp, i + k);
				long double q = end;
				q /= 1000000;

				printf("Time of Bubble_sort: %lf.\n", q);
			}

		}
		printf("Input 'stop' if u wanna kill it, anything for continue\n");
		char user_code[10];
		scanf("%s", user_code);
		if (strcmp(user_code, "stop") == 0) {
			break;
		}

	}
	FindClose(hfile);
	printf("\nIm sure i have max mark for the work. \n I did it for a long time and helped everyone \n Have a good day.");
	scanf("%d", i);
	return 0;
	
}




void insert_sort(ull* a, int* hlp, int n)
{
	ull num = 0;
	int ti = -1;
	int j = 0;
	for (int i = 2; i < n; i++) {
		num = a[i];
		ti = hlp[i];
		j = i - 1;
		while (j >= 0 && a[j] > num) {
			a[j + 1] = a[j];
			hlp[j + 1] = hlp[j];
			j--;
		}
		a[j + 1] = num;
		hlp[j + 1] = ti;

	}
}



void bubble_sort(ull arr[],int *hlp, int n)
{
	ull temp = 0;
	int Htmp = 0;
	for (int write = 0; write < n; write++) {
		for (int sort = 0; sort < n - 1; sort++) {
			if (arr[sort] > arr[sort + 1]) {
				temp = arr[sort + 1];
				arr[sort + 1] = arr[sort];
				arr[sort] = temp;

				Htmp = hlp[sort + 1];
				hlp[sort + 1] = hlp[sort];
				hlp[sort] = Htmp;
			}
		}
	}
}


void merge(ull arr[], int* hlp, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	

	ull* L = (ull*)malloc(n1 * sizeof(ull*));
	ull* R = (ull*)malloc(n2 * sizeof(ull*));
	int* HL = (int*)malloc(n1 * sizeof(int*));
	int* HR = (int*)malloc(n2 * sizeof(int*));



	
	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		HL[i] = hlp[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		HR[j] = hlp[m + 1 + j];
	}
	
	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			hlp[k] = HL[i];
			i++;
		}
		else {
			arr[k] = R[j];
			hlp[k] = HR[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		hlp[k] = HL[i];
		i++;
		k++;
	}

	
	while (j < n2) {
		arr[k] = R[j];
		hlp[k] = HR[j];
		j++;
		k++;
	}
}


void merge_sort(ull arr[], int* hlp, int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;

	
		merge_sort(arr, hlp, l, m);
		merge_sort(arr, hlp, m + 1, r);

		merge(arr, hlp, l, m, r);
	}
}



void dir(wchar_t** wnames, ull* sze, time_t* tme1, int* hlp, int n) {
	printf("[---------------------START---------------------] \n");
	for (int i = 2; i < n; i++) {

		//File name
		printf("%d.   ", i - 1);
		printf("Name:    ");
		int j = hlp[i];
		wprintf(wnames[j]);
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', sze[j]);

		//File creation time
		printf("%10c Created time:  %s     \n", ' ', ctime(&(tme1[j])));

	}
	printf("-------------------------END-----------------------]");
}
int indir( wchar_t** wnames, WIN32_FIND_DATA* names, ull* sze, time_t* tme, ull* tme1,wchar_t *first_path,wchar_t* first_name, wchar_t* path, int last_free_place, int* hlp) {
	
	if (wcslen(path) < 3) return 0;
	WIN32_FIND_DATA names1[N];
	WIN32_FIND_DATA fdata1;
	HANDLE hfile1;

	int i = 0;
	hfile1 = FindFirstFile(path, &fdata1);
	
	if (hfile1 == INVALID_HANDLE_VALUE) return 0;
	wchar_t* cpypath = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	
	
	
	
	do {
		if (i == 0 || i == 1) {
			i++;
			continue;
		}
		names1[i] = fdata1;
		wchar_t* temp_path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t*));
		if (names1[i].nFileSizeLow == 0) {
			wcscpy(cpypath, first_path);
			wcscat(cpypath, first_name);
			wcscat(cpypath, L"\\");
			temp_path = newpath(cpypath, names1[i].cFileName);
			printf("\n");
			int c = indir(wnames, names1, sze, tme, tme1,cpypath,names1[i].cFileName, temp_path, last_free_place, hlp);
			last_free_place += c;
			i += c;
			continue;

		}
		
		
		//File name
		printf("Name:    ");
		//int *k = &last_free_place;
		wnames[last_free_place] = names1[i].cFileName;
		wprintf(wnames[last_free_place]);
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', names1[i].nFileSizeLow);
		sze[last_free_place] = names1[i].nFileSizeLow;
		//File creation time
		printf("  hlp:    %d      ", hlp[last_free_place]);
		time_t* time1 = filetime_to_timet(names1[i].ftCreationTime);
		printf("%10c Created time:  %s     \n", ' ', ctime(&time1));

		
		ull a = names1[i].ftCreationTime.dwHighDateTime;
		ull b = names1[i].ftCreationTime.dwLowDateTime;
		ull tm = a << 32 | b;
		tm /= 10000000;
		tme[last_free_place] = tm;
		tme1[last_free_place] = time1;
		last_free_place++;
		i++;
	} while (FindNextFile(hfile1, &fdata1) != NULL);
	


	if (i > 2) return i - 2;
	return 0;

}
wchar_t *newpath(wchar_t* copypath, wchar_t* name) {
	wchar_t* newpath1 = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t*));
	wcscpy(newpath1, copypath);
	wcscat(newpath1, name);
	wcscat(newpath1, L"\\*.*");
	return newpath1;
}
