#include<stdio.h>
#include<stdlib.h>


// divisible by '3'
enum States{
    ACCEPT,
    REJECT
};


int main(void){
    int input = 21;
    enum States current_state = REJECT;

    if(input %3 == 0){
        current_state = ACCEPT;
    }

    switch (current_state)
    {
    case ACCEPT:
        printf("Accepted!");
        break;
    case REJECT:
        printf("Rejected!");  
        break;
    }
    return EXIT_SUCCESS;
}
