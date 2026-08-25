#include<bits/stdc++.h>
using namespace std ;


class Solution {
	public:
	int maxSubarraySum(vector<int>& arr, int k) {
		int n = arr.size() ;
		
		int max_sum = 0;
		for (int i = 0; i < k; i++)
			max_sum = max_sum + arr[i];

		int window_sum = max_sum;
		for (int i = k; i < n; i++) {
			window_sum = window_sum + arr[i] - arr[i - k];
			max_sum = max(max_sum, window_sum);
		}
		
		return max_sum;
	}
};


int main() {
    vector<int> arr = {4, -2, 7, 1, -5, 6, 3};
    int k = 4;
    Solution obj;
    cout << "Maximum subarray sum = " << obj.maxSubarraySum(arr, k) << endl;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)