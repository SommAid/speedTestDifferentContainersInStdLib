#include "mySet.h"


// Constructor just in case

void mySet::testInsertChronologicalNumbers()
{
    int start = 0, len;
    for (const auto& len : this->sizes) {
        begin = std::chrono::steady_clock::now();
        for (; start < len; start++)
        {
            this->testSet.insert(start);
        }
        end = std::chrono::steady_clock::now();
        testSet.clear();
        double milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
        double micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        double nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
        this->times.push_back({ milli, micro, nano });
        start = 0;
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "Set::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
}

void mySet::testInsertRandomNumbers()
{
    int start = 0, len;
    for (const auto& len : this->sizes) {
        std::vector<int> randomNumbers;
        for (int maxLen = 0; maxLen < len; maxLen++) {
            randomNumbers.emplace_back(rand());
        }
        begin = std::chrono::steady_clock::now();
        for (const int& randNumber : randomNumbers)
        {
            this->testSet.insert(randNumber);
        }
        end = std::chrono::steady_clock::now();
        testSet.clear();
        double milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
        double micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        double nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
        this->times.push_back({ milli, micro, nano });
        start = 0;
    }
    std::cout << "Insertion with ordered Elements\n";
    std::cout << "Set::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
}

void mySet::testAccessRandomPositions()
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
        // Test set insertion
        {
            std::set<int>::iterator iter;
            for (int start = 0; start < len; start++)
            {
                testSet.insert(start);
            }

            begin = std::chrono::steady_clock::now();
            for (const int& i : randomPositions)
            {
                iter = testSet.begin();
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
    std::cout << "Set::Insertion\n";
    std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
    printTimes();
    delete(hold);
}
