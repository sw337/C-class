//Justin McCoy, ,Antony Charles, Ana Marroquin
// CSC 110
// inclass array from user input
// Create an array and fill it with user's numbers
// 30 NOV 2016



#include <iostream>
#include <iomanip>


using namespace std;


void InitArray(float numArray[],const int ARRAY_SIZE); // declares the initial function which initializes the values
float SumArray(float numArray[],const int ARRAY_SIZE, float sum); //declare function that prints out the values
void sumPrint(float sum); // declares function that prints out sum


int main() // main function hosts all other functions
    {
        const int ARRAY_SIZE = 5; // set a constant array size which can be changed without changing all of the codef
        float numArray[ARRAY_SIZE]; // creates array based on the array size
        float sum;

        InitArray(numArray, ARRAY_SIZE); /*out array1 */
        SumArray(numArray, ARRAY_SIZE, sum); /*in numArray */
        sumPrint(sum);





        return 0; // ends the program

    }
// Initialize array with values input from the user
// Pre: numArray should point at a valid integer array and num should hold the
//      number of array elements
// Post: numArray should contain floats entered by the user

void InitArray(/* OUT */ float numArray[], const int ARRAY_SIZE /* IN */ )
    {
    int i; // creates the variable i


    for (i = 0; i < ARRAY_SIZE; i++)
    {
    cout<<"You will enter "<<ARRAY_SIZE<< " numbers. This is number "<< i+1 << "  :";
    cin>>numArray[i];

    }



        /*out array1 i */
    }



// Calculate the sum of all elements in the array and return the result
// Pre: numArray should contain valid values
// Post: Return the sum of all values in the array. numArray is unchanged.
float SumArray(/* IN */ float numArray[],   const int ARRAY_SIZE,/* IN */ float sum)
    { //prints out results
    sum = 0;
    int j = 0;
    for (j =0; j <ARRAY_SIZE; j++)
    {

        sum = numArray[j] + sum; // prints out individual numbers in array separated by a space
    }

    return sum;

    }

void sumPrint(float sum/*inout*/){

    cout<<"The Sum of your numbers is: "<< sum; // prints out the sum


}
