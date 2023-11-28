#include <iostream>
#include <fstream>

void part1(std::string line, std::string &output)
{
}

void part2(std::string line, std::string &output)
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

    std::string output_part1 = 0;
    std::string output_part2 = 0;
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
