#include "func.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
std::vector<T> MaxVector(const std::vector<T>&vector1, const std::vector<T>&vector2) {
    std::vector<T> max_vector(std::max(vector1.size(), vector2.size()));
    std::transform(vector1.begin(), vector1.end(),vector2.begin(),max_vector.begin(),[&vector2](const T&first, const T&second) {  //Iterate through eachelement on vector one and 2 and start adding to max_vector
        return ((&second >= &vector2.at(0)) && (&second < &vector2.at(0) + vector2.size())) ? std::max(first,second) : first; //Return the largest of the two values
    });
    if (vector1.size() < vector2.size()) {  //If vec2 larger than vec 1
        std::copy(vector2.begin() + vector1.size(), vector2.end(), max_vector.begin() + vector1.size());  //Copies the additional elments on to max_vector
    } else if (vector2.size() < vector1.size()) {  //Vise versea
        std::copy(vector1.begin() + vector2.size(), vector1.end(), max_vector.begin() + vector2.size());  //Copies the additional elements 
    }

    return max_vector;
}