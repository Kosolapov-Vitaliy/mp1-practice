#include <iostream>
#include "vector.h"

int main()
{
    TVector v1, v2;
    std::cin >> v1 >> v2;
    TVector res = v1 + v2; // !!! operator=
    std::cout << v1;
    std::cout << v2;
    std::cout << res;
    return 0;
}