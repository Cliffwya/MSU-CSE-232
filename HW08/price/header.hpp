#pragma once
#include <iostream>

/* constructor and a converting constructor
 for a double. It should support the <<, +,
  +=, -, -=, and >> operators. Please see the 
  test cases for the specific behavior for each
   operator.*/


class Price{
    private:
        double cost;

    public:
        Price(double input=0.00):cost{input}{}
        Price operator+(Price const & number);
        Price operator-(Price const & number);
        Price operator-(double number);
        Price operator+=(Price const & number);
        Price operator-=(Price const & number);
        friend std::ostream&operator<<(std::ostream&out,const Price&p);
        friend std::istream&operator>>(std::istream&in,Price&p);


};