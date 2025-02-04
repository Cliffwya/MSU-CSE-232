#include <iostream>
#include <string>
using namespace std;

char * Sandwich(std::string & line, char * bread_ptr) {

    for(size_t i{1}; i < line.size();++i){  //Index through the size of the line
        if(line.at(i-1)==*bread_ptr && line.at(i+1)==*bread_ptr){  //If the character to the left and right of the index is equal to the bread_ptr return the address of the char
            return & line.at(i);
        }
    }

    return nullptr;  //If nothing else return a nullptr
}

int main() {
	std::string line = "Char is a character";
	char bread = 'a';
	char * filling_ptr = Sandwich(line, &bread);
	std::cout << *filling_ptr << std::endl; // Should be r
    return 0;
}
