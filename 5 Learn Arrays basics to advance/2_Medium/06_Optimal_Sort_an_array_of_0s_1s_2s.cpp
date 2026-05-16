/*--------------- Dutch National Flag algorithm ---------------

Leetcode 75. Sort Colors

Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.

Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low = 0;                            // First element
        int mid = 0;                            // Current element in while loop 
        int high = nums.size() - 1;             // Last element 

        while (mid <= high) {                   // Traverse until mid crosses high

            if (nums[mid] == 0) {               // Case 1: Element is 0 → move to left
                swap(nums[low], nums[mid]);     // Place 0 at at starting postion 
                low++;                          // expand 0 region
                mid++;                          // increment of mid (for while loop)
            }

            else if (nums[mid] == 1) {          // Case 2: Element is 1 → already correct
                mid++;                          // increment of mid (for while loop)
            }

            else {                              // Case 3 : If Element is 2 → move to right
                swap(nums[mid], nums[high]);    // Place 2 at correct position
                high--;                         // shrink right region
            }
        }
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

    obj.sortZeroOneTwo(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}



// Time Complexity : 
// Space Complexity : 