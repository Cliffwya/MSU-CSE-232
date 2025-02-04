#include <iostream>
using namespace std;

int main() {
    int input;

    while (cin >> input) {
        if (input < 0) {
            break;  
        }    
        while (input > 99) {
            int total = 0;
            int new_num = input;
            while (new_num > 0) {
                total += new_num % 100;  
                new_num /= 100;        
            }

            input = total;  
        }
        cout << input << endl;
    }
    
    return 0;
}
