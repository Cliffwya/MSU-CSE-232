#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <ranges>
#include <random>

// WRITE YOUR CODE HERE

std::vector<int> SampleWithReplacement(std::vector<int> const & population, int n, std::uint64_t seed){
    std::mt19937_64 engine(seed);  //Use the engine with the given seed
    std::uniform_int_distribution<size_t> distribution(0,population.size()-1);  //Takes from the population sample. Size is one past
    std::vector<int> sample(n);  //Declare the size
    std::generate(sample.begin(),sample.end(),[&](){
        return population.at(distribution(engine));  //Generate a sample given a random pos in the population 
    });
    return sample;
}

int main() {
	std::vector<int> const population = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5};
	std::vector<int> sample = SampleWithReplacement(population, 20, 123);
  //std::ranges::copy(sample, std::ostream_iterator<int>(std::cout, " "));
  // 4 5 5 5 2 2 5 3 5 5 3 5 1 5 5 5 5 5 4 5 

}
