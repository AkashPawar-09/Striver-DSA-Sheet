#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};








// Solution 

class Solution {
public:
    Node* intersectionPresent(Node* head1, Node* head2) {
        Node* d1 = head1;
        Node* d2 = head2;

        while (d1 != d2) {

            if (d1 == NULL) {
                d1 = head2;
            } else {
                d1 = d1->next;
            }

            if (d2 == NULL) {
                d2 = head1;
            } else {
                d2 = d2->next;
            }
        }

        return d1;
    }
};








int main() {
    Node* common = new Node(15);
    common->next = new Node(30);

    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = common;

    Node* head2 = new Node(10);
    head2->next = common;

    Solution obj;
    Node* ans = obj.intersectionPresent(head1, head2);

    if (ans == NULL) {
        cout << "No Intersection";
    } else {
        cout << "Intersection Node: " << ans->data;
    }

    return 0;
}


// Time Complexity: O(N + M)
// Space Complexity: O(1)