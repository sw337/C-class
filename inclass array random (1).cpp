//Justin McCoy
// CSC 1
// program function calculator
// 28 NOV 2016



#include <iostream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 5;

int array1[ARRAY_SIZE];
void InitArray();
void PrintArray(int array1);


int main() // main function hosts all other functions
    {

        InitArray(); /*out array1 */
        PrintArray(array1); /*in array1 */



        return 0;

    }
void InitArray();
    {
    array array1[ARRAY_SIZE];

    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Enter an integer: ";
        cin >> array1[i];
    }

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        cout << array1[i] << " ";
    }

    return 0;
        /*out array1 */
    }





void PrintArray(int array1);
    { //prints out results

    cout<<array1;

    }

