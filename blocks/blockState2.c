// blockState2.c

#include "../Tetris_header.h"

Blocks blockState2(void){		// The third state of the blocks, rotated 180 degrees clockwise.
	Blocks bl = {0};
	bl.block1[0][0] = 1;
	bl.block1[0][1] = 1;
	bl.block1[0][2] = 1;
	bl.block1[0][3] = 1;
	/*  
		0000
		*/
	bl.block2[0][0] = 1;
	bl.block2[0][1] = 1;
	bl.block2[0][2] = 1;
	bl.block2[1][2] = 1;
	/*  
		000
		  0
		*/
	bl.block3[0][0] = 1;
	bl.block3[0][1] = 1;
	bl.block3[0][2] = 1;
	bl.block3[1][0] = 1;
	/*  
		000
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
	bl.block5[0][1] = 1;
	bl.block5[0][2] = 1;
	bl.block5[1][0] = 1;
	bl.block5[1][1] = 1;
	/*  
		 00
		00
		*/
	bl.block6[0][0] = 1;
	bl.block6[0][1] = 1;
	bl.block6[0][2] = 1;
	bl.block6[1][1] = 1;
	/*  
		000
		 0
		*/
	bl.block7[0][0] = 1;
	bl.block7[0][1] = 1;
	bl.block7[1][1] = 1;
	bl.block7[1][2] = 1;
	/*  
		00
		 00
		*/
	return bl;
}
