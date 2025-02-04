#pragma once 
#include <string>
#include <ostream>

class LispExpression{
    private:
        std::string lisp_string;
    public:
        LispExpression(const std::string input):lisp_string{input}{}
        std::string get_lisp_string() const; //getter for lisp string
        std::string PrettyPrint() const;
        //friend std::ostream& operator<<(std::ostream&os,LispExpression const &le);
};