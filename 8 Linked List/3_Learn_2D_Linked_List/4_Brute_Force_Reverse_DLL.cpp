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
        if(head==NULL || head->next==NULL) return head;     // if DLL is empty is empty OR contains only 1 node(head)

        stack<int> st;                  // stack data structure used to store element         

        Node* temp=head;                // head is initialised as temp 

        while(temp!=NULL){              // traverse all nodes in DLL
            st.push(temp->data);        // push every element in DLL to stack data
            temp=temp->next;            // move iteration to next node
        }

        temp=head;                      // rewrite head as temp

        while(temp!=NULL){              // traverse all nodes in DLL
            temp->data=st.top();        // overwrite each data of node from stack's top 
            st.pop();                   // pop the top data as it is inserted
            temp=temp->next;            // move iteration to next node
        }

        return head;                    // return head 
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



// Time Complexity: O(2N)
// Space Complexity: O(N)