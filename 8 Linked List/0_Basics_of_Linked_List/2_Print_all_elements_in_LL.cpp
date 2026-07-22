#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};


int main () {
    Node* first = new Node() ;
    Node* second = new Node () ;
    Node* third = new Node () ;

    first -> data = 100 ; 
    second -> data = 200 ; 
    third -> data = 300 ;

    first -> next = second ;
    second -> next = third ;
    third -> next = NULL ;

    // PRINTING CODE :
    
    Node* temp = first ;

    while (temp != NULL ) {
        cout << temp -> data << " " ;
        temp = temp -> next ;
    }

}