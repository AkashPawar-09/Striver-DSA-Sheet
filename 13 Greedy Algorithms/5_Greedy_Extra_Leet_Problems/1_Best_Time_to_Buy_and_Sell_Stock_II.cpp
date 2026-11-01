/*
Que. 122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
Find and return the maximum profit you can achieve.


Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size() ;
        nums.push_back(0) ;
        int sum = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > nums[i+1]){
                continue ;
            }
            else if(nums[i] < nums[i+1]){
                sum = sum + nums[i+1] - nums[i] ;
            }
            else{
                continue ;
            }
        }
        return sum ;
    }
};


int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution obj;
    int ans = obj.maxProfit(nums);
    cout << ans;
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)