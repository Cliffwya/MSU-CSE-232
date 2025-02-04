#include <iostream>
#include "header.hpp"

int main() {
	int size = 7;
	double source[] = {10.5, 7, 14, 0, 67, -4, 13};
	double destination[7] = {};
	CopyStockPrices(source, destination);
	for (int i = 0; i < size; ++i) {
		std::cout << destination[i] << std::endl;
	}
	return 0;
}