/*

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};







// Solution 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {return head;}
        // if LL have only one node OR only 1 element OR 0 rotation , then return head as it is

        int count = 0;                      // create count variable to count number of nodes in LL 
        ListNode* temp = head;              // create dummy temp node to traverse LL

        while (temp != NULL) {              // loop until temp becomes NULL
            count++;                        // count number of nodes
            temp = temp->next;              // move temp to next node 
        }

        k = k % count;                      // this will give correct value of rotation if k is greater than count

        if (k == 0){                        // if roation will be zero at given k 
            return head;                    // then return head as it is
        }

        ListNode* tail = head;              // create tail to store last node

        while (tail->next != NULL){         // loop till last node
            tail = tail->next;              // move tail forward
        }

        tail->next = head;                  // connect tail to head , for futher breaking 

        int steps = count - k;              // create step variable to store breaking point of LL
        ListNode* newTail = head;           // creating newTail node to make it as new tail of LL , as previous is connected to head

        for (int i = 1; i < steps; i++){    // go to new tail using loop
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;  // create newHead which is next to newTail node
        newTail->next = NULL;               // break connection between newHead and newTail

        return newHead;                     // return that new head 
    }
};





ListNode* createList(vector<int> arr) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int x : arr) {
        ListNode* newNode = new ListNode(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.rotateRight(head, k);

    cout << "After Rotation: ";
    printList(head);

    return 0;
}





// Time Complexity: O(N)
// Space Complexity: O(1)