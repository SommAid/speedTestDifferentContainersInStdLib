#include "containers.h"

containers::containers()  {
    srand(time(0));
    sizes = { 2, 8, 64, 256, 1024, 4096, 16384, 65536 };
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

void containers::setContainerListSize(const std::vector<int>& nums)
{
    for (const auto& i : nums) {
        if (i < 0) {
            std::cout << "ERROR negative list size\n";
            return;
        }
    }
    this->sizes = nums;
}

void containers::printTimes() {
    int pos = 0, unit = 0;
    for (std::vector<double> units : this->times)
    {
        std::cout << std::right << std::setw(17) << this->sizes[unit++] << " > ";
        for (const double& time : units) {
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
        pos = 0;
        std::cout << "\n";
    }

}