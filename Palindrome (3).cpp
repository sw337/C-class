//Justin McCoy
//cs201
// palindrome code for normalize string

#include <iostream>
#include <fstream>

using namespace std;

// Prompt user for file name and return ifstream
// Pre: inData declared
// Post: inData contains valid ifstream for data file
void GetFileInfo(ifstream &inData);

// Reads a string from a file and returns it
// Pre: inData is linked to a valid input file
// Post: Returns next line read from a file
string GetString(ifstream &inData);

// Takes a string and removes all spaces and special characters, and converts
// to upper case, returning the result
// Pre: inString contains a string
// Post: Returns a string with all spaces and special characters removed and
//       converted to upper case
string NormalizeString(string inString);

// Takes a string and reverses its order
// Pre: inString contains a string
// Post: Returns inString in reversed order
string ReverseString(string inString);

// Test to see if a passed string is a palindrome
// Pre: normalString has all spaces and special characters removed and is in
//      upper case
// Post: Rerturns true if normalString is a palindrome, false otherwise.
bool isPalindrome(string normalString);

int main()
{
    ifstream inData;
    string inString;
    string normalString;

    GetFileInfo(inData);

    inString = GetString(inData);

    while (inData) {

        cout << inString << endl;
        cout << ReverseString(inString) << endl;
        normalString = NormalizeString(inString);

        if (isPalindrome(normalString))
            cout << "Yay!\n";
        else
            cout << "Boo!\n";

        inString = GetString(inData);
    }

    inData.close();
}

// ******************** Stub Function Definitions -- Start **********************

string ReverseString(string inString)
{
    string reverseString;

    for(int length1 = inString.length(); length1 > 0; length1--)
    {
        reverseString += inString.at(length1 - 1);
    }

    return reverseString;

}


string NormalizeString(string inString)

{
    return "Stub";
}


string GetString(ifstream &inData)
{
    string str1;

    getline(inData,str1);

    return str1;
}

bool isPalindrome(string normalString)
{
    cout << "Stub" << endl;
}

// ******************** Stub Function Definitions -- End ************************

void GetFileInfo(ifstream& inData){
    string filename;

    do {
        // Prompt user for file name and open file
        cout << "Enter file containing input values: ";
        cin >> filename;

        inData.open(filename.c_str());

        if (!inData)
            cout << "Invalid file!\n\n";


    } while (!inData); // Loop until valid file name provided
}
