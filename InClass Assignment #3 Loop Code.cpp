//Antony Charles, Ana Marroquin, Justin McCoy
// CSC 110
// In-Class Assignment #3
// Simple Calculator Code
// 25 OCT 2016


#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
    float number1;     // First number
    float number2;    // second number
    char action;      //Used for switch statement
    char yesno;       //Used for user prompt



    cout << "Enter a number: ";  // Gets the Users first number.
    cin >> setw(10)>> number1;

    while (!cin)
    {
        if(!cin || number1 == 0) //Checks for invalid characters or the number zero.
            {
                cout << "Invalid number" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "please enter a valid number: ";
                cin>> number1;
            }
    }

    {
        cout<<"Your first number is: "<<number1<<endl;
    }


    cout << "Enter another number: ";  // Gets user's second number
    cin >> setw(10) >> number2;

    while (!cin)
    {
        if(!cin || number2 == 0) //Checks for invalid characters or the number zero.
            {
                cout << "Invalid number" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid number: ";
                cin>> number2;
            }
    }

    {
        cout<<"Your second number is: "<<number2<<endl;
    }


    cout << "Would you still like to continue to calculate these numbers?" << endl; //Prompts the user if they still want to continue
    cout << "Number 1: "<<number1<<" Number 2: "<<number2<<endl;
    cout << "Y/N" << endl;
    cin >> yesno;

    while (yesno == 'Y' || yesno == 'y')
    {
        cout << "Would you like to (A)dd, (S)ubtract, (M)ultiply or (D)ivide those numbers?";  // Gets user's command
        cin >> setw(10) >> action;

        switch(action) //Sets up a switch for action
            {

                case 'a': //What to do for Addition
                    cout<<number1<< "+" <<number2<< "=";
                    cout<<float(number1)+number2<<endl;
                    return 0;
                case 's': //What to do for Subtraction
                    cout<<number1<< "-" <<number2<< "=";
                    cout<<float(number1)-number2<<endl;
                    return 0;
                case 'm': //What to do for Multiplication
                    cout<<number1<< "*" <<number2<< "=";
                    cout<<number1*number2<<endl;
                    return 0;
                case 'd': //What to do for Division
                    cout<<number1<< "/" <<number2<< "=";
                    cout<<float(number1)/number2;
                    if (number2 == 0)
                        {
                            cout << "Cannot divide by zero!" << endl;
                            cin.clear();
                            cin.ignore(100,'\n');
                            return 0;
                        }


    while (yesno == 'n' || yesno == 'N')
        {
            cout<<"Thank you! Goodbye!";
            return 0;
        }

    }
}
}
