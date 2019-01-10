#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>

using namespace std;

int main()
{
    bool someBool;
    char someChar;
    short someShort;
    int someInt;
    long someLong;

    float someFloat;
    double someDouble;
    long double someLongDouble;

    cout << setprecision(5);

    cout << setw(10) << "Data Type" << setw(7) << "Size" << setw(8) << "Min" << setw(13) << "Max" << endl;

    cout << setw(13) << "bool: " << setw(3) << sizeof(someBool)
         << setw(13) << false << setw(14) << true << endl;
    cout << setw(13) << "char: " << setw(3) << sizeof(someChar)
         << setw(13) << CHAR_MIN << setw(14) << CHAR_MAX << endl;
    cout << setw(13) << "short: " << setw(3) << sizeof(someShort)
         << setw(13) << SHRT_MIN << setw(14) << SHRT_MAX << endl;
    cout << setw(13) << "int: " << setw(3) << sizeof(someInt)
         << setw(13) << INT_MIN << setw(14) << INT_MAX << endl;
    cout << setw(13) << "long: " << setw(3) << sizeof(someLong)
         << setw(13) << LONG_MIN << setw(14) << LONG_MAX << endl;
    cout << setw(13) << "float: " << setw(3) << sizeof(someFloat)
         << setw(13) << FLT_MIN << setw(14) << FLT_MAX << endl;
    cout << setw(13) << "double: " << setw(3) << sizeof(someDouble)
         << setw(13) << DBL_MIN << setw(14) << DBL_MAX << endl;
    cout << setw(13) << "long double: " << setw(3) << sizeof(someLongDouble)
         << setw(13) << LDBL_MIN << setw(14) << LDBL_MAX << endl;

    return 0;
}
