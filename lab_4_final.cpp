#include<stdio.h>
#include<string.h>
#include<stack>
#include<iostream>

bool checkPDA(const std::string &input){
    std::stack<char> stack;

    for (const char character : input){
        if(stack.empty()){
            stack.push(character);
            continue;
        }
        if(character == stack.top()){
            stack.push(character);
            continue;
        }else{
            stack.pop();
        }
    }
    
    if(stack.empty()){
        printf("Accepted!\n");
        return true;
    }
    printf("Rejected!\n");
    return false;
}

int main(void){
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
    checkPDA(testCase);
  }
}