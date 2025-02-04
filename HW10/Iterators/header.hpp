#pragma once 
#include <vector>

std::vector<int>::const_iterator FindSmallestIndexRange(const std::vector<int>&vector,int index_start,int index_end);

template <typename T>
void DoubleIteratorRange(T index_start,T index_end){
    for(T iterator{index_start};iterator != (index_end-1);++iterator){  //Loop through each value given the iterators. Doesnt go one past the end
        *iterator *=2;  //Time the value at that iterator by 2
    }
}