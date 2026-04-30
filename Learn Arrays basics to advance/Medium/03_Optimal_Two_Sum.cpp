/*

LeetCode Que No. ->        1. Two Sum

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target. 

Leetcode ( I/P , O/P )
Input: nums = [1, 6, 2, 10, 3], target = 7
Output: [0, 1]
Explanation: nums[0] + nums[1] = 1 + 6 = 7

Input: nums = [1, 3, 5, -7, 6, -3], target = 0
Output: [1, 5]
Explanation: nums[1] + nums[5] = 3 + (-3) = 0

*/
#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;                     

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            mp[nums[i]] = i;
        }

        return {false,false};                             // return if target not found anything
    }
};


int main () {
    int n ; 
    cin >> n ;

    vector<int> nums ;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int target ;
    cin >> target ;

    Solution obj ;
    
    vector<int> result = obj.twoSum(nums,target) ;
    for (int x : result) {
        cout << x << " ";
    }

    return 0;


}


// Time Complexity : O(N log N)
// Space Complexity : O(N)
