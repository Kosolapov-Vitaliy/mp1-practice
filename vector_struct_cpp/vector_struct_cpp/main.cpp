#include <iostream>
#include "vector.h"

int main()
{
    TVector v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "\n" << v1;
    std::cout << "\n" << v2;
    TVector sum = v1 + v2;
    TVector dif = v1 - v2;
    double mplic = v1 * v2;
    std::cout << "\n" << sum;
    std::cout << "\n" << dif;
    std::cout <<"Mplic =\n"<< mplic;
    return 0;
}