#include <string>
#include <vector>
#include <cassert>

#include "counter.hpp"

int main() {
	std::vector<std::string> names = {"A Game of Thrones", "A Clash of Kings", 
		"A Storm of Swords", "A Feast for Crows", "A Dance with Dragons", 
		"The Winds of Winter", "A Dream of Spring"};
	std::vector<int> exception_count = CountExceptions(names);
	std::vector<int> expected = {1, 0, 2};
	assert(exception_count == expected);
	return 0;
}