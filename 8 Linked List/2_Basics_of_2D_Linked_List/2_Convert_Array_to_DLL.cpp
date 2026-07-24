#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1) {
        data = data1;
        next = NULL;
        back = NULL;
    }
};





// Solution 

Node* convertArr2DLL(vector<int> &arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {      // loop for 2nd node to last
        Node* temp = new Node(arr[i]);          // 2nd node named as 'temp'
        temp->back = prev;                      // link 2nd's back as 1st
        prev->next = temp;                      // link 1st's next as 2nd
        prev = temp;                            // update 1st as 2nd and move for 3rd
    }

    return head;                                // return head 
}



// Print Doubly Linked List (Forward)
void printForward(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List: ";
    printForward(head);

    return 0;
}




// Time Complexity :O(N)
// Space Complexity : O(1)