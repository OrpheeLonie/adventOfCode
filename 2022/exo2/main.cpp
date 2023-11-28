#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream infile("input");

    char a;
    char b;

    while (1)
    {
        infile >> a;
        if (!a)
            break;
        infile >> b;
        std::cout << a << " " << b << "\n";
    }

    return 0;
}
