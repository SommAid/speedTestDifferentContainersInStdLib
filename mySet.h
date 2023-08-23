#pragma once
#include "containers.h"

class mySet : protected containers{
private:
    std::set<int> testSet;
public:
    void testInsertChronologicalNumbers();
    void testInsertRandomNumbers();
    void testAccessRandomPositions();
};

