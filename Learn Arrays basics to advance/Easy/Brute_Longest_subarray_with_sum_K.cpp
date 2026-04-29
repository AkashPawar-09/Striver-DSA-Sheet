/*

Que. Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
If no such sub-array exists, return 0.

Input:nums = [10, 5, 2, 7, 1, 9], k = 15  
Output: 4  
Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], 
which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. 
Therefore, the length of this sub-array is 4.

Input: nums = [-3, 2, 1], k = 6  
Output: 0  
Explanation: here is no sub-array in the array that sums to 6. 
Therefore, the output is 0.
 
Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. 
The length of the longest subarray with a sum of 15 is 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.

Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {                       // takes starting index

            for (int j = i; j < n; j++) {                   // takes ending index

                int sum = 0;                                // sum = 0 Used for 2nd loop

                for (int x = i; x <= j; x++) {              // calculate sum of subarray : nums[i to j]
                    sum += nums[x];
                }

                if (sum == k) {                             // check if sum equals k
                    maxLen = max(maxLen, j - i + 1);        // Updation Of maxLen by each subarray 
                }
            }
        }

        return maxLen;
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cin >> k;

    Solution obj;
    cout << obj.longestSubarray(nums, k);

    return 0;
}

// Time Complexity : O(n³)
// Space Complexity : O(1)
