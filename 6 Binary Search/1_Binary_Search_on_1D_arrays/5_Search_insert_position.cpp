/*

Input: nums = [1, 3, 5, 6], target = 5
Output: 2
Explanation: The target value 5 is found at index 2 in the sorted array. 
Hence, the function returns 2.


Input: nums = [1, 3, 5, 6], target = 2
Output: 1
Explanation: The target value 2 is not found in the array. 
However, it should be inserted at index 1 to maintain the sorted order of the array.


Input: nums = [1,3,5,6], target = 5
Output: 2


Input: nums = [1,3,5,6], target = 2
Output: 1


Input: nums = [1,3,5,6], target = 7
Output: 4

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 ;
        int high = n-1 ;
        int ans = n ;
        while (low <= high ) {
            int mid = low + (high - low) / 2 ;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans ;
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
    int index = obj.searchInsert(nums, target);

    cout << "Search Insert Position = " << index << endl;

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)