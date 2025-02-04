// WRITE YOUR CODE HERE
#include "header.hpp"
#include <vector>
#include <valarray>
#include <iostream>
#include <numeric>
#include <algorithm> 
#include <ranges>
#include <complex>
#include <iterator>

void MakeComplex(std::valarray<std::complex<int>>& numbers){
    const std::complex<int> complexified (0,1);
    std::transform(std::begin(numbers), std::end(numbers), std::begin(numbers), [&](const std::complex<int>&current){
        return current.imag() == 0 ? complexified : current;
    });
}


int SumOfOdd(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end){
    int sum = std::accumulate(start,end, int{0}, [](int total, int value){
        return total + (value % 2 == 0 ? 0 : value);
    });
    return sum;
}

int main() {
	std::vector<int> const numbers = {1, 2, 3, 4, 5, 6, 8, 5, 2, 2, 5, 101};
	std::cout << SumOfOdd(numbers.cbegin(), numbers.cend()) << std::endl;
	std::cout << SumOfOdd(numbers.begin(), numbers.end()) << std::endl;

  std::valarray<std::complex<int>> complex_numbers = {{{1, 2}, {3, 0}, {0, 7}, {-45, -68}}};
  MakeComplex(complex_numbers);
  //std::ranges::copy(complex_numbers, std::ostream_iterator<std::complex<int>>(std::cout, " "));
  // (1,2) (0,1) (0,7) (-45,-68)

}
