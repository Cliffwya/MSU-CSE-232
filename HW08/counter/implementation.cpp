#include "header.hpp"
#include <iostream>


int Counter::Value(){  //value, adds log and post fixes the current number beacuse we want to display the init number 
    log_.push_back("Value called. Returned a "+std::to_string(current_number));  //to_string converts int to string
    return current_number--;
}

std::ostream& operator<<(std::ostream&os, Counter & counter){
    os<<"Counter("<<counter.int_number<<")@"<<counter.current_number; //adds the strings wanted for formating plus the init value and current value in an ostream
    counter.log_.push_back("<< called."); //adds the called to the log as well
    return os; //return value
}

Counter& Counter::operator=(const Counter& input){
    if(this !=&input ){  //if the self is not equal to the other counter
        int_number=input.int_number;  //set the int and current value of current self to the = number
        current_number=input.current_number;
        log_=input.log_;
        log_.push_back("= called.");  //add to log
    }
    return *this;  //return self object
}


Counter Counter::operator+(const Counter& input) const{
    Counter final_counter(this->int_number+input.int_number);  //create the new counter object adding their int values using this
    final_counter.current_number=this->current_number+input.current_number; //add current values
    final_counter.log_.push_back("+ called."); //add the + called to the new counter log   
    return final_counter; 
}