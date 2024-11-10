#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 // to check if string ends with an 'ab'
enum States{
  INITIAL,
  FIRST,
  SECOND
 };

 typedef enum States State;



int main(void) {
  char * string = "this-is-so-cool-bro-ab";
  int string_len = strlen(string);
  State current_state = INITIAL;
  
  if (string_len < 2) {
    printf("Need String of Length at least 2");
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
    return EXIT_SUCCESS;
  }

  printf("Condition Failed!\n"); 

  return EXIT_FAILURE;
}