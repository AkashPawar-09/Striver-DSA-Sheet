/*

Input : arr = [1, 2, 3, 4, 5, 6, 7, 8, 5, 1]
Output: 7
Explanation: In this example, there is only 1 peak that is at index 7.


Input : arr = [1, 2, 1, 3, 5, 6, 4]
Output: 1
Explanation: In this example, there are 2 peak numbers at indices 1 and 5. We can consider any of them.


Input : arr = [-2, -1, 3, 4, 5]
Output: 

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;

        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return -1;
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

    cout << obj.findPeakElement(nums) << endl;

    return 0;
}

// Time Complexity : O(log N)
// Space Complexity : O(1)






/* ================================================= Explanation =================================================

---------------------------------------------------- Intuition ---------------------------------------------------

A peak element is an element that is greater than both of its neighbours.

Example:
Index : 0  1  2  3  4  5  6
Array : 1  3  5  7  6  4  2
              ^
            Peak

The important observation is:

------------------------------------------------------------------------------------------------------------------

1. If we are standing on an increasing slope (↗),
   then a peak must exist on the RIGHT side.

Example:
1   3   5   7   6   4
        ^
       mid

Since:
arr[mid] > arr[mid-1]

We are moving upward, so a peak is either at mid itself
(if it is greater than the next element) or somewhere
on the right.

Move:
low = mid + 1

------------------------------------------------------------------------------------------------------------------

2. If we are standing on a decreasing slope (↘),
   then a peak must exist on the LEFT side.

Example:
1   4   8   6   3   2
            ^
           mid

Since:
arr[mid] > arr[mid+1]

We are moving downward, so the peak lies on the left side.

Move:
high = mid - 1

------------------------------------------------------------------------------------------------------------------

3. If arr[mid] is greater than both neighbours,
   then mid itself is the peak.

Example:
1   4   7   5   2
        ^
       Peak

Return mid.

------------------------------------------------------------------------------------------------------------------

4. If mid is in a valley (smaller than both neighbours),
   then moving to either side will eventually reach a peak.

Example:
7   5   2   4   8
        ^
       mid

Both sides contain a peak.

In this implementation we move to the right:

low = mid + 1


Because every increasing slope eventually ends at a peak,
Binary Search can safely discard half of the array in every step.

Time Complexity : O(log n)
Space Complexity: O(1)

========================================================================================================= */