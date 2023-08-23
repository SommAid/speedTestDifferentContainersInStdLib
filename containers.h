#pragma once

#include <list>
#include <set>
#include <vector>

#include <iostream>
#include <iomanip>
#include <string>

#include <random>
#include <chrono>

class containers
{
protected:
	std::vector<int> sizes;

	std::vector<std::vector<double>> times;

	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	void printTimes();
public:
	containers();	

	// Override these in their appropriate classes
	virtual void testInsertChronologicalNumbers() = 0;
	virtual void testInsertRandomNumbers() = 0;
	virtual void testAccessRandomPositions() = 0;


};
