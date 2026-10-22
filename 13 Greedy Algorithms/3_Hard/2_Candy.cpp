#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1); 
        // creates vector with n length and all values are 1

        for(int i = 0 ; i < n-1 ; i++){         // loop from first to last
            if(nums[i] < nums[i+1]) ans[i+1] = ans[i] + 1 ;     
            // if next element is greater than previous 
            // then increase it by 1 than previous element
        }

        for(int j = n-2 ; j >= 0 ; j--){        // loop from last to first
            if(nums[j] > nums[j+1]) {
                ans[j] = max(ans[j], ans[j+1] + 1);
                // if previous element is greater than last
                // previous = maximum of previous element OR last element + 1 
            }
        }

        // Example where the second loop is necessary:
        // nums = [3,2,1]
        // After the first loop:  [1,1,1]
        // After the second loop: [3,2,1]

        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum = sum + ans[i] ;
        }

        return sum ;
    }
};



int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    Solution obj;
    cout << obj.candy(nums) << endl;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(N)