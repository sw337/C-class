#include <iostream>
#include <iomanip>
#include <array>
#include "battleship.h"

using namespace std;

void InitializeBoard(BoardArray);
void DisplayBoard(BoardArray, int rowsUsed, int colsUsed);
void InitializeShips(Ship ships[]);
void InitializeShip(Ship& ship);
void PlaceShip(BoardArray, Ship&, PositionType, Orientation);
bool IsValid(Ship, PositionType);


int main()
{
    int rowsUsed = MAX_ROWS,
        colsUsed = MAX_COLS;

    BoardArray board;
    Ship ships[MAX_SHIPS];

    InitializeBoard(board);
    DisplayBoard(board, rowsUsed, colsUsed);
    cout << endl << endl;
    InitializeShips(ships);








}


//************************************************************Functions**************************
void InitializeBoard(BoardArray board){
    for (int i = 0; i < MAX_ROWS; i++)
        {
            for(int j = 0; j < MAX_COLS; j++){
            board[i][j] = '~';
            }
        }
}
//*********************************************************************************************
void DisplayBoard(BoardArray board, int rowsUsed, int colsUsed){
     for (int i = 0; i < MAX_ROWS; i++)
        {
            for(int j = 0; j < MAX_COLS; j++){
            cout << board[i][j];
            }
            cout << endl;
        }
}
//************************************************************************************************
void InitializeShips(Ship ships[]){

    for(int i = 0; i < MAX_SHIPS ; i++)
        {
        InitializeShip(ships[i]);
        }

    for(int j = 1; j <= MAX_SHIPSIZE; j++)
        {
        ships[j-1].size = j;
        cout << ships[j-1].size;
        }
}
//***********************************************************************************************
void InitializeShip(Ship &ship){

    for(int i = 0; i < MAX_SHIPSIZE; i++){
        ship.status[i] = false;
        ship;
    }
}
//***********************************************************************************************
void PlaceShip(BoardArray, Ship& ship, PositionType, Orientation ){



}
bool IsValid(Ship, PositionType){



}
