/*
============================================================
Q8. Smallest Subarray With Sum >= K

Problem :
Given an array of positive integers and an integer k, find
the length of the smallest contiguous subarray whose sum is
greater than or equal to k.

If no such subarray exists, return 0.

Input : arr = {2, 3, 1, 2, 4, 3}, k = 7
Output: 2
============================================================
*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int minLength(vector<int>& arr, int k) {
        int n = arr.size() ;            // size of given array
        int count = 0 ;                 // count of elements in loop
        int minCount = INT_MAX;         // minimum count (answer)
        int sum = 0 ;                   // sum of elements in loop
        int j = 0 ;                     // left pointer in array while traverse

        for(int i = 0 ; i < n ; i++) {              // travese all subarrays
            sum = sum + arr[i];                     // increment sum until sum < k
            while(sum >= k) {                       // if (sum >= k) then run loop
                count = i - j + 1;                  // count is lenght of subarray
                minCount = min(minCount, count);    // update minimum length of subarray
                sum = sum - arr[j];                 // remove left elements until condition is true
                j++;                                // increase left pointer
            }
        }
        return minCount ;                           // return updated minimum length
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.minLength(arr, k);
    return 0;
}
