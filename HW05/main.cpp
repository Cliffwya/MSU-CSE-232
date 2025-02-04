#include "WordList.h"
#include <iostream>
#include <string>


int main(){
    std::string word1, word2, word_list;

    std::cin >> word1 >> word2; //Input the keywords used

    while (std::getline(std::cin, word_list)) {  //Loop for each list of words until EOF
        if(word_list.empty()){  //If the word list is empty skip past that line
            continue;
        }
        int count1 = CountInList(word_list, word1);  //Count in the list of word 1
        int count2 = CountInList(word_list, word2);  //Count in the list of word 2
        std::string first_word = GetFirstInList(word_list, &word1, &word2);  //Find the first word encountered

        std::cout << first_word << " " << count1 << " " << count2 << std::endl;  //Print the count of the word
    }

    return 0;
}