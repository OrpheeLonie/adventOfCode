#include <iostream>
#include <fstream>

void part1(std::string *lines, int count, int &output)
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
