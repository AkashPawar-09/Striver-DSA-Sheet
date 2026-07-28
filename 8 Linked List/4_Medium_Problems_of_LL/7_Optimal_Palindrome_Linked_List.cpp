/*

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

*/



#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};








// Solution 

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;                  // Previous node, initially NULL
        ListNode* current = head;               // Start traversing from the given head

        while(current != NULL){                 // Traverse until the end of the list
            ListNode* front = current->next;    // Store the next node
            current->next = prev;               // Reverse the current node's link
            prev = current;                     // Move prev one step ahead
            current = front;                    // Move current to the next node
        }

        return prev;                            // prev becomes the new head of the reversed list
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){ // Empty or single-node list is always a palindrome
            return true;
        }

        ListNode* slow = head;                  // Slow pointer moves one step
        ListNode* fast = head;                  // Fast pointer moves two steps

        while(fast->next != NULL && fast->next->next != NULL){      // Find the middle of the list
            slow = slow->next;                                      // Move slow by one node
            fast = fast->next->next;                                // Move fast by two nodes
        }

        ListNode* newHead = reverse(slow->next);                    // Reverse the second half of the list

        ListNode* first = head;                 // Pointer for the first half
        ListNode* second = newHead;             // Pointer for the reversed second half

        while(second != NULL){                  // Compare both halves
            if(first->val != second->val){      // If values differ
                reverse(newHead);               // Restore the original list
                return false;                   // Not a palindrome
            }

            first = first->next;                // Move first pointer
            second = second->next;              // Move second pointer
        }

        reverse(newHead);                       // Restore the original linked list

        return true;                            // All values matched, so it is a palindrome
    }
};







ListNode* createLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    ListNode* head=new ListNode(arr[0]);
    ListNode* temp=head;

    for(int i=1;i<arr.size();i++){
        temp->next=new ListNode(arr[i]);
        temp=temp->next;
    }

    return head;
}

void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ListNode* head=createLL(arr);

    Solution obj;

    if(obj.isPalindrome(head)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }

    return 0;
}




// Time Complexity : O(N)
// Space Complexity : O(1)