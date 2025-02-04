#include "header.hpp"
#include <vector>

template <typename T>
std::vector<T> ArrayToVector(T*source,size_t expected){
    std::vector<T> vector(source,source+expected);  //Create new vector of types thats the size of source with the values of source +size
    delete[] source;  //Delete the allocated memory
    return vector;  //return value of vector
}