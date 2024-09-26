#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define kill 2
#define fail 1
/*---------------------FUNCTIONS--------------------------------------*/
void create_map(char **map, int *gun, int *row, int *col, int *num_monster);
void print_map(char **map, int *row, int *col);
void setup_village(char **map, int *row_input, int *col_input, int *row, int *col);
void setup_monster(int a, int *num_monster, char **map, int *row_input, int *col_input, int *row, int *col, int *x_axis, int *y_axis);
int check_boundary(int row, int col, int row_input, int col_input);
int check_availability(char **map, int row_input, int col_input);
void setup_player(char **map, int *row_input, int *col_input, int *row, int *col);
void setup_gun(int a , int *gun, char **map, int *row_input, int *col_input, int *row, int *col);
void setup_trap(char **map, int *row_input, int *col_input, int *row, int *col, int *x, int *y);
void go_up(int *row_input);
void go_down(int *row_input);
void go_right(int *col_input);
void go_left(int *col_input);
int check_move(char **map, int row, int row_input, int col, int col_input, int *go_to_village, int *g, int *blood, int *strength, int *x, int *y, int *a, int num_monster, int *x_axis, int *y_axis);
void swap(char *a,char *b);
int randomFunc(int *prob, int range);
int dodge();
int choice_for_auto();
/*------------------------------main fucntions---------------------------------------------------------*/
int main(){
    srand((unsigned)time(NULL));
    int row;
    int col;
    int row_input;
    int col_input;
    int num_monster;
    int gun;
    int a = 0;  // only a variable for loop
    int size=64; //use for x_axis[] and y_axis[]
    int x_axis[size];
    int y_axis[size];
    int choice_1;
    int choice_2;
    int blood = 10;
    int strength = 2;
    int x; // use for trap 
    int y; //use for trap 
    int go; //buy thing
    int go_to_village;
    char **map;
    /*------------malloc_part----------*/
    map = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000 ; i++){
        map[i] = (char *)malloc(sizeof(char) * 1000);
    }
    do{
    create_map (map, &gun, &row, &col, &num_monster);
    print_map(map, &row, &col);
    setup_village(map, &row_input,&col_input, &row, &col);
    print_map(map, &row, &col);
    setup_monster(a, &num_monster, map, &row_input, &col_input, &row, &col, x_axis, y_axis);
    print_map(map, &row, &col);
    setup_trap(map,  &row_input,  &col_input,  &row,  &col, &x, &y);
    print_map(map, &row, &col);
    setup_gun(a, &gun, map, &row_input, &col_input, &row, &col);
    print_map(map, &row, &col);
    printf("[1] Create a new map  [2] Start travel the map:"); // want to create new map?
    scanf("%d",&choice_1);
    } while(choice_1 == 1);
    setup_player(map, &row_input, &col_input, &row, &col);
    
    /*----------------player move---------------*/
    while(blood > 0){
    printf("[1] go up  [2] go down  [3] go right  [4] go left  [5] exit:");
        scanf("%d",&choice_2);
        if (choice_2 == 1){
            go_up(&row_input);
            if (check_move(map, row, row_input, col, col_input, &go_to_village, &go, &blood, &strength, &x, &y, &a, num_monster, x_axis, y_axis) != 1){
                swap(&map[row_input][col_input],&map[row_input + 1][col_input]);
                print_map(map, &row, &col);
            }
            else{
                row_input = row_input + 1;
                print_map(map, &row, &col);;
            }
        }
        if (choice_2 == 2){
            go_down(&row_input);
            if (check_move(map, row, row_input, col, col_input, &go_to_village, &go, &blood, &strength, &x, &y, &a, num_monster, x_axis, y_axis) != 1){
                swap(&map[row_input][col_input],&map[row_input - 1][col_input]);
                print_map(map, &row, &col);
            }
            else{
                row_input = row_input - 1;
                print_map(map, &row, &col);;
            }
        }
        if (choice_2 ==3){
            go_right(&col_input);
            if (check_move(map, row, row_input, col, col_input, &go_to_village, &go, &blood, &strength, &x, &y, &a, num_monster, x_axis, y_axis) != 1){
                swap(&map[row_input][col_input],&map[row_input][col_input - 1]);
                print_map(map, &row, &col);
            }
            else{
                col_input = col_input - 1;
                print_map(map, &row, &col);
            }
        }
        if(choice_2 ==4){
            go_left(&col_input);
            if (check_move(map, row, row_input, col, col_input, &go_to_village, &go, &blood, &strength, &x, &y, &a, num_monster, x_axis, y_axis) != 1){
                swap(&map[row_input][col_input],&map[row_input][col_input + 1]);
                print_map(map, &row, &col);
            }
            else{
                col_input = col_input + 1;
                print_map(map, &row, &col);
            }
        }
        if(choice_2 ==5)
            break;
        else if (choice_2 <= 0 || choice_2 >5)
            printf("Invalid action\n");
}
    if(blood <= 0)
        printf("RUBBISH!! YOU DIE!! GAME OVER !!!\n");
for (int i = 0; i < 1000; i++)
{
    free(map[i]);
    }

    free(map);
    return 0;
}
/*------------ Body for every functions------------------*/
void create_map(char **map, int *gun, int *row, int *col, int *num_monster){
    printf("Enter the row and column of the map(largest: 1000* 1000): ") ;
    scanf("%d %d", row, col);
    *num_monster = ((*row * *col)/10) + (*row % 4);
    *gun = (*row * *col)/10;
    for (int i = 0; i < *row; i++){
        for (int j = 0; j < *col; j++){
            map[i][j] = '.';
    }

}
}
void setup_village(char **map, int *row_input, int *col_input, int *row, int *col){
    srand((unsigned)time(NULL));
    printf("Which way do you want to set up your village\n ") ;
    if(choice_for_auto() == 1){
    while(1){
        *row_input = rand() % (*row) ;
        *col_input = rand() % (*col) ;
        if (((check_boundary(*row, *col, *row_input, *col_input)) || (check_availability(map, *row_input, *col_input))) != 1) {
            map[*row_input][*col_input]= 'v';
            printf("the village is built.\n");
            break;
        }
    }
    }
    else{
        while(1){
            printf("Input the row and column for the village location:\n");
            scanf("%d %d", row_input, col_input);
                if (check_boundary(*row, *col, *row_input, *col_input))
                    printf("the location is outside the map\n");
                else{
                    map[*row_input][*col_input]= 'v';
                    printf("the village is built.\n");
                    break;
        }
        }
}
}
void setup_monster(int a, int *num_monster, char **map, int *row_input, int *col_input, int *row, int *col, int *x_axis, int *y_axis){
    printf("Which way do you want to set up your monster\n ") ;
    if(choice_for_auto() == 1){
    srand((unsigned)time(NULL));
    printf("There are %d monsters.\n", *num_monster);
    for(a = 0; a < *num_monster; a++ ){
           *row_input = rand() % (*row) ;
           *col_input = rand() % (*col) ;
            if (check_boundary(*row, *col, *row_input, *col_input)){
                (a)--;
            }
            else if(check_availability(map, *row_input, *col_input)){
                (a)--;
            }
            else{
                map[*row_input][*col_input]= 'm';
                x_axis[a]= *row_input;
                y_axis[a]= *col_input;
                printf("monster %d has been set:\n", a);
            }
        }
}
    else{
        printf("You need to assign location for %d monsters in total\n", *num_monster);
    for(a = 0; a < *num_monster; a++ ){
        printf("Input the row and column for monster %d:\n", a);
        scanf("%d %d", row_input,  col_input);
        if (check_boundary(*row, *col, *row_input, *col_input)){
            printf("the location is outside the map\n");
            (a)--;
        }
        else if(check_availability(map, *row_input, *col_input)){
            printf("the location is occupied\n");
            (a)--;
        }
        else{
            map[*row_input][*col_input]= 'm';
            printf("monster %d has been set:\n", a);
        }
    }
    }   
}
void setup_gun(int a , int *gun, char **map, int *row_input, int *col_input, int *row, int *col){
    printf("Which way do you want to set up your gun\n ") ;
    if(choice_for_auto() == 1){
    srand((unsigned)time(NULL));
    printf("There are %d guns.\n", *gun);
    for(a = 0; a < *gun; a++ ){
        *row_input = rand() % (*row) ;
        *col_input = rand() % (*col) ;
        if (check_boundary(*row, *col, *row_input, *col_input)){
            (a)--;
        }
        else if(check_availability(map, *row_input, *col_input)){
            (a)--;
        }
        else{
            map[*row_input][*col_input]= 'g';
            printf("the gun %d has been set\n", a);
        }
    }
}
    else{
        printf("You need to assign location for %d guns in total\n", *gun);
    for(a = 0; a < *gun; a++ ){
        printf("Input the row and column for gun %d:\n", a);
        scanf("%d %d", row_input,  col_input);
        if (check_boundary(*row, *col, *row_input, *col_input)){
            printf("the location is outside the map\n");
            (a)--;
        }
        else if(check_availability(map, *row_input, *col_input)){
            printf("the location is occupied\n");
            (a)--;
        }
        else{
            map[*row_input][*col_input]= 'g';
            printf("the gun %d has been set\n", a);
        }
    }
    }
}
void setup_trap(char **map, int *row_input, int *col_input, int *row, int *col, int *x, int *y){
    while(1){
        *row_input = rand() % (*row) ;
        *col_input = rand() % (*col) ;
        *x= *row_input;
        *y= *col_input;
        if (((check_boundary(*row, *col, *row_input, *col_input)) || (check_availability(map, *row_input, *col_input))) != 1) {
            printf("the trap is set\n");
            break;
        }
    }
}
void print_map(char **map, int *row, int *col){
    printf("=== MAP ===\n");
    for (int i = 0; i < *row; i++){
        for(int j = 0; j < *col; j++){
            printf("%c ", map[i][j]);
        }
            printf("\n");
    }
    printf("=== MAP ===\n");
}
void setup_player(char **map, int *row_input, int *col_input, int *row, int *col){
    printf("Which way do you want to set up the player's location\n ") ;
    srand((unsigned)time(NULL));
    if(choice_for_auto() == 1){
    while(1){
        *row_input = rand() % (*row) ;
        *col_input = rand() % (*col) ;
        if (((check_boundary(*row, *col, *row_input, *col_input)) || (check_availability(map, *row_input, *col_input))) != 1) {
            map[*row_input][*col_input]= 'p';
            printf("the player is located.\n");
            break;
        }
    }
    }
    else{
        while(1){
            printf("Input the row and column for the player's location:\n");
            scanf("%d %d", row_input, col_input);
                if (check_boundary(*row, *col, *row_input, *col_input))
                    printf("the location is outside the map\n");
                else if(check_availability(map, *row_input, *col_input))
                    printf("the location is occupied\n");
                else{
                    map[*row_input][*col_input]= 'p';
                    printf("the player is located.\n");
                    break;
        }
        }
}
print_map(map, row, col);
}

int check_boundary(int row, int col, int row_input, int col_input){
    return row <= row_input || row_input < 0 || col_input < 0 || col <= col_input;
}
int check_availability(char **map, int row_input, int col_input){
    return map[row_input][col_input] != '.';
}
void go_up(int *row_input){
    *row_input = *row_input - 1;
}
void go_down(int *row_input){
    *row_input = *row_input + 1;
}
void go_right(int *col_input){
    *col_input = *col_input + 1;
}
void go_left(int *col_input){
    *col_input = *col_input - 1;
}

int check_move(char **map, int row, int row_input, int col, int col_input, int *go_to_village, int *go, int *blood, int *strength, int *x, int *y, int *a, int num_monster, int *x_axis, int *y_axis){
    if(row <= row_input || row_input < 0 || col_input < 0 || col <= col_input) {
        printf("You can't go there!\n");
        return 1;
    }
    else if(row_input == *x && col_input == *y && map[row_input][col_input] == '.'){   //check for met trap
        (*blood) = (*blood)-5;
        printf("\n\nBOOM!\n\n");
        printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
        map[row_input][col_input] = '.';
            return 0;
    }
    else if(map[row_input][col_input] == 'v'){
        while(1){
        int sword=0;     // Initialization
        printf("Do you want to go to our village first (1: Yes; 0: No)? ");
        scanf("%d", go_to_village);      // want to go village ?
        while(*go_to_village){
            printf("What do you want to do in our village (1: buy a magical sword; 2: go to the bar; 3: leave the village)? ");
            scanf("%d",go);
            if(*go == 1){
                if(sword == 0){
                    sword=1;
                    (*strength)++;
                    printf("Nice sword! Now you have %d strength!\n",*strength);
                }
                else
                    printf("You already brought a sword.\n") ;  //prevent buy sword many times in one time

            }
            else if(*go == 2){
                    if((*blood) >= 10)
                        printf("Your blood is full. You don't need a beer.\n");
                    else {
                        (*blood)++;
                        printf("Nice beer! Now you have %d blood!\n",*blood);
                    }
            }
            else if(*go == 3){
                printf("You are welcome to come back anytime!\n");
                break;
            }
            else
                printf("Invalid action! 1: buy a magical sword; 2: go to the bar; 3: leave the village\n");

}
        break;
}
        return 1;
}
        else if(map[row_input][col_input] == 'g'){
            (*strength)++;
             printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
            map[row_input][col_input] = '.';
            return 0;

}

    else if(map[row_input][col_input] == 'm'){
        for (*a = 0; *a < num_monster; (*a)++){                          //search monster's states
            if(x_axis[*a] == row_input && y_axis[*a] == col_input){
                *a = *a + 1 ;
                printf("%d",*a);
                break;
            }
        }
        printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
        if(dodge() == kill ){
            printf("The monster dodge your attack.\n");
            return 1;
        }
        if(*strength > *a){
            printf("%d",*a);
            printf("You Win!\n");
            (*strength)++;
            printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
            map[row_input][col_input] = '.';
            return 0;
        }
        else if(*strength == *a){
            printf("%d",*a);
            printf("Draw!\n");
            printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
            return 1;
        }
        else if(*strength < *a){
            printf("%d",*a);
            printf("You lost!\n");
            *blood = *blood - *a ;
            printf("You have %d blood and %d strength.\n" ,*blood ,*strength);
            return 1;
        }
    }
    return 0;
}
void swap(char *a,char *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int randomFunc(int *prob, int range){  //Function use for probability 
    srand((unsigned)time(NULL));
    *prob = rand() % range;
    return *prob;
}
int dodge(){      
    int temp;
    temp = randomFunc(&temp, 4);  // follow the randomFunc
    if(temp == 0){
        return kill;
    }
    return fail;
}

int choice_for_auto(){                         //Function use for random or custom 
    int choice_custom;
    while(1){
        mode:
        printf("[1] RANDOM [2] CUSTOM:");
        scanf("%d", &choice_custom);
        if(choice_custom == 1){
            return 1;
        }
        else if(choice_custom == 2){
            return 2;
        }
        else{
            printf("Invalid move!\n");
            goto mode; 
        }
    }
}
