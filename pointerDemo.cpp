#include <iostream>

using namespace std;

int main()
{
    int* intPtr1; // Will hold the address of an int
    int* intPtr2; // Will hold the address of an int

    int  x;

    x = 12;

    intPtr1 = &x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl << endl;
    cout << "intPtr1: " << intPtr1 << endl;
    cout << "*intPtr1: " << *intPtr1 << endl;
    cout << "&intPtr1: " << &intPtr1 << endl;
//    cout << "intPtr2: " << intPtr2 << endl;
//    cout << "*intPtr2: " << *intPtr2 << endl;
//    cout << "&intPtr2: " << &intPtr2 << endl
    cout << endl;

    intPtr2 = intPtr1;

    *intPtr2 = 35;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl << endl;
    cout << "intPtr1: " << intPtr1 << endl;
    cout << "*intPtr1: " << *intPtr1 << endl;
    cout << "&intPtr1: " << &intPtr1 << endl;
//    cout << "intPtr2: " << intPtr2 << endl;
//    cout << "*intPtr2: " << *intPtr2 << endl;
//    cout << "&intPtr2: " << &intPtr2 << endl
    cout << endl;

    return 0;
}
