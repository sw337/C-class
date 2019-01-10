//Justin McCoy
//linked list for business cards
//4/25/17
//CSC 201
#include <iostream>
#include <string>

using namespace std;

struct CustomerType
{
    string lastName;
    string firstName;
    string phonenumber;
};

struct NodeType;
typedef NodeType* NodePtr;

struct NodeType
{
    CustomerType customer;
    NodePtr next;
};

// Adds data to an existing node
// Pre: Valid NodePtr w/ allocated memory
// Post: NodePtr contains valid info or set to nullptr if no info
void FillInfo(NodePtr&);

// Allocates memory and initializes nodePtr->next to NULL
// Pre: None
// Post: Allocated nodePtr with ->next set to NULL
NodePtr CreateNode();

// Inserts node into list in sorted location
// Pre: Valid pointer for list and prefilled NodePtr
// Post: Sorted list
void InsertNode(NodePtr&, NodePtr);

// Returns a pointer to the node with matching last name.
// Pre: Valid NodePtr and string.
// Post: Returns pointer to matching node or nullptr if not found.
NodePtr SearchNode(NodePtr head, string l);

// Prints out list
// Pre: Valid nodeptr
void PrintList(NodePtr);

// Save data to file
// Pre: Valid nodeptr
void SaveFile(NodePtr);

// Support function to capitalize a name
// Pre: s must point to a valid string
// Post: s will be modified to capitalize the first letter
void NormalizeString(string& s);


void ReversePrintList(NodePtr np);

// Deletes the node containing the passed string.
// Pre: NodePtr points to valid linked list and string points to a valid string
// Post: Node containing the passed string has been removed from the list.
void DeleteNode(NodePtr listPtr, string& l);

int main()
{
    NodePtr headPtr = NULL;
    NodePtr newPtr = NULL;
    string l;
    bool done = false;
    NodePtr np;
    char choice;
    CustomerType customer;
    NodePtr listPtr;

    cout << "Enter names to continue and leave blank to terminate entries.";
    cout << endl;
    do {
        newPtr = CreateNode();

        FillInfo(newPtr);

        if (newPtr != nullptr){
            InsertNode(headPtr, newPtr);
            PrintList(headPtr);
            done = false;
        }
        else{
            done = true;

            cout<< "Would you like to  delete the last node (y/n)?"<<endl;
            cin>>choice;
            if (choice == 'y'||choice == 'Y')
            {
                DeleteNode(headPtr, customer.lastName);
                DeleteNode(headPtr, customer.firstName);
                DeleteNode(headPtr, customer.phonenumber);
                PrintList(headPtr);
            }
            else {

                PrintList(headPtr);
            }

        }


    } while (!done);




    return 0;
}

NodePtr CreateNode()
{
    NodePtr newPtr = new NodeType;
    newPtr->next = nullptr;

    return newPtr;
}

void PrintList(NodePtr np)
{
    while (np != NULL)
    {
        cout << np->customer.lastName << ", " << np->customer.firstName << endl;
        cout << " # "<< np->customer.phonenumber<< endl;
        np = np->next;
    }
}

void FillInfo(NodePtr& np)
{


    cout << "Enter last name: ";
    getline(cin, np->customer.lastName);
    NormalizeString(np->customer.lastName);



    if (np->customer.lastName == ""){
        delete np;
        np = nullptr;
    }
    else{
        cout << "Enter first name: ";
        getline(cin, np->customer.firstName);
        NormalizeString(np->customer.firstName);
    cout << "Enter phone number: ";
        getline(cin, np->customer.phonenumber);
        NormalizeString(np->customer.phonenumber);

    }
}

void InsertNode(NodePtr& head, NodePtr np)
{
    NodeType *currPtr = head;
    NodeType *prevPtr = nullptr;

    NodeType first;
    //1 - Find position in list
        while((currPtr != nullptr) && (np->customer.lastName > currPtr ->customer.lastName)){
            prevPtr = currPtr;
            currPtr = currPtr->next;
            cout << endl;
        }

    //2 - Insert node
        if((currPtr == nullptr) && (prevPtr == nullptr)){
            cout << "New list\n";
            head = np;
            cout<<endl;
        }
        //    Beginning of list
        else if (prevPtr == nullptr){
            cout << "Added to the front of the list\n";
            np->next = head;
            head = np;
            cout<<endl;

        }
        //    End of List
        else if (currPtr == nullptr){
            cout << "Added to the end of the list\n";
            prevPtr->next = np;
            cout<<endl;
        }
        //    Middle-ish
        else{
            cout << "Added to the middle of the list\n";
            np->next = currPtr;
            prevPtr->next = np;
            cout<<endl;
        }


}

NodePtr SearchNode(NodePtr listPtr, string lastName)
{

}

void NormalizeString(string& s)
{
    string normal1; // string for the first part of our normal string
    string normal2; // string for the second part of our normal string
    int j = 0;
    int k = 0;

    for (int l = s.length(); k < l; k++) // changes everything to uppercase
        {
            normal1 += toupper(s.at(k)); // capitalizes new string
        }

    for(int m = normal1.length(); j < m; j++) // checks if any special characters or spaces are used and removes them
        {
            if((isalpha(normal1.at(j)))||isalnum(normal1.at(j)))
                {
                    normal2 += normal1.at(j); // writes only letters  new string
                }
        }
        s = normal2;

}

void ReversePrintList(NodePtr np){

        if (np!= NULL){
            ReversePrintList(np->next);
            cout << np->customer.lastName<< endl;
}



}



void DeleteNode(NodePtr listPtr, string& l){
            l = ' ';
			listPtr = 0;


}
