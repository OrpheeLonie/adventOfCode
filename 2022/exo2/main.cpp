#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Please, give an input file\n";
        return 0;
    }

    std::ifstream infile(argv[1]);

    char a;
    char b;

    while (!infile.eof())
    {
        infile >> a;
        infile >> b;

        std::cout << a << " " << b << "\n";
    }

    return 0;
}
