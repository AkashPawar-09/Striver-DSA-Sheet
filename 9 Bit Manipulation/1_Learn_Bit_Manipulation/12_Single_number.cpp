#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};



int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution obj;
    int result = obj.singleNumber(nums);
    cout << "Non-repeating number: " << result << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)



/* --------------------------------------------------------------------------------------------------------------------

Using Properties : 

1) A ^ A = 0
2) A ^ 0 = A

-------------------------------------------------------------------------------------------------------------------- */