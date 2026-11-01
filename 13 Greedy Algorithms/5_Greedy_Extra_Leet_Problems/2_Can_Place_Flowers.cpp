/*
Que. 605. Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.


Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

*/

#include<bits/stdc++.h>
using namespace std ;

 class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int count) {
        int n = nums.size();

        if (n == 1 && nums[0] == 0 && count <= 1) {
            return true;
        }

        if (n == 2 && nums[0] == 0 && nums[1] == 0 && count <= 1) {
            return true;
        }

        if (nums[0] == 0 && nums[1] == 0) {
            count--;
            nums[0] = 1;
        }

        int i = 1;

        while (i < n - 1) {
            if (nums[i - 1] == 0 && nums[i] == 0 && nums[i + 1] == 0) {
                count--;
                nums[i] = 1;
            }

            i++;
        }

        if (nums[n - 1] == 0 && nums[n - 2] == 0) {
            count--;
            nums[n - 1] = 1;
        }

        if (count <= 0) {
            return true;
        }

        return false;
    }
};


int main() {
    vector<int> nums;
    int n;
    cin >> n;
    int k ;
    cin >> k ;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution obj;
    int ans = obj.canPlaceFlowers(nums,k);
    cout << ans;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)