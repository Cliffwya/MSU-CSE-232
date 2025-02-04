#include "func.hpp"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <cctype>

std::set<std::string> ReplacementCensor(std::istream& is, std::ostream& os, const std::map<std::string, std::string>& values) {
    std::set<std::string> replaced_keys;
    std::string line;
    while (std::getline(is, line)) {  //Index through each line rom the istream
        std::string new_line;  //Returned line
        size_t pos = 0;
        while (pos < line.size()) {  //Index through the last word of the line
            bool replaced = false;  
            for (const auto& pair : values) {  //For each pair in the map 
                std::string key = pair.first;  //Grab the key from the pair
                std::string value = pair.second;  //Grab the value from the pair
                std::string lowercase_key = key;  
                std::transform(lowercase_key.begin(), lowercase_key.end(), lowercase_key.begin(), ::tolower);  //Transform the key to lowercase
                std::string lowercase_substr = line.substr(pos, lowercase_key.size());  
                std::transform(lowercase_substr.begin(), lowercase_substr.end(), lowercase_substr.begin(), ::tolower);  //Transfor the substring to all lower
                if (lowercase_substr == lowercase_key /*||lowercase_key==lowercase_substr.find(lowercase_key)*/) {  //If the key is equal to lower case key
                    new_line += value;  //Add the key to the string
                    replaced_keys.insert(line.substr(pos, key.size()));  //Add to the replaced line
                    pos += key.size();  //Index through the size
                    replaced = true;
                    break;
                }
            }
            if (!replaced) {
                new_line += line.at(pos);
                ++pos;
            }
        }
        os << new_line;
    }
    return replaced_keys;
}