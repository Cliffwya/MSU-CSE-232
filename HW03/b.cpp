#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string input;
    vector<char> new_string;
    char previous_char{' '};

    while(getline(cin,input)){
        for(char i : input){  // Index through each char in string 'input'
            if(i>previous_char){
                new_string.push_back(i);
                previous_char = i;
                continue;
            }else{
                previous_char = i;
                new_string.push_back('_');
                continue;
            }
        }
        for(char j : new_string){
        cout<<j;
        }
        cout<<endl;
        new_string.clear();
    }
 
    return 0;
}