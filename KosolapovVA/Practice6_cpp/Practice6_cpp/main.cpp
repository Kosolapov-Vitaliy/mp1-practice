#include "general.h"

void main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    char* infilename = argv[1];
    char* outfilename = argv[2];
    std::ifstream in(infilename);
    BDLib inlib;
    if (in.is_open())
    {
        in >>inlib;
    }
    in.close();
    std::cout << "Введите отделение ГИБДД:" << std::endl;
    int otdel;    
    try
    {
        std::cin >> otdel;
        BDLib outlib;
        outlib = inlib.check_lib(otdel);
        std::cout << outlib << std::endl;
        std::ofstream out(outfilename);
        if (out.is_open())
        {
            out << outlib << std::endl;
        }
        out.close();
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
    }
}