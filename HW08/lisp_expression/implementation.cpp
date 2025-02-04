#include "header.hpp"
#include <string>
#include <vector>
#include <sstream>
//#include <ostream>
#include <iostream>

std::string LispExpression::get_lisp_string() const{
    return lisp_string;
}

std::string format_with_indents(const std::vector<std::string>& input, int indents) {
    std::stringstream formatted;
    for (const std::string& word : input) {
        if (word == "(") {
            formatted << std::string(indents, ' ') << word << std::endl;
            indents += 1;
        } else if (word == ")") {
            indents -= 1;
            formatted << std::string(indents, ' ') << word << std::endl;
        } else {
            formatted << std::string(indents, ' ') << word << std::endl;
        }
        if(indents==0) return formatted.str();
    }
    return formatted.str();
}

std::string LispExpression::PrettyPrint()const{
    std::stringstream ss(lisp_string);
    std::vector<std::string> input_words;
    std::string word;

    while(ss>>word){
        input_words.push_back(word);
    }

    return format_with_indents(input_words,0);
}
