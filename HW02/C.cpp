#include <iostream>
#include <string>
using namespace std;

int convert(int value, string unit){//converts the string all into mm and returns the new value. Returns the originall mm value if its in mm
    if(unit=="cm")
        return value*10;
    if(unit=="m")
        return value*1000;
    if(unit=="km")
        return value*1000000;
    else
        return value;
}

int main(){
    int value1{0};
    int value2{0};
    string unit1;
    string unit2;

    while(cin >> value1 >> unit1 >> value2 >> unit2){//Goes through the entire inputs and ends when no more characters are entered 
        int distance1 = convert(value1, unit1); //Runs the convert function for both and assigns it into a new variable so we can compare values
        int distnace2= convert(value2,unit2);

        if(distance1== distnace2) //Prints the end statement
            cout << value1 << unit1 << " is the same as " << value2 << unit2<< endl;
        else if(distance1 < distnace2)
            cout << value1 << unit1 << " is the smaller than " << value2 << unit2<< endl;
        else
            cout << value1 << unit1 << " is larger than " << value2 << unit2<< endl;
    }
}