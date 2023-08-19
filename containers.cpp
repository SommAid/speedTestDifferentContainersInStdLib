#include "containers.h"

containers::containers()  {
    srand(time(0));
}

template<typename T>
inline void containers::generateAccessNumbers(int numNumbers, T container)
{
    int len = container.size(), randPos;
    std::uniform_int_distribution<> distrib(0, len);
    for (int i = 0; i < len; i++) {
        randPos = rand() % len;
        if (randPos >= len)
            randPos = len - 1;
        this->randomElements.emplace_back(randPos);
    }
}

void containers::setRandomNumbers(const std::vector<int>& nums)
{
    this->randomElements.clear();
    this->randomElements = {nums.cbegin(), nums.cend()};
}

void containers::printTimes(const std::vector<double>& times) {
    int pos = 0;
    for (const double& time : times) {
        switch (pos)
        {
        case 0:
            std::cout << std::left << std::setw(std::string("milliseconds").size()) << time << " || ";
            break;
        case 1:
            std::cout << std::left << std::setw(std::string("microseconds").size()) << time << " || ";
            break;
        case 2:
            std::cout << std::left << std::setw(std::string("nanoseconds").size()) << time << " || ";
            break;
        }
        pos++;
    }
    std::cout << "\n";
}