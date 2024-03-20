#include <iostream>
#include <fstream>
#include "vector.h"

int main(int argc, char** argv)
{
    TVector v1, v2;
    char* infilename, * outfilename;
    if (argc < 3)
    {
        std::cout << "Incorrect arduments";
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];
    std::ifstream in;
    in.open(infilename);
    if(in.is_open())
    {
        in >> v1 >> v2;
    }
    in.close();
    //std::cin >> v1 >> v2;
    std::cout << v1;
    std::cout << "\n" << v2;
    TVector sum = v1 + v2;
    TVector dif = v1 - v2;
    double mplic = v1 * v2;
    std::ofstream out;
    out.open(outfilename);
    if (out.is_open())
    {
        out << sum << "\n"
            << dif << "\nMplic = " << mplic;
    }
    out.close();
    std::cout << "\n" << sum << "\n"
              << dif <<"\nMplic = "<< mplic;
    return 0;
}