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
        start = 0;
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "List::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
}

void myList::testInsertRandomNumbers()
{
    int start = 0, len;
    for (const auto& len : this->sizes) {
        std::vector<int> randomNumbers;
        for (int maxLen = 0; maxLen < len; maxLen++) {
            randomNumbers.emplace_back(rand());
        }
        begin = std::chrono::steady_clock::now();
        std::list<int>::iterator iter;
        for (const int& randNumber : randomNumbers)
        {
            iter = this->testList.end();
            this->testList.insert(iter, randNumber);
        }
        end = std::chrono::steady_clock::now();
        testList.clear();
        double milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
        double micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        double nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
        this->times.push_back({ milli, micro, nano });
        start = 0;
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "List::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
}

void myList::testAccessRandomPositions()
{
    int* hold = new int();
    for (const auto& len : this->sizes) {
        std::vector<int> randomPositions;
        int randPos;
        for (int i = 0; i < len; i++) {
            randPos = rand() % len;
            if (randPos >= len)
                randPos = len - 1;
            randomPositions.emplace_back(randPos);
        }
        // Test list insertion
        {
            std::list<int> myList;

            std::list<int>::iterator iter;
            for (int start = 0; start < len; start++)
            {
                iter = myList.end();
                myList.insert(iter, start);
            }

            begin = std::chrono::steady_clock::now();
            for (const int& i : randomPositions)
            {
                iter = myList.begin();
                std::advance(iter, i);
                *hold = *iter;
            }
            end = std::chrono::steady_clock::now();
            double milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            double micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            double nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            this->times.push_back({ milli, micro, nano });
        }
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "List::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
    delete(hold);
}
