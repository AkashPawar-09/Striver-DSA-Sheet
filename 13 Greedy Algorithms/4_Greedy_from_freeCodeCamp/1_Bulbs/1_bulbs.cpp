/*
Input: A = [0, 1, 0, 1]
Output: 4
Explanation:
Switch bulb 1: [1, 0, 1, 0]
Switch bulb 2: [1, 1, 0, 1]
Switch bulb 3: [1, 1, 1, 0]
Switch bulb 4: [1, 1, 1, 1]

Input: A = [0, 1, 1, 1]
Output: 2
Explanation:
Switch bulb 1: [1, 0, 0, 0]
Switch bulb 2: [1, 1, 1, 1]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbs(vector<int>& nums) {
        int cost = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (cost % 2 == 1) {            
                // even flips so far -> bulb unchanged
                // odd flips -> bulb inverted
                curr = 1 - curr;            // flip bit (1->0) OR (0->1)
            }

            if (curr == 1) {
                continue;           // already on, nothing to do
            }
            
            if (curr == 0) {
                cost++;             // off, so press this switch
            }
        }

        return cost;
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
    int ans = obj.bulbs(nums);

    cout << "Minimum switches: " << ans << endl;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)