/*

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

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






// Solution :

// The Tortoise and Hare Algorithm (also called the Slow and Fast Pointer Algorithm) 
// is a two-pointer technique used in linked lists.

class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while (fast != NULL && fast->next != NULL){     // loop till fast is not NULL & fast->next is not NULL
            slow=slow->next;                            // pointer moves one node at a time
            fast=fast->next->next;                      // pointer moves two node at a time
        }

        return slow;                                    // return slow pointer (pointing to mid)
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
    ListNode* middle=obj.middleNode(head);

    printLL(middle);

    return 0;
}



// Time Complexity : O(N)
// Space Complexity : O(1)