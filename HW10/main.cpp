#include <iostream>
#include <string>

int main() {
    std::string words{"Hello mynameis wyatt"};
    size_t pos = words.find("name");  // Use std::string::find for substring search
    
    if (pos != std::string::npos) {
        std::cout << "Found at position: " << pos << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }
    
    return 0;
}
