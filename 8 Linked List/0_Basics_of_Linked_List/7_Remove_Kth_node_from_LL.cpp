#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};



// Solution 

Node* removeK(Node* head, int k) {

    if (head == nullptr)
        return head;

    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {

        cnt++;

        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}






void print(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = new Node(12);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(7);

    cout << "Original Linked List: ";
    print(head);

    int k = 4;

    head = removeK(head, k);

    cout << "After Removing " << k << "th Node: ";
    print(head);

    return 0;
}


// Time Complexity :O(N)
// Space Complexity : O(1)