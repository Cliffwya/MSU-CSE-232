// WRITE YOUR CODE HERE

#include <iostream>

#include <string>

 

void CheckForWin(std::string & secret_word, std::string & guess, bool & end_game, int & guess_count) {

  if (guess == secret_word) {

    std::cout << "You Win!" << std::endl;

    end_game = 1;

  }

  else if (guess != secret_word && guess_count != 6) {

    end_game = 0;

  }

  else {

    std::cout << "You Lose." << std::endl;

    end_game = 1;

  }

}

 

int main() {
  std::string secret_word;
  std::cout << "Give me a secret word: " << std::endl;
  std::cin >> secret_word;
  std::string guess;
  bool end_game{0};
  int count{0};
  std::cout <<  "Give me a guess: " << std::endl;
  
  while (std::cin >> guess) {
    int index{0};
    for (char & letter : guess) {
      bool letter_changed{0};
      if (letter != secret_word.at(index)) {
        for (size_t i{0}; i < secret_word.size(); i++) {
          if (letter == secret_word.at(i)) {
             letter = '?';
             letter_changed = 1;
          }
        }
      }
      if (!letter_changed && letter != secret_word.at(index)) letter = '.';
      ++index;
    }

    std::cout << guess << std::endl;
    ++count;
    CheckForWin(secret_word, guess, end_game, count);
    if (end_game) break;
    std::cout <<  "Give me a guess: " << std::endl;
  }
  if (std::cin.eof() && !end_game) {
        std::cout << "You Lose." << std::endl;
      }
}