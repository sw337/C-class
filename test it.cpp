#include <iostream>
	using namespace std;

	void Rev();

	int main(){
	Rev();



	return 0;
	}


void Rev(){
    int number;
    cin >> number;
    if (cin)
    {
    cout << number<< endl;
    Rev();
    cout << number << endl;
    }

	}
