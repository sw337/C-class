//Justin McCoy
// CSC 1
// program 1



#include <iostream>
#include <iomanip>

using namespace std;

const float INCHES_IN_SQ_FT = 144;


int main()
{
    int length;      // measurement in inches
    int width;       // measurement in inches
    float price;       // sold by square foot
    float cost;        // calculated cost

    cout << fixed << showpoint;

    cout << "Enter length: ";
    cin >> length;
    cin.ignore(100, '/n')
    cout << "Enter width: ";
    cin >> width;
    cin.ignore(100, '/n')
    cout << "Enter price: ";
    cin >> price;
    cin.ignore(100, '/n')

    cout << " Width: " << setw(5) << width
         << " Length: " << setw(5) << length
         << " Price: " << setw(6) << setprecision(2)
         << price << endl;

    cost = ((width * length)/ INCHES_IN_SQ_FT) * price;

    cout << "The cost of the glass is $" << setw(6)
        << cost << endl;

    return 0;


}
