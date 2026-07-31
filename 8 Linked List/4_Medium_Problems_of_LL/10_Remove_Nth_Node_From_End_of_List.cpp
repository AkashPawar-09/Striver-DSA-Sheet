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

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* fast = head;                      // pointer used to traverse end of LL
        ListNode* slow = head;                      // used to give answer node

        for(int i = 0; i < n; i++){                 // move fast ahed of slow by n
            fast = fast->next;                      // move to next itearation
        }

        if(fast == NULL){                           // if n becomes the length of LL
            ListNode* newHead = head->next;         // make newHead as head's next 
            delete head;                            // delete old head 
            return newHead;                         // return newHead
        }

        while(fast->next != NULL){                  // move fast pointer till it reaches end
            fast = fast->next;                      // move fast by 1 node each time
            slow = slow->next;                      // move slow by 1 node each time
        }

        ListNode* delNode = slow->next;             // create new node which is next to slow (want to remove from LL)
        slow->next = slow->next->next;              // next node of slow is next to next node of slow (making connection)
        delete delNode;                             // delete created node (free node)

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

    int k;
    cin >> k;

    ListNode* head = createLL(arr);

    Solution obj;
    head = obj.removeNthFromEnd(head, k);

    printLL(head);

    return 0;
}





// Time Complexity : O(N) 
// Space Complexity : O(1)