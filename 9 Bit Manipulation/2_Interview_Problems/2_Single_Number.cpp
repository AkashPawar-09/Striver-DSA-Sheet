#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return -1;
        if (n == 1) return nums[0];

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            if (count == 1)
                return nums[i];
        }

        return -1;
    }
};

int main() {

    vector<int> nums = {4, 1, 2, 1, 2};

    Solution obj;

    int result = obj.singleNumber(nums);

    cout << "Single number: " << result << endl;

    return 0;
}



// Time Complexity : O(N²)
// Space Complexity : O(1)