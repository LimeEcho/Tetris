#include "../Tetris_header.h"
void swap (char *ui[], Size size)
{
	for (int y_index = 0; y_index < size.y; y_index++){
		int full_of_blocks = 1;
		for (int x_index = 1; x_index < size.x; x_index++){
			if (ui[y_index][x_index] != BLOCK){
				full_of_blocks = 0;
			}
		}
		if (full_of_blocks){
			for (int swapping_y_index = y_index; swapping_y_index > 0; swapping_y_index--){
				for (int swapping_x_index = 0; swapping_x_index < size.x + 1; swapping_x_index++)
					ui[swapping_y_index][swapping_x_index] = ui[swapping_y_index - 1][swapping_x_index];
			}
		}
	}
}
