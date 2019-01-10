#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


using namespace std;

int main() {
	int i; // counter
	int num1; //minimum number variable
	int outcount; // maximum number variable
	int count;  // amount of numbers variable
    int sum;

    sum = 0;
    i =1;


       do
        {

        sum = sum + i++;


        } while( sum <= 10000);
        cout << " Most recently added:   " << 10000- (sum - i) << endl;


	return 0;
}
