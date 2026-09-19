/*

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        int left = 0;

        for(int right = 0; right < n; right++) {
            sum = sum + nums[right];
            while(sum > goal) {
                sum = sum - nums[left];
                left++;
            }
            count = count + right - left + 1;
        }

        if(goal == 0) return count;

        int count2 = 0;
        sum = 0;
        left = 0;

        for(int right = 0; right < n; right++) {
            sum = sum + nums[right];
            while(sum >= goal) {
                sum = sum - nums[left];
                left++;
            }
            count2 = count2 + right - left + 1;
        }

        return count - count2;
    }
};




int main() {
    Solution obj;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << obj.numSubarraysWithSum(nums, goal);
    return 0;
}