#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& neww) {
        int n = intervals.size() ;
        vector<vector<int>> result ;
        int i =0 ; 
        while(i < n && intervals[i][1] < neww[0]){
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0] <= neww[1]){
            neww[0] = min(neww[0] , intervals[i][0]);
            neww[1] = max(neww[1] , intervals[i][1]);
            i++;
        }
        result.push_back(neww);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};


int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);
    for(auto x : ans) {
        cout << "[" << x[0] << "," << x[1] << "] ";
    }
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)