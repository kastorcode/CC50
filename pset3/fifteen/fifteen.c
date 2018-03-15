/***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int
main(int argc, char *argv[])
{
	// greet user with instructions
	greet();

	// ensure proper usage
	if (argc != 2)
	{
		printf("Uso: %s d\n", argv[0]);
		return 1;
	}

	// ensure valid dimensions
	d = atoi(argv[1]);
	if (d < DIM_MIN || d > DIM_MAX)
	{
		printf("Escolha um valor entre %d x %d e %d x %d.\n",
		 DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
		return 2;
	}

	// initialize the board
	init();

	// accept moves until game is won
	while (true)
	{
		// clear the screen
		clear();

		// draw the current state of the board
		draw();

		// check for win
		if (won())
		{
			printf("\033[36mftw!\n");
			break;
		}

		// prompt for move
		printf("\033[39mMover peça: ");
		int tile = GetInt();

		// move if possible, else report illegality
		if (!move(tile))
		{
			printf("\033[31mMovimento ilegal.\n");
			usleep(500000);
		}

		// sleep thread for animation's sake
		//usleep(500000);
	}

	// that's all folks
	return 0;
}

/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

/*
 * Greets player.
 */

void
greet(void)
{
	clear();
	printf("\033[1mBEM-VINDO AO JOGO DOS QUINZE! POWERED BY RAMALHOLIVEIRA\n");
	usleep(3000000);
}

/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
	int n = d*d-1;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			board[i][j] = n--;
	if (!(d % 2))
		board[d-1][d-2] = 2, board[d-1][d-3] = 1;
}

/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			if (board[i][j] == 0)
				printf(" \033[32m_  ");
			else
				printf("\033[32m%2d  ", board[i][j]);
		}
		printf("\n\n");
	}
}

/* 
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

int a, l;
bool al = true;

bool
move(int tile)
{
	if (al) {
		a = d-1, l = d-1;
		al = false;
	}

	if (tile == 0)
		return false;

	if (tile == board[a][l-1]) {
		board[a][l] = tile;
		board[a][l-1] = 0;
		l--;
		return true;
	}

	if (tile == board[a][l+1]) {
		board[a][l] = tile;
		board[a][l+1] = 0;
		l++;
		return true;
	}

	if (tile == board[a-1][l]) {
		board[a][l] = tile;
		board[a-1][l] = 0;
		a--;
		return true;
	}

	if (tile == board[a+1][l]) {
		board[a][l] = tile;
		board[a+1][l] = 0;
		a++;
		return true;
	}
	else
		return false;
}

/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
	int w = 1;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++)
			if (w == board[i][j]) {
				w++;
				if (w == d * d)
					return true;
			}
	return false;
}
