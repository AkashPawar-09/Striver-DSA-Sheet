/*

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
        vector<pair<int,int>> arr;                              // vector arr using pairs 

        for (int i = 0; i < nums.size(); i++) {                 // loop to add all elements of nums in arr 
            arr.push_back({nums[i], i});                        // store value + original index
        }

        sort(arr.begin(), arr.end());                           // Sort array from start to end 

        int left = 0, right = arr.size() - 1;                   // make 2 elements that will be returned

        while (left < right) {                                  // loop for 0 to n 
            int sum = arr[left].first + arr[right].first;       // take values at left and right pointers and compute their sum

            if (sum == target) {                                // if the current pair gives the required target
                return {arr[left].second, arr[right].second};   // return ORIGINAL indices (stored in pair.second)
            }
            else if (sum < target) {                            // if sum is small
                left++;                                         // move left pointer right to increase sum
            }
            else {                                              // if sum is too large
                right--;                                        // move right pointer left to decrease sum 
            }
        }

        return {false, false};                             // return if target not found anything 
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


// Time Complexity : O(N)
// Space Complexity : O(N)
