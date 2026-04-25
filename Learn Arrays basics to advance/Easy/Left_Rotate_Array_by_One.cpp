/*
Input: nums = [1, 2, 3, 4, 5]  
Output: [2, 3, 4, 5, 1]  
Explanation: Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].

Input:nums = [-1, 0, 3, 6]  
Output: [0, 3, 6, -1]  
Explanation: Initially, nums = [-1, 0, 3, 6]  
Rotating once to the left results in nums = [0, 3, 6, -1].

Input: nums = [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]
Explanation: Initially, nums = [1, 2, 3, 4, 5]
Rotating once to left -> nums = [2, 3, 4, 5, 1]

Input: nums = [-1, 0, 3, 6]
Output: [0, 3, 6, -1]
Explanation: Initially, nums = [-1, 0, 3, 6]
Rotating once to left -> nums = [0, 3, 6, -1]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {

        int n = nums.size();        // n = size of nums array
        if (n == 0) return;         // if n is empty return 
        vector<int> vec(n);         // initialize new vector vec
        vec[n - 1] = nums[0];       // end element of nums is start element of nums 

        for (int i = 0; i < n - 1; i++) {       // iteration from index 1 to n-1 
            vec[i] = nums[i+1];     // replacing all element without first elelment vec[0]
        }
        nums = vec;                 // Since return type is void so you can't return vec directly 
                                    // So return original array by changing it by new array 
    }
};




int main() {

    int n;
    cin >> n;
    vector<int> nums(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> nums[i] ;
    }

    Solution obj; 
    obj.rotateArrayByOne(nums); 

    for (int x : nums) { 
        cout << x << " ";
    }

    return 0;
}







