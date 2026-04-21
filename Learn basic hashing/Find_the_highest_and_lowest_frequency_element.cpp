/*
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, 
i.e. the highest and the frequency of 15 is 1 i.e. the lowest.

Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, 
i.e. the highest and the frequency of 3 is 1 i.e. the lowest.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minMaxFrequency(vector<int>& nums) {
        
        int hash[100000 + 1] = {0};

        // Step 1: Count frequency
        for(int x : nums){
            hash[x]++;
        }

        int minFreq = INT_MAX, maxFreq = INT_MIN;
        int minElement = -1, maxElement = -1;

        // Step 2: Find min & max frequency element
        for(int i = 0; i <= 100000; i++){
            if(hash[i] > 0){
                
                if(hash[i] < minFreq){
                    minFreq = hash[i];
                    minElement = i;
                }

                if(hash[i] > maxFreq){
                    maxFreq = hash[i];
                    maxElement = i;
                }
            }
        }

        return {minElement, maxElement};    // vector<int> ans in int main
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.minMaxFrequency(nums);

    cout << "Min freq element: " << ans[0] << endl;     // min output printing
    cout << "Max freq element: " << ans[1] << endl;     // max output printing 

    return 0;
}



/*

Note : INT_MAX and INT_MIN are constants (macros)
they are alredy defined with values :

INT_MAX = 2147483647      //  2^31 - 1
INT_MIN = -2147483648     // -2^31

for use of INT_MAX and INT_MIN
include #include <climits>

*/


// Time Complexity: O(n)
// Space Complexity: O(1)