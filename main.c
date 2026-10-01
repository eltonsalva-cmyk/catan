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

// defining a player

typedef struct{
    char name[20];
    int resources[6]; // 6- to match the types of resources
    int victory_points;
    int roads_left;
    int settlement_left;
    int city_left;
} player;

// function to simulate rolling 2 die

int roll_die(){
    return(rand() % 6) + 1;
}

void print_player_status(player p){
    printf("Player: %s  Victory points: %d\n", p.name, p.victory_points);
    printf("Resources -> Brick: %d | Lumber: %d | Wool: %d | Grain: %d | Ore: %d \n", p.resources[BRICK], p.resources[LUMBER], p.resources[WOOL], p.resources[GRAIN], p.resources[ORE]);
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

    player p1 = {
        .name = "Alice",
        .resources = {0,0,0,0,0,0},
        .victory_points = 0,
        .roads_left = 13,
        .settlement_left = 10,
        .city_left = 5
    };

    printf("============INITIAL PLAYER STATUS=================\n\n");
    print_player_status(p1);

    // simulating 10 turns of rolling die

    for(int i=0;i<10;i++){
        int die1 = roll_die();
        int die2 = roll_die();
        int total = die1 + die2;
    
        printf("\n=====================================\n");
        printf("\nTurn %d\n",i);
        printf("Die1: %d, Die2: %d, Total = %d\n",die1,die2,total);

        if(total == 7){
            printf("ROBBER ACTIVATED. PLEASE MOVE IT TO A DESIRED TILE\n");
            continue;
        }

        int prod_count = 0;
        //checking the total with the resource ID

        for(int i = 0; i < 19; i++){
            if(board[i].number_token == total){
                ResourceType res = board[i].resource;
                printf("Tile %2d (%s) produced resources!\n",board[i].id, resource_to_string(res));

                p1.resources[res]++;
                prod_count++;
            }
        }

        if (prod_count == 0){
            printf("No tile produced resources", total);
        }

        printf("===Player status===\n");
        print_player_status(p1);
    }
    return 0;
}



