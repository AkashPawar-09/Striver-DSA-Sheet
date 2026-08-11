#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }
        int bit = xorr & (-xorr);
        int a = 0;
        int b = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] & bit){
                a = a ^ nums[i];
            }
             else {
                b = b ^ nums[i];
            }
        }
        return {a, b};
    }
};




int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    Solution obj;
    vector<int> result = obj.singleNumber(nums);
    cout << "Non-repeating numbers: ";
    cout << result[0] << " " << result[1];
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)


/* --------------------------------------------------------------------------------------------------------------------

Using Properties : 

1) A ^ A = 0
2) A ^ 0 = A

-------------------------------------------------------------------------------------------------------------------- */