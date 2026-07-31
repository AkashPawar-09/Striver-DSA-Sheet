#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};









// Solution

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){     // if no node or only only one node 
            delete head;                            // delete current head 
            return NULL;                            // return null
        }

        ListNode* slow = head;                      // slow pointer initially pointing to head
        ListNode* fast = head->next->next;          // fast pointer initially pointing to third node

        while(fast != NULL && fast->next != NULL){  // loop while fast or next node of fast becomes null
            slow = slow->next;                      // move slow pointer by 1
            fast = fast->next->next;                // move fast pointer by 2
        }

        ListNode* delNode = slow->next;             // new node named as delNode which is next node of slow
        slow->next = slow->next->next;              // making new connection to secure chain link
        delete delNode;                             // delete created node

        return head;                                // return head of modified of LL
    }
};






ListNode* createLL(vector<int> &arr){
    if(arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printLL(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ListNode* head = createLL(arr);

    Solution obj;
    head = obj.deleteMiddle(head);

    printLL(head);

    return 0;
}






// Time Complexity : O(N) 
// Space Complexity : O(1)