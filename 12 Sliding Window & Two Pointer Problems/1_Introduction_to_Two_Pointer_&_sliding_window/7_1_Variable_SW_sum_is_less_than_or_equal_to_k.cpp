/*
============================================================
Q7. Longest Subarray With Sum <= K

Problem :
Given an array of positive integers and an integer k, find
the length of the longest contiguous subarray whose sum is
less than or equal to k.

Input : arr = {2, 1, 5, 1, 3, 2}, k = 7
Output: 3
============================================================
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size() ;
        int count = 0 ;
        int sum = 0 ;
        int j = 0 ;
        int maxCount = 0 ;
        for(int i = 0 ; i < n ; i++) {
            sum = sum + arr[i] ;
            if (sum <= k) {
                count++ ;
            }
            while(sum > k){
                sum = sum - arr[j] ;
                j++ ;
            }
            maxCount = max(maxCount , i - j + 1) ;
        }
        return maxCount ;
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
