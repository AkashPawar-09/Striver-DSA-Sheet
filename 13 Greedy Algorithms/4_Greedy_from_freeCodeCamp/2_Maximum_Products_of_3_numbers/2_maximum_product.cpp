#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end());
        int first = nums[0] * nums[1] * nums[n-1] ;
        int last = nums[n-1] * nums[n-2] * nums[n-3] ;
        return max(first,last);
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.maximumProduct(nums);

    cout << "Highest product: " << ans << endl;
    return 0;
}



// Time Complexity : O(N)
// Space Complexity : O(1)