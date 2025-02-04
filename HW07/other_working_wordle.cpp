#include <iostream>
#include <string>

using namespace std;

bool end_game(const string &secret_word, const string &guess, int guess_count) {  //Checks for endgame state, either lose or win 
    if (guess == secret_word) {
        cout << "You Win!" << endl;
        return true; // Game ends with a win
    } else if (guess_count >= 6) {
        cout << "You Lose." << endl;
        return true; // Game ends with a loss
    }
    return false; // Game continues
}

void process_guess(const string &secret_word, string &guess) {
    for (size_t i = 0; i < secret_word.size(); ++i) {  //CHecks to see for correct words in the first loop
        if (guess.at(i) == secret_word.at(i)) {  //if correct keep pos
            continue;
        } else {
            bool letter_found = false;
            for (size_t j = 0; j < secret_word.size(); ++j) {  //checks for any incorrect placements
                if (guess.at(i) == secret_word.at(j)) { //Letter is present but in the wrong position
                    guess.at(i) = '?';
                    letter_found = true;
                    break; //exit loop after finding a match
                }
            }
            if (!letter_found) { //letter not found it word
                guess.at(i) = '.';
            }
        }
    }
    cout << guess << endl; //Show the modified guess
}

void get_secret_word(string &secret_word) {  
    cout << "Give me a secret word: " << endl;
    cin >> secret_word;
}

void get_guess(string &guess) {  //gets player guesses
    cout << "Give me a guess: " << endl;
    getline(cin,guess);
}

bool valid_guess(const string &guess){
    return guess.size() == 5;
}

void game_loop(const string &secret_word) {  //loop that plays the game
    bool end_game_flag{false};
    int count{0};
    string guess;

    while (count < 6) {  //loops till we hit 6 guesses and its not the end game
        get_guess(guess);  //get player guess
        if(!valid_guess(guess)||guess.empty()||cin.eof()){
            cout<< "You Lose."<<endl;;
            break;
        }
        process_guess(secret_word, guess);  //process it
        ++count; //++ count for amount of guesses
        end_game_flag = end_game(secret_word, guess, count);  //checks for end game
        if(end_game_flag) break;
    }
}

int main() {  //init everything 
    string secret_word;
    get_secret_word(secret_word);
    cin.ignore();
    game_loop(secret_word);
    return 0;
}
