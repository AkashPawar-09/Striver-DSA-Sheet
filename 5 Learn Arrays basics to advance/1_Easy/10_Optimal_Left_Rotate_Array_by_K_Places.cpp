/*
Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 

Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
Output : [3, 4, 5, 6, 1, 2]
Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {    // eg. [1, 2, 3, 4, 5, 6]   ,k=8
        int n = nums.size();                        // n = 6
        if (n == 0) return;     

        k = k % n;                                  // k = 8 % 6 = 2   ------>  i.e. k = 2

        reverse(nums.begin(), nums.begin() + k);    // [2, 1, 3, 4, 5, 6]
        reverse(nums.begin() + k, nums.end());      // [2, 1, 6, 5, 4, 3]
        reverse(nums.begin(), nums.end());          // [3, 4, 5, 6, 1, 2]
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution obj;
    obj.rotateArray(nums, k);

    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}


// Time Complexity : O(n) 
// Space Complexity : o(1)
