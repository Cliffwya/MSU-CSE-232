#include <iostream>
#include <vector>
#include <string>

using namespace std;

string secret_word(const vector<string>&words){  //Gets the secret word
    cout << "Give me a secret word: "<<endl;
    return words.at(0);
}

vector<string> player_guess(const vector<string>& words){  //Process each player guess one at a time
    cout << "Give me a guess: " << endl;
    vector<string> guesses(words.begin()+1,words.end());
    return guesses;
}

bool valid_guess(const string &guess){  //With the input of the guess check to see if the size of the word is = to 5
    return guess.size() == 5;
}

void update_corr_pos(string &feedback, string &secret, const string &guess){
    for(size_t i{0};i < 5; ++i){ //Loop through each char in the guess
        if(guess.at(i)==secret.at(i)){  //if the char is equal to the secret word at that pos update the word with the correct char
            feedback.at(i) = guess.at(i); //The feedback is update to the guess char at that pos
            secret.at(i)= '+';  //secret word is updated with a space so it doesnt get messed with anymore
        }
    }
}

void update_incorr_pos(string &feedback, string &secret, const string &guess){

    for(size_t i{0};i<5;++i){ //Starts the same at corr pos
        if(feedback.at(i)=='.'){ //checks with char that are '.' or like still needed feecback
            for(size_t j{0};j <5;++j){//another for loop needed because where that position that needs feedback we check with the other pos in secret word
                if(guess.at(i)==secret.at(j) && secret.at(j)!='+' && feedback.at(j) != guess.at(j)){
                    feedback.at(i)='?';//incorrect placement
                    //secret.at(j)='+'; //same as the corr pos
                    break;
                }
            }
        }
    }
}

string update_game(const string& secret, const string& guess){
    string feedback{"....."}; //just starts with an empty feedback string so we can check all the positons first
    string starting_secret{secret};  //gets the secret word
    update_corr_pos(feedback,starting_secret,guess);//both updates . corr goes first to check if they got it right first
    update_incorr_pos(feedback,starting_secret,guess);
    return feedback;
}

bool process_guess(const string& secret, const string& guess){
    if(!valid_guess(guess)){
        return false; //not a valid guess dont check for win con
    }
    string feedback{update_game(secret,guess)};
    cout << feedback << endl; //update the feedback
    return feedback == secret; //return the win cond
}

void play_game(const vector<string> & words){
    string secret{secret_word(words)};  //grabs the secret word
    vector<string> guesses{player_guess(words)};  //grabs the players guesses
    int attempt{0};
    for (const string & guess : guesses) {  //for all the guesses in player guesses
        if (attempt >= 6) break;  //if we attempt more than 6 times break the code
        if (process_guess(secret, guess)) {  //check win con
            cout << "You Win!" << endl;
            return;
        }
        ++attempt;  //no win add an attempt
        if(attempt <6){
            cout<<"Give me a guess: "<<endl;
        }
    }
    cout << "You Lose." << endl;  //else lose
}

int main(){
    string input;
    vector<string> words;
    while (cin >> input) {
        words.push_back(input);
    }
    play_game(words);
    return 0;
}