CC = clang
CFLAGS = -Wall -g
TARGET = tetris
SRCS = main.c size_initer.c event_handler.c game_area_ctrler.c blocks/InitialBlock.c rand_num_giver.c ctrler/collision_testing.c ctrler/keyboard_listener.c blocks/blockState1.c blocks/blockState2.c blocks/blockState3.c ctrler/swap.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRCS)

.PHONY: all clean
