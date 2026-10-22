/*
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [2,3,0,1,4]
Output: 2

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        int left = 0;                   // left pointer  (min JUMP)
        int right = 0 ;                 // right pointer (max JUMP)
        int count = 0 ;                 // count (answer)

        while(right < n-1){                             // until right is at end
            int farthest = right ;                      // last point in range is right
            for(int i = left ; i <= right ; i++){       // find range {left,right} -> pointer
                farthest = max(farthest , i+nums[i]);   // last point is max of last point and jump
            }
            left = right + 1 ;
            // move left to next to right to create group of next range {left,right} which is left pointer

            right = farthest ;                          // right is last point in range
            count++ ;                                   // increase count by 1 
        }
        return count ;
    }
};



int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.jump(nums) << endl;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)