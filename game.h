/* game.h */

typedef enum { LOST, WON } outcome_t; /* an enumerated data type for the variable "outcome" */ 

extern void init_game(void); /* for initializing game module */
extern void play_round(outcome_t *outcome_p); /* for playing one round of the game */
