#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
 // to check if string ends with an 'ab'
enum States{
  INITIAL,
  FIRST,
  SECOND
 };

typedef enum States State;

bool ends_with_ab(const char * string) {

  int string_len = strlen(string);
  State current_state = INITIAL;
  
  if (string_len < 2) {
    printf("Need String of Length at least 2\n");
    return EXIT_FAILURE;
  }
  if (string[string_len - 2] == 'a'){
    current_state = FIRST;
    if (string[string_len - 1] == 'b'){
      current_state = SECOND;
    }  
  }

  if (current_state == SECOND){
    printf("Condition Satisfied!\n");
    return true;
  }

  printf("Condition Failed!\n"); 
  return false;
}

int main(void){

  printf("This code is run by Aashutosh Pudasaini - 1202\n");

    std::string testCases[] = {
    "0",
    "001a",
    "00000ab",
    "1111bba",
    "0101ab",
    "001ab10"
  };

  for (const std::string & testCase: testCases) {
    printf("%s: ", testCase.c_str());
    ends_with_ab(testCase.c_str());
  }
}