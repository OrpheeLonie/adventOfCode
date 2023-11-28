#include <iostream>
#include <fstream>

int count_score(char c)
{
    if (c <= 'z' && c >= 'a')
        return c - 'a' + 1;
    return c - 'A' + 27;
}

void part1(std::string line, int &output)
{
    int length = line.length() / 2;
    int map1[255] = {0};
    int map2[255] = {0};
    for (int i = 0; i < length; i++)
    {
        char c1 = line[i], c2 = line[i + length];
        map1[c1] = 1;
        map2[c2] = 1;

        if (map2[c1])
        {
            output += count_score(c1);
            return;
        }

        if (map1[c2])
        {
            output += count_score(c2);
            return;
        }
    }
}

void part2(std::string line, int &output)
{
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Please, give an input file\n";
        return 0;
    }

    std::ifstream infile(argv[1]);

    std::string line;

    int output_part1 = 0;
    int output_part2 = 0;
    while (getline(infile, line))
    {
        part1(line, output_part1);
        part2(line, output_part2);
    }

    std::cout << "part1: " << output_part1 << '\n';
    std::cout << "part2: " << output_part2 << '\n';

    infile.close();

    return 0;
}
