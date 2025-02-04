  #include <vector>
  #include <iostream>
  #include "traffic_jam.h"
  int main() {
  std::vector<std::vector<bool>> road_map = {
    {false, true, false, false},
    {false, false, true, true},
    {true, false, false, false},
    {false, true, false, false}
  };
  std::cout << AreRoadsBalanced(road_map) << std::endl; // Should be true
  road_map = {
    {false, true, false},
    {true, false, false},
    {false, true, false},
  };
  std::cout << AreRoadsBalanced(road_map) << std::endl; // Should be false
  }   

