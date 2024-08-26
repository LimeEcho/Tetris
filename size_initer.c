// size_initer.c

#include <string.h>
#include "Tetris_header.h"

// Initializes the size structure based on command-line arguments.
Size size_initer(int argc, char *argv[])
{
	Size size;
	size.x = size.y = 0;  								// Initialize size to zero.

	if (argc != 3) {
		event_handler(0);  								// Error if the number of arguments is not 3.
		return size;
	} else if ((*++argv)[0] == '-') {
		(*argv)[0] = '0';  								// Replace '-' with '0' for processing.

		int xlen = strlen(*argv);  						// Get the length of the x size argument.

		int xtem;
		for (xtem = 0; xtem < xlen; ++xtem) {
			size.x = size.x * 10 + (*argv)[xtem] - '0'; // Convert string to integer for x size.
		}

		if ((*++argv)[0] == '-') {
			(*argv)[0] = '0';  							// Replace '-' with '0' for processing y size.

			int ylen = strlen(*argv);  					// Get the length of the y size argument.

			int ytem;
			for (ytem = 0; ytem < ylen; ++ytem) {
				size.y = size.y * 10 + (*argv)[ytem] - '0';
														// Convert string to integer for y size.
			}

		} else {
			event_handler(0);  							// Error if the second argument does not start with '-'.
			return size;
		}
	} else {
		event_handler(0);  								// Error if the first argument does not start with '-'.
		return size;
	}

	return size;  										// Return the initialized size structure.
}
