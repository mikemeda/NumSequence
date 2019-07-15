// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type CAPACITY = _____
//     sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#include <iostream>
#include <cctype>       // Provides toupper
#include <cstdlib>      // Provides EXIT_SUCCESS

using namespace std;
class sequence
{
public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        sequence( ){used=0; current_index=0;};
        // MODIFICATION MEMBER FUNCTIONS
        void start( ){current_index=0; };
        void advance( ){if(is_item()){if(current_index<CAPACITY){current_index=current_index+1;}}};
        void insert(const value_type& entry){ data[current_index]=entry; used++; current_index++;};
        void attach(const value_type& entry);
        void remove_current( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const {return used;};
        bool is_item( ) const {if(data[current_index]>=0){return true;}
          else return 0;};
        value_type current( ) const { return data[current_index];};
        void prints(){for(int i=0; i<used; i++){cout<<data[i];}};
private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
};
void sequence::attach(const value_type&entry ){
    value_type i=current_index;
    if(size()==0){data[current_index]=entry; used++;}
    else{
    if(size()<=28)
       for(current_index=size()-1; current_index>i; current_index-- ){
         data[current_index+1]=data[current_index];
        }}
        current_index=i; used++;
  data[current_index+1]=entry;}


void sequence::remove_current(){
    for(int i=current_index+1; i<size(); i++){
        data[i]=data[i+1];
    }
    used--;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " !   Activate the start( ) function" << endl;
    cout << " +   Activate the advance( ) function" << endl;
    cout << " ?   Print the result from the is_item( ) function" << endl;
    cout << " C   Print the result from the current( ) function" << endl;
    cout << " P   Print a copy of the entire sequence" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " A   Attach a new number with the attach(...) function" << endl;
    cout << " R   Activate the remove_current( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void show_sequence(sequence display)
// Library facilities used: iostream
{display.start( );
    for( int i=0; i<display.size(); i++){
        if(display.is_item( ) ){
        cout << display.current( ) << endl;}
         display.advance( );
}}

double get_number( )
// Library facilities used: iostream
{
    double result;

    cout << "Please enter a real number for the sequence: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}


int main( )
{    char choice;   // A command character entered by the user
    sequence();
    sequence test;// A sequence that we’ll perform tests on

    cout << "I have initialized an empty sequence of real numbers." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case '!': test.start( );
                      break;
            case '+': test.advance( );
                      break;
            case '?': if (test.is_item( ))
                          cout << "There is an item." << endl;
                      else
                          cout << "There is no current item." << endl;
                      break;
            case 'C': if (test.is_item( ))
                           cout << "Current item is: " << test.current( ) << endl;
                      else
                          cout << "There is no current item." << endl;
                      break;
            case 'P': show_sequence(test);
                      break;
            case 'S': cout << "Size is " << test.size( ) << '.' << endl;
                      break;
            case 'I': test.insert(get_number( ));
                      break;
            case 'A': test.attach(get_number( ));
                      break;
            case 'R': test.remove_current( );
                      cout << "The current item has been removed." << endl;
                      break;
            case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;

}

