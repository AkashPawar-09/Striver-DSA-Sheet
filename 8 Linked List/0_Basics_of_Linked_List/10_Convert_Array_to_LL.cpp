#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = NULL;
    }
};




// Solution 

Node* convertArr2LL(vector<int> &arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);

    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    Node* head = convertArr2LL(arr);

    print(head);

    return 0;
}


// Time Complexity :O(N)
// Space Complexity : O(1)