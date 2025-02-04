/*In the file CountingExceptions/counter.cpp, you need to write a function named CountExceptions that takes a 
vector of strings and returns a vector of ints (size 3). The purpose of this function is to take a list of book 
titles and check that they are valid, according to the function named CheckName. The CheckName function takes a 
string and raises various exceptions if the name isn’t acceptable. The CountExceptions function should return a 
vector with the number of title that raised an invalid_argument, a length_error, or an out_of_range exception.
I’ve provided an example CheckName implementation and main function for local testing, however some of the test 
cases use a variation of CheckName that looks for different criteria to throw exceptions for. Be sure to use the
 appropriate header files. Be sure not to alter any files besides the counter.cpp file.*/
#include "counter.hpp"
#include "name_checker.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<int> CountExceptions(std::vector<std::string> const & input){
    std::vector<int> total_exceptions(3,0);  //Creates an empty (0) vector of size 3
    // also used https://www.geeksforgeeks.org/exception-handling-c/  for references
    for(const std::string & name : input){  //For each word in the vector of strings
        try{  //https://www.w3schools.com/cpp/cpp_exceptions.asp  had to use this link on how to use catch/try/throw so i am able to catch each excpetion thrown by name_checker.cpp
            CheckName(name);  //Try the checkname function from name_checker.cpp
        } catch(const std::invalid_argument&){  //catches if it has a t in the title and adds 1 to spot 0 on the vector 
            ++total_exceptions.at(0);
        } catch(const std::length_error&){  //cathces to see if it has a s in the name 
            ++total_exceptions.at(1);
        } catch(const std::out_of_range&){  //catches to see if it has a s and the end
            ++total_exceptions.at(2);
        }
    }

    return total_exceptions;
}