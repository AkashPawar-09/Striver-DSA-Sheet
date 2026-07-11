/*

Input: nums = [5, 7, 7, 8, 8, 10], target = 8
Output: [3, 4]
Explanation: The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]


Input: nums = [5, 7, 7, 8, 8, 10], target = 6
Output: [-1, -1]
Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].


Input: nums = [], target = 0
Output: [-1,-1]


Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
Output: [2, 5]
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5


Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
Output: [6, 6]
Explanation: First and last occurrence of 7 is at index 6


Input: arr[] = [1, 2, 3], x = 4
Output: [-1, -1]
Explanation: No occurrence of 4 in the array, so, output is [-1, -1]

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return first;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);

        if (first == -1)
            return {-1, -1};

        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);

    cout << "First Occurrence = " << ans[0] << endl;
    cout << "Last Occurrence = " << ans[1] << endl;

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)