#include <iostream>
#include <fstream>

void part1(char a, char b, int &score)
{
    int j1 = a - 'A';
    int j2 = b - 'X';
    int sub = j2 - j1;

    if (sub == 0)
        score += 3;
    else if (sub == 1 || sub == -2)
        score += 6;

    score = score + j2 + 1;
}

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

    int score_part1 = 0;
    while (!infile.eof())
    {
        infile >> a >> b;
        if (infile.fail())
            break;

        part1(a, b, score_part1);
    }

    std::cout << score_part1 << '\n';

    infile.close();

    return 0;
}
