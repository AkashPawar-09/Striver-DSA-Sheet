/*

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.


Input: nums = [3, 4, 5, 1, 2]
Output: 3
Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.


Input: nums = [4, 5, 1, 2]
Output: 2

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int findKRotation(vector<int> &nums) {

        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                low = mid + 1;
            }

            // Right half is sorted
            else {
                high = mid - 1;
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
            }
        }

        return index;
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

    cout << obj.findKRotation(nums) << endl;

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)