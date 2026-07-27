#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next=NULL;
    }
};

//------------------------------------------------------------------------------------------------------------------------------
// You are given the head of a singly linked list.
// Your task is to determine whether a cycle exists.
// If no cycle exists, return 0.
// If a cycle exists, return the number of nodes present in the cycle (loop length).
//------------------------------------------------------------------------------------------------------------------------------







// Solution 

class Solution{
public:
    int countNodesinLoop(Node *head){
        if(head == NULL || head->next == NULL) { return false; }
        Node* slow=head;                        // tortoise
        Node* fast=head;                        // rabbit

         while(fast!=NULL && fast->next!=NULL){     // iterate until we found end
            slow=slow->next;                        // tortoise speed
            fast=fast->next->next;                  // rabbit speed

            if(slow==fast){                     // if LL is circular
                int count = 1;                  // initiate count as 1
                Node* temp=slow->next;          // create a node named as temp which is next node of slow

                while(temp != slow){            // iterate temp until it becomes slow 
                    count++;                    // count number of nodes 
                    temp=temp->next;            // move temp forward
                }

                return count;                   // return count
            }
        }

        return 0;                               // otherwise return 0
    }
};






Node* createLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<arr.size();i++){
        temp->next=new Node(arr[i]);
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

    Node* head=createLL(arr);

    int pos;
    cin>>pos;

    if(pos!=-1){
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }

        Node* cycleNode=head;
        for(int i=0;i<pos;i++){
            cycleNode=cycleNode->next;
        }

        tail->next=cycleNode;
    }

    Solution obj;
    cout<<obj.countNodesinLoop(head)<<endl;

    return 0;
}






// Time Complexity : O(N)
// Space Complexity : O(1)