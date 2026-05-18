/*

Input: nums = [1, 2, 1, 1, 3, 2]
Output: [1]
Explanation: Here, n / 3 = 6 / 3 = 2.
Therefore the elements appearing 3 or more times is : [1]

Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

Input: arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

Input: arr[] = [3, 2, 2, 4, 1, 4]
Output: [ ]
Explanation: n/3 = (6/3 = 2)
here number should occur more than 2 times 
There is no majority element.

Input: nums = [3,2,3]
Output: [3]
Explanation: n/3 = (3/3 = 1)
here number should occur more than 1 times 
majority element = [3]

Input: nums = [1]
Output: [1]
Explanation: 1/3 = (1/3 = 0)
here number should occur more than 0 times (i.e. at least 1 time) 
majority element = [1]

Input: nums = [1,2]
Output: [1,2]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();                // n is size of nums
        vector<int> ans;                    // create ans vector to store final answers
        unordered_map<int, int> mpp;        // hashmap → key , value  [element,  its frequency]
        int mini = (n / 3) + 1;             // minimum frequency required to put in ans vector
        for (int i = 0; i < n; i++) {       // traverse i = 0 to i < n 
            mpp[nums[i]]++;                 // increase frequency of current element by 1
            if (mpp[nums[i]] == mini) {     // if element in nums vector is seen more than (n/3)+1 times
                ans.push_back(nums[i]);     // then push_back that element 
            }               
            if (ans.size() == 2) {          // if size of ans vector becomes 2 
                break;                      // then break the for loop to save the time
            }
        }
        return ans;                         // after completing loop return the updated ans vector
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

    Solution obj ;
    
    vector<int> result = obj.majorityElementTwo(nums) ;
    for (int x : result) {
        cout << x << " ";
    }

    return 0;

}

// Time Complexity : O(N)
// Space Complexity : O(N)
