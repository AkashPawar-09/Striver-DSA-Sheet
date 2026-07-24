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
    Node* insertTail(Node* head,int x){
        Node* ans = new Node (x) ;
        if(head ==  NULL ){return ans ;}
        Node* temp = head ;
        while(temp->next != nullptr) {
            temp = temp->next ;
        }
        temp->next = ans ;
        ans->prev = temp ;
        return head ;
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
    head=obj.insertTail(head,60);

    cout<<"After Inserting at Tail: ";
    print(head);

    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)