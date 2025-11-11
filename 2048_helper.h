// ===========================================================
// CS 211 – Project 2: 2048
// Student: Jin Yilun(J288R328) and Coytt Chiarolanza(V787Q989)
// File: 2048_helper.h
// ===========================================================
#pragma once
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

//PRINT BOARD FUNCTION
void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}

/* Move all tiles to the left and merge identical values */
void move_left(int board[][5], int numrows = 5)
{
	for (int current_row = 0; current_row < numrows; current_row++)
	{
		int free_loc = 0;
		bool already_merged = false;

		for (int i = 0; i < 5; i++)
		{
			if (board[current_row][i] != 0)
			{
				if (free_loc > 0 &&
					board[current_row][free_loc - 1] == board[current_row][i] &&
					already_merged == false)
				{
					board[current_row][free_loc - 1] += board[current_row][i];
					board[current_row][i] = 0;
					already_merged = true;
				}
				else
				{
					int temp = board[current_row][i];
					board[current_row][i] = 0;
					board[current_row][free_loc] = temp;
					free_loc++;
					already_merged = false;
				}
			}
		}
	}
}

/* Move all tiles to the right and merge identical values */
void move_right(int board[][5], int numrows = 5)
{
	for (int current_row = 0; current_row < numrows; current_row++)
	{
		int free_loc = 4;
		bool already_merged = false;

		for (int i = 4; i >= 0; i--)
		{
			if (board[current_row][i] != 0)
			{
				if (free_loc < 4 &&
					board[current_row][free_loc + 1] == board[current_row][i] &&
					already_merged == false)
				{
					board[current_row][free_loc + 1] += board[current_row][i];
					board[current_row][i] = 0;
					already_merged = true;
				}
				else
				{
					int temp = board[current_row][i];
					board[current_row][i] = 0;
					board[current_row][free_loc] = temp;
					free_loc--;
					already_merged = false;
				}
			}
		}
	}
}

/* Move all tiles upward and merge identical values */
void move_up(int board[][5], int numrows = 5)
{
	for (int current_col = 0; current_col < 5; current_col++)
	{
		int free_loc = 0;
		bool already_merged = false;

		for (int r = 0; r < numrows; r++)
		{
			if (board[r][current_col] != 0)
			{
				if (free_loc > 0 &&
					board[free_loc - 1][current_col] == board[r][current_col] &&
					already_merged == false)
				{
					board[free_loc - 1][current_col] += board[r][current_col];
					board[r][current_col] = 0;
					already_merged = true;
				}
				else
				{
					int temp = board[r][current_col];
					board[r][current_col] = 0;
					board[free_loc][current_col] = temp;
					free_loc++;
					already_merged = false;
				}
			}
		}
	}
}

/* Move all tiles downward and merge identical values */
void move_down(int board[][5], int numrows = 5)
{
	for (int current_col = 0; current_col < 5; current_col++)
	{
		int free_loc = numrows - 1;
		bool already_merged = false;

		for (int r = numrows - 1; r >= 0; r--)
		{
			if (board[r][current_col] != 0)
			{
				if (free_loc < numrows - 1 &&
					board[free_loc + 1][current_col] == board[r][current_col] &&
					already_merged == false)
				{
					board[free_loc + 1][current_col] += board[r][current_col];
					board[r][current_col] = 0;
					already_merged = true;
				}
				else
				{
					int temp = board[r][current_col];
					board[r][current_col] = 0;
					board[free_loc][current_col] = temp;
					free_loc--;
					already_merged = false;
				}
			}
		}
	}
}

//Insert a random number {2,4} at an empty slot on board
void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}
