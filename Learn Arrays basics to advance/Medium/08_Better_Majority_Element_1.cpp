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
        unordered_map<int, int> mp;  
        // Create a hash map where it stores key value pair

        int n = nums.size();        // Store the size of array 
        
        for (int num : nums) {      // Loop through each element in the array

            mp[num]++;              // If 'num' is not present,it is automatically initialized to 0,then incremented to 1
            // Increase frequency of current element      

            if (mp[num] > n / 2) {  // cheak condition of majority

                return num;  
                // As soon as it find majority element, return it immediately
            }
        }

        return -1;  
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
    int result = obj.majorityElement(nums);  
    cout << result << endl;
    return 0;
}


// Time Comlexity : O(n)
// Space Complexity : O(1)
