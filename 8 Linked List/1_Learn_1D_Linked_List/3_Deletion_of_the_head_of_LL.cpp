#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() {
        data = 0;
        next = nullptr;
    }

    ListNode(int x) {
        data = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* next) {
        data = x;
        this->next = next;
    }
};



// Solution : 

class Solution {
public:
    ListNode* deleteHead(ListNode*& head) {

        if (head == nullptr)        // if LL is empty (contains only nullptr)
            return nullptr;         // return null pointer

        ListNode* temp = head;      // giving name 'temp' to node having head 
        head = head->next;          // move head by 1 to next node
        delete temp;                // now delete old head(temp)

        return head;                // return new head
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

    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;
    head = obj.deleteHead(head);

    cout << "After Deleting Head: ";
    printList(head);

    return 0;
}