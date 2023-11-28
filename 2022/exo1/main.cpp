#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    std::ifstream infile("input");
    std::string line;

    int max = 0;
    int count = 0;
    while(getline(infile, line))
    {
        if (line != "")
            count += std::atoi(line.c_str());
        else
        {
            if (max < count)
                max = count;
            count = 0;
        }
    }
    std::cout << max << "\n";

    return 0;
}
