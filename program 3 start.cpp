//Justin McCoy
// CSC 110
// Program 2
// user enters a number the program tells them the characteristics of the number
// 12 Nov 2016


#include <iostream>
#include <iomanip>



using namespace std;

int num; //user's input
char cont; // continue characters

void numberAn(); // first function for user number input
void contTest(); // function that asks user to continue
void NumOp(int num); // function that uses number input
void contTest2(char cont); // function that continues based on user input


int main()
{

    numberAn();
    NumOp(num);
    contTest();
    contTest2(cont);
    return 0;
    }


void numberAn()
{

    cout<< "Please enter an integer: ";
    cin>>num;
    if(!cin) //Checks for invalid integers
                {
                    cout << "Invalid number" << endl;
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<< "Please enter a valid number";
                    cin>> num;
                    }

}

void NumOp(int num){
                    if(num >=0) //figures out if the number is positive
                        {
                        cout << num <<" is positive."<<endl;
                        }
                     if(num <0) //figures out if the number is negative
                        {
                        cout << num <<" is negative."<<endl;
                        }
                    if (num>9000) // easter egg for DBZ nerds
                        {
                        cout<<num <<" is over 9000!!!!"<<endl;
                        }

                    if(num %2==0) // figures out if the number is even based on remainder
                        {
                        cout <<num<< " is even." << endl; //

                        }
                    if (num%2!=0) //figures out if number is odd based on remainder
                        {
                        cout << num<<" is odd. " << endl;

                        }

        }

void contTest() // function for continuing program
       {
        cout<<"Would you like to continue 'Y' or 'N'?"<< endl; //lets user know  how to continue the program

        cin>>cont; // gets user's input on what they want to do


        // checks if user entered a valid command
        if(cont=='N'||cont=='n')
            {

            }

        else if(cont=='Y'||cont=='y')
            {
            }
        else{
                cout << "Invalid command" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid command";
                cin>> cont;
                }

       }

void contTest2(char cont){ //function for using user's input to continue function

        if(cont=='N'||cont=='n')
            {
            cout<< "Thank you for using this program!"<<endl;
            }

        else if(cont=='Y'||cont=='y')
            {
            main();
            }
        else
            {
            cout<<"invalid command"<<endl;
            }




            }




