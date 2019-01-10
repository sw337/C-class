// Justin McCoy
// assignment 8
//
// 27 Feb 2017

#include "phonebook.h"
#include <iostream> // mandatory to compile
#include<fstream> // opens files
#include<iomanip>
#include<array>

const int MO = 11;
const int TE = 1;

using namespace  std;
int getdata(int temps[MO][TE]);
void displayData(int temps[MO][TE]);
float averageHigh(int temps[MO][TE], float avg);


int main(){

    int temps[MO][TE];

    float avg;



    getdata(temps);
    displayData(temps);
    averageHigh(temps,avg);





   return 0;
}


int getdata(int temps[MO][TE], int hightemp, int lowtemp){
    for (int month =0; month < 11; month++){
            int dailytemp;
            int lowtemp;
            int hightemp;
        for(int day = 1; day <= 31; day++){
            cout << "enter data for the "<< day << " day of the "<< month+1<< " month."<<endl;
            cin >> dailytemp;
            if (dailytemp > hightemp){
                hightemp = dailytemp;
                hightemp>>temps[month][0];
                }
            if (dailytemp < lowtemp){
                lowtemp = dailytemp;
                lowtemp>>temps[month][1];
                }
            }
        }

}



void displayData(int temps[MO][TE]){
        for (int month =0; month < 11; month++){
                cout << "High for month number "<< month+1<<' ' << temps[month][0]<<endl;
                cout << "Lows for month number "<< month+1<<' '<< temps[month][1]<<endl;
        }

}
float averageHigh(int temps[MO][TE], float avg){
            int sum =0;

          for (int month =0; month < 11; month++){
                sum= float(temps[month][0]);

        }
        avg = sum/12;
        return avg;
}
