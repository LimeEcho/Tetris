// blockState3.c

#include "../Tetris_header.h"

Blocks blockState3(void){		// The fourth state of the blocks, rotated 270 degrees clockwise.
	Blocks bl = {0};
	bl.block1[0][0] = 1;
	bl.block1[1][0] = 1;
	bl.block1[2][0] = 1;
	bl.block1[3][0] = 1;
	/*  
		0
		0
		0
		0
		*/
	bl.block2[0][1] = 1;
	bl.block2[1][1] = 1;
	bl.block2[2][0] = 1;
	bl.block2[2][1] = 1;
	/*  
		 0
		 0
		00
		*/
	bl.block3[0][0] = 1;
	bl.block3[0][1] = 1;
	bl.block3[1][1] = 1;
	bl.block3[2][1] = 1;
	/*  
		00
		 0
		 0
		*/
	bl.block4[0][0] = 1;
	bl.block4[0][1] = 1;
	bl.block4[1][0] = 1;
	bl.block4[1][1] = 1;
	/*  
		00
		00
		*/
	bl.block5[0][0] = 1;
	bl.block5[1][0] = 1;
	bl.block5[1][1] = 1;
	bl.block5[2][1] = 1;
	/*  
		0
		00
		 0
		*/
	bl.block6[0][1] = 1;
	bl.block6[1][0] = 1;
	bl.block6[1][1] = 1;
	bl.block6[2][1] = 1;
	/*  
		 0
		00
		 0
		*/
	bl.block7[0][1] = 1;
	bl.block7[1][0] = 1;
	bl.block7[1][1] = 1;
	bl.block7[2][0] = 1;
	/*  
		 0
		00
		0
		*/
	return bl;
}
