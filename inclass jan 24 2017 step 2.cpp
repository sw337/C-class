//Antony Charles, Ana Marroquin, Justin McCoy
//CSC210
//FileIO Assignment #2
//1/24/17


#include <iostream>
#include <cmath>	// Access power function
#include <iomanip>	// Access manipulators
#include <fstream>      // Access file i/o functions
#include <string>

using namespace std;
using std::string;

string GetFileInfo(ifstream &inData, string filename);
float CollectData(ifstream &inData, float sum, float avg, float numsRead, string filename);
float FindMedian(ifstream &inData, float numsRead, float median);
void DisplayOutput(ifstream &inData, float sum, float avg, float numsRead,float median, string filename );
void CloseFile(ifstream &inData, string filename);



int main()
{
    float median;
    float avg;
    float numsRead;
    float sum;
    ifstream inData;
    ofstream outData;
    string filename;

    GetFileInfo(inData, filename);
    CollectData(inData, sum, avg, numsRead, filename);
    FindMedian(inData, numsRead, median);
    DisplayOutput(inData, sum, avg, numsRead, median, filename) ;
    CloseFile(inData, filename);

 return 0;

}

//Pre: inData defined as ifstream in calling function
//Post: inData contains link to valid input file
string GetFileInfo(ifstream &inData, string filename)
{
    cout << "What File do you want to open?" << endl;
    cin >> filename;
    inData.open(filename.c_str());
    if (inData.fail()){
		cout << "File does not exist";
		cin.clear();
        cin.ignore(100,'\n');
        cout<< " please try again:";
        cin>> filename;
                    }


    return filename;


}

//Pre: inData for the filename is set
//Post: Total determined, average calculated
float CollectData(ifstream &inData, float sum, float avg, float numsRead, string filename)
{
    int i;
    avg = 0;
    numsRead = 0;
    int data;
    data =0;
    sum = 0;



    for(int i = 0; i < numsRead; i++){
        inData.open(filename.c_str());
        inData >> data;
        sum = data + sum;
		numsRead++;
    }

    avg = float(sum)/ numsRead;

    return avg;
    return numsRead;

}


//Pre: Number of inputs has been counted
//Post: Mean is defined based on whether it total is even or odd, mean is defined
float FindMedian(ifstream &inData, float numsRead, float median)
{

	cout << "STUB for FINDMEDIAN" << endl;

	//return median;
}

//Pre: Average, number of inputs, and mean calculated
//Post: Average, number of inputs, and mean printed
void DisplayOutput(ifstream &inData, float sum, float avg, float numsRead,float median, string filename)
{
	cout << "For the file " << filename << endl;
	cout << "The number of intergers is " << numsRead << endl;
	cout << "The average is " << avg << endl;
	cout << "The median is " << median << endl;
    cout << "The sum is " << sum << endl;
}

//Pre: File open
//Post: File closed
void CloseFile(ifstream &inData, string filename)
{
    cout<< filename<<endl;
    inData.close();
}
