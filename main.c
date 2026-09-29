#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumerating catan resources

typedef enum{
    DESERT,
    BRICK,
    LUMBER,
    WOOL,
    ORE,
    GRAIN
} ResourceType;

// functino to convert the ResourceType enum to a readable string

const char* resource_to_string(ResourceType res){
    switch(res){
        case DESERT: return "Desert";
        case BRICK: return "Brick";
        case LUMBER: return "Lumber";
        case WOOL: return "Wool";
        case ORE: return "Ore";
        case GRAIN: return "Grain";
        default: return "Unknown";
    }    
}

// defining a struct for a single tile
typedef struct {
    int id;
    ResourceType resource;
    int number_token;
} HexTile;

// function to simulate rolling 2 die

int roll_die(){
    return(rand() % 6) + 1;
}


int main(){
    srand(time(NULL));

    printf("\n\n\n\n=======CATAN BOARD SETUP=======\n");

    // hex tile setup

    HexTile board[19] = {
        {1,  ORE,    10}, {2,  WOOL,    2}, {3,  LUMBER,    9}, // (Using WOOD/LUMBER interchangeably)
        {4,  GRAIN,  12}, {5,  BRICK,   6}, {6,  WOOL,    4},
        {7,  BRICK,  10}, {8,  LUMBER,   9}, {9,  GRAIN,  11},
        {10, DESERT,  0}, {11, LUMBER,   3}, {12, ORE,     8},
        {13, LUMBER,  8}, {14, ORE,      3}, {15, GRAIN,   4},
        {16, WOOL,    5}, {17, BRICK,   5}, {18, WOOL,    6},
        {19, GRAIN,  11}
    };

    // simulating 10 turns of rolling die

    for(int i=0;i<10;i++){
        int die1 = roll_die();
        int die2 = roll_die();
        int total = die1 + die2;
    
        printf("\n=====================================\n");
        printf("Turn %d\n",i);
        printf("Die1: %d, Die2: %d, Total = %d\n",die1,die2,total);

        if(total == 7){
            printf("ROBBER ACTIVATED. PLEASE MOVE IT TO A DESIRED TILE\n");
            continue;
        }

        int prod_count = 0;
        //checking the total with the resource ID

        for(int i = 0; i < 19; i++){
            if(board[i].number_token == total){
                printf("Tile %2d (%-6s) produced resources!\n",board[i].id, resource_to_string(board[i].resource));
                prod_count++;
            }
        }

        if (prod_count == 0){
            printf("No tile produced resources", total);
        }
    }
    return 0;
}



