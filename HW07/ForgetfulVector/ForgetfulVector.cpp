#include "ForgetfulVector.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>

size_t ForgetfulVector::size(){
    return remembered_values.size();  //returns the size
}

int ForgetfulVector::at(size_t pos){
    return remembered_values.at(pos);  //returns the at pos value
}

void ForgetfulVector::push_back(int value){
    if(std::find(seen_values.begin(),seen_values.end(),value)!=seen_values.end()){ //checks to see if the value in the input of pushback is in the seen_values
         remembered_values.push_back(value);  //add to the rem. alues
    } else{
        seen_values.push_back(value);  //else add to the seen values
    }
}