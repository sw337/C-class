//Justin McCoy,Antony Charles, Ana Marroquin
// CSC 110
// In-Class Assignment #4
// Random number Generator
// 04 Nov 2016


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


using namespace std;

int main(void) {
	int i; // counter
	int num1; //minimum number variable
	int num2; // maximum number variable
	int amt;  // amount of numbers variable


    cout<< "Welcome to the Random number generator!"<<endl;

    cout << "What is the lowest possible number you want generated? "; // gets user's high for range
    cin >> setw(10) >> num1;

    while (!cin)
    {
        if(!cin) //Checks for invalid characters or the number zero.
            {
                cout << "Invalid number" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> num1;
            }
    }


    cout << "What is the highest possible number you want generated? " ;  // Gets user's high for range
    cin >> setw(10) >> num2;

    while (!cin||num2<=num1) //checks to see if the user entered a higher number than the previous one
    {
        if(!cin) //Checks for invalid characters or the same number as before
            {
                cout << "Invalid number" << endl; // forces user to enter valid number
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> num2;
            }
        else{
                cout << "Max value must be higher, lets try again." << endl; //makes sure the second value is cleared
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> num2;

        }
    }

    cout << "How many random numbers do you want? ";
    cin >> setw(10) >> amt;  // gets the user to enter the amount they want to print

    while (!cin|| amt<= 0)
    {
        if(!cin) //Checks for invalid characters
            {
                cout << "Invalid number" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> amt;
            }
        else{
            cout << "Amount must be greater than 0." << endl; // catches user from trying to enter zero or lower
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> amt;
        }

    }

        srand(time(0)); // seeds the time for random

	for (i = 0; i <= amt; i++) {  //


        cout << num1+ rand() % (num2-num1+1); // verifies that all numbers are within the range the user gave
        cout << endl;
	}


	return 0;
}
