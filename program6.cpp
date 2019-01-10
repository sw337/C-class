// Justin McCoy
// inclass battleship
// create a working battleship game
// 2 May 2017



#include <iostream>
#include <iomanip>
#include <array>
#include "battleship.h"
#include <ctime>

using namespace std;

void getboardsize(int &MAX_ROWS, int &MAX_COLS, int &MAX_SHIPS);
void InitializeBoard(BoardArray,int MAX_ROWS, int MAX_COLS);
void DisplayBoard(BoardArray, int rowsUsed, int colsUsed,int MAX_ROWS, int MAX_COLS);
void InitializeShips(Ship ships[],int MAX_SHIPS);
void InitializeShip(Ship& ship);
void PlaceShip(BoardArray &board, Ship& ship, int &rowsUsed, int &colsUsed, Orientation& orient,Ship ships[], int &shipz, int MAX_ROWS, int MAX_COLS, int MAX_SHIPS);
bool IsValid(Ship, int rowsUsed, int colsUsed,Ship ships[], Ship ship, int shipz, int MAX_ROWS, int MAX_COLS);
void guess(BoardArray& board,BoardArray& board2,bool &flag);
void isgood(BoardArray& board,BoardArray& board2, int n, int k, int MAX_ROWS, int MAX_COLS, int MAX_SHIPS, bool &flag);
bool sunk(Ship& ship, BoardArray& board,BoardArray& board2);

int main()
{
    int rowsUsed = 0; //
    int colsUsed = 0;
    int shipz = 0;
    int MAX_ROWS = 0;
    int MAX_COLS = 0;
    const int MAX_SHIPSIZE = 5;
    int MAX_SHIPS = 0;
    bool flag;
    int g = 0;

    Ship *lastPtr;      // Points to last element in the list
    Ship *listPtr;      // Points to first element in the list
    Ship *currPtr;      // Points to currently used element (working pointer)
    Ship *newNodePtr;   // Used to point to newly created nodes

    getboardsize(MAX_ROWS, MAX_COLS, MAX_SHIPS);
    BoardArray board;
    BoardArray board2;
    Ship ships[MAX_SHIPS];
    Ship ship;
    PositionType positon;
    Orientation orient;

    InitializeBoard(board, MAX_ROWS, MAX_COLS);
    InitializeBoard(board2, MAX_ROWS, MAX_COLS);
    DisplayBoard(board, rowsUsed, colsUsed,MAX_ROWS, MAX_COLS);
    int k = MAX_SHIPSIZE * MAX_SHIPS;
    int n = MAX_COLS * MAX_ROWS;
    cout << endl << endl;
    InitializeShips(ships,MAX_SHIPS);
    PlaceShip(board,ship, rowsUsed, colsUsed, orient, ships, shipz,MAX_ROWS, MAX_COLS, MAX_SHIPS);

    do{
        guess(board, board2,flag);
        DisplayBoard(board2, rowsUsed, colsUsed,MAX_ROWS, MAX_COLS);
        g++; // have a count timer so the program executes when all possible guesses are made
        if (g >= n){
            flag = false;
                    }
    }while(flag); // run a loop to keep the user guessing until they quit
    cout << "                Game Over! "<< endl;
    DisplayBoard(board, rowsUsed, colsUsed,MAX_ROWS, MAX_COLS);



  return 0;
}

//************************************************************Functions**************************
void InitializeBoard(BoardArray board,int MAX_ROWS, int MAX_COLS){
    /*
     creates board for the user
     */


    for (int i = 0; i < MAX_ROWS; i++)
        {
            for(int j = 0; j < MAX_COLS; j++){
            board[i][j] = '~';
            }
        }
}


//*********************************************************************************************
void DisplayBoard(BoardArray board, int rowsUsed, int colsUsed, int MAX_ROWS, int MAX_COLS){
     /*
     Prints out a board for the user to see their progress as the game continues
     */

     cout<<"      ";
     for (int i = 0; i < MAX_ROWS; i++)
        {
         cout<< i<< ' ';
        }
            cout<< endl;



     for (int i = 0; i < MAX_ROWS; i++)

        {
            cout << i << "     ";
            for(int j = 0; j < MAX_COLS; j++){

            cout << board[i][j]<<' ';
            }
            cout << endl;
        }
}
//************************************************************************************************
void InitializeShips(Ship ships[],int MAX_SHIPS){

    for(int i = 0; i < MAX_SHIPS ; i++)
        {
        InitializeShip(ships[i]);
        }

    for(int j = 1; j <= MAX_SHIPSIZE; j++)
        {
        ships[j-1].size = j;
        }
}
//***********************************************************************************************
void InitializeShip(Ship &ship){

    for(int i = 0; i < MAX_SHIPSIZE; i++){
        ship.status[i] = false;
    }
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orient = None;
}
//***********************************************************************************************
void PlaceShip(BoardArray &board, Ship &ship,int &rowsUsed, int &colsUsed, Orientation& orient, Ship ships[], int &shipz,int MAX_ROWS, int MAX_COLS, int MAX_SHIPS){
    srand(time(0));
    int l = 0;
    while(l < MAX_SHIPS)
    {
        int x = rand() % 2 ; // generates a random number
        int y = rand() % 2 ;

        if (x>=y){ // gives about 5050 odds ships will be horizontal or vertical

            ship.orient = Horizontal;
            l++;

        }
        else if (y>x){
            ship.orient = Vertical;
            l++;

        }

        for(int j = 1; j <= MAX_SHIPSIZE; j++)
        {
        ships[j-1].size = j;

            shipz = ships[j].size; // size of the ship on each interation of j
            rowsUsed = j;
            colsUsed = j;


            {
                    if (ship.orient == Vertical){ // places ships vertically

                                        colsUsed = rand() % MAX_COLS; // random numbers for rows
                                        rowsUsed = rand()  % MAX_ROWS;
                                        int r = colsUsed;
                                        int t= rowsUsed;



                                if(IsValid(ship, rowsUsed, colsUsed,ships, ship, shipz,MAX_ROWS, MAX_COLS)){ // checks if locations are valid
                                                        {


                                        int i =0;
                                        while (i < shipz){

                                        if(board[r+i][t] = '~'){
                                                board[r+i][t] = '#'; // places the location on the part of the board that ne
                                                i++;
                                                            }
                                                            }
                                        }
                                }



                    }
                else if (ship.orient = Horizontal){
                                        colsUsed = rand() % MAX_COLS;
                                        rowsUsed = rand()  % MAX_ROWS;
                                        int r = colsUsed;
                                        int t= rowsUsed;


                                if (IsValid(ship, rowsUsed, colsUsed,ships, ship, shipz,MAX_ROWS, MAX_COLS)){// checks if locations are valid


                                        int i = 0;
                                        while (i <  shipz){
                                        if(board[t+i][r] = '~'){
                                                    board[t+i][r] = '#'; // places the location on the part of the board that ne
                                                    i++;
                                                                }
                                                            }
                                        }

                }

            }
        }

    }
}

bool IsValid(Ship, int rowsUsed, int colsUsed, Ship ships[], Ship ship, int shipz,int MAX_ROWS, int MAX_COLS){

            // test to see if ship can be placed on board and allows it to be placed

         if (rowsUsed+shipz > MAX_ROWS){
            return false;
        }
        if (colsUsed+shipz <= MAX_COLS){
            return true;
        }
        if (colsUsed+shipz > MAX_ROWS){
            return false;
        }
        if (rowsUsed+shipz <= MAX_COLS){
            return true;
        }

}
void getboardsize(int &MAX_ROWS, int &MAX_COLS, int &MAX_SHIPS){

    cout<<"Welcome to Battleship"<<endl;

    cout << "Board sizes over 10 have a tendency to look weird, keep that in mind"<< endl;


    cout<< "How many rows would you like your board"<<endl; // gets size of board
    cin >> MAX_ROWS;

    cout<< "How many colums would you like your board"<<endl;
    cin >> MAX_COLS;

    cout<< "How many ships would you like your board"<<endl; // get number of ships
    cin >> MAX_SHIPS;



}

void guess(BoardArray& board,BoardArray& board2, bool &flag){

    int i = 0;
    int j = 0;
    cout << "Enter a negative Number for row and column  to exit the game program"<< endl; // gives the user an opt out
    cout << "Enter your guess for row"<< endl; // gets user's guest
    cin >> i;
    cout << "Enter your guess for column"<< endl;
    cin >>j;

if (i>=0){

    if(board[i][j] == '~'){

        board2[i][j] = 'O'; // lets the user know they missed
        board[i][j] = 'O'; // lets the user know they hit something
        cout<<endl;
        cout << "              Miss"<< endl;


    }
    else if(board[i][j] == '#'){

        board2[i][j] = 'X'; // changes the board that the user sees
        board[i][j] = 'X'; // changes the hidden board
        cout<<endl;
        cout << "              Hit"<< endl; // lets user know they hit something


    }
            }

          else  if((i<0)&&(j<0)){
                flag = false; // exist program if negative number is entered
                            }

                                cout<< endl;


}

void isgood(BoardArray& board,BoardArray& board2, int n, int k, int MAX_ROWS, int MAX_COLS, int MAX_SHIPS, bool &flag){
    int i = 0;
    int j = 0;
    int r = 0;
    int q = MAX_SHIPS * MAX_SHIPSIZE;

    for (i=0; i <MAX_ROWS; i++){ // loops until maximum rows and colums have been used up
    for (j=0; j <MAX_COLS; j++){
    if((board[i][j] == 'X')||(board[i][j] == 'O')){

            r++;

    if (r >= k){ // keeps running while ships exist

        flag = false;
    }
    else if ((r >= n)||(r=q)){ // allows user to keep guessing

        flag = false;
    }
     else {

        flag = true;
    }

    }
            }


}
}

bool sunk(Ship& ship, BoardArray& board,BoardArray& board2){











}
