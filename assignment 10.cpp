//Justin McCoy
//assignment 10
//4/18/17
//CSC 201
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

typedef int ComponentType;

struct NodeType;
    typedef NodeType *NodePtr;


struct NodeType
{
    ComponentType component;
    NodeType *link;
};

void AddNode(NodeType *&listPtr, NodeType *newNodePtr);

//*******************************************************************************************
int main()
{
    NodeType *lastPtr;      // Points to last element in the list
    NodeType *listPtr;      // Points to first element in the list
    NodeType *currPtr;      // Points to currently used element (working pointer)
    NodeType *newNodePtr;   // Used to point to newly created nodes

    return 0;


}

/*

14

{
            newNodePtr->link = currPtr;
            prevPtr->link == 32;
}

15

{
            prevPtr->link = currPtr->link;
            delete currPtr;
            listPtr = newNodePtr;

}
16
*/


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
