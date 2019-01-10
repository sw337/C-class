//Justin McCoy, ,Antony Charles, Ana Marroquin
// CSC 110
// Random number array assignment
// Create an array and fill it with random numbers you generate
// 29 NOV 2016



#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> //time is important

using namespace std;

const int ARRAY_SIZE = 5; // set a constant array size which can be changed without changing all of the code
int array1[ARRAY_SIZE]; // creates array based on the array size
void InitArray(); // declares the initial function which initializes the values
void PrintArray(int array1); //declare function that prints out the values


int main() // main function hosts all other functions
    {

        InitArray(); /*out array1 */
        PrintArray(array1[ARRAY_SIZE]); /*in array1 */



        return 0; // ends the program

    }
void InitArray()
    {
    int i; // creates the variable i
    srand(time(0)); // seeds random number

    for (i = 0; i < ARRAY_SIZE; i++)
    {

    array1[i]=rand()%100; // generates random number below 100 and assigns it to a place in the array

    }



        /*out array1 i */
    }





void PrintArray(int i)  /*in array1 i*/
    { //prints out results

    for (i =0; i <ARRAY_SIZE; i++)
    {
        cout << array1[i] << " "; // prints out individual numbers in array separated by a space
    }


    }

