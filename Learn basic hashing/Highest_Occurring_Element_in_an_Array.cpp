/*

Input: nums = [1, 2, 2, 3, 3, 3]
Output: 3
Explanation: The number 3 appears the most (3 times). 
It is the most frequent element.


Input: nums = [4, 4, 5, 5, 6]
Output: 4
Explanation: Both 4 and 5 appear twice, but 4 is smaller. 
So, 4 is the most frequent element.

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        int hash[100000 + 1] = {0};

        // Step 1: Count frequency
        for(int x : nums){
            hash[x]++;
        }

        int maxFreq = 0;
        int maxElement = -1;

        // Step 2: Find max frequency element
        for(int i = 0; i <= 100000; i++){
            if(hash[i] > 0){
                if(hash[i] > maxFreq){
                    maxFreq = hash[i];
                    maxElement = i;
                }
            }
        }
        return maxElement;
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
    int result = obj.mostFrequentElement(nums);

    cout << "Element with maximum frequency: " << result << endl;

    return 0;
}
