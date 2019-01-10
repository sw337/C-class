// Justin McCoy
// Phonebook assignment
// Have a phonebook program be searchable for users and have it continue
// 27 Feb 2017


#include <string>
#include <iostream>

const int MAX_CON = 5;
const int MAX_INF = 5;

enum uses{add, del, searc};


struct Name
{
    std::string firstName;
    std::string lastName;
};

struct Contact
{
  Name names;
  std::string phoneNumber;
  std::string address;

};

Contact contacts[MAX_CON];
