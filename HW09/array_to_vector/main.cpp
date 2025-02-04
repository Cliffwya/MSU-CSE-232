// Note: This file is not tested by the autograder
#include <iostream>
#include <vector>
#include <cassert>
#include "header.hpp"

int main() {
	
  std::vector<int> const expected = {1, 45, -84, 0, 3, 2, 0};

	int * source = new int[expected.size()];
  for (int i = 0; i < static_cast<int>(expected.size()); ++i) {
    source[i] = expected.at(i);
  }

  std::vector<int> const result = ArrayToVector(source, expected.size());

  assert(result.size() == expected.size());
  
  for (int i = 0; i < static_cast<int>(expected.size()); ++i) {
    assert(result.at(i) == expected.at(i));
  }
  assert(result == expected);

	return 0;
}