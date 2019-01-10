//Justin McCoy
//3/14/17
//CSC 201
// Program Cars reads a record from a file and prints it with a 10% price increase.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "cars.h"

using namespace std;



// Pre:  File dataIn has been opened.
// Post: The fields of car are read from file dataIn.
Car GetCar(ifstream& dataIn);


personType GetCustomer(ifstream& dataIn);

// Pre:  car holds a valid Car variable.
// Post: The fields of car are written to the screen,
//       appropriately labeled.
void WriteCar(Car car, personType customer);

int main () {
  Car  car;
  personType customer; //struct personType
  ifstream dataIn;

  dataIn.open("cars.dat");

  car = GetCar(dataIn);
  customer = GetCustomer(dataIn);
  while (dataIn) {
    car.price = car.price * 1.10;
    WriteCar(car, customer);
    car = GetCar(dataIn);

  }

  return 0;
}

//*****************************************************

Car GetCar(ifstream&  dataIn) {
  Car car;

  dataIn >> car.price  >> car.purchased.day
         >> car.purchased.month  >> car.purchased.year;
  dataIn.ignore(2, '\n');
  return car;
}

personType GetCustomer(ifstream& dataIn){

    return customer;

}





//*****************************************************

void  WriteCar(Car  car, personType customer) {
    //personType customer; //struct personType
  cout << fixed << noshowpoint << setprecision(0);
  cout << "Customer: " << personType.customer << endl //struct personType
	   << "Price:    $" << car.price << endl
	   << "Purchased:"  << car.purchased.day << "/"
	   << car.purchased.month << "/"
	   << car.purchased.year << endl;
}
