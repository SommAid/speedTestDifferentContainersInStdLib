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
	std::vector<int> randomElements;

	std::set<int> testSet;
	std::list<int> testList;
	std::vector<int> testVector;

	std::vector<std::vector<double>> times;

	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;

	void printTimes();
public:
	containers();

	template <typename T>
	void generateAccessNumbers(int numNumbers, T container);
	void setContainerListSize(const std::vector<int>& nums);
	

	// Override these in their appropriate classes
	virtual void testInsertChronologicalNumbers() = 0;
	virtual void testInsertRandomNumbers() = 0;
	virtual void testAccessRandomPositions() = 0;


};
