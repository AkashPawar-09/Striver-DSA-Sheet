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
        unordered_map<int, int> mp;

        int xr = 0;
        long count = 0;

        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            xr ^= nums[i];

            int x = xr ^ k;

            if (mp.find(x) != mp.end())
                count += mp[x];

            mp[xr]++;
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


// Time Complexity : O(N)
// Space Complexity : O(N)