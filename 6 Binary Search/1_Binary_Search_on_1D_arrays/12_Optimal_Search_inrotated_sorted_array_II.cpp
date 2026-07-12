/* ===================================================================== CONTAINS DUPLICATES ============================================================================

Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Output: True
Explanation: The element 3 is present in the array. So, the answer is True.


Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Output: False
Explanation:The element 10 is not present in the array. So, the answer is False.


Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 7
Output: True

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k) {

        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == k)
                return true;

            // Shrink the search space if low, mid and high are the same
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution obj;

    if (obj.searchInARotatedSortedArrayII(nums, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)



/* ============================================== WHEN WE WANT TO RETURN INDEX ==========================================================


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int search(vector<int> &nums, int k) {

        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == k)
                return mid;

            // Shrink the search space if low, mid and high are the same
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
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

    int k;
    cin >> k;

    Solution obj;

    cout << obj.search(nums, k) << endl;

    return 0;
}



// Time Complexity : O(log N)
// Space Complexity : O(1)

*/