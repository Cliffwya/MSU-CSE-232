//Penultimate.cpp
#include "Penultimate.hpp"
#include <iostream>
#include <string>


std::string Penultimate::push_back(const std::string &added_string){
    std::string final_string{last_string};
    last_string = added_string;
    return final_string;
}