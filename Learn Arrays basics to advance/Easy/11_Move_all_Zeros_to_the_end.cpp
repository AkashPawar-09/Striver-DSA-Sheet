/*

Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Input : 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation : All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation: Both the zeroes are moved to the end and the order of the other elements stay the same

Input: nums = [0, 0, 0, 1, 3, -2]
Output: [1, 3, -2, 0, 0, 0]
Explanation: All 3 zeroes are moved to the end and the order of the other elements stay the same

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size() ;
        if (n==0) {return ;}
        int count = 0 ;

        for (int x : nums) {
            if (x == 0) count++;
        }

        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());

        for (int i = 0; i < count; i++) {
            nums.emplace_back(0);
        }
        nums ;
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

    obj.moveZeroes(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(n)
