/*

Input: arr = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The subarray [-2, 2, -8, 1, 7] sums up to 0 and has the maximum length among all such subarrays.


Input: arr = [2, 10, 4]
Output: 0
Explanation: There is no subarray whose elements sum to 0.


Input: N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result: 5  
Explanation: The following subarrays sum to zero: {-3, 3} , {-1, 6, -5} , {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.


*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size() ;                            // size of array
        int maxCount = 0 ;                              // to store maxCount of subarray
        for (int i = 0 ; i < n ; i++ ){                 // loop for first element of subarray
            int sum = 0 ;                               // initialize sum = 0 for every variable i
            for (int j = i ; j < n ; j++ ){             // loop for last element of subarray
                sum = sum + arr[j] ;                    // compute sum
                if (sum == 0 ) {                        // if sum = 0 
                    maxCount = max(maxCount,j-i+1) ;    // update maxCount for every subarray
                }
            }
        }
        return maxCount ;                               // return maxCount 
    }   
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.maxLen(arr);

    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(1)