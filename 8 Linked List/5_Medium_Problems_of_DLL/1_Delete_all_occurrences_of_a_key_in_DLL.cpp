/*
Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
Output: head -> 2 <-> 3 <-> 4
Explanation: All nodes with the value 1 were removed.


Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2
Output: head -> 3 <-> -1 <-> 4
Explanation: All nodes with the value 2 were removed.

Note that the value of head is changed.

*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }

    ListNode(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};








// Solution 

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* current = head;

        while (current != NULL) {
            ListNode* nextNode = current->next;

            if (current->val == target) {                   // if deleting node is found 
                if (current->prev != NULL)                  // if previous node exists (not head node)
                    current->prev->next = current->next;    // make connection of previous node and next node of current
                
                else                                        // if previous node does not exist (head node)
                    head = current->next;                   // move head to next node after head 

                
                if (current->next != NULL)                  // if next element of current exist (current is not last node)
                    current->next->prev = current->prev;    // make connection of cureent's prevoius and next node

                delete current;                             // delete current node (which is target)
            }

            current = nextNode;                             // moving current forward 
        }

        return head;                                        // return head after loop completed 
    }
};






ListNode* insertAtEnd(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL)
        return newNode;

    ListNode* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = NULL;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 5);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.deleteAllOccurrences(head, 2);

    cout << "\nAfter Deleting 2:\n";
    printList(head);

    return 0;
}



// Time Complexity : O(N) 
// Space Complexity : O(1)