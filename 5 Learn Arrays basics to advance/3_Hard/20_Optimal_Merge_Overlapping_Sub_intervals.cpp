/*

Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.


Input : [[1,4],[4,5]]
Output :  [[1,5]]
Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].


Input: intervals = [[5,7],[1,3],[4,6],[8,10]]
Output: [[1,3],[4,7],[8,10]]
Explanation: Intervals [4,6] and [5,7] overlap and are merged into [4,7].


Input: intervals = [[1,5],[3,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].


Input: arr[][] = [[6, 8], [1, 9], [2, 4], [4, 7]]
Output: [[1, 9]]
Explanation: In the given intervals all the intervals overlap with the interval [1, 9]. Therefore we will return [1, 9].

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();                                     // Store the number of intervals

        sort(arr.begin(), arr.end());                           // Sort intervals by starting time

        vector<vector<int>> ans;                                // Store the merged intervals

        for (int i = 0; i < n; i++) {                           // Traverse all intervals

            if (ans.empty() || arr[i][0] > ans.back()[1]) {     // If ans is empty OR no overlap exists
                ans.push_back(arr[i]);                          // Add current interval to answer
            }
            else {                                              // If current interval overlaps
                ans.back()[1] = max(ans.back()[1], arr[i][1]);  // Extend the end of the last merged interval
            }
        }

        return ans;                                             // Return all merged intervals
    }
};



// Time Complexity : O(N*logN) + O(N)
// Space Complexity : O(N)