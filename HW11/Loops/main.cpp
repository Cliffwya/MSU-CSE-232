#include <string>
#include <vector>
#include "header.hpp"
#include <iostream>



int main(){
    std::vector<std::string> words = {"wolf", "BanAna", "caRRot", "AprIcots", "BEets", "chiCkPeas", "orAngEs", "apple", "CAT", "dOG"};
    std::vector<std::string> expected = {"wolf", "apple", "orAngEs", "AprIcots", "BanAna", "BEets", "CAT", "chiCkPeas", "dOG", "caRRot"};
    SortByUppercase(words);
    for(std::string s: words){
        std::cout<<s<<std::endl;
    }
    std::cout<<std::endl;
    for(std::string s : expected){
       std::cout<<s<<std::endl; 
    }
    return 0;
}