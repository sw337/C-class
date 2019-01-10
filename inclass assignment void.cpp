//Justin McCoy
// CSC 110
// inclass CheckParams
// user enters a number the program tells them if the numbers are equal
// 21 Nov 2016


#include <iostream>
#include <iomanip>

using namespace std;

void CheckParams(int num1, int num2);// function that checks numbers coming in

int main(){
    int num1;  // defines first variable
    int num2;// defines second variable

        cout << "Enter a positive number: "; // gets firs user input
        cin >> num1;


    if (num1<0) { // checks that user input is positive
        cout << "Enter a positive number: ";
        cin >> num1;
    }
        cout << "Enter another positive number: ";
        cin >> num2;// gets users second input
    if (num2<0){ // checks that user input is positive
        cout << "Enter another positive number: ";
        cin >> num2;
    }
    CheckParams(num1, num2);

    cout<<"Thanks for using the program!";

    return 0;
}

void CheckParams(int num1, int num2){

    if (num1 == num2)// checks if numbers are equal
        cout << "They're equal!" << endl;
    else
        cout << "They're not equal." << endl;
}



