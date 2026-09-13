/*
============================================================
Q1. Maximum Sum of Subarray of Size K

Problem :
Given an integer array arr and an integer k, find the maximum
sum of any contiguous subarray of size k.

Input : arr = {2, 1, 5, 1, 3, 2}, k = 3
Output: 9
============================================================
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& arr, int k) {
        int max_sum = 0 ;
        int n = arr.size() ;
        for (int i = 0 ; i < k ; i++) {
            max_sum = max_sum + arr[i] ;
        }
        int window_sum = max_sum ;
        for(int j = k ; j < n ; j++){
            window_sum = window_sum + arr[j] - arr[j-k];
            max_sum = max(max_sum , window_sum) ;
        }
        return max_sum ;
    }
};




int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.maxSum(arr, k);
    return 0;
}
