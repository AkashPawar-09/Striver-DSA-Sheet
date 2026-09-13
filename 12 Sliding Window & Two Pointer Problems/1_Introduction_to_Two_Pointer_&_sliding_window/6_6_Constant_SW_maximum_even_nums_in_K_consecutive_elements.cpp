/*
============================================================
Q6. Maximum Even Numbers in K Consecutive Elements

Problem :
Given an integer array arr and an integer k, find the maximum
number of even elements present in any contiguous subarray
of size k.

Input : arr = {2, 3, 4, 6, 5, 8}, k = 3
Output: 2
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxEven(vector<int>& arr, int k) {
        int count = 0 ;
        int n = arr.size() ;
        for(int i = 0 ; i < k ; i++) {          // first window calculation 
            if(arr[i] % 2 == 0){
                count++;
            }
        }
        int maxCount = count ;
        for(int j = k ; j < n ; j++) {
            if(arr[j-k] % 2 == 0) {             // if leaving element in window is even 
                count--;                        // decrease count 
            }
            if(arr[j] % 2 == 0) {               // if entering element in window is even 
                count++ ;                       // increase count
            }
            maxCount = max(maxCount , count) ;  // update maxCount of even numbers
        }
        return maxCount ;                       // return maxCount
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.maxEven(arr, k);
    return 0;
}
