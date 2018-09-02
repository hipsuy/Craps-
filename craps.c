/* This is a general purpose game module that may well be used for any other betting game */

# include <stdio.h>
# include <stdlib.h>
# include "game.h"

static void get_stake( double *); /* reads and validates the user's stake */
static void get_bet(double *, double); /* reads and validates the user's bet */

int main()
{

	outcome_t outcome; 
	double stake;
	double bet;
	char another; /* used to store 'y'/'Y' or 'n'/'N' to decide to play another round */
	

	init_game();
	get_stake(&stake);

	do{
		get_bet( &bet, stake);
		play_round( &outcome);
		
		if(outcome == WON){
			stake += bet;
			printf("\n\tYe win, * luck -_- * \n");
		}	
		else{
			stake -= bet;
			printf("\n\tYe lose, poor thing ;)\n");
		}
		
		printf("\n\tYe now have %.2lf left.\n", stake);

		if( stake == 0.0){
			printf("\n\tOops, thou art broke now!\n");
			another = 'n';
		}
		else{
			printf("\n\tWould ye love to play another round (y/n)?\n\t:");
			getchar();
			scanf("%c", &another);
		}
		



	}while((another == 'y') || (another == 'Y'));

	printf("\n\tWell, nice to see you, let's play again sometime!\n");
	printf("\n\nYe, whom'st hath sown the seeds, shall reap.\n\t-hipsuy\n\n");
	
	return EXIT_SUCCESS;
}

static void get_stake( double * stake_p)
{
	printf("\n\n\tHow much doth ye have for betting, gentleman?\n\t:");

	while(1){
		scanf("%lf", stake_p);
		if(*stake_p > 0.0)
		break;
		printf("\n\tInvalid stake -- try again, ye genius!\n\t:");
	}
}

static void get_bet( double * bet_p, double stake)
{
	printf("\n\n\tHow much doth ye wish to bet?\n\t:");

	while(1){
		scanf("%lf", bet_p);
		if((*bet_p > 0.0) && ( *bet_p <= stake))
		break;
		printf("\n\tInvalid bet -- try again!\n\t:");
	}
		
}
