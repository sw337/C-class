// Justin McCoy
// Phonebook assignment
// Have a phonebook program be searchable for users and have it continue
// 27 Feb 2017

#include "phonebook.h"
#include <iostream> // mandatory to compile
#include<fstream> // opens files
#include<iomanip>
#include<string> // strings allowed


using namespace std;
//precondition: no file open
//postcondition:file opne
void openFile(ifstream &inFile, ofstream &fileIn);/*in opens file */
//precondition: file open
//postcondition:file closed
void closeFile(ifstream &inFile, ofstream &fileIn);/*in closes file*/
//precondition: file is open
//postcondition: users know what to input
char fChoice(char &select);
void menu();
//precondition:users know what to input
//postcondition: users input is stored
void searchfile(char select);
//precondition:user doesn't know what is in file
// postcondition:user knows what is in file
void addtofile(ofstream &fileIn,ifstream &inFile);
//precondition: new information is not in file
// postcondition: new information in file
char choice(char &selection); /*out char selection*/
//precondition: users see their possible choices
//postcondition: choice is saved
string lastnameFinder(ifstream &inFile,string &lastName); /*inout*/
//precondition: Open file
//postcondition: last name in program
string firstnameFinder(ifstream &inFile, string &firstName);/*inout*/
//precondition: open file
//postcondition:first name in program
string GetString(ifstream &inFile, string &phoneNumber);/*inout*/
//precondition: open file
//postcondition: phone number in program
string GetAddress(ifstream &inFile, string &address);/*inout*/
//precondition: open file
//postcondition: address in the program
string searchTool(ifstream &inFile,char selection, string &input);/*inout*/
//precondition: all values are in program
//postcondition: users search is in the program
void printer(string lastName,string  firstName,string phoneNumber,string address); /*in*/
//precondition: strings are declared but not output
//postcondition: strings are output
bool isInFinder(string lastName, string  firstName, string phoneNumber, string address, string input , char selection);/*inout*/
//precondition: user will see output or nothing
//postcondition: if nothing user is informed if nothing has been found
void found(int i, string input);/*in*/

//precondition: program has run and unknown if the user wants to continue
//postcondition: the program runs
int cont();/*out*/

string NormalizeString(string &inString); // normalizes string
string NormalizeString2StringWithAVengance(string &inString); // gets rid of punctuation
int main()
{

    string input;
    char selection;
    char select;
    ifstream inFile;
    ofstream fileIn;
    int i=0;
    Contact contact;

    openFile(inFile, fileIn); //opens file
    fChoice(select);


    if (select == 's'){
        menu(); // print menu

        choice(selection); // gets user input

        searchTool(inFile,selection, input);// searches for user input
   while(!inFile.eof()){ // does while not at the end of the file
        lastnameFinder(inFile,contact.lastName); // get last name
        firstnameFinder(inFile,contact.firstName); // get first name
        GetString(inFile,contact.phoneNumber); // get phone number
        GetAddress(inFile,contact.address); // get address

        if(isInFinder(contact.lastName,contact.firstName,contact.phoneNumber,contact.address, input, selection)){ // check if search is in string
            printer(contact.lastName, contact.firstName, contact.phoneNumber, contact.address); // print if search is in string
            i++; // count if this loop runs if not the user will be notified
            contact.lastName.clear(); // clears last name to prevent duplicates
            contact.firstName.clear(); // clears first name to avoid duplicates
            contact.phoneNumber.clear(); // clears address
            contact.address.clear(); //clears address
            }
        }
    found(i,input);
    closeFile(inFile, fileIn);// close
    }
    else if (select == 'a'){
            addtofile(fileIn,inFile);
        closeFile(inFile, fileIn);// close
    }


    cont(); // test to continue




    return 0;
}
void openFile(ifstream &inFile,  ofstream &fileIn){ /*in*/

    inFile.open("book.txt"); // opens file now
    fileIn.open("book.txt",std::ios_base::app);

}

void closeFile(ifstream &inFile, ofstream &fileIn)
{

    inFile.close(); // added to close file
    fileIn.close();// closes file
}


string lastnameFinder(ifstream &inFile, string &lastName)
{
        inFile >> lastName;
        NormalizeString2StringWithAVengance(lastName); // erases comma
        return lastName;
}
string firstnameFinder(ifstream &inFile, string &firstName)
{
        inFile >> firstName;
        NormalizeString2StringWithAVengance(firstName); // erases comma
        return firstName;
}
string GetString(ifstream &inFile, string &phoneNumber)
{
    getline(inFile,phoneNumber);

    return phoneNumber;
}
string GetAddress(ifstream &inFile, string &address){
    getline(inFile,address);

    return address;

}

void menu(){
    // prints out menu and prompts user input
    cout << "Phonebook program" << endl;
    cout << " To search by [l]ast name enter l" << endl;
    cout << " To search by [f]irst name enter f" << endl;
    cout << " To search by phone [n]umber enter n" << endl;
    cout << " To search by [a]ddress enter a" << endl;
}

char choice(char &selection){
    // gets user selection
    cin >> selection; // input of selection
    selection=tolower(selection); // makes sure selection is lowercase

    // checks users selection


    while (selection != 'a'&&selection != 'f'&&selection != 'l' && selection!= 'n'){
            cout << "Invalid entry" << endl;
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<< "Please enter a valid choice: ";
                    cin>> selection;
                    selection=tolower(selection);// makes sure selection is lowercase
        }
     return selection; // returns selection after it is verified
}

string searchTool(ifstream &inFile, char selection, string &input){

    // print what they are searching by by selection, let them know about the parameters
    if (selection == 'l'){
        cout << "Searching last names"<<endl;
        cout << "not case sensitive " <<endl;
    }
    else if (selection== 'n'){

        cout << "Searching by phone number"<<endl;
    }
    else if (selection == 'f'){
        cout << "Searching first names"<<endl;
        cout << "not case sensitive " <<endl;
    }
    else if (selection == 'a'){

      cout << "Searching addresses "<<endl;
        cout << "not case sensitive " <<endl;
    }

    cin >> input; // get users search

    return input; // return input

}
void printer(string lastName,string  firstName,string phoneNumber,string address){ // output results
    cout << "--------------------------------------------------------------------------"<<endl;
    cout <<"|"<< " last name: " << lastName << "|"<<endl;
    cout <<"|"<<" first name: " << firstName <<"|"<< endl;
    cout <<"|"<< " phone number: " << phoneNumber <<"|"<< endl;
    cout <<"|"<< " address: " << address <<"|"<< endl;
    cout << "---------------------------------------------------------------------------"<<endl;

    // prints out contact information
}

bool isInFinder(string lastName, string  firstName, string phoneNumber,string address, string input, char selection){
            // normalize all strings to make sure they are not case sensitive
            NormalizeString(input);
            NormalizeString(lastName);
            NormalizeString(firstName);
            NormalizeString(phoneNumber);
            NormalizeString(address);


    //sort out the choice based on user selection
    // making the bool true or false depending if the input is in the string
        if (selection == 'l' ||selection ==  'L'){
                if(lastName.find(input) != string::npos)
                    return true;
               else
                return false;


            }
            else if (selection== 'n' ||selection ==  'N'){
                 if (phoneNumber.find(input) != string::npos)
                    return true;
                else
                    return false;

            }
            else if (selection == 'f' ||selection ==  'F'){
                if (firstName.find(input) != string::npos)
                    return true;
                else
                    return false;

            }
            else if (selection == 'a' || selection == 'A'){
                if(address.find(input) != string::npos)
                    return true;
                else
                    return false;

                }

}
void found(int i, string input){ /*in */
    if (i==0)
        cout<< "Nothing found for "<< "'"<<input<<"'"<<endl; // lets user know nothing was found
}

int cont(){
    char answer;
    cout << "Would you like to continue? (y/n) " << endl; // give the user an option to continue
    cin >> answer;

    while (answer != 'y'&& answer != 'Y'&& answer != 'N' && answer != 'n' ){ // forces user to enter a valid choice
        cout << "Invalid entry" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid choice: ";
                cin>> answer;
                }

        if (answer == 'y' ||answer ==  'Y')
                main(); // restarts program

}
string NormalizeString(string &inString)
{

    string normal1; // string for the first part of our normal string
    string normal2; // string for the second part of our normal string
    int j = 0;
    int k = 0;

    for (int l = inString.length(); k < l; k++) // changes everything to uppercase
        {
            normal1 += toupper(inString.at(k)); // capitalizes new string
        }

    for(int m = normal1.length(); j < m; j++) // checks if any special characters or spaces are used and removes them
        {
            if((isalpha(normal1.at(j)))||isalnum(normal1.at(j)))
                {
                    normal2 += normal1.at(j); // writes only letters  new string
                }
        }
        inString = normal2;
        return inString;
}
string NormalizeString2StringWithAVengance(string &inString)
{

    string normal1; // string for the first part of our normal string
    int j = 0;
    // codewritten by Justin McCoy
    for(int m = inString.length(); j < m; j++) // checks if any special characters or spaces are used and removes them
        {
            if((isalpha(inString.at(j)))||isalnum(inString.at(j)))
                {
                    normal1 += inString.at(j); // writes only letters  new string
                }
        }
        inString = normal1;
        return inString;
}

char fChoice(char &select){


      cout << "Would you like to [s]earch the phonebook or [a]dd to it?"<<endl;
       cin >> select; // input of select
    select=tolower(select); // makes sure select is lowercase

    // checks users selection


    while (select != 'a'&&select != 's'){
            cout << "Invalid entry" << endl;
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout<< "Please enter a valid choice: ";
                    cin>> select;
                    select=tolower(select);// makes sure selection is lowercase
        }


        return select;

}

void searchfile(char select){}
void addtofile(ofstream &fileIn,ifstream &inFile){ // gets new contact information

    string str1;
    string str2;
    string str3;
    string str4;

    cout << "Enter last name then a comma then press enter "<< endl;
    cin>> str1;
    fileIn<<str1;
    cout << "Enter first name  then press enter "<< endl;
    cin>> str2;
    fileIn<<str2<<endl;
    cout << "Enter phone number then press enter "<< endl;
    cin>> str3;
    fileIn<<str3<<endl;
    cout << "Enter address then press enter "<< endl;
    cin>> str4;
    fileIn<<str4<<endl;
    cout << "New contact added."<< endl;




}
