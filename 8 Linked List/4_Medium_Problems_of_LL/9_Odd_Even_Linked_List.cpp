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

// Detailed Solution Video (Striver) Link : https://youtu.be/qf6qp7GzD5Q?si=ITerV_bCJA7KWzOV






// Solution 

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
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




/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Complete Dry Run :
_____________________________________________________________________________________________________________________________________________________________________________
| Iteration | odd (before) | even (before) | `odd->next = odd->next->next` | `even->next = even->next->next` | odd (after) | even (after) | Odd List          | Even List   |
| --------- | ------------ | ------------- | ----------------------------- | ------------------------------- | ----------- | ------------ | ----------------- | ----------- |
| Initial   | 1            | 2             | -                             | -                               | 1           | 2            | 1→2→3→4→5→6→7     | 2→3→4→5→6→7 |
| 1         | 1            | 2             | 1→3                           | 2→4                             | 3           | 4            | 1→3→4→5→6→7       | 2→4→5→6→7   |
| 2         | 3            | 4             | 3→5                           | 4→6                             | 5           | 6            | 1→3→5→6→7         | 2→4→6→7     |
| 3         | 5            | 6             | 5→7                           | 6→NULL                          | 7           | NULL         | 1→3→5→7           | 2→4→6       |
| Final     | 7            | NULL          | `odd->next = evenHead`        | -                               | -           | -            | **1→3→5→7→2→4→6** | Attached    |



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */