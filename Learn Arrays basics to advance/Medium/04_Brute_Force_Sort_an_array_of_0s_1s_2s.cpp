/*

Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.

Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

Input: nums = [0, 0, 1, 1, 1]
Output: [0, 0, 1, 1, 1]
Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        int index = 0;

        while(count0--) {
            nums[index++] = 0;
        }

        while(count1--) {
            nums[index++] = 1;
        }

        while(count2--) {
            nums[index++] = 2;
        }
    }
};



int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    obj.sortZeroOneTwo(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)