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

class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
    
        while(current!=NULL){
            ListNode* front = current->next;        
            current->next = prev;
            prev = current;
            current = front;
        }
        return prev;
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
    head=obj.reverseList(head);

    printLL(head);

    return 0;
}




// Time Complexity : O(N)
// Space Complexity : O(1)








/*

Stores the next node of current
This preserves the remaining part of the linked list before changing any links

*/