//Penultimate.hpp
#pragma once

#include <iostream>
#include <string>

class Penultimate{
    private:
    std::string last_string;

    public:
        Penultimate(const std::string &input): last_string(input){}
        std::string push_back(const std::string &added_string);

};