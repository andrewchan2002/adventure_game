# Adventure Game - README

## Project Description

This is an adventure game where the player can customize the map size according to their preferences. The game offers two choices for setting up the location of the village, monsters, guns, and the player: random or custom. The player can attack monsters, and if the player's health drops to 0, the game is over.

### New Functions
I have added the following new functions:
- `dodge()`
- `setup_gun()`
- `setup_trap()`
- `randomFunc()`
- `choice_for_auto()`

Details of these functions will be explained in the **Functions Description** section.

## Playing Method

### Introduction
This is an adventure game. Here are some key points that players must consider:

1. **Map**: Players need to input the map size, with a maximum size of 1000x1000.
2. **Village (v)**: Players can set the village location. In the village, players can drink beer to increase their health and buy a sword (once) to increase strength.
3. **Monster (m)**: The number of monsters is determined by the formula:  
   `((row * col) / 10) + (row % 4)`  
   Each monster's health equals its number +1.  
   For example:  
   | Monster’s Number | Monster’s Health |
   |------------------|------------------|
   | 0                | 1                |
   | 1                | 2                |
4. **Gun (g)**: Finding a gun on the map increases the player's strength by 1.  
   Formula: `Number of guns = (row * col) / 10`
5. **Trap**: There is one hidden trap on the map, and it is placed randomly. If a player triggers it, they lose 5 health points.
6. **Player (p)**: Only one player exists on the map.
7. **Random or Custom**: Players can choose to randomly generate or customize the location of the village, monsters, guns, and player.
8. **Health and Strength**: The player starts with 10 health points and 2 strength points.
9. **Movement**: Players can move using the following commands:
   - [1] Move up
   - [2] Move down
   - [3] Move right
   - [4] Move left
   - [5] Exit
10. **Create New Map**: If unsatisfied with the current map, players can generate a new one.

### Rules

1. Set up the map size and the locations of the village, monsters, and guns.
2. If unsatisfied with the map, create a new one; otherwise, begin the adventure.
3. Move the player to search for guns, villages, or fight monsters.
4. Combat Rules:
   - If the player's strength is greater than the monster’s health, the player wins and gains 1 strength.
   - If the player's strength is less, they lose health equal to the monster's health.
   - If their strengths are equal, the battle is a draw, and no stats change.
5. If the player's health reaches 0 or below, the game ends.

## Functions Description

The game consists of 18 functions, which are described below:

| Function          | Purpose                                            |
|-------------------|----------------------------------------------------|
| `create_map()`     | Creates the map                                    |
| `print_map()`      | Prints the map                                     |
| `setup_village()`  | Sets the location of the village                   |
| `setup_monster()`  | Sets the location of monsters                      |
| `check_boundary()` | Checks if an item is inside or outside the map     |
| `check_availability()` | Checks if an item’s location is occupied       |
| `setup_player()`   | Sets the player’s location                         |
| `setup_gun()`      | Sets the location of guns                          |
| `setup_trap()`     | Sets the location of traps                         |
| `go_up()`          | Moves the player upward                            |
| `go_down()`        | Moves the player downward                          |
| `go_right()`       | Moves the player to the right                      |
| `go_left()`        | Moves the player to the left                       |
| `check_move()`     | Verifies the player’s position after moving        |
| `swap()`           | Swaps the player’s location with another object    |
| `randomFunc()`     | Determines the probability of monster dodging      |
| `dodge()`          | Monsters dodge or endure an attack                 |
| `choice_for_auto()`| Allows players to choose between random and custom |

## Variables Description

### Main Function Variables

- `int row & int col`: Store the map's row and column size.
- `int row_input & col_input`: Store the location of guns, village, player, trap, and monsters.
- `int num_monster`: The number of monsters.
- `int gun`: Stores the number of guns.
- `int a = 0`: Used for loops.
- `int size = 64`: Size used for `x_axis[]` and `y_axis[]`.
- `int x_axis[size]`: Used to track the ID of monsters.
- `int y_axis[size]`: Used to track the ID of monsters.
- `int choice_1`: For creating a new map or starting the adventure.
- `int choice_2`: Used for player movement.
- `int blood = 10`: Stores the player’s health.
- `int strength = 2`: Stores the player’s strength.
- `int x, int y`: Used to hide the trap location.
- `int go`: Used for buying items in the village.
- `int go_to_village`: Chooses whether or not to go to the village.
- `char **map`: Stores the map.

### `check_move()` Variables

- `int sword`: Prevents buying multiple swords.

### `swap()` Variables

- `char *a, char *b, int temp`: Helps swap locations during movement.

### `randomFunc(int *prob, int range)` Variables

- `*prob`: Probability variable.
- `range`: Used to assist the function.

### `dodge()` Variables

- `int temp`: Stores value from `randomFunc(&temp, 4)`.

### `choice_for_auto()` Variables

- `int choice_custom`: Used for selecting between random and custom map setup.
