/*

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 = 310 - 100 = 210 and Buy the stock on day 4 and 
sell it on day 6 = 695 - 40 = 655 so the Maximum Profit  is = 210 + 655 = 865.

Input: prices[] = [4, 2]
Output: 0
Explanation: Stock prices keep decreasing, there is no chance to sell at a higher price after buying, 
so no profit can be made.

Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){

        int maxProfit = 0;

        for (int i = 0; i < n; i++) {                   // buy day
            for (int j = i + 1; j < n; j++) {           // sell day
                int profit = arr[j] - arr[i];           // profit from buy to sell everytime
                maxProfit = max(maxProfit, profit);     // always takes maximum values and replace negative value by zero
            }
        }
        return maxProfit;                               // return updated maximum profit
        }
};



int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int> arr(n) ;
    for (int  i = 0  ; i < n ; i++ ){
        cin >> arr[i] ;
    }

    Solution obj;   
    int result = obj.stockBuySell(arr,n);  
    cout << result << endl;
    return 0;
}


// Time Comlexity : O(n²)
// Space Complexity : O(1)
