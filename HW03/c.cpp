#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string input;
    vector<char>new_string;
    bool can_print{true};
    while(getline(cin,input)){
       for(char c:input){
        if(isalpha(c) && can_print==true){
            new_string.push_back(c);
            can_print=false;
        }
        if(!isalpha(c)||isblank(c)){
            can_print=true;
            continue;
        }
       }
    }
    for(char j : new_string){
        cout<<j;
        }
        cout<<endl;

    return 0;
}

