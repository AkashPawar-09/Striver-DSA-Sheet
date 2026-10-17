#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int maximum = 0 ; 
        int target = n-1 ;
        for(int i = 0 ; i < n ; i++){
            if(i > maximum) return false;
            maximum = max(maximum , i+nums[i]);
            if(maximum >= target) return true ;    
        }
        return false ;
    }
};


int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << boolalpha << sol.canJump(nums) << endl;
    return 0;
}