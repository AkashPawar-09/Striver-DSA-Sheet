#include <iostream>
using namespace std;

// Node class

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


// Solution class (CP)

class Solution {
public:
    int getCount(Node* head) {

        int count = 0;                      // initilise count as 0
        Node* temp = head;                  // temperary pointer named as temp to traverse nodes

        while (temp != NULL) {              // while node becomes NULL
            count++;                        // increase count 
            temp = temp->next;              // move head to next node
        }

        return count;                       // return total number of nodes
    }
};


// USER INPUT DRIVER CODE 

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

    Solution obj;

    cout << "Total Nodes = " << obj.getCount(head);

    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)