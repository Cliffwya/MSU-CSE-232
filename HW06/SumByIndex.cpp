#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> SumByIndex(const std::vector<std::vector<int>> & input_2d){
    size_t max{0};

    for(size_t i{0}; i < input_2d.size(); ++i){  //Index through each item in vector (i)
        max = std::max(max,input_2d.at(i).size());  //If the size of each vector (i) is larger than the current vector set it to the new max. Used so we dont index out of bounds with .at()
    }

    std::vector<int> sum_of_2d(max,0);

    for (size_t i{0}; i < input_2d.size(); ++i){  //Index through each vector in the vector (i)
        for (size_t j{0}; j < input_2d.at(i).size(); ++j){   //Index through the ints in vector i
            sum_of_2d.at(j) += input_2d.at(i).at(j);  //Append to the returned vector from location x,y on the 2d vector
        }
    }

    return sum_of_2d;
}