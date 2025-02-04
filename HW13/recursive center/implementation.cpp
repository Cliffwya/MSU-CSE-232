#include "header.hpp"
#include <list>
#include <iterator>

int center(std::list<int>::const_iterator start, std::list<int>::const_iterator end){
    size_t distance = std::distance(start,end);  //Use the STL to find the distance between the two
    if (distance == 1) return *start;  //If there distance is one return the iterator derferanced (val)
    return center(++start,--end);  //Call recursively one over to the right of start and one to the left of end
}