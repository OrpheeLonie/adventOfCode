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

    int score = 0;
    while (!infile.eof())
    {
        infile >> a >> b;
        if (infile.fail())
            break;

        int j1 = a - 'A';
        int j2 = b - 'X';
        int sub = j2 - j1;

        if (sub == 0)
            score += 3;
        else if (sub == 1 || sub == -2)
            score += 6;

        //std::cout << "earn " << j2 + 1 << " point\n";

        score = score + j2 + 1;

        //std::cout << a << " " << b << "\n";
    }

    std::cout << score << '\n';

    infile.close();

    return 0;
}
