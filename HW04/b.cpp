#include <string>
#include <cctype>

using namespace std;

void To_Digits(string & input) {  //Void referance so it wont return anything but rather update without creating a copy
    string final_Word;  //final word we replace new_string with
    size_t i = 0; //size instead of int so i dont need to static cast with .size()

    string new_string{};
    for(size_t i {0}; i < input.size();++i){  //To make each each char lowercase to change
        new_string.push_back(tolower(input.at(i)));
    }

    while (i < new_string.size()) {
        if (new_string.substr(i, 4) == "zero") {  // Using Substr I am able to find if the following letters are in the string so I am able to replace them with the numbers. Takes from the current index and moves to the length of the word to check if its that long to replace
         final_Word += "0";
            i += 4;   //Update index after replacing the word with the number. Same is used for the all number 0-9
        } else if (new_string.substr(i, 3) == "one") {  // https://cplusplus.com/reference/string/string/substr/  used cpp referance to learn how to use substr
         final_Word += "1";
            i += 3;
        } else if (new_string.substr(i, 3) == "two") {
         final_Word += "2";
            i += 3;
        } else if (new_string.substr(i, 5) == "three") {
         final_Word += "3";
            i += 5;
        } else if (new_string.substr(i, 4) == "four") {
         final_Word += "4";
            i += 4;
        } else if (new_string.substr(i, 4) == "five") {
         final_Word += "5";
            i += 4;
        } else if (new_string.substr(i, 3) == "six") {
         final_Word += "6";
            i += 3;
        } else if (new_string.substr(i, 5) == "seven") {
         final_Word += "7";
            i += 5;
        } else if (new_string.substr(i, 5) == "eight") {
         final_Word += "8";
            i += 5;
        } else if (new_string.substr(i, 4) == "nine") {
         final_Word += "9";
            i += 4;
        } else {
         final_Word += new_string.at(i); //If its not a number continue essentially
            ++i;
        }
    }
    input = final_Word;  // Because its void im changing the new_string rather than return
}
