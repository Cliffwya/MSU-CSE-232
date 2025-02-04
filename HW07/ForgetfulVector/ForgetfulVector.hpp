#pragma once

#include <iostream>
#include <vector>

class ForgetfulVector{
    private:  //Declares needed data
        std::vector<int> remembered_values;
        std::vector<int> seen_values;

    public:
        // no constructor needed because we dont init. with anything. all classes have a "private" included const so i dont declare it
        // below are the methods explained
        void push_back(int value);  //adds to back
        int at(size_t pos); //returns the value at pos
        size_t size();  //returns size

};