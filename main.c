#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//roll die 

int roll_die() {
    return(rand() %6 +1);
}

int main(){
    // seeding the current time for the random number generator
    srand(time(NULL));

    printf("====Catan dice roll====\n");

    //simulating 3 turns of rolling 2 die
    
    for(int turn=1;turn<=3;turn++){
        int die1 = roll_die();
        int die2 = roll_die();
        int total = die1 + die2;

        printf("Turn: %d \n", turn);
        printf("Die1: %d, Die2: %d, Total = %d \n",die1,die2,total);

        if (total==7) {
            printf("ROBBER IS ACTIVATED\n");
        }

    }

    return 0;

}