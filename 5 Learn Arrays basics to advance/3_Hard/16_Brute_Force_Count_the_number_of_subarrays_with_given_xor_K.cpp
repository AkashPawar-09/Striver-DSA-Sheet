/*

Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].


*/

#include<bits/stdc++.h>
using namespace std ;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int xr = 0;

            for (int j = i; j < n; j++) {

                xr ^= nums[j];

                if (xr == k)
                    count++;
            }
        }

        return count;
    }
};


int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;

    int ans = obj.subarraysWithXorK(nums, k);

    cout << "Number of subarrays with XOR " << k << " = " << ans << endl;

    return 0;
}

// Time Complexity : O(N²)
// Space Complexity : O(1)