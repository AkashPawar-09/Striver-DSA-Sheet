/*

Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
Output: 2
Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Input: N = 3, array[] = {1,2,3}, k = 3
Output: 2
Explanation: The subarrays that sum up to 3 are [1, 2], and [3].

Input: nums = [1,1,1], k = 2
Output: 2

Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.

Input: arr[] = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution{
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;                    // Stores prefix sum and its frequency
        mpp[0] = 1;                                     // Prefix sum 0 occurs once initially

        int prefixSum = 0;                              // Stores running prefix sum
        int count = 0;                                  // Stores total number of subarrays

        for (int i = 0; i < nums.size(); i++) {         // traverse array
            prefixSum = prefixSum + nums[i];            // Add current element to prefix sum
            int remove = prefixSum - k;                 // Find required prefix sum to get sum k
            count = count + mpp[remove];                // Add frequency of required prefix sum
            mpp[prefixSum]++;                           // Store current prefix sum in map
        }
        return count;                                   // Return total count of subarrays
    }
};


/*       Que.     nums = [10, 2, -2, -20, 10], k = -10

  i | num | prefixSum | remove | mpp[remove] | count |  mpp
----|-----|-----------|--------|-------------|-------|------------------------
  - |  -  |     0     |   -    |      -      |   0   | {0:1}
  0 | 10  |    10     |   20   |      0      |   0   | {0:1, 10:1}
  1 |  2  |    12     |   22   |      0      |   0   | {0:1, 10:1, 12:1}
  2 | -2  |    10     |   20   |      0      |   0   | {0:1, 10:2, 12:1}
  3 | -20 |   -10     |    0   |      1      |   1   | {0:1, 10:2, 12:1, -10:1}
  4 | 10  |     0     |   10   |      2      |   3   | {0:2, 10:2, 12:1, -10:1}

 */


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution obj;
    obj.subarraySum(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }
    
    return 0;
}

// Time Complexity: O(n)
// Space Complextiy : O(n)
