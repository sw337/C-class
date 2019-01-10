//Justin McCoy
//linked list for business cards
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
// open file
void openFile(ofstream &myfile);
// close file
void CloseFile(ofstream &myfile);
// write file to dat file
void PrintList(NodeType *currPtr, ofstream &myfile);
//Creates and returns a new node
NodeType *CreateNode();
//Adds a given node to a list in a sorted position
void AddNode(NodeType *&listPtr, NodeType *newNodePtr);
//Will find a value and delete that node from list
void DeleteNode(NodeType *&listPtr, string &delVal);
// test to see if user wants to continue
bool cont(bool flag);
//*******************************************************************************************
int main()
{
    NodeType *lastPtr;      // Points to last element in the list
    NodeType *listPtr;      // Points to first element in the list
    NodeType *currPtr;      // Points to currently used element (working pointer)
    NodeType *newNodePtr;   // Used to point to newly created nodes
    string delVal;
    NodeType firstName;
    ofstream myfile;
    listPtr = nullptr;
    bool flag;

    openFile(myfile);
    cout << "Business card input tool"<< endl;
    cout<< "Make sure to start all your contacts with either capital letters or lowercase "<< endl;

    do{
    cout <<endl;
    newNodePtr = CreateNode();
    AddNode(listPtr,newNodePtr);
    }while(cont(flag) != false);


    PrintList(listPtr, myfile);
    CloseFile(myfile);
    cout << "Your contacts are saved in contacts.dat"<<endl;


    return 0;
}
//*******************************************************************************************************
void PrintList(NodeType *currPtr, ofstream &myfile){
   while (currPtr != nullptr){ // writes all the pointser into the file
       myfile << currPtr->component << "."<< endl;
        currPtr = currPtr->link;
    }
    cout << endl;
}
//********************************************************************************************************
NodeType *CreateNode()
{
  //1 - Allocate space for new node
    NodeType *newNodePtr;
    string nodeVal;
    string nodeval2;
    string nodeval3;
    newNodePtr = new NodeType;
  //2 - Assign values to node
    cout << "Enter last name: ";
    cin >> nodeVal;
    cout << "Enter First Name: ";
    cin >> nodeval2;
    cout << "Enter phone Number: ";
    cin >> nodeval3;

    newNodePtr->component = nodeVal + "  "+  nodeval2 + "  "+ nodeval3;
    newNodePtr->link = nullptr;
  //3 - Return node
    return newNodePtr;
}
//********************************************************************************************************
//Adds a given node to a list in a sorted position
void AddNode(NodeType *&listPtr, NodeType *newNodePtr)
{
    NodeType *currPtr = listPtr;
    NodeType *prevPtr = nullptr;
    NodeType first;
    //1 - Find position in list
        while((currPtr != nullptr) && (newNodePtr->component > currPtr ->component)){
            prevPtr = currPtr;
            currPtr = currPtr->link;
            cout << endl;
        }

    //2 - Insert node
        if((currPtr == nullptr) && (prevPtr == nullptr)){
            cout << "New list\n";
            listPtr = newNodePtr;
            cout<<endl;
        }
        //    Beginning of list
        else if (prevPtr == nullptr){
            cout << "Added to the front of the list\n";
            newNodePtr->link = listPtr;
            listPtr = newNodePtr;
            cout<<endl;

        }
        //    End of List
        else if (currPtr == nullptr){
            cout << "Added to the end of the list\n";
            prevPtr->link = newNodePtr;
            cout<<endl;
        }
        //    Middle-ish
        else{
            cout << "Added to the middle of the list\n";
            newNodePtr->link = currPtr;
            prevPtr->link = newNodePtr;
            cout<<endl;
        }

}
//*********************************************************************************************************

// open file
void openFile(ofstream &myfile){
    myfile.open("contacts.dat");



}
// close file
void CloseFile(ofstream &myfile){
    myfile.close();



}
// runs to see if you want to input data
bool cont(bool flag){
    char input;
    cout << "Would you like to add a business card? (y/n)";
    cin >> input;

    if (input =='y'|| input == 'Y'){

        flag = true;
        return flag;
    }
    else if (input !='y'|| input != 'Y'){

        flag = false;
        return flag;
    }





}


