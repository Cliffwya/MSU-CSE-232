#include <iostream>

using namespace std;


int Triple(int number){
    return number*3;  //returns number trippled
}

int Closest_Multiple_Of_13(int number){
    int lower_number {0};
    int higher_number {0};
    int remainder {0};
    if((number%13)==0){ //if its already a multiple
        return number;
    } else{
        if (number>0){ //for positive numbers
            remainder = number%13; //finds the remainder of the number to find the closest multiple 
            lower_number = number - remainder;  //finds the smallest closest multiple
            higher_number = (number-remainder)+13; //finds the higer closest multiple

            if ((higher_number-number) > (number-lower_number)) //returns the closest multiple of either the higher or smaller 
                return lower_number;
            else
                return higher_number;
        } else{  //for negative numbers
            number *= -1;
            remainder = number%13; //finds the remainder of the number to find the closest multiple 
            lower_number = number - remainder;  //finds the smallest closest multiple
            higher_number = (number-remainder)+13; //finds the higer closest multiple

            if ((higher_number-number) > (number-lower_number)){ //returns the closest multiple of either the higher or smaller 
                lower_number *= -1;
                return lower_number;
            }
            else{
                higher_number *= -1;
                return higher_number;
            }
        }
    }
}

int main(){
    int input{0};

    cin >> input;  //input number
    cout << input *2;  //returns the double of number

    return 0;
}