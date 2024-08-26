#include "../Tetris_header.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void *keyboard_listener (void *arg)
{
	args4mmntCtr *args = (args4mmntCtr *)arg;
	int *move_step = args -> move_step;
	Blocks **bls = args -> bls;
	int *fast_falling = args -> fast_falling;
	int *L_move_possibility = args -> L_move_possibility;
	int *R_move_possibility = args -> R_move_possibility;
	int *changing_state_possibility = args -> changing_state_possibility;

	int block_state = 0;
	while (1){
		fflush (stdin);
		switch (getchar()){
			case 'd':
				if (*R_move_possibility)
					(*move_step) += MOVESTEP;
				break;
			case 'a':
				if (*L_move_possibility)
					(*move_step) -= MOVESTEP;
				break;
			case 'w':
				if (*changing_state_possibility){
					block_state++;
					if (*bls)
						free (*bls);
					(*bls) = malloc (sizeof (Blocks));
					switch (block_state % 4){
						case 0:
							block_state = 0;
							(**bls) = InitialBlocks();
							break;
						case 1:
							(**bls) = blockState1();
							break;
						case 2:
							(**bls) = blockState2();
							break;
						case 3:
							(**bls) = blockState3();
							break;

					}
				}
				break;
			case 'f':
				(*fast_falling) = FALLINGSPEED - FASTERFALLING;
				break;
			case 'q':
				event_handler (3);
				break;
		}
	}
}

