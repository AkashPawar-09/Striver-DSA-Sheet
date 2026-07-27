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
    bool hasCycle(ListNode* head){  
        if(head == NULL || head->next == NULL) { return false; }
        ListNode* slow=head;                        // tortoise
        ListNode* fast=head;                        // rabbit

        while(fast!=NULL && fast->next!=NULL){      // iterate until we found end
            slow=slow->next;                        // tortoise speed
            fast=fast->next->next;                  // rabbit speed

            if(slow==fast){                         // if end is not found then it must be (slow == fast)
                return true;                        // if slow == fast then return true (circular iteration)
            }
        }

        return false;                               // if loop end , means we found end at last , therefore return false
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

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ListNode* head=createLL(arr);

    int pos;
    cin>>pos;

    if(pos!=-1){
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }

        ListNode* cycleNode=head;
        for(int i=0;i<pos;i++){
            cycleNode=cycleNode->next;
        }

        tail->next=cycleNode;
    }

    Solution obj;

    if(obj.hasCycle(head)){
        cout<<"Cycle Present"<<endl;
    }
    else{
        cout<<"Cycle Not Present"<<endl;
    }

    return 0;
}




// Time Complexity : O(N)
// Space Complexity : O(1)