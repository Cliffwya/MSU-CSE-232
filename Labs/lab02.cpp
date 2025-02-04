#include <iostream>
using namespace std;

int main() {
    int input;

    while (cin >> input) {
        if (input < 0) {
            break;  
        }
        int persistence = 0;      
        while (input > 9) {
            int total = 0;
            int new_num = input;
            while (new_num > 0) {
                total += new_num % 10;  
                new_num /= 10;        
            }

            input = total;  
            persistence++;  
        }
        cout << persistence << " " << input << endl;
    }
    
    return 0;
}
