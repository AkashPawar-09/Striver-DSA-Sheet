/* --------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* back;
    Node* next;

    Node(int data){
        this->data=data;
        back=NULL;
        next=NULL;
    }
};

int main(){

    Node* first=new Node(10);           // new node named as first having value (data) = 10 

    Node* second=new Node(20);          // new node named as second having value (data) = 20

    first->next=second;                 // creatig a forward link (next)

    second->back=first;                 // creating a backward link (back)

    cout<<first->data<<" ";             // 10

    cout<<first->next->data<<endl;      // 20 

    cout<<second->back->data<<" ";      // 10 

    cout<<second->data<<endl;           // 20

    return 0;
}


------------------------------------------------------------------------------------------------------------------------------


_________________________________________________
| Singly LL         | Doubly LL                 |
| ----------------- | ------------------        |
| data + next       | prev + data + next        |
| Move only forward | Move forward & backward   |
| Uses less memory  | Uses more memory          |
| Easier structure  | Slightly complex          |
| Less memory       | More memory               |
| Deletion harder   | Deletion easier           |
| Reverse difficult | Reverse easier            |

------------------------------------------------------------------------------------------------------------------------------


Structure of Doubly Linked List Node
Theory

A Doubly Linked List (DLL) node contains 3 parts:

Prev Pointer → Stores the address of the previous node.
Data → Stores the value.
Next Pointer → Stores the address of the next node.
+-------------------------+
| Prev | Data | Next      |
+-------------------------+

Unlike a Singly Linked List, every node can move in both directions.

NULL <- 10 <-> 20 <-> 30 -> NULL
10 has no previous node → prev = NULL
30 has no next node → next = NULL


------------------------------------------------------------------------------------------------------------------------------

Memory Representation


Suppose

Address of 10 = 100
Address of 20 = 200
Address of 30 = 300


Then memory looks like
________________________________
| Address | Prev | Data | Next |
| ------- | ---- | ---- | ---- |
| 100     | NULL | 10   | 200  |
| 200     | 100  | 20   | 300  |
| 300     | 200  | 30   | NULL |



------------------------------------------------------------------------------------------------------------------------------

1. Forward Traversal


head
 ↓
NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL

10 → 20 → 30 → 40 → NULL

_________________________________________________________

2. Backward Traversal

NULL <- 10 <-> 20 <-> 30 <-> 40 -> NULL
                              ↑
                            tail

40 → 30 → 20 → 10 → NULL

------------------------------------------------------------------------------------------------------------------------------

// 1. Forward Traversal


#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;                   // 1st and 2nd forward connection 
    second->prev = first;                   // 1st and 2nd backward connection 

    second->next = third;                   // 2nd and 3rd forward connection 
    third->prev = second;                   // 2nd and 3rd backward connection 

    cout << first->data << " ";             // 10
    cout << first->next->data << endl;      // 20

    cout << second->prev->data << " ";      // 10
    cout << second->data << " ";            // 20
    cout << second->next->data << endl;     // 30

    cout << third->prev->data << " ";       // 20
    cout << third->data << endl;            // 30

    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)

------------------------------------------------------------------------------------------------------------------------------

// 2. Backward Traversal


#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    Node* temp = first;

    cout<<"Forward Traversal : ";

    while(temp != NULL){
        cout<<temp->data<<" ";              // Forward Traversal : 10 20 30 40 
        temp = temp->next;
    }
    
    cout << endl ;

    Node* temp2 = fourth;

    cout<<"Backward Traversal : ";

    while(temp2 != NULL){
        cout<<temp2->data<<" ";             // Backward Traversal : 40 30 20 10 
        temp2 = temp2->prev;
    }
    

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)

-------------------------------------------------------------------------------------------------------------------------- */