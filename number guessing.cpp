//Justin McCoy,Antony Charles, Ana Marroquin
// CSC 110
// In-Class Assignment #5
// Random number Generator guessing game
// 09 Nov 2016


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


using namespace std;

int main(void) {
	int num1; //random number to be generated
	int guess; // user's guess
	bool flag = false; // bool variable



    srand(time(0)); // seeds random number

    num1=rand()%100+1; // generates random number and assigns it
    cout<< "Gues a number between 1 and 100: ";
    cin>> guess;


    while (flag==false){
         if(!cin) //Checks for invalid characters
            {
                cout << "Invalid number" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                flag = false;
                cout<< "Please enter a valid number between 1 and 100: ";
                cin>> guess;
                }
                if(guess >100) //Checks for numbers above 100
            {
                cout << "What part of between 1 and 100 didn't you get? Try again." << endl;
                cin.clear();
                cin.ignore(100,'\n');
                flag = false;
                cout<< "Please enter a valid number between 1 and 100: ";
                cin>> guess;
                }
                 if(guess <1) //Checks for numbers below 1
            {
                cout << "What part of between 1 and 100 didn't you get? Try again." << endl;
                cin.clear();
                cin.ignore(100,'\n');
                flag = false;
                cout<< "Please enter a valid number between 1 and 100: ";
                cin>> guess;
                }
                else if( guess> num1)

                {
                cout << "Too high" << endl; // Tells the user to guess lower
                cin.clear();
                cin.ignore(100,'\n');
                flag = false;
                cout<< "Please enter a smaller: ";
                cin>> guess;

                }
        else if (guess<num1){
            cout << "Too low" << endl; // tells the user to  guess higher
                cin.clear();
                cin.ignore(100,'\n');
                flag = false;
                cout<< "Please enter a higher: ";
                cin>> guess;
                }
        else if(guess=num1){  //finds out if the user guessed the correct number
            cout << "Correct!" << endl;
            flag= true;
        }
    }
    while (flag==true){

        cout<<"You Win game over"<< endl;
        return 0;
    }


    return 0;
    }


