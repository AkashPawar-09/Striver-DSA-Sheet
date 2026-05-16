/*

Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
Output: 7  
Explanation: The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

Input: nums = [1, 1, 1, 2, 1, 2]  
Output: 1  
Explanation: The number 1 appears 4 times in the 6-sized array, making it the most frequent element.

Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0 ; i < nums.size() ; i++ ){
            int count = 0 ; 
            for (int j = 0 ; j < nums.size() ; j++ ){
                if (nums[i] == nums[j]) {count++ ;}
                if(count > (nums.size()/2) ){return nums[i];}
            }
        }
        return -1 ;
    }
};


int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int> nums(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> nums[i] ;
    }

    Solution obj;   
    int result = obj.majorityElement(nums);  
    cout << result << endl;
    return 0;
}


// Time Comlexity : O(n)
// Space Complexity : O(n)
