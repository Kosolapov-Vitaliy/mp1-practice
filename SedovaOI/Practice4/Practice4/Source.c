#include<stdio.h>
#define N 10
const char* products[N] = { "Limon","Milk","Eggs","Apple","Honey","Oil","Bread","Tea","Sausage","Cheese" };
const char* barcodes[N] = { "0101","2020","0303","4040","0505","6060","0707","8080","0909","1010" };
float price[N] = { 25.00, 69.00, 75.00, 80.00, 300.00, 120.00, 30.00, 80.00, 250.00, 400.00 };
float skidka[N] = { 4.50, 7.00, 5.00, 6.55, 21.35, 12.50, 5.00, 13.90, 42.10, 51.30 };
void scan(int* ct) {
	char* bc[1];
	int counts[N] = { 0 };
	printf("Enter barcodes...\n");
	while (strcmp(bc, "s")) {
		gets(bc);
		if (strcmp(bc, "s")) {
			for (int i = 0; i < N; i++) {
				if (strcmp(barcodes[i], bc) == 0) {
					printf("%s, price: %.2f, skidka: %.2f\n", products[i], price[i], skidka[i]);
					ct[i] += 1;
				}}}}}

void printchek(int* ct) {
	float stoimoct = 0;
	printf("Your receipt:\n");
	for (int i = 0; i < N; i++) {
		if (ct[i] == 0)
			continue;
		printf("%s, price vkluchaet skidka - %.2f, %d units.\n", products[i], price[i] - skidka[i], ct[i]);
		stoimoct += (price[i] - skidka[i]) * ct[i];
	}
	printf("Stoimoct - %.2f", stoimoct);
}

int main() {
	int counts[N] = { 0 };
	scan(counts);
	printchek(counts);
	return 0;
}

