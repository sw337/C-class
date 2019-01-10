//Antony Charles
//3/11/17
//CSC 201
// Program Cars reads a record from a file and writes
// its contents to the screen with the price member
// increased by 10%.

struct Date
{
  int month;
  int day;
  int year;
};

struct Car
{
  float price;
  Date purchased; //string customer removed from this struct
};

struct personType
{
  std::string customer; //Uses std::string to avoid polluting the global namespace for users.
};
