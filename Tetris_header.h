// Tetris_header.h

#ifndef TetrisHeader
#define TetrisHeader

void event_handler (int);
typedef struct{
	unsigned int x;
	unsigned int y;
} Size;
typedef struct{
	int block1[5][5];
	int block2[5][5];
	int block3[5][5];
	int block4[5][5];
	int block5[5][5];
	int block6[5][5];
	int block7[5][5];
} Blocks;
Size size_initer (int, char *[]);
void initGameArea (char *[], Size);
void updateGameArea (char *[], int, Size, Blocks, int, int);
void renderGameArea (char *[], Size, int);
#define FALLINGSPEED 1000000 / 2
#define SIDE '#'
#define BLOCK '*'
#define SPACE ' '
#define ACTIVEBLOCK '@'
#define MOVESTEP 1
#define FASTERFALLING 2
void hardening (char *[], Size);
Blocks InitialBlocks(void);
int rand_num_giver (int);
int collision_testing (char *[], int *, Size, int *, int *, int *, int *);
void *keyboard_listener(void*);
#define MOVELEFTKEY 'a'
#define MOVERIGHTKEY 'd'
#define CHANGEBLOCKKEY 'w'
#define FASTFALLKEY 'f'
#define QUITKEY 'q'
typedef struct {
	int *move_step;
	Blocks **bls;
	int *fast_falling;
	int *L_move_possibility;
	int *R_move_possibility;
	int *changing_state_possibility;
} args4mmntCtr;
Blocks blockState1(void);
Blocks blockState2(void);
Blocks blockState3(void);
void swap (char *[], Size);

#endif
