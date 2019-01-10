// Program Cars reads a record from a file and writes
// its contents to the screen with the price member
// increased by 10%.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Date
{
  int month;
  int day;
  int year;
};

struct Car
{
  float price;
  Date purchased;
  string customer;
};

// Pre:  File dataIn has been opened.
// Post: The fields of car are read from file dataIn.
Car GetCar(ifstream& dataIn);

// Pre:  car holds a valid Car variable.
// Post: The fields of car are written to the screen,
//       appropriately labeled.
void WriteCar(Car car);

int main () {
  Car  car;
  ifstream dataIn;

  dataIn.open("cars.dat");

  car = GetCar(dataIn);
  while (dataIn) {
    car.price = car.price * 1.10;
    WriteCar(car);
    car = GetCar(dataIn);
  }

  return 0;
}

//*****************************************************

Car GetCar(ifstream&  dataIn) {
  Car car;
  dataIn >> car.customer;
  dataIn >> car.price  >> car.purchased.day
         >> car.purchased.month  >> car.purchased.year;
  dataIn.ignore(2, '\n');
  return car;
}

//*****************************************************

void  WriteCar(Car  car) {
  cout << fixed << noshowpoint << setprecision(0);
  cout << "Customer: " << car.customer << endl
	   << "Price:    $" << car.price << endl
	   << "Purchased:"  << car.purchased.day << "/"
	   << car.purchased.month << "/"
	   << car.purchased.year << endl;
}
