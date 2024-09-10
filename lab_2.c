#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 // to check if string ends with an 'ab'

int main(void) {
  char * string = "this-is-so-cool-bro-ab";
  int string_len = strlen(string);
  
  if (string_len < 2) {
    printf("Need String of Length at least 2");
    return EXIT_FAILURE;
  }

  if (string[string_len - 2] == 'a' && string[string_len - 1] == 'b') {
    printf("String Passes!\n");
    return EXIT_SUCCESS;
  }

  printf("String Fails!\n");
  return EXIT_FAILURE;
}