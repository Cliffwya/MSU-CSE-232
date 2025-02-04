/* If repeat is called with an int, it should return the int doubled. If it is called with a char, 
it should return a string with that char used twice. 
If it is called with a string, it should return that string repeated twice 
(with a space character separating the two copies).*/
#include "header.hpp"
#include <iostream>
#include <string>

int Repeat(int number){
    return number*2;
}

std::string Repeat(char character){
    std::string new_string{};
    new_string.push_back(character);
    new_string.push_back(character);
    return new_string;
}

std::string Repeat(std::string word){
    return word + " " + word;
}