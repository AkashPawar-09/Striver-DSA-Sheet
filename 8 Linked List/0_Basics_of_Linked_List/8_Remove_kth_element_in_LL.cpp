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

class Solution {
public:
    Node* removeElement(Node* head, int el) {

        if (head == nullptr)
            return head;

        if (head->data == el) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {

            if (temp->data == el) {
                prev->next = temp->next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

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

    int element = 5;

    Solution obj;
    head = obj.removeElement(head, element);

    cout << "After Removing " << element << ": ";
    print(head);

    return 0;
}



// Time Complexity :O(N)
// Space Complexity : O(1)