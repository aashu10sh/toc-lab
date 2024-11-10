#include<stdio.h>
#include<string.h>
#include<stack>
#include<iostream>


int main(){
    printf("This code is run by Aashutosh Pudasaini - 1202\n");
    std::stack<char> stack;
    std::string input = "11001";

    for (char character : input){
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
        printf("PDA accepts the string %s \n", input.c_str());
    }else{
        printf("PDA does not accept the string %s\n",input.c_str());
    }
            // printf("%c\n",stack.top());

    return 0;

}