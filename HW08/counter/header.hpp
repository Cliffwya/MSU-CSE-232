#pragma once
#include <vector>
#include <iostream>
#include <string>

class Counter {
    private:
        int int_number;
        int current_number;

    public:
        std::vector<std::string> log_;
        Counter(int x): int_number{x},current_number{x}{  //used both init and current so we can keep track of the first init valued and we used to modified current number
            log_.push_back("Constructor called with a "+std::to_string(int_number));  //displays the init number in log
        }
        Counter(const Counter &x):int_number{x.int_number},current_number{x.current_number}{
            log_=x.log_;
            log_.push_back("Copy Constructor called.");
        }
        Counter(){
            log_.push_back("Default Constructor called.");
        }
        ~Counter(){ //https://www.geeksforgeeks.org/destructors-c/   deconstructor
            log_.push_back("Destructor called.");
        }
        int Value();
        Counter & operator=(const Counter&input);
        friend std::ostream& operator<<(std::ostream&os, Counter & counter);
        Counter operator+(const Counter& input) const;


};