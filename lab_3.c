#include<stdio.h>
#include<stdlib.h>


// divisible by '3'
enum States{
    ACCEPT,
    REJECT
};


int main(void){
    printf("This code is run by Aashutosh Pudasaini - 1202\n");
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
