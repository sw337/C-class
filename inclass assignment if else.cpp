//Justin McCoy , Antony Charles, Ana Marroquin
// CSC 1
// inclass 3
// calculator
// 25 OCT 2016



#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
    float  number1;     // First number
    float number2;    // second number
    char action;



    cout << "Enter a number: ";  // gets user's first number
    cin >> setw(10)>> number1;
    if(!cin) //checks for invalid characters
        {
            cout << "invalid number" << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "please enter a valid number: ";
            cin>> number1;
        }
    else
        {
            cout<<"Your first number is:"<<number1<<endl;
        }
    cout << "Enter another number: ";  // gets user's second number
    cin >> setw(10) >> number2;
   if(!cin) //checks for invalid characters
        {
            cout << "invalid number" << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout<< "please enter a valid number: ";
            cin>> number2;
        }
    else
        {
            cout<<"Your second number is:"<<number2<<endl;
        }
    cout << "Would you like to (a)dd, (s)ubtract, (m)ultiply or (d)ivide those numbers?";  // gets user's command
    cin >> action;



    if (action =='a'|| action=='A')  //what to do for a or A
    {
        cout<<number1<< "+" <<number2<< "=";
        cout<<float(number1)+number2<<endl;
    }

    else if (action == 's'||action=='S') //what to do for the letter s
    {
        cout<<number1<< "-" <<number2<< "=";
        cout<<float(number1)- number2<<endl;
    }

                       else if (action=='m'||action == 'M') // what to do when asked to multiply
                        {
                            cout<<number1<< "*" <<number2<< "=";
                            cout<<number1 * number2<<endl;
                        }
                           else if (action=='d'||action=='D') // what to do when asked to divide
                            {

                              if (number2 == 0){

                                        cout << "Cannot divide by zero!" << endl;
                                        cin.clear();
                                        cin.ignore(100,'\n');
                                        cout<< "please enter a valid number: ";
                                        cin>> number2;
                                            }
                                        cout<<number1<< "/" <<number2<< "=";
                                        cout<<number1/number2<<endl;

                                }

                    else // ends program if user enters incorrect command
                            {
                            cout << "Invalid input"<<endl;
                            return 1;
                            }
    return 0;


}
