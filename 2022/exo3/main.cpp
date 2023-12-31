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
    int *maps = new int[count * 255];
    for (int i = 0; i < count * 255; i++)
        maps[i] = 0;

    for (int j = 0; j < count; j++)
    {
        int length = lines[j].length();
        for (int i = 0; i < length; i++)
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
    }
    infile.close();

    std::cout << "part1: " << output_part1 << '\n';


    std::string line1, line2;
    std::ifstream infile2(argv[1]);
    while (getline(infile2, line))
    {
        int length = line.length();
        getline(infile2,line1);
        getline(infile2,line2);
        std::string *lines = new std::string[3] {line, line1, line2};

        part1(lines, 3, output_part2);

        delete[] lines;
    }
    infile2.close();

    std::cout << "part2: " << output_part2 << '\n';

    return 0;
}
