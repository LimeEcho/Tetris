// display.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Tetris_header.h"

#define CALL1 print_ctrl \
    (size.y, game_area, &block_y_index, &create_location,

#define CALL2 , &block_x_index, game_y_index, &game_x_index, divide_blocks, offset \
);
// Simplifies the call to 'print_ctrl'.

void print_ctrl (int, char *[], int *, int *, int[5][5], int *, int, int *, int, int); 
																				// Determines if the block should be ACTIVEBLOCK or SPACE.

void initGameArea (char *game_area[], Size size) 								// Initializes the entire game area.
{
    for (int i = 0; i < size.y + 1; i++) { 										// Allocates memory for the game area rows.
        game_area[i] = malloc(size.x + 0);
    }

    size.x += 2; 																// Adjusts the width to account for the sides. The bottom row will be added separately.
    for (int game_y_index = 0; game_y_index < size.y; game_y_index++) { 		// Iterates over the game area.
        for (int game_x_index = 0; game_x_index < size.x; game_x_index++) {
            if (game_x_index == 0 || game_x_index == size.x - 1) { 				// If at the left or right edge.
                game_area[game_y_index][game_x_index] = SIDE;
            } else { 															// If inside the game area (not at the edges).
                game_area[game_y_index][game_x_index] = SPACE;
            }
        }
    }
    for (int game_x_index = 0; game_x_index < size.x; game_x_index++) { 		// Adds the bottom row.
        game_area[size.y][game_x_index] = SIDE;
    }
}

void updateGameArea (char *game_area[], int divide_blocks, Size size, Blocks bls, int offset, int moveOffset)
// Updates the game area based on the current block and movement.
{
    int create_location; 														// Default block generation location, usually in the middle.
    int block_x_index; 															// Index of the block's x position.
    int block_y_index = 0; 														// Index of the block's y position.
    for (int game_y_index = 0; game_y_index < size.y; game_y_index++) { 		// Iterates over the game area rows.
        create_location = size.x / 2 + moveOffset; 								// Adjusts the creation location based on user input.
        block_x_index = 0; 														// Resets the block's x index.
        for (int game_x_index = 0; game_x_index <= size.x; game_x_index++) {
            switch (divide_blocks) { 											// Determines whether to place ACTIVEBLOCK or SPACE based on the block type.
                case 0:
                    CALL1 bls.block1 CALL2
                    break;
                case 1:
                    CALL1 bls.block2 CALL2
                    break;
                case 2:
                    CALL1 bls.block3 CALL2
                    break;
                case 3:
                    CALL1 bls.block4 CALL2
                    break;
                case 4:
                    CALL1 bls.block5 CALL2
                    break;
                case 5:
                    CALL1 bls.block6 CALL2
                    break;
                case 6:
                    CALL1 bls.block7 CALL2
                    break;
            }
        }
    }
}

void renderGameArea (char *game_area[], Size size, int speed) 					// Renders the game area to the terminal.
{
    system("clear"); 															// Clears the terminal screen.
    for (int i = 0; i < size.y + 1; i++) {
        printf("%s\n", game_area[i]); 											// Prints each row of the game area.
    }
    usleep(FALLINGSPEED - speed); 												// Controls the falling speed of the block. The higher the speed, the faster the block falls.
}

void print_ctrl (int sizey, char *game_area[], int *block_y_index, int *create_location, int block[5][5], int *block_x_index, int game_y_index, int *game_x_index, int divide_blocks, int offset)
// Manages the placement of blocks within the game area.
{
    if (block[*block_y_index][*block_x_index] && *game_x_index == *create_location && game_y_index == *block_y_index + offset) {
        // If the block is in the correct position, mark it as ACTIVEBLOCK.
        game_area[game_y_index][*game_x_index] = ACTIVEBLOCK; 					// Place ACTIVEBLOCK in the game area.
        (*game_x_index)++; 														// Move to the next x position in the game area.
        if (block[*block_y_index][++(*block_x_index)] == 1) { 					// If there's more to print in this row.
            (*create_location)++; 												// Move the creation location to the right.
            print_ctrl(sizey, game_area, block_y_index, create_location, block, block_x_index, game_y_index, game_x_index, divide_blocks, offset); 
																				// Recursively call to continue printing.
        } else {
            (*game_x_index)--; 													// If nothing more to print, reset the x position.
            (*block_y_index < 5) ? ((*block_y_index)++) : ((*block_y_index) = 0); 
																				// Move to the next row of the block if not complete.
        }
    } else if (((block[*block_y_index][(*block_x_index) + 1]) || block[*block_y_index][(*block_x_index) + 2]) && block[*block_y_index][*block_x_index] == 0 && (*game_x_index) != 0) {
        // If the block needs to be printed in one or two spaces later.
        (*block_x_index)++; 													// Move to the next x position in the block.
        (*create_location)++; // Move the creation location to the right.
        print_ctrl(sizey, game_area, block_y_index, create_location, block, block_x_index, game_y_index, game_x_index, divide_blocks, offset); 
																				// Recursively call to continue printing.
        (*create_location)--; 													// Reset the creation location.
    } else if (*game_x_index != 0) { 											// If not at the first column of the game area.
        (*block_x_index) = 0; 													// Reset the block's x index.
        game_area[game_y_index][*game_x_index] != BLOCK ? (game_area[game_y_index][*game_x_index] = SPACE) : (game_area[game_y_index][*game_x_index] = game_area[game_y_index][*game_x_index]); 												  // Clean the game area space.
    }
}

void hardening (char *game_area[], Size size) 									// Converts each ACTIVEBLOCK to a BLOCK.
{
    for (int game_y_index = 0; game_y_index < size.y; game_y_index++) { 		// Iterates over the game area rows.
        for (int game_x_index = 0; game_x_index <= size.x; game_x_index++) {
            game_area[game_y_index][game_x_index] == ACTIVEBLOCK ? (game_area[game_y_index][game_x_index] = BLOCK) : (game_area[game_y_index][game_x_index] = game_area[game_y_index][game_x_index]); 											  // Converts ACTIVEBLOCK to BLOCK.
        }
    }
}
