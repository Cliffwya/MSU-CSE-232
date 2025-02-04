#include "header.hpp"
#include <vector>

std::vector<int>::const_iterator FindSmallestIndexRange(const std::vector<int>&vector,int index_start,int index_end){
    if(index_end>=static_cast<int>(vector.size())) index_end = vector.size()-1;  //Makes sure the index is in range of the iterator
    std::vector<int>::const_iterator min_iterator{vector.cbegin()+index_start};  //Makes the lowest value for starting pos
    for(int start{1+index_start};start<=index_end;++start){  //Iterate through the vector
        if(vector.at(start)<(*min_iterator)) min_iterator = vector.cbegin() + start;  //Sets the new min iterator
    }
    return min_iterator;
}



int main(){return 0;}