#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        int xor1 = 0 ;
        int xor2 = 0 ; 
        
        for (int i = 0 ; i < n ; i++) {
            xor1 = xor1 ^ nums[i] ;
        }
        for (int i = 0 ; i < n+1 ; i++){
            xor2 = xor2 ^ i ;
        }
        return xor1 ^ xor2 ;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};
    Solution obj;
    int result = obj.missingNumber(nums);
    cout << "Missing number: " << result << endl;
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(1)