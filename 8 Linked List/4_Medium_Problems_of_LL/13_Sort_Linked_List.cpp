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

class Solution{                                             // solution is written like Merge Sort Algorithm 
public:
    ListNode* findMiddle(ListNode* head){                   // function used to find middle (it will seprate 2 equal parts of LL)
        ListNode* slow = head;                              // tortoise
        ListNode* fast = head->next;                        // hare 
        // fast is head->next NOT head , because when there are even nodes in LL then slow (node) is at [ integer division - 1 ] 

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;                                        // findMiddle function return slow as MID
    }
    // finding middle repo page link : 
    // https://github.com/AkashPawar-09/Striver-DSA-Sheet/blob/main/8%20Linked%20List/4_Medium_Problems_of_LL/1_Middle_of_the_Linked_List.cpp



    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1 != NULL){
            temp->next = list1;
        }
        else{
            temp->next = list2;
        }

        return dummyNode->next;
    }
    // merge two sorted Lists repo page link : 
    // https://github.com/AkashPawar-09/Striver-DSA-Sheet/blob/main/8%20Linked%20List/4_Medium_Problems_of_LL/12_Merge_Two_Sorted_Lists.cpp



    // Actual Function used to do operations using upper functions 
    ListNode* sortLL(ListNode* head){
        if(head == NULL || head->next == NULL){             // if LL have 0 or 1 node then return that node (head)
            return head;
        }

        ListNode* middle = findMiddle(head);                // more then 1 element , find middle element

        ListNode* right = middle->next;                     // new node which is right part of mid in LL 
        middle->next = NULL;                                // break connection between LEFT and RIGHT part

        ListNode* left = head;                              // left node having normal head

        left = sortLL(left);                                // sort left side by function
        right = sortLL(right);                              // sort right side by function

        return mergeTwoLists(left, right);                  // merge 2 sorted Linked Lists (i.e. RIGHT AND LEFT)
    }


    ListNode* sortList(ListNode* head){                     // LeetCode Function used to return head of sorted LL
        return sortLL(head);
    }
};








// Driver code : 

ListNode* createLL(vector<int> &arr){
    if(arr.size() == 0){
        return NULL;
    }

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

    head = obj.sortList(head);

    printLL(head);

    return 0;
}




// Time Complexity : O(N log N)     - The list is recursively divided into halves and merged
// Space Complexity : O(log N)      - Due to the recursion stack