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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* t1 = list1;                           // t1 is LL1 
        ListNode* t2 = list2;                           // t2 is LL2

        ListNode* dummyNode = new ListNode(-1);         // create a dummy node 
        ListNode* temp = dummyNode;                     // create a temp node having same dummy node value (used to make connection)

        while(t1 != NULL && t2 != NULL){                // run loop until t1 and t2 both becomes NULL
            if(t1->val < t2->val){                      // value of t1 is smaller than value of t2
                temp->next = t1;                        // connect current temp to t1
                temp = t1;                              // move temp to current t1
                t1 = t1->next;                          // move t1 forward 
            }
            else{                                       // value of t2 is smaller than value of t1
                temp->next = t2;                        // connect current temp to t2
                temp = t2;                              // move temp to current t2
                t2 = t2->next;                          // move t2 forward 
            }
        }

        if(t1 != NULL){                                 // if t1 is not null (remaining nodes of t1)
            temp->next = t1;                            // include it in last
        }
        else{                                           // if t2 is not null (remaining nodes of t2)
            temp->next = t2;                            // include it in last
        }

        return dummyNode->next;                         // head of NEW LL is next node of dummyNode (from where we compared nodes)
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
    int n1;
    cin >> n1;

    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;

    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    ListNode* list1 = createLL(arr1);
    ListNode* list2 = createLL(arr2);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1, list2);

    printLL(ans);

    return 0;
}




// Time Complexity : O(N) 
// Space Complexity : O(1)





/* ---------------------------------------------------------------------------------------------------------------------------------------

Input :

list1 = 1 → 2 → 4
list2 = 1 → 3 → 4


Initially
________________________
| Pointer | Points To  |
| ------- | ---------- |
| t1      | 1 (list1)  |
| t2      | 1 (list2)  |
| temp    | Dummy (-1) |


Merged List:
Dummy


Dry Run Table : 
________________________________________________________________________________________________________________________________________
| Iteration | t1 | t2 | Condition `t1->val < t2->val` | Node Attached | `temp` Moves To | t1 After | t2 After | Merged List            |
| --------- | -- | -- | ----------------------------- | ------------- | --------------- | -------- | -------- | ---------------------- |
| Initial   | 1  | 1  | -                             | Dummy         | Dummy           | 1        | 1        | -1                     |
| 1         | 1  | 1  | False                         | t2 (1)        | 1               | 1        | 3        | -1 → 1                 |
| 2         | 1  | 3  | True                          | t1 (1)        | 1               | 2        | 3        | -1 → 1 → 1             |
| 3         | 2  | 3  | True                          | t1 (2)        | 2               | 4        | 3        | -1 → 1 → 1 → 2         |
| 4         | 4  | 3  | False                         | t2 (3)        | 3               | 4        | 4        | -1 → 1 → 1 → 2 → 3     |
| 5         | 4  | 4  | False                         | t2 (4)        | 4               | 4        | NULL     | -1 → 1 → 1 → 2 → 3 → 4 |


Loop Ends


Reason:
t2 == NULL

So,
while(t1 != NULL && t2 != NULL)

becomes false.


Remaining Nodes
________________________________________________________________________
| Condition    | Action            | Result                            |
| ------------ | ----------------- | --------------------------------- |
| `t1 != NULL` | `temp->next = t1` | Attach remaining node(s) of list1 |


Remaining node:
4

Merged List becomes:
-1 → 1 → 1 → 2 → 3 → 4 → 4


Return Statement
return dummyNode->next;
The dummy node is skipped.

Final Output
1 → 1 → 2 → 3 → 4 → 4


--------------------------------------------------------------------------------------------------------------------------------------- */