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

    Node* insertHead(Node* head,int x){             // Done
        Node* temp=new Node(x);
        if(head==NULL) return temp;
        temp->next=head;
        head->prev=temp;
        return temp;
    }


    Node* deleteHead(Node* head){                   // Done
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


    Node* insertTail(Node* head,int x){             // Done
        Node* temp=new Node(x);
        if(head==NULL) return temp;

        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next=temp;
        temp->prev=curr;

        return head;
    }


    Node* deleteTail(Node* head){                   // Done
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }

        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->prev->next=NULL;
        delete curr;

        return head;
    }


    Node* insertBeforeNode(Node* head,Node* node,int x){        // Done
        if(node==NULL) return head;

        Node* temp=new Node(x);

        if(node==head){
            temp->next=head;
            head->prev=temp;
            return temp;
        }

        Node* back=node->prev;

        back->next=temp;
        temp->prev=back;
        temp->next=node;
        node->prev=temp;

        return head;
    }


    Node* insertBeforeElement(Node* head,int element,int x){    // Done
        if(head==NULL) return head;

        Node* curr=head;

        while(curr!=NULL && curr->data!=element){
            curr=curr->next;
        }

        if(curr==NULL) return head;

        return insertBeforeNode(head,curr,x);
    }
};



void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}



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



Node* getNode(Node* head,int pos){
    int cnt=1;
    while(head!=NULL && cnt<pos){
        head=head->next;
        cnt++;
    }
    return head;
}



int main(){

    vector<int> arr={10,20,30,40,50};

    Node* head=createDLL(arr);

    Solution obj;

    
    cout<<"Original: ";
    print(head);


    head=obj.insertHead(head,5);
    cout<<"Insert Head: ";
    print(head);


    head=obj.deleteHead(head);
    cout<<"Delete Head: ";
    print(head);


    head=obj.insertTail(head,60);
    cout<<"Insert Tail: ";
    print(head);


    head=obj.deleteTail(head);
    cout<<"Delete Tail: ";
    print(head);


    Node* node=getNode(head,3);
    head=obj.insertBeforeNode(head,node,25);
    cout<<"Insert Before Node (Position 3): ";
    print(head);


    head=obj.insertBeforeElement(head,40,35);
    cout<<"Insert Before Element (40): ";
    print(head);

    return 0;
}