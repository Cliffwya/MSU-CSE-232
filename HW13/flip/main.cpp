// Note: This file is not tested by the autograder

#include "header.hpp"
#include "Node.hpp"
#include <iostream>
int main() {
	
  Node * n1 = new Node;
  std::cout << (*n1).on << std::endl;
  Flip(n1);
  std::cout << (*n1).on << std::endl;

  return 0;
}