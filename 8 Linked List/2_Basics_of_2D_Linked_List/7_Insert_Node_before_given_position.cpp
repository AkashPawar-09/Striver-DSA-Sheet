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
    Node* insertBeforeNode(Node* head,Node* node,int x){
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

Node* getNode(Node* head,int pos){
    int cnt=1;

    while(head!=NULL && cnt<pos){
        head=head->next;
        cnt++;
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

    Node* node=getNode(head,3);

    head=obj.insertBeforeNode(head,node,25);

    cout<<"After Inserting Before Position 3: ";
    print(head);

    return 0;
}