// Justin McCoy
//inclass assignment
// 21 feb 2017


#include <iostream>
#include<fstream> // opens files
#include<iomanip>
#include<string> // strings allowed

using namespace std;
//precondition: no file open
//postcondition:file opne
void openFile(ifstream &inFile);/*in opens file */
//precondition: file open
//postcondition:file closed
void closeFile(ifstream &inFile);/*in closes file*/

char choice(char &selection); /*in* the strings and intergers needed*/

void menu();

int cont();

string lastnameFinder(ifstream &inFile,string &lastName);
string firstnameFinder(ifstream &inFile, string &firstName);
string GetString(ifstream &inFile, string &phoneNumber);
string GetAddress(ifstream &inFile, string &address);
string searchTool(ifstream &inFile,string &input);
void printer(string &lastName,string  &firstName,string &phoneNumber,string &address);
bool isInFinder(string lastName, string  firstName, string phoneNumber, string address, string input , char selection);

int main()
{
    string lastName;
    string firstName;
    string phoneNumber;
    string address;
    string input;
    char selection;
    ifstream inFile;



    openFile(inFile);
    menu();
    choice(selection);
    searchTool(inFile, input);




   do{
        lastnameFinder(inFile,lastName);

        firstnameFinder(inFile,firstName);

        GetString(inFile,phoneNumber);

        GetAddress(inFile,address);


        if (isInFinder(lastName,firstName,phoneNumber,address, input, selection)){
            printer(lastName, firstName, phoneNumber, address);

        }

            }while(!inFile.eof()); // does while not at the end of the file

            cont();




    closeFile(inFile);


    return 0;
}
void openFile(ifstream &inFile){ /*in*/


    inFile.open("book.txt"); // opens file now

}

void closeFile(ifstream &inFile){


    inFile.close(); // added to close file

}

string searchTool(ifstream &inFile, string &input){

    cout << "enter based on above selection "<< endl;

    cin >> input;

    return input;

}
string lastnameFinder(ifstream &inFile, string &lastName){

        inFile >> lastName;
        lastName.erase(lastName.length()-1); // erases comma

        return lastName;


}
string firstnameFinder(ifstream &inFile, string &firstName){

        inFile >> firstName;
        firstName.erase(firstName.length()-1); // erases comma
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

    cout << " To search by last name enter l" << endl;
    cout << " To search by first name enter f" << endl;
    cout << " To search by phone number enter n" << endl;
    cout << " To search by address enter a" << endl;
}

char choice(char &selection){

    cin >> selection;



    if (selection == 'l' ||selection ==  'L'){
        return selection;
    }
    else if (selection== 'n' ||selection ==  'N'){

        return selection;
    }
    else if (selection == 'f' ||selection ==  'F'){
        return selection;
    }
    else if (selection == 'a' || selection == 'A'){

        return selection;
    }
    else
        while (selection != 'a'&&selection != 'f'&&selection != 'l' && selection!= 'n' ){
        cout << "Invalid entry" << endl;
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid choice: ";
                cin>> selection;
                }




}
void printer(string &lastName,string  &firstName,string &phoneNumber,string &address){

   cout << " last name: " << lastName << endl;
    cout << " first name: " << firstName<< endl;
    cout << " phone number: " << phoneNumber << endl;
    cout << " address: " << address << endl;
}

bool isInFinder(string lastName, string  firstName, string phoneNumber,string address, string input, char selection){


        if (selection == 'l' ||selection ==  'L'){
                if(input == lastName)
                    return true;
               else
                return false;


            }
            else if (selection== 'n' ||selection ==  'N'){
                 if (input == phoneNumber)
                    return true;
                else
                    return false;

            }
            else if (selection == 'f' ||selection ==  'F'){
                if (input ==firstName)
                    return true;
                else
                    return false;

            }
            else if (selection == 'a' || selection == 'A'){
                if(input == address)
                    return true;
                else
                    return false;

                }
            // else {
                  //  return false;
        //    }


}

int cont(){
    char answer;
    cout << "Would you like to continue? (y/n) " << endl;
    cin >> answer;

       if (answer == 'n' ||answer ==  'N')
                 return 0;


        else if (answer == 'y' ||answer ==  'Y')
                main();

}

