/*

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 0
Explanation: Here, the element 0 is the minimum element in the array.


Input : nums = [3, 4, 5, 1, 2]
Output: 1
Explanation:Here, the element 1 is the minimum element in the array.

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int findMin(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Search space is already sorted.
            // Then arr[low] will always be the minimum
            // in that search space.
            if (arr[low] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }

            // Right half is sorted
            else {
                high = mid - 1;
                ans = min(ans, arr[mid]);
            }
        }

        return ans;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.findMin(arr) << endl;

    return 0;
}



// Time Complexity : less than O(log N)
// Space Complexity : O(1)