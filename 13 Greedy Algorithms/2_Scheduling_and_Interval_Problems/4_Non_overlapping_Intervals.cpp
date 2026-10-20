#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];         // sort 2D vector by 2nd element of pair of vector
        });

        int count = 0;                                  // count = answer
        int prevEnd = intervals[0][1];                  // prevEnd = 2nd element of 1st row

        for (int i = 1; i < intervals.size(); i++) {    // start from 2nd row to easy compare for prevEnd
            if (intervals[i][0] < prevEnd) {            // if intervals 1st element is smaller than prevEnd's 2nd element
                count++;                                // increase count
            }
            else {                                      // if intervals 1st element is not smaller than prevEnd's 2nd element
                prevEnd = intervals[i][1];              // make prevEnd's 2nd element as interval's 2nd element 
            }
        }

        return count;                                   // return count(answer)
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

