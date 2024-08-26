// Initial.c

#include "../Tetris_header.h"

Blocks InitialBlocks(void) {        // Initialize the original state of the 7 blocks.
    Blocks bl = {0};

    bl.block1[0][0] = 1;
    bl.block1[0][1] = 1;
    bl.block1[0][2] = 1;
    bl.block1[0][3] = 1;
    /*  
        0000
    */

    bl.block2[0][0] = 1;
    bl.block2[1][0] = 1;
    bl.block2[1][1] = 1;
    bl.block2[1][2] = 1;
    /*  
        0
        000
    */

    bl.block3[0][2] = 1;
    bl.block3[1][0] = 1;
    bl.block3[1][1] = 1;
    bl.block3[1][2] = 1;
    /*  
          0
        000
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

    bl.block6[0][1] = 1;
    bl.block6[1][0] = 1;
    bl.block6[1][1] = 1;
    bl.block6[1][2] = 1;
    /*  
         0
        000
    */

    bl.block7[0][0] = 1;
    bl.block7[0][1] = 1;
    bl.block7[1][1] = 1;
    bl.block7[1][2] = 1;
    /*  
        00
         00
    */

    return bl;                    // To add a new block: First, add it to Tetris_header.h. Then, add the block to this file, blockState1.c, blockState2.c, and blockState3.c. Finally, increase the argument of ran() in main.c.
}
