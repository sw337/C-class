//Justin McCoy, ,Antony Charles, Ana Marroquin
// CSC 110
// In-Class Array, User Input
// Create an array and fill it with user's numbers
// 30 NOV 2016



#include <iostream>
#include <iomanip>


using namespace std;


void InitArray(float numArray[],const int ARRAY_SIZE); // declares the initial function which initializes the values
int SumArray(float numArray[],const int ARRAY_SIZE); //declare function that prints out the values
void PrintArray(/* IN */ const float numArray[], /* IN */ int i);
bool CompareArrays(/* IN */ const float numArray1[], /* IN */ const float numArray2[], /* IN */ int i);


int main() // main function hosts all other functions
    {
        const int ARRAY_SIZE = 5; // set a constant array size which can be changed without changing all of the codef
        float numArray[ARRAY_SIZE]; // creates array based on the array size
        float numArray1[ARRAY_SIZE];
        float numArray2[ARRAY_SIZE];
        int i;
        int sum = 0;

        InitArray(numArray, ARRAY_SIZE); /*out array1 */
        SumArray(numArray, ARRAY_SIZE); /*in numArray */
        PrintArray(numArray, ARRAY_SIZE);
        CompareArrays(numArray1, numArray2, i);
        sum = SumArray(numArray, ARRAY_SIZE);
        cout << "The sum is: " << sum << endl;
        return 0;
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
int SumArray(/* IN */ float numArray[], /* IN */ const int ARRAY_SIZE)
    { //prints out results
        int sum = 0;
        int j = 0;
            for (j =0; j <ARRAY_SIZE; j++)
                {

                    sum = numArray[j] + sum; // prints out individual numbers in array separated by a space
                }
            return sum;
    }

void PrintArray(/* IN */ const float numArray[], /* IN */ int i)
    {
        cout << "PrintArray" << endl;
    }
bool CompareArrays(/* IN */ const float numArray1[], /* IN */ const float numArray2[], /* IN */ int i)
    {
        numArray1 = 0;
        numArray2 = 0;
        i = 0;
        cout << "Compare Arrays" << endl;
    }


