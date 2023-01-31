/**
* Alfredo Renteria
* Filename: main.cpp
* Main function
* Code Status: Working/Tested
*/

#include <iostream>
#include <string>
#include "Stack.h"

int main() {
  Stack s;
  std::string a = "";

  while (std::getline (std::cin, a)) {
    s.push(a);
  }

  while (!s.empty()) {
    std::string top = s.pop();
    std::cout << top << std::endl;
  }

  return 0;
}
