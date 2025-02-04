#include "func.hpp"
#include <vector>
#include <string>
#include <cassert>

int main() {
  std::vector<int> const vec_a = {1, 20, -3, 7, 56, 0, -2};
  std::vector<int> const vec_b = {10, 4, -3, 8};
  std::vector<int> const expected = {10, 20, -3, 8, 56, 0, -2};
  assert(MaxVector<int>(vec_a, vec_b) == expected);

  std::vector<std::string> const vec_c = {"hello", "apple", "CSE"};
  std::vector<std::string> const vec_d = {"bye", "banana"};
  std::vector<std::string> const expected2 = {"hello", "banana", "CSE"};
  assert(MaxVector(vec_c, vec_d) == expected2);
}