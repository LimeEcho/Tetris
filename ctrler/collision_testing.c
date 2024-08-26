// collision_testing.c
#include "../Tetris_header.h"
int collision_testing (char *ui[], int *y_move_step, Size size, int *L_move_possibility, int *R_move_possibility, int *move_step, int *changing_state_possibility)
{
	int moveable = 0;

	for (int y_index = 0; y_index < size.y; y_index++){
		for (int x_index = 0; x_index < size.x; x_index++){
			if (ui[y_index][x_index] == ACTIVEBLOCK){
				if (ui[y_index + 1][x_index] == SPACE || ui[y_index + 1][x_index] == ACTIVEBLOCK){
					moveable = 1;
				}else{
					if (y_index == 0)
						event_handler (4);
					moveable = 0;
					break;
				}
			}
		}
	}
	int left_moveable = 1, right_moveable = 1;
	for (int y_index = 0; y_index < size.y; y_index++){
		for (int x_index = 0; x_index <= size.x; x_index++){
			if (ui[y_index][x_index] == ACTIVEBLOCK){
				if (ui[y_index][x_index + 1] == SIDE){
					*changing_state_possibility = 0;
					if (!moveable)
						*move_step = 0;
					right_moveable = 0;
				}
				if (ui[y_index][x_index - 1] == SIDE){
					if (!moveable)
						*move_step = 0;
					left_moveable = 0;
					*changing_state_possibility = 0;
				}
			}
		}
	}
	*R_move_possibility = right_moveable;
	*L_move_possibility = left_moveable;
	if (moveable){
		(*y_move_step)++;
		return 0;
	}

	return 1;
}
