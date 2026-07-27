#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};






// Solution 

class Solution{
public:
    Node* reverseDLL(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        Node* previousNode=NULL;            // initially previous node as NULL 
        Node* current=head;                 // and current node as head 

        while(current!=NULL){               // loop to traverse all nodes
            previousNode = current->prev;   // previousNode is current's prev
            current->prev = current->next;  // but prev pointer is overwrite by nextpointer
            current->next = previousNode;   // next node is also overwrite by prevoius node

            current = current->prev;        // move to prev node (i.e. Moving to next node in DLL)
        }

        head = previousNode->prev ;
        return head;                        // head is defined as Previous node's prev (i.e. next )
    }
};



Node* createDLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    Node* head=new Node(arr[0]);
    Node* prev=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        temp->prev=prev;
        prev=temp;
    }

    return head;
}

void printDLL(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
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

    Node* head=createDLL(arr);

    Solution obj;
    head=obj.reverseDLL(head);

    printDLL(head);

    return 0;
}



// Time Complexity: O(1)
// Space Complexity: O(1)