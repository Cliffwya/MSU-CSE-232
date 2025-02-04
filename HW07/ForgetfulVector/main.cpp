#include "ForgetfulVector.hpp"
#include <cassert>

int main() {
  ForgetfulVector fv; 
  fv.push_back(1);
  fv.push_back(2);
  fv.push_back(3);
  fv.push_back(2);

  // Currently only "knows about" [2] as it "forgets" the first occurrence of 1, 2, and 3
  assert(fv.size() == 1); // Should be 1
  fv.push_back(1); // now holds [2, 1] as this is the second time seeing a 1
  assert(fv.at(0) == 2); // returns a 2 as that is the value in index 0 in this forgetful vector
  assert(fv.at(1) == 1);

}