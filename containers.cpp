#include "containers.h"

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

// Make sfinae must cotain a .function() parameter
template<typename T>
void containers::insertElements(T myContainer) {
    begin = std::chrono::steady_clock::now();
    T::iterator iter;
    for (const int& number : randomElements)
    {
        iter = myList.end();
        myList.insert(iter, number);
    }
}