/*

Input : nums= [1,2,2,3], x = 2
Output:1
Explanation: Index 1 is the smallest index such that arr[1] >= x.


Input : nums= [3,5,8,15,19], x = 9
Output: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    Solution obj;

    cout << obj.lowerBound(arr, n, x);

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)