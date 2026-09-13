/*
============================================================
Q5. Count Windows With Sum Greater Than Target

Problem :
Given an integer array arr and integers k and target, count
how many contiguous subarrays of exactly size k have a sum
greater than target.

Input : arr = {2, 1, 5, 1, 3, 2}, k = 3, target = 7
Output: 2
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int countWindows(vector<int>& arr, int k, int target) {
        int sum = 0 ; 
        int n = arr.size() ;
        for(int i = 0 ; i < k ; i++) {
            sum = sum + arr[i] ;
        }
        int count = 0 ;
        if (sum > target) {
            count++ ;
        }
        int window_size = sum ;
        for(int j = k ; j < n ; j++) {
            window_size = window_size + arr[j] - arr[j-k] ;
            if (window_size > target) {
                count++ ;
            }
        }
        return count ;
    }
};


int main() {
    int n, k, target;
    cin >> n >> k >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.countWindows(arr, k, target);
    return 0;
}
