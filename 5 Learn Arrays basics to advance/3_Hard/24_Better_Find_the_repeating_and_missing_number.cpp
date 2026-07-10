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
        int n = nums.size();                        // Store the size of the array.
        sort(nums.begin(), nums.end());             // Sort the array so duplicate and missing number are easier to find.

        int firstElement = -1;                      // firstElement will store the repeating number. Initialize with -1.
        int secondElement = -1;                     // secondElement will store the missing number. Initialize with -1.
        vector<int> ans;                            // Vector to store the final answer.

        for (int i = 0; i < n - 1; i++) {           // Traverse till the second-last element.
            if (nums[i] == nums[i + 1]) {           // If two adjacent elements are equal
                firstElement = nums[i];             // then this is the repeating number.
                break;                              // No need to continue searching.
            }
        }

        if (nums[0] != 1) {                         // If the first element is not 1
            secondElement = 1;                      // then 1 is the missing number.
        }
        else {                                      // Otherwise, search for the missing number.
            for (int i = 0; i < n - 1; i++) {       // Traverse the sorted array.
                
                if (nums[i] == nums[i + 1])         // If current and next elements are equal...
                    continue;                       // ...skip the duplicate and move to the next iteration.

                if (nums[i] + 1 != nums[i + 1]) {   // If the next number is not exactly current + 1...
                    secondElement = nums[i] + 1;    // ...then current + 1 is the missing number.
                    break;                          // Missing number found, exit the loop.
                }
            }

            if (secondElement == -1)                // If no missing number was found in the loop
                secondElement = n;                  // then the missing number is the last number (n).
        }

        ans.push_back(firstElement);                // Add the repeating number to the answer vector.
        ans.push_back(secondElement);               // Add the missing number to the answer vector.

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


// Time Complexity : O(N * log N)
// Space Complexity : O(1)