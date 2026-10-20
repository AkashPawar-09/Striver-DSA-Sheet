#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();                                           // Store the number of intervals
        sort(intervals.begin(), intervals.end());                           // Sort intervals by starting time
        vector<vector<int>> ans;                                            // Store the merged intervals
        for (int i = 0; i < n; i++) {                                       // Traverse all intervals
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {           // If ans is empty OR no overlap exists
                ans.push_back(intervals[i]);                                // Add current interval to answer
            }
            else {                                                          // If current interval overlaps
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);        // Extend the end of the last merged interval
            }
        }
        return ans;                                                         // Return all merged intervals
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);
    for(auto x : ans) {
        cout << "[" << x[0] << "," << x[1] << "] ";
    }
    return 0;
}


// Time Complexity : O(N log N)
// Space Complexity : O(N)