/*
=====================================================================
Q9. Longest Subarray With At Most K Zeros

Problem :
Given a binary array arr and an integer k, find the length
of the longest contiguous subarray containing at most k zeros.

Input : arr = {1, 1, 0, 0, 1, 1, 0}, k = 2
Output: 5

Input : arr = {1, 0, 0, 1, 1, 1, 0}, k = 2
Output: 6

Input : arr = {1, 1, 1, 0, 1, 1, 0}, k = 2
Output: 7

Input : arr = {1, 0, 1, 0, 1, 1, 1}, k = 1
Output: 5

Input : arr = {1, 1, 1, 0, 1, 1, 0}, k = 3
Output: 7
=====================================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return n;               // return n if k is greater than n (i.e. At most k Zeros)

        int count0 = 0;                     // counting zeros in subarray
        int i = 0;                          // slow pointer (moves on condition of count0)
        // int j = 0;                       // fast pointer
        int length = 0;                     // to calculate current length of subarray
        int maxLength = 0;                  // to store anwer

        for (int j = 0; j < n; j++) {           // Move fast pointer and count zeros
            if (nums[j] == 0) {             // if element is 0 
                count0++;                   // then count0++
            }
            if (count0 > k) {               // if count0 > k        (While LOOP replaced by if)
                if (nums[i] == 0) {         // Remove the leftmost element from the window
                    count0--;               // if slow pointer is 0 then decrease count0 by 1
                }
                i++;                        // iterate of i until slow pointer is 0
            }
            maxLength = max( maxLength, j-i+1 );    // calculate and update Max Length of subarray
        }
        return maxLength;                   // return Max Length of subarray
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    cout << obj.longestOnes(nums, k);
    return 0;
}
