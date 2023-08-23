#include "containers.h"

containers::containers()  {
    srand(1);
    sizes = { 2, 8, 64, 256, 1024, 4096, 16384, 65536 };
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