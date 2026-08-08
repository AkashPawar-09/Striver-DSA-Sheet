#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};











// Solution - 2 pointer approach

class Solution {
public:
    Node* findTail(Node* head) {            // finds right pointer
        Node* tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        return tail;
    }

    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>> ans;

        if (head == NULL)                       // if empty DLL
            return ans;                         // return empty ans vector

        Node* left = head;                      // left pointer = head
        Node* right = findTail(head);           // right pointer = last node from findTail function

        while (left != right  &&  (left->data) < (right->data) ) {  
        // loop until left pointer is not right pointer AND data in left pointer crosses data in right pointer
            
            int sum = left->data + right->data;             // sum of left and right pointer's data 

            if (sum == target) {                            // if sum is equal to target
                ans.push_back({left->data, right->data});   // push it to ans vector
                left = left->next;                          // move left pointer to next 
                right = right->prev;                        // move right pointer to back (prev)
            }
            else if (sum < target) {                        // if sum is smaller than target 
                left = left->next;                          // move left pointer to next 
            }
            else {                                          // if sum is greater than target
                right = right->prev;                        // move right pointer to back (prev)
            }
        }

        return ans;                                         // return ans vector
    }
};









Node* createList(vector<int> arr) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int x : arr) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL)
            cout << " <-> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 7;

    Node* head = createList(arr);

    cout << "Doubly Linked List: ";
    printList(head);

    Solution obj;

    vector<vector<int>> ans = obj.givenSumPairs(head, target);

    cout << "Pairs with sum " << target << ":" << endl;

    for (auto p : ans) {
        cout << "(" << p[0] << ", " << p[1] << ")" << endl;
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)