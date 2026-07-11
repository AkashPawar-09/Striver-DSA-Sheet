/*

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.


Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 6
Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.


Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: As no element in arr[] is greater than 100, return the length of array.


Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation: Index 3 is the smallest index such that arr[3] > x.


Input : n = 5, nums = [3,5,8,15,19], x = 9
Output: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
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
    cout << "Enter target: ";
    cin >> x;

    Solution obj;
    int index = obj.upperBound(nums, x);

    if (index == n)
        cout << "Upper Bound does not exist." << endl;
    else
        cout << "Upper Bound Index = " << index << endl;

    return 0;
}


// Time Complexity : 
// Space Complexity : 