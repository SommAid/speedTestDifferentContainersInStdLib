#include "myList.h"


// Constructor just in case

void myList::testInsertChronologicalNumbers()
{
    int start = 0, len;
    for (const auto& len : this->sizes) {
        begin = std::chrono::steady_clock::now();
        std::list<int>::iterator iter;
        for (; start < len; start++)
        {
            iter = this->testList.end();
            this->testList.insert(iter, start);
        }
        end = std::chrono::steady_clock::now();
        testList.clear();
        double milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
        double micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        double nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
        this->times.push_back({ milli, micro, nano });
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "List::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
}

void myList::testInsertRandom()
{
    

}

void myList::testAccessRandom()
{
}
