/* This module provides the pseudorandom numbers required to simulate the rolling of a die */

# include <stdlib.h>
# include <time.h>
# include "random.h"

extern void init_random(void) 
{
	srand( (unsigned)time(NULL)); /* initializes the random number generator with an unsigned value that determines the sequence of numbers to be generated */

/* for variety, we use time() to get a diff. value each time the program is run */
}

extern int rand_1_to_n(int n)
{
	double f_rand;
	static double rand_count = (double)RAND_MAX + 1.0;

	/* but is static of any use here ? bcuz the expressions gonna get evalutated either way ??? */

	f_rand = (double)rand() / rand_count; /* rand used to get a pseudorandom number and then it is scaled to the desired range */
	return (int)(n * f_rand +1);
}
