//Antony Charles, Ana Marroquin, Justin McCoy
//CSC210
//FileIO Assignment #2
//1/24/17


#include <iostream>
#include <cmath>	// Access power function
#include <iomanip>	// Access manipulators
#include <fstream>      // Access file i/o functions

using namespace std;

float GetFileInfo(ifstream &InData, string filename);
float CollectData(ifstream &InData, float sum, float avg, float numsRead);
float FindMedian(ifstream &InData, float numsRead, float median);
void DisplayOutput(ifstream &InData, float sum, float avg, float numsRead,float median );
void CloseFile(ifstream &InData);



int main()
{
    float median;
    float avg;
    float numsRead;
    float sum;
    ifstream InData;
    ofstream outData;
    string filename;

    GetFileInfo(InData, filename);
    CollectData(InData, sum, avg, numsRead);
    FindMedian(InData, numsRead, median);
    DisplayOutput(InData, sum, avg, numsRead, median) ;
    CloseFile(InData);

 return 0;

}

//Pre: inData defined as ifstream in calling function
//Post: inData contains link to valid input file
float GetFileInfo(ifstream &InData, string filename)
{
  cout << "Stub for GetFileInfo" << endl;

}

//Pre: inData for the filename is set
//Post: Total determined, average calculated
float CollectData(ifstream &InData, float sum, float avg, float numsRead)
{
	cout << "STAB for COLLECTDATA" << endl;

 //return avg;
 //return numsRead;
}


//Pre: Number of inputs has been counted
//Post: Mean is defined based on whether it total is even or odd, mean is defined
float FindMedian(ifstream &InData, float numsRead, float median)
{

	cout << "STUB for FINDMEDIAN" << endl;

	//return median;
}

//Pre: Average, number of inputs, and mean calculated
//Post: Average, number of inputs, and mean printed
void DisplayOutput(ifstream &InData, float sum, float avg, float numsRead,float median)
{
	cout << "STUB for DISPLAYOUTPUT" << endl;
}

//Pre: File open
//Post: File closed
void CloseFile(ifstream &InData)
{
    cout << "STUB for closefile" << endl;
}
