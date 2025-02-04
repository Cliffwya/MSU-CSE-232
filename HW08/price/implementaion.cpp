#include "header.hpp"
#include<iomanip>
#include <iostream>

Price Price::operator+(Price const & number){
    return Price(this->cost+number.cost);
}

Price Price::operator-(Price const & number){
    return Price(this->cost-number.cost);
}

Price Price::operator-(double number){
    return Price(this->cost - number);
}

Price Price::operator+=(Price const & number){
    this->cost +=number.cost;
    return *this;
}

Price Price::operator-=(Price const & number){
    this->cost -=number.cost;
    return *this;
}

std::ostream&operator<<(std::ostream&out,const Price&p){
    out << std::fixed << std::setprecision(2) << "$" << p.cost;
    return out;
}

std::istream&operator>>(std::istream&in,Price&p){
    char $;
    in>>$>>p.cost;
    return in;
}
