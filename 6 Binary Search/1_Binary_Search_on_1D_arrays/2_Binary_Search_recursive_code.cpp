/*

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4


Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.


Input: arr[] = [1, 2, 4, 5, 6], k = 3
Output: false
Exlpanation: Since, 3 is not present in the array, output is false.


Input: arr[] = [2, 3, 5, 6], k = 1
Output: false

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {         // Search function.
        return bs(nums, 0, nums.size() - 1, target);    // Calls bs() for the complete array and returns the answer.
    }
    int bs(vector<int>& nums, int low, int high, int target) {

        if (low > high)                                 // if low pointer is smaller than high
            return -1;                                  // returns mid

        int mid = low +  (high - low) / 2;              // calculate mid 

        if (nums[mid] == target)                        // if mid is target
            return mid;                                 // then return mid

        else if (target > nums[mid])                    // if target is greater than mid pointer
            return bs(nums, mid + 1, high, target);     // then call function back with low as mid+1 

        return bs(nums, low, mid - 1, target);          // if target is smaller than mid pointer
        // then call fucntion back with high as mid-1 
    }
};


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution obj;

    cout << obj.search(nums, target);

    return 0;
}


// Time Complexity : (log N)
// Space Complexity : (1)