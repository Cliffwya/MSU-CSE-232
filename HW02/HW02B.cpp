#include <iostream>

using namespace std;

int main(){

    int character;
    int total{0};

    while(cin>> character){
        total += character;
    }
    cout << total << endl;
    return 0;
}