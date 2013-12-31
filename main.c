#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
AUTHOR: Dhruv Bhaskar
LAST MODIFIED: 31th December 2013
*/

void comp_move (char board[], int i);

int main (int argc, char *argv[])
{
	char str1[10];
	char str2[10];
	strcpy (str1, "easy");
	strcpy (str2, "advanced");
	
	srand (time (NULL));
	
	if (argc < 2) // if no argument is given
		printf("\n\nUsage : Give argument 'easy' for easy or 'advanced' for advanced level \n\n");
	else if (strcmp (str1, argv[1]) != 0 && strcmp (str2, argv[1]) != 0) // if argument is not typed correctly
		printf ("\nARGUMENT NOT RECOGNIZED \n \n");
	else
	{
		printf ("\nTIC-TAC-TOE \n \n");
		
		char board[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		int i;
		print_board (board);
		
		if (strcmp (str1, argv[1]) == 0) // if run in easy mode
			i = 0;
		else // run in advanced mode
			i = 1; 

		int turn_number = 0;
		int is_win = 0; // flag that indicates that the game is won

		while (turn_number < 9)
		{
			if (turn_number % 2 == 0)
				user_turn(board);
			else
				comp_move(board, i);
				
			turn_number++;
			print_board (board);
			
			if (check_win(board))
			{	
				if (turn_number % 2 == 1)
					printf("\n\nYou Win!\n\n");
				else
					printf("\n\nComputer Wins!\n\n");
				is_win = 1;
				break;
			}
		}

		if (is_win == 0) // all turns are over and no one wins, then its a draw
		printf("\n\nIts's a draw!\n\n");		
	}
	return 0;
}

/* Pick turn for computer */
void comp_move (char board[], int i)
{
	if (i == 0) // game run in easy mode
		comp_random (board);
	else // game run in advanced mode
		comp_turn (board);
}