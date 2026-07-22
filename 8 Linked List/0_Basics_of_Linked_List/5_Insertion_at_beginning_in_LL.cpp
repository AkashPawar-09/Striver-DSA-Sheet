/*

Input: x = 1,
Output: 1 -> 2 -> 10
Explanation: We can see that 1 is inserted at the beginning of the linked list.


Input: x = 1,
Output: 1 -> 2 -> 3 -> 4 -> 5
Explanation: We can see that 1 is inserted at the beginning of the linked list.

*/



#include <iostream>
using namespace std;

// Node class

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// Solution class (CP)

class Solution {
public:
    Node* insertAtBeginning(Node* head, int x) {

        Node* newNode = new Node(x);                // create new node with given value x

        newNode->next = head;                       // Make the new node point to the current head

        head = newNode;                             // update head with newly created node

        return head;                                // Return the new head of the linked list
    }
};


void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    // Create linked list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before Insertion: ";
    printList(head);

    Solution obj;

    head = obj.insertAtBeginning(head, 5);

    cout << "After Insertion: ";
    printList(head);

    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)