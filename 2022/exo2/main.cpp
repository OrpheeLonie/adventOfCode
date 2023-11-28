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

void part2(char a, char b, int &score)
{
    int j1 = a - 'A';
    int j2;
    switch(b)
    {
        case 'X':
            j2 = j1 + 2;
            break;

        case 'Y':
            j2 = j1;
            score += 3;
            break;

        case 'Z':
            j2 = j1 + 1;
            score += 6;
            break;
    }

    score = score + (j2 % 3) + 1;
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
    int score_part2 = 0;
    while (!infile.eof())
    {
        infile >> a >> b;
        if (infile.fail())
            break;

        part1(a, b, score_part1);
        part2(a, b, score_part2);
    }

    std::cout << "part1: " << score_part1 << '\n';
    std::cout << "part2: " << score_part2 << '\n';

    infile.close();

    return 0;
}
