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

//------------------------------------------------------------------------------------------------------------------------------
// You are given the head of a singly linked list.
// Your task is not only to detect whether a cycle exists, but also to return the node where the cycle begins.
// If a cycle exists, return the starting node of the cycle.
// If no cycle exists, return NULL.
//------------------------------------------------------------------------------------------------------------------------------







// Solution 

class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                ListNode* entry=head;

                while(entry!=slow){
                    entry=entry->next;
                    slow=slow->next;
                }

                return entry;
            }
        }

        return NULL;
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
    ListNode* ans=obj.detectCycle(head);

    if(ans!=NULL){
        cout<<"Cycle starts at node with value: "<<ans->val<<endl;
    }
    else{
        cout<<"No Cycle"<<endl;
    }

    return 0;
}





// Time Complexity : O(N)
// Space Complexity : O(1)