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
        int zero = 0 ;
        int one =  0 ;
        int two =  0 ;
        for (int k = 0 ; k < nums.size() ; k++ ){
            if(nums[k] == 0 ) {zero++ ;}
            if ( nums[k] == 1 ) {one++ ;}
            if(nums[k] == 2 ) {two++ ;}
        }
        nums.clear() ;
        for (int a = 0 ; a < zero ; a++) {
            nums.emplace_back(0) ;
        }
        for (int b = 0 ; b < one ; b++ ){
            nums.emplace_back(1) ;
        }
        for (int c = 0 ; c < two ; c++){
            nums.emplace_back(2);
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

    obj.sortZeroOneTwo(nums);

    for(int k : nums ){
        cout << k << " ";
    }
    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1)