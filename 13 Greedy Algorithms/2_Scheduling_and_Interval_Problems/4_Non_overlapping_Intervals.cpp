#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                count++;
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};


int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> intervals[i][0] >> intervals[i][1];
    cout << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}