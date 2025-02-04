#include <iostream>
#include <string>
using namespace std;

//index through each line and output number of a's for each line 

int main(){
    string input;
    int count{0};
    while(getline(cin,input)){
        for(int i=0;i != '\n';i++){
            if(input.at(i)=='a')
            ++count;
        }
        cout << count;
    }
}