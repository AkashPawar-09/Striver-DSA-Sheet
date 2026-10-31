/*
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void Solve(int ind, vector<int>& ds, int target, vector<int>& nums, vector<vector<int>>& ans, int n) {
        if(target == 0) {               // after recursion more and more time when finally target becomes 0 
            ans.push_back(ds);          // push the given ds to ans 2D vector
            return;                     // return and backtrack
        }
        
        for(int i = ind; i < n; i++) {                          // traverse all indices
            if(i > ind && nums[i] == nums[i-1]) continue;       // if i > ind AND current nums[i] is not duplicate of previous then continue 
            if(nums[i] > target) break;                         // if current nums[i] exceeds the sum (i.e. target) then break 
            ds.push_back(nums[i]);                              // if current element does not follow upper 2 conditions then push it to ds
            Solve(i+1, ds, target-nums[i], nums, ans, n);       // solve recursion for next element with removing current element from sum(target)
            ds.pop_back();                                      // backtrack and remove last picked element
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();                              // size of given 2D array (candidates)
        vector<vector<int>> ans;                                // stores ans 2D array
        vector<int> ds;                                         // used to store in ans 
        sort(candidates.begin(), candidates.end());             // sort given candidates 
        Solve(0, ds, target, candidates, ans, n);               // Solve for ind = 0 , ds , target = given , candidates = given , ans , n = size of candidates
        // start recursion from index 0
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);
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


// Time Complexity: O(2^N × N)
// Space Complexity: O(N)



/* ---------------------------------------------------------------------------------------------------- recursion tree ----------------------------------------------------------------------------------------------------

LeetCode 40 - Combination Sum II 

candidates = [10,1,2,7,6,1,5]
sorted = [1,1,2,5,6,7,10], target = 8
Node = [ds], remaining_target / ind=start index. Each row = loop i=ind..n-1
Final answer: [1,1,6] [1,2,5] [1,7] [2,6]

                                                                                                                                         [],8
                                                                                                                                         ind=0
                                                                                                                                           |
                                                                     +--------------------------------------------------------+------------+----------+-----------------------+-----------+-----------+-----------+
                                                                     |                                                        |                       |                       |           |           |           |
                                                                i=0 Pick 1                                                   i=1                 i=2 Pick 2              i=3 Pick 5  i=4 Pick 6  i=5 Pick 7      i=6
                                                                   [1],7                                                    SKIP                    [2],6                   [5],3       [6],2       [7],1       BREAK
                                                                   ind=1                                                  dup 1==1                  ind=3                   ind=4       ind=5       ind=6       10>8
                                                                     |                                                                                |                       |           |           |
                        +-----------------------------------+--------+--------+-----------+-----------+-----------+                       +-----------+-----------+           +           +           +
                        |                                   |                 |           |           |           |                       |           |           |           |           |           |
                   i=1 Pick 1                          i=2 Pick 2        i=3 Pick 5  i=4 Pick 6  i=5 Pick 7      i=6                 i=3 Pick 5  i=4 Pick 6      i=5         i=4         i=5         i=6
                     [1,1],6                             [1,2],5           [1,5],2     [1,6],1     [1,7],0      BREAK                  [2,5],1     [2,6],0      BREAK       BREAK       BREAK       BREAK
                      ind=2                               ind=3             ind=4       ind=5       FOUND       10>7                    ind=4       FOUND        7>6         6>3         7>2        10>1
                        |                                   |                 |           |                                               |
      +-----------+-----+-----+-----------+           +-----+-----+           +           +                                               +
      |           |           |           |           |           |           |           |                                               |
i=2 Pick 2    i=3 Pick 5   i=4 Pick 6    i=5     i=3 Pick 5      i=4         i=4         i=5                                             i=4
[1,1,2],4      [1,1,5],1   [1,1,6],0     BREAK     [1,2,5],0     BREAK       BREAK       BREAK                                           BREAK
   ind=3        ind=4       FOUND        7>6        FOUND        6>5         6>2         7>1                                             6>1
    |            |
    +            +
    |            |
   i=3          i=4
  BREAK        BREAK
   5>4          6>1


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Example 2 :  candidates = [2,5,2,1,2] , target = 5
             candidates = [1,2,2,2,5] 

                         [], 5
             _____________|____________________
            /             |       |     |      \
        Pick 1         Pick 2   Skip 2 Skip 2  Pick 5
           |              |       |     |      |
        [1], 4          [2], 3   DUP   DUP    [5], 0
           |              |                    |
        Pick 2         Pick 2                FOUND
           |              |
        [1,2], 2       [2,2], 1
           |              |
        Pick 2         Next 2 > 1
           |              |
      [1,2,2], 0        DEAD
           |
         FOUND

       Remaining branches:
       - Duplicate 2 at [1] level → SKIP
       - Duplicate 2 at [1,2] level → SKIP
       - 5 > 4 at [1] level → BREAK
       - 5 > 3 at [2] level → BREAK

*/