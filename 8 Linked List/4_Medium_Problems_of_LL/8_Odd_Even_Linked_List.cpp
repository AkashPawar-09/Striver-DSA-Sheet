#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};







// Solution 

class Solution{
public:
    ListNode* oddEvenList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};






ListNode* createLL(vector<int> &arr){
    if(arr.size() == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

void printLL(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
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

    ListNode* head = createLL(arr);

    Solution obj;
    head = obj.oddEvenList(head);

    printLL(head);

    return 0;
}




// Time Complexity : O(N) 
// Space Complexity : O(1)



/* ------------------------------------------------------------------------------------------------------------------------------

For the input:
head = [1,2,3,4,5]




Initial State :
____________________
| Pointer  | Value |
| -------- | ----- |
| odd      | 1     |
| even     | 2     |
| evenHead | 2     |





Dry Run Table :
_______________________________________________________________________________________________________________________________________________________________________
| Iteration | `odd` (Before) | `even` (Before) | `odd->next = even->next` | `odd = odd->next` | `even->next = odd->next` | `even = even->next` | Odd List | Even List |
| --------- | -------------- | --------------- | ------------------------ | ----------------- | ------------------------ | ------------------- | -------- | --------- |
| Initial   | 1              | 2               | -                        | -                 | -                        | -                   | 1        | 2         |
| 1         | 1              | 2               | 1→3                      | odd=3             | 2→4                      | even=4              | 1→3→4→5  | 2→4→5     |
| 2         | 3              | 4               | 3→5                      | odd=5             | 4→NULL                   | even=NULL           | 1→3→5    | 2→4       |





After Loop :
___________________________________
| Statement              | Result |
| ---------------------- | ------ |
| `odd->next = evenHead` | `5->2` |





Final Linked List :
_________________________________________________
| Odd List  | Even List | Final Answer          |
| --------- | --------- | --------------------- |
| 1 → 3 → 5 | 2 → 4     | **1 → 3 → 5 → 2 → 4** |




Pointer Movement Summary :
____________________________________________________
| Iteration           | odd Pointer | even Pointer |
| ------------------- | ----------- | ------------ |
| Initial             | 1           | 2            |
| After 1st iteration | 3           | 4            |
| After 2nd iteration | 5           | NULL         |



------------------------------------------------------------------------------------------------------------------------------ */