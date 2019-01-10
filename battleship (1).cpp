//Nina Salugao & Connor Randlett
//Imagine we are using a two-dimensional array as the basis for creating a one-player game of battleship.
//(The computer generates the board and places the ships and the player has to guess the ship positions.)
//In the game a '~' character represents ocean, a '#' character represents a part of a ship,
//an 'H' character represents a place where a part of a ship has been hit, and a '.' character represents a miss

// Determine what data structures you will need and how they will be defined.
// Determine what functions you will need and specify their prototypes w/ pre/post conditions
// Write the pseudocode for the main function.
// Be prepared to discuss/support your choices.

#include <iostream>
#include <string>
#include <iomanip>
#include "battleship (1).h"

using namespace std;

void InitializeBoard(BoardArray board, PositionType a);
void DisplayBoard(BoardArray board, int row, int column, PositionType a);
void InitializeShips(Ship[]);
void InitializeShip(Ship&);
void PlaceShip(BoardArray&, Ship&, int, int, Orientation);
bool IsValid(Ship, int, int);


int main()
{
    int row = MAX_ROWS;
    int column = MAX_COLS;
    PositionType a;


    BoardArray board;
    InitializeBoard(board, a);
    DisplayBoard(board, row, column, a);


    return 0;
}


//***************************************************************
void InitializeBoard(BoardArray board, PositionType a)
{
   for (a.column = 0; a.column < MAX_COLS; a.column++)
        for (a.row = 0; a.row < MAX_ROWS; a.row++)
        board[a.row][a.column] = '~';



}

//***************************************************************
void DisplayBoard(BoardArray board, int row, int column, PositionType a)
{
    cout << "   ";
    for (char column = 'A'; column < 'K'; column++)
            cout << setw(3) << column;
        cout << endl;

    for (a.row = 0; a.row < MAX_ROWS; a.row++){
        cout << setw(3) << a.row + 1;

        for (a.column = 0; a.column < MAX_COLS; a.column++)
            cout << setw(3) << board[a.row][a.column];
        cout << endl;
    }
}


//***************************************************************
void InitializeShips(Ship ships[])
{
    for (int i = 0; i < MAX_SHIPS; i++)
    {
        InitializeShip(ships[i]);
    }
}


//***************************************************************
void InitializeShip(Ship& ship)
{
    ship.size = 5;
    for (int i = 0; i < MAX_SHIPSIZE; i++)
    {
        ship.status[i] = false;
    }
    ship.position.row = ship.position.column = 0;
    ship.orientation = None;
}

//***************************************************************
void PlaceShip(BoardArray& board, Ship& ship, int row, int column, Orientation orient)
{
    int i;

    ship.position.row = row;
    ship.position.column = column;
    ship.orientation = orient;

    if (IsValid(ship, row, column))
    {
        if (orient == Vertical)
        {
            for (i = 0; i < ship.size; i++)
            {
                board[i + row - 1][column - 1] = '*';
            }
        } else if (orient = Horizontal)
        {
            for (i = 0; i < ship.size; i++)
            {
                board[row - 1][i + column - 1] = '*';
            }
        }
    }
}

