#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};









// Solution 

class Solution{
public:
    Node* segregate(Node* head){
        if(head == NULL || head->next == NULL){     // if LL have 0 or 1 node then return that node (head)
            return head;
        }

        Node* zeroHead = new Node(-1);              // create dummy node named as zeroHead
        Node* oneHead = new Node(-1);               // create dummy node named as oneHead
        Node* twoHead = new Node(-1);               // create dummy node named as twoHead

        Node* zero = zeroHead;                      // create pointer to traverse zero's
        Node* one = oneHead;                        // create pointer to traverse ones's
        Node* two = twoHead;                        // create pointer to traverse two's

        Node* temp = head;                          // create temperary pointer to traverse all nodes in given LL

        while(temp != NULL){                        // traverse all nodes until it reaches end

            if(temp->data == 0){                    // if node stores value 0
                zero->next = temp;                  // then add this node to next to current zero pointer
                zero = zero->next;                  // move pointer zero to next node (which is also zero)
            }
            
            else if(temp->data == 1){               // if node stores value 1
                one->next = temp;                   // then add this node to next to current one pointer
                one = one->next;                    // move pointer one to next node (which is also one)
            }
            
            else{                                   // if node stores value 2
                two->next = temp;                   // then add this node to next to current two pointer
                two = two->next;                    // move pointer two to next node (which is also one)
            }

            temp = temp->next;                      // after cheaking value move temp forward
        }

        if(oneHead->next != NULL){                  // if node have data as 1 then connect pointer zero
            zero->next = oneHead->next;             // connect pointer zero to ineHead's next element (starting of node having data 1)
        }
        else{zero->next = twoHead->next;}           // if node dont have data 1 then connect zero to two

                
        one->next = twoHead->next;                  // connection between one and two 
        two->next = NULL;                           // last two is pointing to NULL 

        Node* newHead = zeroHead->next;             // new head of LL is next node dummy node zeroHead

        delete zeroHead;                            // delete dummy head zeroHead
        delete oneHead;                             // delete dummy head oneHead
        delete twoHead;                             // delete dummy head twoHead

        return newHead;                             // return newHead (zeroHead->next)
    }
};







Node* createLL(vector<int> &arr){
    if(arr.size() == 0){
        return NULL;
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node* head = createLL(arr);

    Solution obj;
    head = obj.segregate(head);

    printLL(head);

    return 0;
}






// Time Complexity : O(N) 
// Space Complexity : O(1)