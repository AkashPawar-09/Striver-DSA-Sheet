#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};





// Solution 

Node* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}



void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertBeforeValue(Node* head, int el, int val) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == val) {
        return new Node(el, head);
    }

    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};

    Node* head = convertArr2LL(arr);

    cout << "Original Linked List: ";
    print(head);

    head = insertBeforeValue(head, 100, 8);

    cout << "After Inserting 100 before 8: ";
    print(head);

    return 0;
}





// Time Complexity :O(N)
// Space Complexity : O(1)