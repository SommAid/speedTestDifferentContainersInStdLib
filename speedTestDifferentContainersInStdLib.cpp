// flat_set vs set vs vector vs list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// IO related

#include "containers.h"

// std lib data strucutres
//#include <flat_set> //Note: requires (c++23)

static void testInsertOrderedNumbers();
static void printTimes(const std::vector<double>& times);
static void testInsertRandomNumbers();
static void testAccessRandomNumbers();

static std::random_device rd;
static std::mt19937 gen(rd());

int main() {

    // use as reference delete at end
    std::vector<int> numElements{ 2, 4, 8, 16, 64, 256, 512, 1024, 2048, 4096, 65536 };

    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    std::vector<std::vector<double>> listInsertionTimes{};
    std::vector<std::vector<double>> setInsertionTimes{};
    std::vector<std::vector<double>> vectorInsertionTimes{};

    int numEle;

    double milli;
    double micro;
    double nano;

    testAccessRandomNumbers();
}

static void printTimes(const std::vector<double>& times) {
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

static void testInsertRandomNumbers()
{
    std::vector<int> numElements{ 2, 4, 8, 16, 64, 256, 512, 1024, 2048, 4096, 65536 };

    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    std::vector<std::vector<double>> listInsertionTimes{};
    std::vector<std::vector<double>> setInsertionTimes{};
    std::vector<std::vector<double>> vectorInsertionTimes{};

    int numEle;

    double milli;
    double micro;
    double nano;

    // Test list insertion

    std::uniform_int_distribution<> distrib(-10000, 10000);
    for (const auto& currMaxEle : numElements)
    {
        std::vector<int> randomElements;
        for (int i = 0; i < currMaxEle; i++) {
            randomElements.emplace_back(distrib(gen));
        }

        // Test list insertion
        numEle = 0;
        {
            std::list<int> myList;
            begin = std::chrono::steady_clock::now();
            std::list<int>::iterator iter;
            for (const int& number : randomElements)
            {
                iter = myList.end();
                myList.insert(iter, number);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            listInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test set insertion
        numEle = 0;
        {
            std::set<int> mySet;
            std::list<int> myList;
            begin = std::chrono::steady_clock::now();
            for (const int& number : randomElements)
            {
                mySet.insert(number);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            setInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test vector insertion
        numEle = 0;
        {
            std::vector<int> myVector;
            std::list<int> myList;
            begin = std::chrono::steady_clock::now();
            std::vector<int>::iterator iter;
            for (const int& number : randomElements) {
                iter = myVector.end();
                myVector.insert(iter, number);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            vectorInsertionTimes.push_back({ milli, micro, nano });
        }
    }

    {
        int pos = 0;
        std::cout << "Insertion with random elements\n";
        std::cout << "List::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : listInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nSet::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : setInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nVector::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : vectorInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
}

static void testInsertOrderedNumbers()
{
    std::vector<int> numElements{ 2, 4, 8, 16, 64, 256, 512, 1024, 2048, 4096, 65536 };

    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    std::vector<std::vector<double>> listInsertionTimes{};
    std::vector<std::vector<double>> setInsertionTimes{};
    std::vector<std::vector<double>> vectorInsertionTimes{};

    int numEle;

    double milli;
    double micro;
    double nano;

    // Test list insertion

    for (const auto& currMaxEle : numElements)
    {
        // Test list insertion
        numEle = 0;
        {
            std::list<int> myList;
            begin = std::chrono::steady_clock::now();
            std::list<int>::iterator iter;
            for (; numEle < currMaxEle; numEle++)
            {
                iter = myList.end();
                myList.insert(iter, numEle);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            listInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test set insertion
        numEle = 0;
        {
            std::set<int> mySet;
            begin = std::chrono::steady_clock::now();
            for (; numEle < currMaxEle; numEle++)
            {
                mySet.insert(numEle);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            setInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test vector insertion
        numEle = 0;
        {
            std::vector<int> myVector;
            begin = std::chrono::steady_clock::now();
            std::vector<int>::iterator iter;
            for (; numEle < currMaxEle; numEle++) {
                iter = myVector.end();
                myVector.insert(iter, numEle);
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            vectorInsertionTimes.push_back({ milli, micro, nano });
        }
    }

    {
        int pos = 0;
        std::cout << "Insertion with ordered Elements\n";
        std::cout << "List::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : listInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nSet::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : setInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nVector::Insertion\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : vectorInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
}

static void testAccessRandomNumbers() {
    std::vector<int> numElements{ 2, 4, 8, 16, 64, 256, 512, 1024, 2048, 4096, 65536 };

    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    std::vector<std::vector<double>> listInsertionTimes{};
    std::vector<std::vector<double>> setInsertionTimes{};
    std::vector<std::vector<double>> vectorInsertionTimes{};

    int numEle;

    double milli;
    double micro;
    double nano;

    // forcing the data into this memory locaiton so it doesn't get optimized away
    int* hold = new int();

    // Test list insertion
    for (const auto& currMaxEle : numElements)
    {
        std::uniform_int_distribution<> distrib(0, currMaxEle);
        std::vector<int> randomElements;
        int randPos;
        for (int i = 0; i < currMaxEle; i++) {
            randPos = distrib(gen);
            if (randPos >= currMaxEle)
                randPos = currMaxEle - 1;
            randomElements.emplace_back(randPos);
        }
        // Test list insertion
        numEle = 0;
        {
            std::list<int> myList;

            std::list<int>::iterator iter;
            for (; numEle < currMaxEle; numEle++)
            {
                iter = myList.end();
                myList.insert(iter, numEle);
            }

            begin = std::chrono::steady_clock::now();
            for (const int& i : randomElements)
            {
                iter = myList.begin();
                std::advance(iter, i); // derefrence it for the value at that position I am considering this the same as accessing
                *hold = *iter;
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            listInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test set insertion
        numEle = 0;
        {
            std::set<int> mySet;
            for (; numEle < currMaxEle; numEle++)
            {
                mySet.insert(numEle);
            }
            begin = std::chrono::steady_clock::now();
            std::set<int>::iterator iter;
            for (const int& i : randomElements)
            {
                iter = mySet.begin();
                std::advance(iter, i); // derefrence it for the value at that position I am considering this the same as accessing
                *hold = *iter;
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            setInsertionTimes.push_back({ milli, micro, nano });
        }

        // Test vector insertion
        numEle = 0;
        {
            std::vector<int> myVector;
            std::vector<int>::iterator iter;
            for (; numEle < currMaxEle; numEle++) {
                iter = myVector.end();
                myVector.insert(iter, numEle);
            }
            begin = std::chrono::steady_clock::now();
            for (const int& i : randomElements)
            {
                *hold = myVector[i]; // Accessing the element and doing nothing with it
            }
            end = std::chrono::steady_clock::now();
            milli = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
            micro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            nano = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
            vectorInsertionTimes.push_back({ milli, micro, nano });
        }
    }

    delete(hold);

    {
        int pos = 0;
        std::cout << "Accessing with ordered Elements\n";
        std::cout << "List::Accessing\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : listInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nSet::Accessing\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : setInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
    {
        int pos = 0;
        std::cout << "\nVector::Accessing\n";
        std::cout << "Number of Elements: Milliseconds || Microseconds || Nanoseconds ||\n";
        for (std::vector<double> i : vectorInsertionTimes)
        {
            std::cout << std::right << std::setw(17) << numElements[pos++] << " > ";
            printTimes(i);
        }
    }
}
