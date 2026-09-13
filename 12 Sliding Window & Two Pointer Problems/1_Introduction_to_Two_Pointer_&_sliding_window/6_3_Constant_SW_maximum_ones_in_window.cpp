/*
============================================================
Q3. Maximum Number of 1s in a Window

Problem :
Given a binary array arr and an integer k, find the maximum
number of 1s present in any contiguous subarray of size k.

Input : arr = {1, 0, 1, 1, 0, 1, 0}, k = 3
Output: 2
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int sum = 0 ;
        int n = arr.size() ;
        for (int i = 0 ; i < k ; i++) {
            sum = sum + arr[i] ;
        }
        int maxSum = sum ;
        for(int j = k ; j < n ; j++) {
            sum = sum + arr[j] - arr[j-k];
            maxSum = max(maxSum, sum);
        } 
        return maxSum ;
        
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.maxOnes(arr, k);
    return 0;
}
