// ===========================================================
// CS 211 – Project 2: 2048
// Student: Jin Yilun(J288R328) and Coytt Chiarolanza(V787Q989)
// File: 2048_helper.h
// ===========================================================
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_board(int board[][5])
{
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
                cout << ".\t";
            else
                cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

/* Move all tiles to the left and merge identical values */
void move_left(int board[][5], int numrows)
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
                    board[current_row][free_loc - 1] =
                        board[current_row][free_loc - 1] + board[current_row][i];
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
void move_right(int board[][5], int numrows)
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
                    board[current_row][free_loc + 1] =
                        board[current_row][free_loc + 1] + board[current_row][i];
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
void move_up(int board[][5], int numrows)
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
                    board[free_loc - 1][current_col] =
                        board[free_loc - 1][current_col] + board[r][current_col];
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
void move_down(int board[][5], int numrows)
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
                    board[free_loc + 1][current_col] =
                        board[free_loc + 1][current_col] + board[r][current_col];
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

void insert_random(int board[][5], int numrows)
{
    srand(time(0));
    int r, c;
    do
    {
        r = rand() % numrows;
        c = rand() % 5;
    } while (board[r][c] != 0);

    int value = (rand() % 10 == 0) ? 4 : 2;
    board[r][c] = value;
}
