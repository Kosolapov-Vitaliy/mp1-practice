#include "outlet.h"
#include <iostream>

int main() {
	string path = start();
	buyerGuide guide(path);
	buyerGuide all_time_shops = guide.show_24_outlets();
	cout << all_time_shops;
	return 0;
}