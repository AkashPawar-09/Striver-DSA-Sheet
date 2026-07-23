#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};





// Solution 

class Solution {
public:
    bool searchKey(ListNode* head, int key) {

        ListNode* temp = head;

        while (temp != nullptr) {

            if (temp->val == key)
                return true;

            temp = temp->next;
        }

        return false;
    }
};



int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    int key = 3;

    Solution obj;

    if (obj.searchKey(head, key))
        cout << "true";
    else
        cout << "false";

    return 0;
}