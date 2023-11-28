#include <iostream>
#include <fstream>

void insert(int *maxs, int val)
{
    int i;
    int next;
    for (i = 0; i < 3; i++)
        if (val > maxs[i])
            std::swap(maxs[i], val);

    for (; i < 3; i++)
        std::swap(maxs[i], val);
}

int main(int argc, char** argv)
{
    std::ifstream infile("input");
    std::string line;

    int max[3] = {0, 0, 0};
    int count = 0;
    while(getline(infile, line))
    {
        if (line != "")
            count += std::atoi(line.c_str());
        else
        {
            insert(max, count);
            count = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += max[i];
        std::cout << max[i] << ", ";
    }
    std::cout << sum << "\n";

    return 0;
}
