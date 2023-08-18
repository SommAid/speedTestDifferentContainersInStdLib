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
public:

private:
	std::vector<int> randomElements;

	template<typename T>
	static void insertElements(T container);
	static void printTimes(const std::vector<double>& times);
};

