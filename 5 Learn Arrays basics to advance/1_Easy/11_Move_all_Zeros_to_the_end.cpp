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
            if (x == 0) count++;                // count zeros
        }

        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end()); // remove zeros from nums

        for (int i = 0; i < count; i++) {
            nums.emplace_back(0);               // add removed number of zeros at last of array
        }
        nums ;                                  // return given array nums (void = no return keyword)
    }
};

/* --------------------------------- Why you need BOTH (erase & remove) ---------------------------------
remove alone → wrong size, garbage values at the tail, zeros not truly gone.
erase alone (without remove) → you'd need to know exact positions of zeros to erase them, 
and erasing one-by-one from the middle is O(n) per erase (shifts everything), making it O(n²) overall.

// Combining them (erase-remove idiom) gives you O(n) total: one pass to compact, one pass to truncate.
-------------------------------------------------------------------------------------------------------*/



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
