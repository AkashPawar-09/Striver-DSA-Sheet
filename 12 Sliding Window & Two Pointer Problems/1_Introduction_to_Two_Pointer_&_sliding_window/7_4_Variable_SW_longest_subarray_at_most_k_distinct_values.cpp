/*
=====================================================================
Q10. Longest Subarray With At Most K Distinct Values

Problem :
Given an integer array arr and an integer k, find the length
of the longest contiguous subarray containing at most k
distinct values.

Input : arr = {1, 2, 1, 2, 3}, k = 2
Output: 4

Input : arr = [1, 2, 3, 1, 2, 4], k = 3
Output: 5

Input : arr = [1, 2, 2, 2, 3, 3], k = 1 
Output: 3

Input : arr = [1, 2, 1, 3, 2, 2], k = 2
Output: 3

Input : arr = [1, 2, 1, 3, 2, 2, 2], k = 2
Output: 4
=====================================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size() ;
        int i = 0;
        int maxLength = 0 ;
        unordered_map<int, int> freq;

        for (int j = 0; j < n; j++) {           // travese arr
            freq[arr[j]]++;                     // store frequency of each element in map as <element,occurance>
            while (freq.size() > k) {           // if frequency size (i.e. no. of Elements) is greater than k
                freq[arr[i]]--;                 // remove frequency of leftmost element 
                if (freq[arr[i]] == 0) {        // until its frequency becomes 0 
                    freq.erase(arr[i]);         // When freq = 0 , then remove that element
                }
                i++;                            // increase leftmost pointer to get new elements
            }
            maxLength = max(maxLength, j - i + 1);      // calculate max length by using current length & maxLength
        }
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.longestSubarray(arr, k);
    return 0;
}
