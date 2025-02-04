/*In the file ScaryMultiples/main.cpp, you need to 
write function named SumButScared that takes a vector
of integers. It returns an int which is the sum of 
those integers. However, if any of the integers are 
multiples of 13, an invalid_argument exception should 
be raised, you can supply whatever error message you want.*/

#include <iostream>
#include <vector>
#include <stdexcept>

int SumButScared(std::vector<int> const & input){
    int sum_of_ints{0};
    for(int i : input){
        if(i%13==0){
            throw std::invalid_argument("Not a multiple of 13");
        }
        sum_of_ints += i;
    }
    return sum_of_ints;
}