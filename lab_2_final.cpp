#include<stdio.h>
#include<iostream>


enum States {
  Q0,
  Q1,
  Q2
};

typedef enum States State;

bool consecutive_ones(const std::string & input) {
  State current_state = Q0;
  for (char current: input) {
    if (current == '1') {
      if (current_state == Q1) {
        current_state = Q2;
        break;
      }
      current_state = Q1;
    } else {
      current_state = Q0;
    }
  }

  if (current_state == Q2) {
    printf("Accepted!\n");
    return true;
  }

  printf("Failed!\n");
  return false;
}

int main(void) {
  printf("This code is run by Aashutosh Pudasaini - 1202\n");
  std::string testCases[] = {
    "0",
    "0011",
    "00000",
    "11111",
    "010101",
    "00110"
  };

  for (const std::string & testCase: testCases) {
    printf("%s: ", testCase.c_str());
    consecutive_ones(testCase);
  }
}