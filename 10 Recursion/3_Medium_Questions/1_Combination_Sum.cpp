/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []
 
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void solve(int ind, vector<int>& ds, int target, vector<int>& arr, int n, vector<vector<int>>& ans) {
        if(target == 0) {                   // if target is zero 
            // value of target is already 0 OR becomes zero beacause of removing arr[ind] from target
            ans.push_back(ds);              // push current ds
            return;                         // return and go for Not pick condition
        }

        if(ind == n) return;                // if completed traversing ---> go for Not Pick

        // Pick
        if(arr[ind] <= target) {            // if current element is smaller than target
            ds.push_back(arr[ind]);         // push that element to ds
            solve(ind, ds, target - arr[ind], arr, n, ans);     // recursion step for same index till base case 
            // ----> BUT ----> target - arr[ind] ----> use that element again and again till ----> arr[ind] <= target
            ds.pop_back();                  // After completing Upper step (i.e. return)
            // Go for next element 
        }

        // Not Pick
        solve(ind + 1, ds, target, arr, n, ans);        // go for next index 
        // For each element , There pick and not pick option 
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();

        solve(0, ds, target, nums, n, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
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


/* ------------------------ recursion tree ------------------------

        Input: candidates = [2,3,5], target = 8

                                [ ], 8
                              /        \
                             /          \
                            /            \
                         Pick 2           Not Pick 2
                           |                   |
                         [2], 6             [ ], 8
                       /       \               |
                  Pick 2    Not Pick 2       Pick 3
                    |            |             |
                 [2,2], 4     [2], 6         [3], 5
                    |            |           /     \
                  Pick 2      Pick 3      Pick 3   Not Pick 3
                    |            |           |         |
                 [2,2,2], 2   [2,3], 3   [3,3], 2   [3], 5
                    |            |           |         |
                  Pick 2      Pick 3       Dead      Pick 5
                    |            |                     |
               [2,2,2,2],0    [2,3,3],0              [3,5],0
                    |            |                     |
                  FOUND        FOUND                 FOUND

               Other unexplored branches → DEAD
*/