#include<stdio.h>

#include<string.h>

enum States {
  INITIAL,
  FIRST,
  SECOND,
  FINAL
};

int main(void) {
  enum States current_state = INITIAL;
  char * input = "001110";
  for (int i = 0; i < strlen(input); i++) {
    switch (current_state) {
    case INITIAL:
      if (input[i] == '1') {
        current_state = FIRST;
        continue;
      }
    case FIRST:
      if (input[i] == '1') {
        current_state = SECOND;
        continue;
      }

    case SECOND:
      if (input[i] == '1') {
        current_state = FINAL;
        continue;
      }
    case FINAL:
      break;
    default:
      printf("Does Not Match the pattern");
    }
  }

  if (current_state == FINAL) {
    printf("String Passes!");
    printf(" %d", current_state);
  } else {
    printf("String Fails!");
    printf(" %d", current_state);
  }
}