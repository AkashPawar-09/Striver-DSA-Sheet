/* ---------------------------------- Power Set Using Recursion ----------------------------------

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Input: nums = [0]
Output: [[],[0]]
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void solve(int index, vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Take the current element
        temp.push_back(nums[index]);
        solve(index + 1, nums, temp, ans);

        // Backtracking: remove the last picked element
        temp.pop_back();

        // Don't take the current element
        solve(index + 1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.subsets(nums);
    for(auto v : ans) {
        cout << "[";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if(i != v.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}


// Time Complexity : O(2^N × N)
// Space Complexity : O(N)