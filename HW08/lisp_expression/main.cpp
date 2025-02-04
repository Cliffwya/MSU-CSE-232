#include <iostream>
#include "header.hpp"

int main() {
	LispExpression le(" (  one two ( three )   ) ");
	std::cout << le.PrettyPrint();

	return 0;
}