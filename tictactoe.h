#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
AUTHOR: Dhruv Bhaskar
LAST MODIFIED: 31th December 2013
*/

	void print_board (char board[]); /* Print the game board */
	
	void user_turn (char board[]); /* Prompt user for next move */
	
	void comp_random (char board[]); /* Computer's turn for easy level, fills places randomly */
	
	void comp_turn (char board[]); /* Computer's turn for advanced level */
	
	int comp_check (char board[], int i); /* Check if computer can win in the next move */
	
	int user_check (char board[], int i); /* Check if user can win in the next move */
	
	int check_win (char board[]); /* Check if the user or the computer has won the game */
	
#endif
