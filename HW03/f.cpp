#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;

  while (getline(cin, input)) {
    string final_word;
    string working_word;

    for (char c : input) {  // for each char in input
      if (isalpha(c) || isdigit(c) || ispunct(c)) { // if its anything besides space or newline add it to the working word
        working_word += c;
      } else{
        if (static_cast<int>(working_word.length()) >= 5) {  // if the word is greater is greater than or equal to 5 add it to the new final word and clear the new working word
          final_word += working_word;  // Here we add the working word to the final word
          final_word += ' ';  // Add a space inbetween the words in the vector
        }
        working_word.clear();  // cler the working word
      }
    }
    if (static_cast<int>(working_word.length()) >= 5) { // Does the same thing as the previous if statement but checks for the final word
            final_word += working_word;
            final_word += ' ';  // Add a space inbetween the words in the vector
        }
    cout << final_word << endl;  //print the final words
  }

  return 0;
}
