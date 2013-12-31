#include "tictactoe.h"
#include <stdio.h>

/*
AUTHOR: Dhruv Bhaskar
LAST MODIFIED: 31th December 2013
*/

/* Print the game board */
void print_board (char board[])
{
	printf ("\n %c | %c | %c \n", board[0], board[1], board[2]);
	printf ("---|---|--- \n");
	printf (" %c | %c | %c \n", board[3], board[4], board[5]);
	printf ("---|---|--- \n");
	printf (" %c | %c | %c \n", board[6], board[7], board[8]);
	printf("\n");
}

/* Prompt user for next move */
void user_turn (char board[])
{
	printf ("Enter the position : ");
	int i;
	scanf ("%d", &i);
	if (board[i - 1] == 'o' || board[i - 1] == 'x')
	{
		// position already filled
		printf ("INVALID ENTRY \n");
		user_turn (board);
	}
	else
		board[i - 1] = 'x';
}

/* Computer's turn for easy level, fills places randomly */
void comp_random (char board[])
{
	int i = rand () % 8; // generate random number between 0 and 8
	if (board[i] == 'x' || board[i] == 'o') // if position already filled		
		comp_random (board);
	else
		board[i] = 'o';
}

/* Computer's turn for advanced level */
void comp_turn (char board[])
{
	int y;
	for (y = 0; y < 9; y++)
	{
		if (comp_check (board, y))
		{
			board[y] = 'o';
			// computer will play at the position where it has a chance of winning
			return;
		}
	}

	// if the computer does not have a chance of winning in the next move  
	for (y = 0; y < 9; y++)
	{
		if (user_check (board, y))
		{
			board[y] = 'o';
			// computer will play so that the user cannot win
			return;
		}
	}

	// both the user and the computer do not have a chance of winning in the next move, hence computer fills randomly
	comp_random (board);
}

/* Check if computer can win in the next move */
int comp_check (char board[], int i)
{
	int temp = board[i];
	if (board[i] != 'x' && board[i] != 'o')
	{
		board[i] = 'o';
		if (check_win (board))
		{
			board[i] = temp;
			return 1;
		}
		board[i] = temp;
	}
	return 0;
}

/* Check if user can win in the next move */
int user_check (char board[], int i)
{
	int temp = board[i];
	if (board[i] != 'x' && board[i] != 'o')
	{
		board[i] = 'x';
		if (check_win (board))
		{
			board[i] = temp;
			return 1;
		}
		board[i] = temp;
	}
	return 0;
}

/* Check if the user or the computer has won the game */
int check_win (char board[])
{
	int i;
	for (i = 0; i < 7; i = i + 3)
	{
		// check rows
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2])
			return 1;
	}

	for (i = 0; i < 3; i = i + 1)
		{
		int m = i;
		// check columns
		if (board[m] == board[m + 3] && board[m + 3] == board[m + 6])
			return 1;
	}

	// check diagonals
	if (board[0] == board[4] && board[4] == board[8])
		return 1;

	if (board[2] == board[4] && board[4] == board[6])
		return 1;

	return 0;
}
