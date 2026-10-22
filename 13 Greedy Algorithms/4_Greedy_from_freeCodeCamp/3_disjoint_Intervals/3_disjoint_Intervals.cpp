// Sort the intervals by end time, then always keep the interval that ends earliest, because it blocks the fewest others. 
// Any later interval that starts after the last kept end is disjoint, so keep it too.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int disjointIntervals(vector<vector<int>>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];                                 // sorting by 2nd element 
        });

        
        int prevEnd = nums[0][1];               // end of 1st range (2nd element)
        int count = 1;                          // count(answer) = 1 
        
        for (int i = 1; i < n; i++) {           
            if (nums[i][0] <= prevEnd) {        // if 1st element of next range is smaller or equal (intersecting)
                continue;                       // continue loop dont go forward
            }
            prevEnd = nums[i][1];               // else update prevEnd if not intersecting or end before....
            count++;                            // increase count
        }
        
        return count;
    }
};


int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    cout << "Enter " << n << " intervals (start end): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    Solution obj;
    int ans = obj.disjointIntervals(nums);

    cout << "Maximum disjoint intervals: " << ans << endl;
    return 0;
}



// Time Complexity : O(N log N)
// Space Complexity : O(1)