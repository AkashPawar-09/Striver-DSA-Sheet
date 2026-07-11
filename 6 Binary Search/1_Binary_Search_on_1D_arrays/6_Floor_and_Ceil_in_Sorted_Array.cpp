/*

Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.


Input : nums =[3, 4, 4, 7, 8, 10], x= 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int floor = -1, ceil = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= x) {
                floor = nums[mid];
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        low = 0;
        high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
                ceil = nums[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {floor, ceil};
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

    int x;
    cout << "Enter value of x: ";
    cin >> x;

    Solution obj;
    vector<int> ans = obj.getFloorAndCeil(nums, x);

    cout << "Floor = " << ans[0] << endl;
    cout << "Ceil = " << ans[1] << endl;

    return 0;
}


// Time Complexity : O(logN)
// Space Complexity : O(1)