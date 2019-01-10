#include <iostream>
#include <cmath>	// Access power function
#include <iomanip>	// Access manipulators
#include <fstream>      // Access file i/o functions

using namespace std;

int main()
{
    // Input variables
    float loanAmt;      // Amount of loan
    float yearlyInt;    // Yearly interest
    int numYears;	    // Number of years
    ifstream inData;     // Link to input file
    ofstream outData;     // Link to output file

    // Local variables
    float monthlyInterest;	// Monthly interest rate
    int numberOfPayments;   // Total number of payments
    float payment;	        // Monthly payment
    string inFileName;         // Input file name
    string outFileName;          // Output file name

    // Prompt user for input file name
    cout << "Enter input File name: ";
    cin >> inFileName;

    // Open input file
    inData.open(inFileName.c_str());

    // Prompt user for output file name
    cout << "Enter output File name: ";
    cin >> outFileName;

    // Open output file
    outData.open(outFileName.c_str());

    // Get first line of data from file
    inData >> loanAmt >> yearlyInt >> numYears;


    // Loop until user enters 0... /* CHANGE CODE */
    while (inData){

       // Calculate values
        monthlyInterest = yearlyInt / 12;
        numberOfPayments = numYears * 12;
        payment = (loanAmt *
                    pow(monthlyInterest + 1, numberOfPayments)
                    * monthlyInterest)/(pow(monthlyInterest + 1,
                    numberOfPayments) - 1);

        // Send output to file
        outData << loanAmt << " " << yearlyInt << " " << numYears << endl;

        // Send output to screen
        cout << fixed << setprecision(2)
             << "Loan amount: $" << loanAmt << endl;
        cout << fixed << setprecision(2)
             << "Interest rate: " << yearlyInt << endl;
        cout << "Years:  " << numYears << endl << endl;

        cout << "Your monthly payments are $" << payment << endl << endl << endl;

        // Get next line of data from file
        inData >> loanAmt >> yearlyInt >> numYears;


    // Close files (necessary?)
    outData.close();
    inData.close();


    cout << "Good bye!" << endl;

    return 0;
}
