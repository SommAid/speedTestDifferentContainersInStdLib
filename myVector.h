#pragma once
#include "containers.h"
class myVector : protected containers
{
private:
	std::vector<int> testVector;

public:
	void testInsertChronologicalNumbers();
	void testInsertRandomNumbers();
	void testAccessRandomPositions();

};

