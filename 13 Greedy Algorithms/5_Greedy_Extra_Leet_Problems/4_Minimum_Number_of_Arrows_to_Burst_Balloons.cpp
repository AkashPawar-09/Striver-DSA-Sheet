/*
Que. 452. Minimum Number of Arrows to Burst Balloons

There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points 
where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. 
A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        if(nums.empty()) return 0 ;
        sort(nums.begin(),nums.end(),[](const vector<int> &a , const vector<int> &b){
            return a[1] < b[1] ;
        });

        int n = nums.size() ;
        int arrow = 1 ;
        int curr_end = nums[0][1] ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i][0] > curr_end) {
                arrow++;
                curr_end = nums[i][1] ;
            }
        }
        return arrow ;
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
    int ans = obj.findMinArrowShots(nums);

    cout << "Maximum disjoint intervals: " << ans << endl;
    return 0;
}


// Time Complexity : O(N log N)
// Space Complexity : O(1)