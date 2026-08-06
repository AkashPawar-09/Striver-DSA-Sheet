#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};









// Solution 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};



  



ListNode* createList(vector<int> v) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int x : v) {
        ListNode* node = new ListNode(x);

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}


void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    vector<int> a = {2, 4, 3};
    vector<int> b = {5, 6, 4};

    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1, l2);

    printList(ans);

    return 0;
}





// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))




/* -----------------------------------------------------------------------------------------------------------------------------

123 + 123

Iteration Table
________________________________________________________________________________
| Iteration | l1 | l2 | Carry In | Sum | Digit Added | Carry Out | Result List |
| --------- | -- | -- | -------- | --- | ----------- | --------- | ----------- |
| 1         | 3  | 3  | 0        | 6   | 6           | 0         | 6           |
| 2         | 2  | 2  | 0        | 4   | 4           | 0         | 6→4         |
| 3         | 1  | 1  | 0        | 2   | 2           | 0         | 6→4→2       |
+-----------+----+----+----------+-----+-------------+-----------+-------------+


______________________________________________________________________________________________________________________________ */