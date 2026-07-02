/*

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target. 


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
        vector<int> vec ;                                   // New vector to return output
        for (int i = 0 ; i < nums.size() ; i++ ) {          // outer loop for index 0 to n
            for ( int j = i+1 ; j< nums.size() ; j++ ) {    // inner loop for index 1 to n , to avoid i=j 
                if(nums[i] + nums[j] == target ) {          // condition to cheak sum equal to target 
                    vec.push_back(i) ;                      // adding 1st element 
                    vec.push_back(j) ;                      // adding 2nd element 
                    return vec ;                            // return output vector
                }
            }
        }
        return {false , false};                             // return if target not found anything 
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

// Time Complexity : O(N²)
// Space Complexity : O(1)
