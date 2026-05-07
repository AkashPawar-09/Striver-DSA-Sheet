/*

Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. 
This sequence can be formed regardless of the initial order of the elements in the array.

Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation:  The longest consecutive subsequence [2, 6, 1, 4, 5, 3].

Input: arr[] = [1,1,1,2,2,3]
Output: 3
Explanation: The subsequence [1, 2,3] is the longest subsequence of consecutive elements

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();                            // n = size of nums array

        if (n == 0) return 0;                           // return if empty 

        // sort array
        sort(nums.begin(), nums.end());                 // Sort the given array

        int longest = 1;                                // longest = 1
        int cnt = 1;                                    // count = 1

        int lastSmaller = nums[0];                      // 1st number of array = lastSmaller

        // traverse sorted array
        for (int i = 1; i < n; i++) {                   // iteration over 1st element to nth element

            // consecutive element
            if (nums[i] == lastSmaller + 1) {           // if number in array is equal to number itself
                cnt++;                                  // increase count
                lastSmaller = nums[i];                  // update lastSmaller to next value for iteration
            }

            // duplicate element
            else if (nums[i] == lastSmaller) {          // drop the step for duplicate numbers
                continue;                               // using continue statement 
            }

            // start new sequence
            else {
                cnt = 1;                                // if there is only 1 element 
                lastSmaller = nums[i];                  // lastSmaller is always 1st element
            }

            // update longest
            longest = max(longest, cnt);                // longest is maximum between longest and count 
        }

        return longest;                                 // return it 
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int ans = obj.longestConsecutive(nums);

    return 0;
}

// Time Complexity : O(N log N)
// Space Complexity : O(1)