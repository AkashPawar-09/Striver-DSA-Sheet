/* --------------------------------------------------------------------------------------------------------------------------

1. What is a Linked List?

Definition

A Linked List is a linear data structure where elements (called nodes) are stored separately in memory. Each node contains:

Data
Pointer (address) to the next node

Unlike arrays, linked list elements are not stored in contiguous memory.

------------------------------------------------------------------------------------------------------------------------------

2. Why do we need Linked List?

Problems with Arrays
Fixed size
Insertion is slow
Deletion is slow
Memory can be wasted
Need contiguous memory
Advantages of Linked List

✅ Dynamic size

✅ Easy insertion

✅ Easy deletion

✅ No memory wastage

✅ Does not require contiguous memory

------------------------------------------------------------------------------------------------------------------------------

3. Array vs Linked List

_________________________________________________________________________________________________________________
| Feature                    | Array                                   | Linked List                            |
| -------------------------- | --------------------------------------- | -------------------------------------- |
| **Memory Allocation**      | Contiguous (continuous) memory          | Non-contiguous (scattered) memory      |
| **Size**                   | Fixed (or needs resizing)               | Dynamic, grows/shrinks as needed       |
| **Access Time**            | O(1) using index                        | O(n), must traverse from head          |
| **Insertion at Beginning** | O(n)                                    | O(1)                                   |
| **Insertion at Middle**    | O(n)                                    | O(n) to reach position, O(1) to insert |
| **Insertion at End**       | O(1) if space available, otherwise O(n) | O(n) (or O(1) with a tail pointer)     |
| **Deletion at Beginning**  | O(n)                                    | O(1)                                   |
| **Deletion at Middle**     | O(n)                                    | O(n) to reach node, O(1) to delete     |
| **Deletion at End**        | O(1)                                    | O(n) (for singly linked list)          |
| **Memory Overhead**        | Only stores data                        | Stores data + pointer(s)               |
| **Cache Performance**      | Excellent                               | Poor                                   |
| **Binary Search**          | Possible (sorted array)                 | Not efficient                          |
| **Random Access**          | Yes                                     | No                                     |
| **Memory Utilization**     | May waste memory if oversized           | Uses memory only when needed           |
| **Implementation**         | Simple                                  | More complex                           |
| **Searching**              | O(n), Binary Search O(log n) if sorted  | O(n)                                   |
| **Traversal**              | Easy using index                        | Using pointers only                    |
| **Resizing**               | Difficult                               | Easy                                   |
| **Pointer Requirement**    | Not required                            | Required                               |
| **Best Use Case**          | Frequent indexing                       | Frequent insertion/deletion            |


------------------------------------------------------------------------------------------------------------------------------

Advantages of Arrays : 
    Fast random access (O(1))
    Better CPU cache performance
    Lower memory overhead
    Supports binary search
    Simple implementation
    Efficient for fixed-size data

______________________________________________________________________________________________________________________________

Disadvantages of Arrays :
    Fixed size
    Expensive insertion and deletion
    Requires contiguous memory
    Resizing requires copying all elements
    Can waste memory if oversized

______________________________________________________________________________________________________________________________

Advantages of Linked Lists :
    Dynamic size
    Fast insertion and deletion (after reaching the position)
    No need for contiguous memory
    Easy to grow and shrink
    Memory allocated only when needed
    Suitable for implementing stacks, queues, graphs, and adjacency lists

______________________________________________________________________________________________________________________________

Disadvantages of Linked Lists :
    Slow random access (O(n))
    Extra memory required for pointers
    Poor cache locality
    Cannot efficiently perform binary search
    More complex implementation
    Memory management (allocation/deallocation) is required

______________________________________________________________________________________________________________________________
------------------------------------------------------------------------------------------------------------------------------

4. Node

Definition
A Node is the basic building block of a linked list.

Each node contains

Data
Pointer to next node

----------------------------------------+
#include <iostream>                     |
using namespace std;                    |
class Node                              |
{                                       |
public:                                 |
    int data;                           |
    Node* next;                         |
};                                      |
----------------------------------------+

Here

data -> stores value
next -> stores address of next node

------------------------------------------------------------------------------------------------------------------------------


5. Pointer

Definition
A Pointer is a variable that stores the memory address of another variable.

Example

int x = 10;
int *p = &x;

Memory

x = 10

p -----> x

Output

#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    int *p = &x;

    cout << x << endl;
    cout << &x << endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}

Output

10
0x61ff08
0x61ff08
10

------------------------------------------------------------------------------------------------------------------------------

6. Creating First Node

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main(){
    Node* first = new Node();
    first->data = 10;
    first->next = NULL;
    cout << first->data;
    return 0;
}


Memory :

first
|
V
+------+------+
| 10   | NULL |
+------+------+

------------------------------------------------------------------------------------------------------------------


7. Connecting Nodes

Create three nodes

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int main()
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    return 0;
}

Diagram

first
|
V
10 -----> 20 -----> 30 -----> NULL

------------------------------------------------------------------------------------------------------------------

8. Traversing a Linked List

Definition
Traversing means visiting every node one by one.

Algorithm

Start from head

While current != NULL
    Print current data
    Move to next node



#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

int main()
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    Node* temp = first;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }

    return 0;
}



Output

10 20 30

------------------------------------------------------------------------------------------------------------------

9. Printing Linked List

Method 1

Node* temp = first;

while(temp != NULL)
{
    cout << temp->data << " ";

    temp = temp->next;
}

Method 2 (Using Function)

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int main()
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    print(first);

    return 0;
}

Output

10 20 30

------------------------------------------------------------------------------------------------------------------

Complete Example (All Concepts Together)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int main()
{
    // Create nodes
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Store data
    first->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = NULL;

    // Print linked list
    print(first);

    return 0;
}
Output
10 20 30


------------------------------------------------------------------------------------------------------------------

Time Complexities

| Operation                            | Time Complexity |
| ------------------------------------ | --------------- |
| Access nth node                      | O(n)            |
| Traverse                             | O(n)            |
| Search                               | O(n)            |
| Insert at beginning                  | O(1)            |
| Insert at end (without tail pointer) | O(n)            |
| Delete at beginning                  | O(1)            |
| Delete at end                        | O(n)            |


-------------------------------------------------------------------------------------------------------------------------- */