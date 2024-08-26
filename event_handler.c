// event_handler.c

#include <stdio.h>
#include <stdlib.h>

// Handles various error events based on the given type.
void event_handler(int type)
{
	switch (type) {
		case 0:
			printf("Error! Please correctly input size. (e.g. -20 -21)\n");
			system("stty icanon");   											// Restore terminal settings to canonical mode.
			system("stty echo");     											// Re-enable echoing of input characters.

			exit(0);  															// Exit due to incorrect size input.
			break;

		case 1:
			printf("Something went wrong, please contact the developer.\n");
			system("stty icanon");
			system("stty echo");

			exit(1);  															// Exit due to an unspecified error.
			break;

		case 2:
			printf("The row length should not be less than 16, and the column length should not be less than 10.\n");
			system("stty icanon");
			system("stty echo");

			exit(2);  															// Exit due to invalid row or column size.
			break;

		case 3:
			printf("Player quit.\n");
			system("stty icanon");
			system("stty echo");

			exit(3);  															// Exit because the player quit the game.
			break;

		case 4:
			system("clear");  													// Clear the terminal screen.
			printf("You failed. :(\nWhy not try again?\n");
			system("stty icanon");
			system("stty echo");

			exit(4);  															// Exit due to game over (player failed).
			break;
	}
}
