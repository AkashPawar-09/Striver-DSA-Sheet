/*

Input: nums = [3, 5, 4, 1, 1]
Output: [1, 2]
Explanation: 1 appears two times in the array and 2 is missing from nums


Input: nums = [1, 2, 3, 6, 7, 5, 7]
Output: [7, 4]
Explanation: 7 appears two times in the array and 4 is missing from nums.


Input: arr[] = [3, 1, 3]
Output: [3, 2]
Explanation: 3 is occurs twice and 2 is missing.


Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5] 
Explanation: 1 is occurs twice and 5 is missing.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();                        // Size of the array.

        int repeating = -1;                         // Stores the repeating number.
        int missing = -1;                           // Stores the missing number.

        for (int i = 1; i <= n; i++) {              // Check every number from 1 to n.

            int count = 0;                          // Count frequency of current number.

            for (int j = 0; j < n; j++) {           // Traverse the entire array.
                if (nums[j] == i) {                 // If current number is found
                    count++;                        // Increase its frequency.
                }
            }

            if (count == 2) {                       // Number appears twice.
                repeating = i;                      // Store repeating number.
            }

            if (count == 0) {                       // Number does not appear.
                missing = i;                        // Store missing number.
            }
        }

        vector<int> ans;                            // Answer vector.

        ans.push_back(repeating);                   // Add repeating number.
        ans.push_back(missing);                     // Add missing number.

        return ans;                                 // Return [repeating, missing].
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.findMissingRepeatingNumbers(nums);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(1)