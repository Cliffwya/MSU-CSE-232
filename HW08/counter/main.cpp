#include <iostream>
#include "header.hpp"

int main() {
	Counter c(6);
	std::cout << c.Value() << std::endl; // Prints 6
	std::cout << c.Value() << std::endl; // Prints 5
	return 0;
}