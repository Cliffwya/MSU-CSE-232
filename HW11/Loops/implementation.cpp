#include "header.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <iterator>
#include <iostream>
#include <sstream>

void SortByUppercase(std::vector<std::string>&list){
    std::sort(list.begin(),list.end(),[](const std::string&left, const std::string &right){
        std::string upper_left,upper_right;
        std::copy_if(left.begin(),left.end(),std::back_inserter(upper_left), [](char ch){
            return std::isupper(static_cast<unsigned char>(ch));
        });
        std::copy_if(right.begin(),right.end(),std::back_inserter(upper_right), [](char ch){
            return std::isupper(static_cast<unsigned char>(ch));
        });
        return upper_left < upper_right;
    });
}

std::string DoubleToPercentString(const std::vector<double>&list){
    std::vector<std::string> converted(list.size());
    std::transform(list.begin(),list.end(),converted.begin(),[](double number){
        int percentage{static_cast<int>(number*100)};
        return std::to_string(percentage)+"%";
    });

    std::ostringstream all_string;  //Puts them all into one string
    std::copy(converted.begin(),converted.end(), std::ostream_iterator<std::string>(all_string, " "));
    std::string final{all_string.str()};
    final.pop_back();
    return final;
}

int main(){
  return 0;
}