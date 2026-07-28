/*

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false

*/



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








// Solution 

class Solution{
public:
    bool isPalindrome(ListNode* head){
        stack<int> st;

        ListNode* temp = head;

        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL){
            if(temp->val != st.top()){
                return false;
            }

            st.pop();
            temp = temp->next;
        }

        return true;
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

void printLL(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
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

    ListNode* head=createLL(arr);

    Solution obj;

    if(obj.isPalindrome(head)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }

    return 0;
}




// Time Complexity : O(N)
// Space Complexity : O(N)