//wordList.hpp
#include "WordList.h"
#include <iostream>
#include <string>
#include <cctype>

bool AtListPosition(const std::string & word_list, const std::string & single_string, size_t pos){
    std::string working_word{};
    if(pos>word_list.size()){  //If out of index return false
        return false;
    }
    if (word_list.substr(pos, single_string.size()) == single_string) {  //takes a substring from pos with the size of the input string and checks to see if its equal to the single string. Substring guide was used in the following link: https://www.geeksforgeeks.org/substring-in-cpp/
        if (pos == 0 || word_list.at(pos - 1) == ',') {  //Checks to see if its the starting position or if the position is following a comma
            if (pos + single_string.size() == word_list.size() || word_list.at(pos + single_string.size()) == ',') { //Checks if the position plus the word size is equal to the word list size or the word list at the pos + word length is equal to a comma
                return true;
            }
        }
    }
    return false;
}

size_t FindInList(const std::string & word_list, const std::string & single_string, size_t pos=0){   //Default value given to pos if not given a value 
    for(size_t i{pos};i<word_list.size();++i){  //starting at the position index through the list of words
        if(AtListPosition(word_list,single_string,i)){  //If AtListPosition is true given the word list, single string, and the current index return true
            return i;
        }
    }
    return std::string::npos; //If the string could not be found return a npos

}


std::string GetFirstInList(const std::string & word_list, std::string * word1, std::string * word2){
    size_t word1_pos = FindInList(word_list,*word1);  //Position of word one 
    size_t word2_pos = FindInList(word_list,*word2);  //Position of word two

    if(word1_pos < word2_pos){  //If word one pos is closer to the start return it
        return *word1;
    } if(word2_pos < word1_pos){  //If word two pos is closer to the start return it
        return *word2;
    } else{
        return "N/A";  //Else return N/A if NPOS or equal or other reasons
    }

}

size_t CountInList(const std::string & word_list, const std::string & single_string){
    size_t total_count{0};  //Set the total count of word apperances to 0
    size_t position{FindInList(word_list,single_string)};  //Set position equal to the first word apperance

    while(position!=std::string::npos){ //Loop till we get a npos 
        ++total_count; //Add for each apperance. Already at one for the first pos set
        position=FindInList(word_list,single_string,position+single_string.size());  //Update the new pos given the current pos plus the length of the given word
    }

    return total_count;  //Return the total counts
}