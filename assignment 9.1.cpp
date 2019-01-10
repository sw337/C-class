
#include <iostream> // mandatory to compile


using namespace  std;

struct Book{ // creates book structure
    string title;
    Book *next;
};

Book *add_node(Book *in_root); // function prototype for adding a book title
void print_list(Book *in_root); // function protoype for printing a book title


int main(){
    Book *head = NULL;// sets linked list to null
    Book *next_ptr = NULL;

    char choice; // character for choice

    do{
        cout << "(a)dd node"<< endl;
        cout << "(p)rint list" << endl;
        cout << "(q)uit program" << endl;
        cin >> choice;

        choice = toupper(choice); // uppercase choice

        switch(choice){

    case 'A': //add
        head = add_node(head);
        break;
    case 'P': // print books
        print_list(head);
        break;
    case 'Q': // quit program
        break;
    default:
        cout << "invalid choice" << endl;





        }

    }while(choice != 'Q');


    return 0;
}

Book *add_node(Book *in_root){

   // two temporary variable
    Book *next_ptr = NULL;
    Book *prev_ptr = NULL;

    if(in_root == NULL)
        {

        if( (in_root = new Book) != NULL)
        {
            next_ptr = in_root;
            cout<< "Title: ";
            cin>> next_ptr->title; // gets book title
            next_ptr->next = NULL; // makes sure the next is always null
        }
    else
        {
        cout << "Unable to allowcate memory"<< endl;
        return NULL;
    }

            return next_ptr;
        }
    else{ // gets new book titles if titles exist
        next_ptr = in_root;
        while(next_ptr->next != NULL) // moves on to the next
        {
            next_ptr = next_ptr->next;
        }
        prev_ptr = next_ptr;
        if ((next_ptr= new Book) != NULL)
            {
                prev_ptr->next =next_ptr;
                cout << "Title: ";
                cin >> next_ptr->title; // gets new title

                next_ptr->next = NULL; // moves the pointer next to null
            }
            else{
                cout << "error unable to allocate memory"<< endl; // doesn't allow new memory to be allocated
            }
            return in_root;
    }
}



void print_list(Book *in_root){
    Book *next_ptr; // declares new_ptr variable

    next_ptr = in_root; // assigns next_ptr to what it already has
    if (next_ptr == NULL){
    cout<< "empty list" << endl;// prints empty list if nothing has been added
    }
    else
        {
              while(next_ptr != NULL)// moves on to the next book until it hits the end
                {
                cout << next_ptr->title <<endl; // prins book name
                next_ptr = next_ptr->next;
                }

        }

}
