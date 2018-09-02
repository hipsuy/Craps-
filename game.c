/* This module contains the code specific to CRAPS */

# include "game.h"
# include "random.h"
# include <stdio.h>
static int roll_dice(); /* simulates rolling of dice */

/* functions which determine the outcome of a round
They are accessed via the same array of pointer and hence are declared with the same types, even when "win" and "lose" don't need an argument */
static outcome_t win(int); /* always return WON */
static outcome_t lose(int); /* always return LOST */
static outcome_t play_on(int); /* continues play acc. to the rules */


typedef outcome_t (*fct_ptr_t)(int); /* fct_ptr_t defined as a type which points to a function which takes an int argument and returns a value of type outcome_t */

/* an array of function pointers which determines gameplay for first roll of dice -- BEAUTY ALERT!! */
static fct_ptr_t action_tab[13] = { lose, lose, lose, lose, play_on, play_on, play_on, win, play_on, play_on, play_on, win, lose}; /* first two entries are dummies because 0 and 1 can't be the sum of numbers on two dicd */



extern void init_game()
{
	init_random();
}

extern void play_round( outcome_t * outcome_p)
{
	int roll = roll_dice();
	*outcome_p = action_tab[roll](roll); /* roll used as a subscript to action_tab and then as an argument to the function called */
}




static int roll_dice()
{
	int die_1 = rand_1_to_n(6);
	int die_2 = rand_1_to_n(6);
	 
	printf("\n\tYe rolled a %d and a %d.\n", die_1, die_2);
	return die_1 + die_2;
}

static outcome_t win(int point)
{
	return WON;
}

static outcome_t lose(int point)
{
	return LOST;
}

static outcome_t play_on(int point)
{
	int roll;
	do{
		roll = roll_dice();
		if(roll == 7)
		return LOST;
	}while(roll != point);
	return WON;	
}
