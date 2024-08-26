// rand_num_giver.c

#include <stdlib.h>
#include <sys/time.h>

// Generates a random number between 0 and max-1.
int rand_num_giver(int max) {
	struct timeval tv;
	gettimeofday(&tv, NULL);  					// Get the current time to seed the random number generator.
	srand(tv.tv_sec * 1000000 + tv.tv_usec);  	// Seed the random number generator with microseconds.

	int or = rand();  							// Generate a random number.
	return or % max;  							// Return a random number in the range [0, max-1].
}
