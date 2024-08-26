// main.c
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "Tetris_header.h"

int main(int argc, char *argv[])
{
	system ("stty -icanon");					// Allow the program to read stdin without requiring <CR>.
	system ("stty -echo");						// Disable echoing of input characters.

	Blocks *bls = malloc(sizeof(Blocks));		// Allocate memory for storing the blocks.
	*bls = InitialBlocks();						// Initialize the default blocks.
	Size size = size_initer(argc, argv);		// Get the game area size based on user input.

	if (size.x != 0 && size.y != 0) {			// If size is valid.
		if (size.x < 16 || size.y < 10)			// Check if the size is too small (which may cause memory issues).
			event_handler(2);					// Handle the error event.

		char *game_area[size.y + 1];			// Define the game area.

		int divide_blocks = rand_num_giver(7);	// Generate a random block index.
		int y_move_step = 0;					// Y-axis offset (vertical movement).
		int move_step = 0;						// X-axis offset (horizontal movement).
		int fast_falling = 0;					// Enable fast dropping of the block.
		int L_move_possibility = 1;				// Prevent the block from moving out of bounds (left).
		int R_move_possibility = 1;				// Prevent the block from moving out of bounds (right).
		int falling_possibility = 1;			// Determine if the block can keep falling.
		int changing_state_possibility = 1;		// Disable rotation if the block is against a wall.

		initGameArea(game_area, size);			// Initialize the game area.

		args4mmntCtr args;						// Arguments for 'keyboard_listener', the secondary thread.
		args.move_step = &move_step;
		args.bls = &bls;
		args.fast_falling = &fast_falling;
		args.L_move_possibility = &L_move_possibility;
		args.R_move_possibility = &R_move_possibility;
		args.changing_state_possibility = &changing_state_possibility;

		pthread_t kbd_listener;					// Create the secondary thread for keyboard input.
		pthread_create(&kbd_listener, NULL, keyboard_listener, (void*)&args);

		while (1) {
			updateGameArea(game_area, divide_blocks, size, *bls, y_move_step, move_step);
												// Update the game area with the current block position.

			changing_state_possibility = 1;		// Reset rotation possibility. 
												// 'collision_testing' will decide based on the current state.

			falling_possibility = collision_testing(game_area, &y_move_step, size, &L_move_possibility, &R_move_possibility, &move_step, &changing_state_possibility);
												// Determine if the block can continue falling.

			swap(game_area, size);				// Clear any full lines and shift down the blocks.

			if (falling_possibility) {			// If the block has reached the bottom.
				fast_falling = 0;				// Reset the falling speed.
				hardening(game_area, size);		// Convert ACTIVE_BLOCKs to BLOCKs.

				divide_blocks = rand_num_giver(7);	
												// Generate the next block.
				y_move_step = 0;				// Reset to the top position.
			}

			renderGameArea(game_area, size, fast_falling);	
												// Render the game area to the screen.
		}
	}
}
