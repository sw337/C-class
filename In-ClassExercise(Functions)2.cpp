// Justin McCoy
//inclass assignment
// 21 feb 2017


#include <iostream>
#include <string>
#include<fstream> // opens file
#include<math.h> // does math
#include<iomanip>
#include<string> // strings allowed

using namespace std;
//precondition: no file open
//postcondition:file opne
void openFile(ifstream &inFile);/*in opens file */
//precondition: file open
//postcondition:file closed
void closeFile(ifstream &inFile);/*in closes file*/
//precondition:data is calculated but not output
//postcondition: everything is printed
void works(ifstream &inFile, string lastName,string message, int stuScore, int totPoints, float grade,int gradePercent); /*in* the strings and intergers needed*/
//precondition:grade percentages is calculated
//postcondition: grade percent solves for message
string messageFind(string message, int gradePercent);
string lastnameFinder(ifstream &inFile,string &lastName);
int main()
{
    string lastName;
    string message; // moved up

    int stuScore;
    int totPoints;
    float grade;// moved from lower
    int gradePercent; // moved from lower

    ifstream inFile;


    openFile(inFile);
    do{ // changed from while loop
        lastnameFinder(inFile,lastName);

        inFile >> stuScore;

        inFile.get(); // changed from cin.get

        inFile >> totPoints;


        grade = float(stuScore) / totPoints; //makes sure numbers are accurate as floats
        gradePercent = ceil(grade * 100);

        messageFind( message, gradePercent);


        works(inFile, lastName, message, stuScore, totPoints, grade, gradePercent);

            }while(!inFile.eof());// does while not at the end of the file

    closeFile(inFile);


    return 0;
}
void openFile(ifstream &inFile){ /*in*/


    inFile.open("scores.txt"); // opens file now

}

void closeFile(ifstream &inFile){


    inFile.close(); // added to close file

}


void works(ifstream &inFile, string lastName,string message, int stuScore, int totPoints, float grade,int gradePercent){
    cout <<setw(9)<<fixed<< left<< lastName << " " ; // sets width to align everything
    cout << gradePercent << "% ";
    cout <<setprecision(3)<<grade << " "; // makes sure it is uniform for all the numbers
    cout << message << endl;


}
string messageFind(string message, int gradePercent){


if (gradePercent > 90) // switched from if
            message = "Excellent";
        else if (gradePercent > 80) // switched from if
            message = "Well Done";
        else if (gradePercent > 70) // switched from if
            message = "Good";
        else if (gradePercent > 60) // switched from if
            message = "Need Improvement";
        else if (gradePercent < 50&& gradePercent>=0)
            message = "Fail";
        else
            message ="invalid number"; // if somehow a number less than zero is entered
            return message;




}
string lastnameFinder(ifstream &inFile, string &lastName){

        inFile >> lastName;
        lastName.erase(lastName.length()-1); // erases comma
        return lastName;


}
