/*
============================================================
Q4. Average of Every K Elements

Problem :
Given an integer array arr and an integer k, find the average
of every contiguous subarray of size k.

Input : arr = {1, 3, 2, 6, -1, 4, 1, 8, 2}, k = 5
Output: {2.2, 2.8, 2.4, 3.6, 2.8}
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<double> findAverages(vector<int>& arr, int k) {
        vector<double> vec ;
        double sum = 0 ; 
        int n = arr.size() ;
        for(int i = 0 ; i < k ; i++) {
            sum = sum + arr[i] ;
        }
        double divi = sum / k ;
        vec.push_back(divi) ;
        for(int j = k ; j < n ; j++) {
            sum = sum + arr[j] - arr[j-k] ;
            divi = sum/k ;
            vec.push_back(divi) ;
        }
        return vec ;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    vector<double> ans = obj.findAverages(arr, k);

    for (double x : ans)
        cout << x << " ";

    return 0;
}
