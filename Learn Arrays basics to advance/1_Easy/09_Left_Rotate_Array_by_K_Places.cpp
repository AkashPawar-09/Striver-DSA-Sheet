/*

Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: nums = [3, 4, 5, 6, 1, 2]
Explanation:
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]


Input: nums = [3, 4, 1, 5, 3, -5], k = 8
Output: nums = [1, 5, 3, -5, 3, 4]
Explanation:
rotate 1 step to the left: [4, 1, 5, 3, -5, 3]
rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]
rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]
rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]
rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]
rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]
rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]
rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]

*/

#include<bits/stdc++.h>
using namespace std ;



class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();    // size of nums
        if (n == 0) {           // if empty return 
            return ;
        }

        k = k % n;          // 

        vector<int> vec(n) ; 

        for (int i = 0; i < n; i++) {
            vec[i] = nums[(i + k) % n]; 
        }
        nums = vec;
    }
};

/*      ANOTHER Solution 

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();

        // Store first k elements
        vector<int> temp(nums.begin(), nums.begin() + k);

        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }

        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }

        nums;
    }
};

(temp array) :
Time Complexity : O(n)
Space Complexity : O(k)

*/


int main() {

    int n;
    cin >> n;
    vector<int> nums(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> nums[i] ;
    }
    int k ;
    cin >> k ;

    Solution obj; 
    obj.rotateArray(nums,k); 

    for (int x : nums) { 
        cout << x << " ";
    }

    return 0;
}

// (modulo method) :
// Time Complexity : O(n)
// Space Complexity : O(n)
