#include <iostream>
//#include "temperature.cpp" // LAter you will be taught better ways to include files */
using namespace std;


/*The first parameter is a double representing a temperature, the second parameter 
is a char, denoting if the unit is C, F, R, K. This class has only 4 methods,
AsCelsius, AsFahrenheit, AsKelvin, and AsRankine. All of which take no arguments,
and return the temperature value in that unit (as a double)*/

class Temperature{  //https://www.youtube.com/watch?v=FXhALMsHwEY&list=LL&index=2   https://www.youtube.com/watch?v=2BP8NhxjrO0&list=LL&index=3  
                    // Learned more on how to use classes with attached videos. Created a better understanding with con
                    //structors and public/private methods (accessors and mutators)
    public:
        Temperature(double temp_cons, char type_cons): temp(temp_cons), type(type_cons){

        }  //https://www.youtube.com/watch?v=1nfuYMXjZsA&list=LL&index=1&t=334s learned how to initalize using a intilaizer list via this video

        double AsCelsius(){  //converts all entered types to a celsius degree. Used in later methods so I dont need to repeat these lines of code in every method
            if(type =='C'){
                return temp;
            } else if(type == 'F') {
                return (temp - 32.0) * (5.0 / 9.0);
            } else if(type == 'R') {
                return (temp - 491.67) * (5.0 / 9.0);
            }  else if(type == 'K') {
                return temp - 273.15;
            } else{
                return 0.00;
            }

        }

        double AsFahrenheit(){  //Far convert that uses the celsius convert
            return AsCelsius() * (9.0 / 5.0) + 32.0;
        }

        double AsKelvin(){  //kelvin convert that uses the celsius convert
            return AsCelsius() + 273.15;
        }

        double AsRankine(){  //rankie convert that uses the celsius convert
            return (AsCelsius() + 273.15) * (9.0 / 5.0);  //https://www.calculatorsoup.com/calculators/conversions/celsius-to-rankine.php#:~:text=Celsius%20%C2%B0C%20to%20Rankine,9%2F5%2C%20plus%20491.67.&text=Since%209%2F5%20equals%201.8,C%20multiplied%201.8%20plus%20491.67.
                                                          // Convert from celsuis to rankie learned online
        }

    private:  //Variables used in class
        double temp;
        char type;
};  // dont forget the ;

/*int main() {
  Temperature t(13, 'C'); // 13.0 degrees C
  std::cout << t.AsKelvin() << std::endl; // Should return 286.15 as that is the temp in Kelvin.
}*/