/*

Input: arr[] = [1, 2, 3, 4, 5], x = 11 
Output: 10
Explanation: Subarray having maximum sum is [1, 2, 3, 4].

Input: arr[] = [2, 4, 6, 8, 10], x = 7 
Output: 6
Explanation: Subarray having maximum sum is [2, 4] or [6].

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxSum = 0;

        while(right < n) {
            sum = sum + arr[right];
            while(sum > x) {
                sum = sum - arr[left];
                left++;
            }
            maxSum = max(maxSum, sum);
            right++;
        }
        return maxSum;
    }
};


int main() {
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    Solution obj;
    cout << obj.maxSum(arr, x) << endl;
    return 0;
}


// Time Complexity : O(N²)
// Space Complexity : O(1)