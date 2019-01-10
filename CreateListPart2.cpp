//Justin McCoy Antony Charles
//CreateList Assignment P2
//4/11/17
//CSC 201
#include <iostream>
#include <string>

using namespace std;

struct NodeType
{
    string component;
    string firstName;
    string phoneNumber;
    NodeType *link;
};

void PrintList(NodeType *currPtr);
//Creates and returns a new node
NodeType *CreateNode();
//Adds a given node to a list in a sorted position
void AddNode(NodeType *&listPtr, NodeType *newNodePtr);
//Will find a value and delete that node from list
void DeleteNode(NodeType *&listPtr, string &delVal);
//*******************************************************************************************
int main()
{
    NodeType *lastPtr;      // Points to last element in the list
    NodeType *listPtr;      // Points to first element in the list
    NodeType *currPtr;      // Points to currently used element (working pointer)
    NodeType *newNodePtr;   // Used to point to newly created nodes
    string delVal;


    listPtr = nullptr;

    newNodePtr = CreateNode();
    AddNode(listPtr, newNodePtr);
    PrintList(listPtr);

    // 1) Create a new node, assign the value 200 to the component,
    //       set listPtr to point to the node, also set currPtr and lastPtr to
    //       point to the node. Set link to nullptr
    newNodePtr = CreateNode();
    AddNode(listPtr, newNodePtr);
    PrintList(listPtr);



    // 2) Create a new node with component value 300. Add this element to
    //       the end of the list. (i.e., Set link of node from Step 1 to point to
    //       this node.) What else do you need to set?
    newNodePtr = CreateNode();
    AddNode(listPtr, newNodePtr);
    PrintList(listPtr);

////    // 3) Using listPtr, print out the component value of both nodes
////    cout << "Node 1: " << listPtr->component << endl;
////    cout << "Node 2: " << listPtr->link->component << endl;
//
//    // 4) Using currPtr, print out the component value of the first node
//    cout << "Node 1: " << currPtr->component << endl;
//
//    // 5) Advance currPtr to point to the second node and print out the component
//    currPtr = currPtr->link;
//    cout << "Node 2: " << currPtr->component << endl;
//
//    // 6) Create a new node with component value 400 and add it to the
//    //       end of the list.
    newNodePtr = CreateNode();
    AddNode(listPtr, newNodePtr);
    PrintList(listPtr);
//    lastPtr->link = newNodePtr;
//    lastPtr = newNodePtr;
//    PrintList(listPtr);

    // 7) Create a new node with component value 100 and add it to the
    //       front of the list.
    newNodePtr = CreateNode();
    AddNode(listPtr, newNodePtr);
    PrintList(listPtr);
    //DeleteNode(listPtr, delVal);

    // 8) Write a loop that will use currPtr to traverse through the list and
    //       print out each component
    NodeType *ptr = listPtr;
    while (ptr != nullptr){
        cout << ptr->component << " ";
        ptr = ptr->link;
    }
    cout << endl;

    // 9) Move your loop from the last step into a function.
    PrintList(listPtr);

    // 10) Use your function to print out the list after adding each node in
    //        the steps above



    return 0;
}
//*******************************************************************************************************
void PrintList(NodeType *currPtr){
   while (currPtr != nullptr){
        cout << currPtr->component << " ";
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
    newNodePtr = new NodeType;
  //2 - Assign values to node
    cout << "Enter last name: ";
    cin >> nodeVal;
    newNodePtr->component = nodeVal;
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
        }
        //    Beginning of list
        else if (prevPtr == nullptr){
            cout << "Added to the front of the list\n";
            newNodePtr->link = listPtr;
            listPtr = newNodePtr;
        }
        //    End of List
        else if (currPtr == nullptr){
            cout << "Added to the end of the list\n";
            prevPtr->link = newNodePtr;
        }
        //    Middle-ish
        else{
            cout << "Added to the middle of the list\n";
            newNodePtr->link = currPtr;
            prevPtr->link = newNodePtr;
        }

}
//*********************************************************************************************************
//Will find a value and delete that node from list
void DeleteNode(NodeType *&listPtr, string &delVal)
{
    NodeType *currPtr = listPtr;
    NodeType *prevPtr = nullptr;
    cout << "Please enter a value you would like to delete: ";
    cin >> delVal;

    //1 - Find the correct node
    while ((currPtr != nullptr) &&
           (currPtr->component != delVal)){
            cout << currPtr->component << " ";
            prevPtr = currPtr;
            currPtr = currPtr->link;
           }
        cout << endl;

    if((currPtr != nullptr) &&
        (currPtr->component == delVal))
        cout << "Value found\n";
    //2 - Remove node from list
    //      Beginning of list
    if(prevPtr == nullptr){
        cout << "First node\n";
        listPtr = currPtr->link;
    }
    //      End of list
    else if(currPtr->link == nullptr){
        cout << "Last node \n";
        prevPtr->link = nullptr;
    }
    //      Middle-ish
    else{
        cout << "Middle node\n";
        prevPtr->link = currPtr->link;
    }

    //3 - Deallocate node
    delete currPtr;

}







