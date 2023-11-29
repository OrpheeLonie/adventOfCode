#include <iostream>
#include <fstream>

bool is_present_for_all_maps(int *maps, int count, char c)
{
    for (int i = 0; i < count; i++)
    {
        if (!maps[255 * i + c])
            return false;
    }
    return true;
}

int count_score(char c)
{
    if (c <= 'z' && c >= 'a')
        return c - 'a' + 1;
    return c - 'A' + 27;
}

void part1(std::string *lines, int count, int &output)
{
    int length = lines[0].length();
    int *maps = new int[count * 255];

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < count; j++)
        {
            char c = lines[j][i];
            maps[255 * j + c] = 1;

            if (is_present_for_all_maps(maps, count, c))
            {
                output += count_score(c);
                delete[] maps;
                return;
            }
        }
    }
    std::cerr << "Did not find matching value\n";
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
        int length = line.length() / 2;
        std::string *lines = new std::string[2] {line.substr(0, length), line.substr(length, line.length())};
        part1(lines, 2, output_part1);
        delete[] lines;

        part2(line, output_part2);
    }

    std::cout << "part1: " << output_part1 << '\n';
    std::cout << "part2: " << output_part2 << '\n';

    infile.close();

    return 0;
}
