//Justin McCoy
//assignment 11 programmming exercize
//4/25/17
//CSC 201

#include <iostream>
	using namespace std;

	int Fib(int N);

	int main()
	{
		int N;
		cout << "Fibonacci Calculator" << endl;
		cout << "Please enter a positive number: ";
		cin >> N;
		if (N < 0){
                cin.clear();
                cin.ignore(100,'\n');
                cout<< "Please enter a valid POSITIVE number: ";
                cin>> N;

		}
		cout << "The Nth Fibonacci number is: " << Fib(N);
		return 0;
	}

int Fib(int N)
	{
		if (N == 0)
			return 0;
		else if (N == 1)
			return 1;
        else
            return Fib(N-1)+Fib(N-2);
	}
