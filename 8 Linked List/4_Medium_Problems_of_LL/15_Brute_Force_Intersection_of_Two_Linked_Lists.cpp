#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};






// Solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;

        while (headA != NULL) {
            mp[headA]++;
            headA = headA->next;
        }

        while (headB != NULL) {
            if (mp.find(headB) != mp.end()) {
                return headB;
            }
            headB = headB->next;
        }

        return NULL;
    }
};







void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans != NULL)
        cout << "Intersection Node = " << ans->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}



// Time Complexity: O(N + M)
// Space Complexity: O(N)