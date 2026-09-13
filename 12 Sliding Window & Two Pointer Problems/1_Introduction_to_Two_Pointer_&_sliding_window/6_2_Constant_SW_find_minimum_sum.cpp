/* 
============================================================
Q2. Minimum Sum of Subarray of Size K

Problem :
Given an integer array arr and an integer k, find the minimum
sum of any contiguous subarray of size k.

Input : arr = {4, 2, 7, 1, 8, 3}, k = 3
Output: 13
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;



class Solution {
public:
    int minSum(vector<int>& arr, int k) {
        int min_sum = 0 ;
        int n = arr.size() ;
        for (int i = 0 ; i < k ; i++) {
            min_sum = min_sum + arr[i] ;
        }
        int window_sum = min_sum ;
        for(int j = k ; j < n ; j++){
            window_sum = window_sum + arr[j] - arr[j-k];
            min_sum = min(min_sum , window_sum) ;
        }
        return min_sum ;
    }
};




int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.minSum(arr, k);
    return 0;
}
