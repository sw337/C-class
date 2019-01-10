//Justin McCoy
//linked list for business cards prototypes
//4/18/17
//CSC 201
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct NodeType
{
    string component;
    string firstName;
    string phoneNumber;
    NodeType *link;
};
//Pre: File isn't opened
//Postcondition file is opened
void openFile(ofstream &myfile);
//Pre: File is opened
//Postcondition file is closed
void CloseFile(ofstream &myfile);
//Pre: List exist and file is blank
//Postcondition: list is written to file
void PrintList(NodeType *currPtr, ofstream &myfile);
//Pre:no nodes exist
//Postcondition nodes exist
NodeType *CreateNode();
//Pre: Node exist but isn't on list
//Postcondition node is put on list based on alphabetical order.
void AddNode(NodeType *&listPtr, NodeType *newNodePtr);
//Pre: no input on if the user wants to continue
//Postcondition: program knows if user wants to continue
bool cont(bool flag);

