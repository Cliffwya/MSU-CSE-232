//main.cpp
#include "Penultimate.hpp"
#include <string>
#include <cassert>

int main() {
  Penultimate p("first");
  std::string s = p.push_back("second"); // s is "first"
  assert(s == "first");
  p.push_back("Third"); // returns "second"
  s = p.push_back("last"); // returns "Third"
  assert(s == "Third");
}