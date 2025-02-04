#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

/*  
    35,  55,  55,  55,  55,  35,  35,  15,   *,  15,  35,  55,  55,  55,  55,  55,  55,  55,  55,  55,
  20,  40,  60,  60,  40,  20,  40,  40,  20,  40,  60,  60,  60,  60,  60,  60,  60,  60,  60,  60,
   *,  25,  45,  45,  25,   *,  25,  45,  45,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,
  30,  50,  70,  70,  50,  30,  50,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
  55,  75,  75,  75,  75,  55,  75,  75,  75,  75,  75,  75,  75,  55,  55,  75,  75,  75,  75,  75,
  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  80,  60,  20,   0,  60,  80,  80,  80,  80,
  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  65,  25,   *,   *,   5,  65,  85,  85,  85,
  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  30, -50,   *,  30,  70,  90,  90,  90,
  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  95,  75,  55,   *,  -5,  55,  95,  95,  95,  95,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  80,  60,  60, 100, 100, 100, 100, 100,

    used in VSCode so I didn't have to swap between codio to make sure I've got the correct output
*/

std::vector<std::vector<int>> create_seats() {  // Creates the stadium (10X20 with each value starting at 100)
    std::vector<std::vector<int>> stadium(10, std::vector<int>(20, 100));
    for (int i = 0; i < 10; ++i) { // For each row decrease that row number * 5
        for (int j = 0; j < 20; ++j) {
            stadium.at(i).at(j) -= i * 5;
        }
    }
    return stadium;  // Return the base stadium
}

void adjust_seat_rankings(std::vector<std::vector<int>>& stadium, const std::vector<int>& fan_x, const std::vector<int>& fan_y) {  // Algo for figuring out the new seat rankings
    for (size_t k{0}; k < fan_x.size(); ++k) {  // For the size of the amount of super fans go through each fan
        int fan_x_coord = fan_x.at(k);
        int fan_y_coord = fan_y.at(k);
        for (int dx{-1}; dx <= 1; ++dx) {
            for (int dy{-1}; dy <= 1; ++dy) {
                if ((dx == 0 && dy == 0) || std::abs(dx) + std::abs(dy) > 1) {  // Makes sure it's not the fan's own seat and the pos iterated is not greater than one 
                    continue;
                }
                int adjacent_x = fan_x_coord + dx;  // This sections checks for N, S, W, E positions and decreases each adjacent seat by 40
                int adjacent_y = fan_y_coord + dy;  // The following two lines where to calculate the adjacent seats
                if (adjacent_x >= 0 && adjacent_x < 20 && adjacent_y >= 0 && adjacent_y < 10) {  // Makes sure the adjacent seats are valid to decrease by 40 
                    stadium.at(adjacent_y).at(adjacent_x) -= 40;
                }
            }
        }
        for (int dx{-2}; dx <= 2; ++dx) {  // These two for loops loops through the displacement of each seat by 2 for both horizontally and vertically ensuring its diagonal
            for (int dy{-2}; dy <= 2; ++dy) {
                if (std::abs(dx) + std::abs(dy) != 2) {  // If the absolute value of those seats combined don't equal to 2 continue. More checking to ensure it's diagonal
                    continue;
                }
                int diagonal_x = fan_x_coord + dx;  // Similar to the previous section but checks for diagonal seats instead
                int diagonal_y = fan_y_coord + dy;
                if (diagonal_x >= 0 && diagonal_x < 20 && diagonal_y >= 0 && diagonal_y < 10) {  // If it is a valid seat decrease the value of the seat by 20 at that pos
                    stadium.at(diagonal_y).at(diagonal_x) -= 20;
                }
            }
        }
    }
}

void print_stadium(const std::vector<std::vector<int>>& stadium, const std::vector<int>& fan_x, const std::vector<int>& fan_y) {    // Print the stadium given the current stadium and the fans x/y pos
    for (int i{9}; i >= 0; --i) {  // Starting from row 10 go down
        for (int j{0}; j < 20; ++j) {
            bool is_superfan = false;
            for (size_t k{0}; k < fan_x.size(); ++k) {  // Checks to see if seat is a super fan
                if (fan_x.at(k) == j && fan_y.at(k) == i) {
                    is_superfan = true;
                    break;
                }
            }
            if (is_superfan) {  // If it's a super fan print the '*"
                std::cout << std::setw(4) << "*";  // Adjust spacing for the super fan
            } else {
                int seat_value = stadium.at(i).at(j);
                // Adjusting output formatting for seat values
                std::cout << std::setw(4) << seat_value;  // Use std::setw for proper formatting. tried with using setw() using this referance https://www.geeksforgeeks.org/setw-function-in-cpp-with-examples/
            }
            if (j < 20) {  // Comma at everywhere but the end
                std::cout << ",";
            }
        }
        std::cout << std::endl;  // Move to the next line after printing a row
    }
}

void read_superfans(std::vector<int>& fan_x, std::vector<int>& fan_y) {  // Two lists of each superfan pos, updates each vector
    std::string line;
    while (std::getline(std::cin, line)) {  // Index through the lines in the text file or cin
        if (line.empty()) {  // if it's empty continue
            continue;
        }
        int x = 0;
        int y = 0;
        bool reading_x = true; // Indicates whether we're reading x or y
        for (char c : line) {
            if (std::isdigit(c)) {
                if (reading_x) {
                    x = x * 10 + (c - '0'); // Build the x value
                } else {
                    y = y * 10 + (c - '0'); // Build the y value
                }
            } else if (c == ',') {
                reading_x = false; // Switch to reading y after comma
            }
        }
        fan_x.push_back(x);  // Push the values of each superfan's x/y pos
        fan_y.push_back(y);
    }
}

int main() {
    std::vector<int> fan_x, fan_y;  // X/Y positions of each fan
    read_superfans(fan_x, fan_y);  // Read in the fans from the data
    //std::vector<int> fan_x = {5, 13, 14, 14,13,8,0}; // X-coordinates of superfans
    //std::vector<int> fan_y = {7,3,3,2,1,9,7};
    std::vector<std::vector<int>> stadium = create_seats();  // Create the stadium as well
    adjust_seat_rankings(stadium, fan_x, fan_y);  // Adjust the rankings of the seats
    print_stadium(stadium, fan_x, fan_y);  // Print the adjusted rankings
    return 0;
}
