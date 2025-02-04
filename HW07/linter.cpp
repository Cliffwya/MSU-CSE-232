#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

// WRITE YOUR CODE HERE


bool myLinter(std::istream &file) {
    int bracket{0};
    int parenth{0};
    std::string line;

    while (std::getline(file, line)) {
        size_t first_character{0};
        while (first_character < line.size() && std::isspace(line.at(first_character))) {  //looks for first non-whitespace character in each line
            ++first_character;
        }

        if (first_character == line.size()) {  //If its an empty line continue because its valid
            continue;
        }

        if (line.at(first_character) != 'S') {  //Checks to see if the first other than the whitespace is an 'S'
            return false;
        }

        char last_character = line.at(line.size() - 1);  //set the last character to the size of the line - 1
        if (last_character != ';' && last_character != '{' && last_character != '}' && last_character != '(' && last_character != ')') {  //Checks to see if the last char is valid with one of the char shown before hand
            return false;
        }

        for (size_t i = 0; i < line.size(); ++i) {  //Iterate through and the line size
            char ch = line.at(i);  //Keeps a count of the total amount of {} and () so we can compare later to make sure theres no open or closed brackets/paren.
            if (ch == '{') {  //Add for open bracket
                ++bracket;
            } else if (ch == '}') {  //Minus for close showing its complete
                --bracket;
            } else if (ch == '(') {  //Same as bracket just ()
                ++parenth;
            } else if (ch == ')') {
                --parenth;
            }

            if (bracket < 0 || parenth < 0) {  //If the count ever becomes negative showing theres too many } return false 
                return false;
            }
        }
    }

    return bracket == 0 && parenth == 0;  //Gives true or false if both {} and () are closed completely
}

int main() {
  // provided for your testing convenience
  return 0;
}