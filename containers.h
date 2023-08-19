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
	std::vector<int> randomElements;

	std::set<int> mySet;
	std::list<int> myList;
	std::vector<int> myVector;

public:
	containers();

	template <typename T>
	void generateAccessNumbers(int numNumbers, T container);
	void setRandomNumbers(const std::vector<int>& nums);
	static void printTimes(const std::vector<double>& times);

	// Override these in their appropriate classes
	virtual void testInsertChronological() = 0;
	virtual void testInsertRandom() = 0;
	virtual void testAccessRandom() = 0;


};
