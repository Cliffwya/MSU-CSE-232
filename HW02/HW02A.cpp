#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    getline(cin,input); //User input and takes all spaces and includes it into one string

    int count{0};

    for( int i=0; i<input.size();i++){ //Index through the entire length of the input using .size()
        if(input[i]=='M' || input[i]=='S' || input[i]=='U'){ //if char is M,S,U add one to the total count
            count += 1;
            continue;
        }
        else if(input[i]=='.')//Break code at '.'
        break;

    }
    cout << "The count of letters (MSU) is " << count << '.'<< endl;//print final count
}