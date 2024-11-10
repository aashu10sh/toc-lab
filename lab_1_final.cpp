#include <iostream>

#include <string>

enum States {
  INITIAL,
  FIRST,
  SECOND
};

typedef enum States State;

bool isDivisibleBy3(const std::string & binaryString) {
  State state = INITIAL; // Start at state q0 (representing remainder 0)

  for (char bit: binaryString) {
    if (bit == '0') {
      if (state == INITIAL)
        state = INITIAL; // q0 -> q0
      else if (state == FIRST)
        state = SECOND; // q1 -> q2
      else if (state == SECOND)
        state = FIRST; // q2 -> q1
    } else if (bit == '1') {
      if (state == INITIAL)
        state = FIRST; // q0 -> q1
      else if (state == FIRST)
        state = INITIAL; // q1 -> q0
      else if (state == SECOND)
        state = SECOND; // q2 -> q2
    } else {
      std::cout << "Invalid input: only binary digits (0 or 1) are allowed." << std::endl;
      return false;
    }
  }

  return state == INITIAL;
}

int main() {
  printf("This code is run by Aashutosh Pudasaini - 1202\n");

  // Test cases
  std::string testCases[] = {
    "0",
    "11",
    "110",
    "1001",
    "10",
    "101"
  };

  std::cout << "Results for binary strings divisible by 3:" << std::endl;
  for (const std::string & binary: testCases) {
    bool result = isDivisibleBy3(binary);
    std::cout << "Binary string " << binary << " is " <<
      (result ? "divisible" : "not divisible") << " by 3." << std::endl;
  }

  return 0;
}