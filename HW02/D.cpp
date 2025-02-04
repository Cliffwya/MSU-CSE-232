#include <iostream>
using namespace std;

int main() {
    int value1{0};
    int value2{0};
    int value3{0};

    while(cin >> value1 >> value2 >> value3) {//input till EOF
        int diff1{0};
        int diff2{0};
        int diff3{0};

        if (value1 > value2) { //the following if and else statements comapre each inputed value to find a non negitive difference
            diff1 = value1 - value2;
        } 
        else {
            diff1 = value2 - value1;
        }

        if (value2 > value3) { //find the 2nd smallest value
            diff2 = value2 - value3;
        } 
        else {
            diff2 = value3 - value2;
        }

         if (value1 > value3) { //find the 3rd smallest value
            diff3 = value1 - value3;
        } 
        else {
            diff3 = value3 - value1;
        }



        int smallest_diff = min(diff1, min(diff2, diff3));//found how to use min using StackOverFlow. Takes two paramters and finds the smallest. min also has an optional 3rd parameters. uses std library

        cout << "The smallest diff of " << value1 << ", " << value2 << ", and " << value3 << " is " << smallest_diff << "." << endl;//prints the smallest
    }
}
