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

class Solution{
public:
    Node* insertBeforeElement(Node* head,int element,int x){
        if(head==NULL) return NULL;

        Node* curr=head;

        while(curr!=NULL && curr->data!=element){
            curr=curr->next;
        }

        if(curr==NULL) return head;

        Node* temp=new Node(x);

        if(curr==head){
            temp->next=head;
            head->prev=temp;
            return temp;
        }

        Node* back=curr->prev;

        back->next=temp;
        temp->prev=back;
        temp->next=curr;
        curr->prev=temp;

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
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    vector<int> arr={10,20,30,40,50};

    Node* head=createDLL(arr);

    cout<<"Original DLL: ";
    print(head);

    Solution obj;

    head=obj.insertBeforeElement(head,40,35);

    cout<<"After Inserting 35 Before 40: ";
    print(head);

    return 0;
}