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
    Node* deleteHead(Node* head){
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
};



Node* createDLL(vector<int>& arr){
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


void print(Node* head){
    while(head!=NULL){
        cout<< head->data <<" ";
        head = head->next ;
    }
    cout<<endl;
}


int main(){

    vector<int> arr={10,20,30,40,50};

    Node* head=createDLL(arr);

    cout<<"Original DLL: ";
    print(head);

    Solution obj;
    head=obj.deleteHead(head);

    cout<<"After Deleting Head: ";
    print(head);

    return 0;
}





// Time Complexity: O(1)
// Space Complexity: O(1)