#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};


// Solution : 
class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode* newNode = new ListNode(X);        // create new node with given value x
            newNode->next = head;                       // Make the new node point to the current head
            head = newNode;                             // update head with newly created node
            return head;                                // Return the new head of the linked list
        }
};



void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    head = new ListNode(20);
    head->next = new ListNode(30);
    head->next->next = new ListNode(40);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;
    head = obj.insertAtHead(head, 10);

    cout << "After Inserting at Head: ";
    printList(head);

    return 0;
}



// Time Complexity : O(1)
// Space Complexity : O(1)