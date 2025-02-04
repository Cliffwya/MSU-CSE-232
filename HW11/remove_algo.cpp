//#include <algorithm> // Remove me
//#include <numeric> // Remove me
#include <string>
#include <vector>
#include <iterator>

int Func(int a) 
{
    std::vector<int> b(a);
    int number {12};
    for(int i{0}; i<a; ++i){
        b.at(i)= number++;
    }
    //std::iota(b.begin(), b.end(), 12);
    std::vector<int> c(b);
    for(size_t i{0};i<c.size()/2;++i){
        std::swap(c.at(i),c.at(c.size()-1-i));  //Flip each value in c which is a copy of b to make a new flipped vector c 
    }
    //std::reverse(c.begin(), c.end());
    for(size_t i{0};i<b.size();++i){
        b.at(i)=2*b.at(i)+c.at(i);
    }
    /*std::transform(b.begin(), b.end(), c.begin(), b.begin(), 
        [](auto c, auto d){return 2 * c + d;}
    );*/
    int total{0};
    for(size_t i{2};i<b.size()-2;++i){
        if(std::to_string(b.at(i)).find("2") != std::string::npos) ++total;
    }
   /* return std::count_if(b.begin() + 2, b.end() - 2, 
        [](auto d){return std::to_string(d).find("2") != std::string::npos;}
    );*/
    return total;
}
