/*

Input: LinkedList = 2 -> 3 -> 4 -> 5, newData = 1, key = 2
Output: LinkedList = 2 -> 1 -> 3 -> 4 -> 5


Input: LinkedList = 1 -> 3 -> 5 -> 7, newData = 1, key = 2
Output: Node not found

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

// Solution class
class Solution {
public:
    Node* insertAfterNode(Node* head, int key, int newData) {

        Node* temp = head;                              // Start traversing the linked list from the head

        // loop while temp goes until last element and until key not found
        while (temp != NULL && temp->data != key) {     // find Node node whose data is equal to the given key 
            temp = temp->next;                          // move pointer temp to next
        }

        if (temp == NULL) {                             // if temp becomes NULL (last node)
            cout << "Node not found";                   // printing "Node not found"
            return head;                                // return head
        }

        Node* newNode = new Node(newData);              // Create a new node with the given data (newData)
        newNode->next = temp->next;                     // Make the new node point to the next node of the key node

        temp->next = newNode;                           // Make the key node point to the newly created node

        return head;                                    // Return the updated head
    }
};

// Print Linked List
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// User Input Driver Code
int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int key, value;

    cout << "Enter the node after which to insert: ";
    cin >> key;

    cout << "Enter value to insert: ";
    cin >> value;

    Solution obj;

    head = obj.insertAfterNode(head, key, value);

    cout << "Updated Linked List: ";
    printList(head);

    return 0;
}




// Time Complexity :O(N)
// Space Complexity : O(1)