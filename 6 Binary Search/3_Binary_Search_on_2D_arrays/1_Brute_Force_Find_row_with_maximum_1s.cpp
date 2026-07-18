/*

Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
Output: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).


Input: mat = [ [0, 0], [0, 0] ]
Output: -1
Explanation: The matrix does not contain any 1. So, -1 is the answer.


Input: arr[][] = [[0,1,1,1],
                 [0,0,1,1],
                 [1,1,1,1],
                 [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.


Input: arr[][] = [[0,0],
                 [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.


Input: arr[][] = [[0,0], 
                 [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {

        int n = arr.size();

        int maxSum = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = 0; j < n; j++) {
                sum = sum + arr[i][j];
            }

            if (sum > maxSum) {
                maxSum = sum;
                ans = i;
            }
        }

        return ans;
    }
};


int main() {

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    Solution obj;

    cout << obj.rowWithMax1s(arr);

    return 0;
}

// Time Complexity : O(N * M)
// Space Complexity : O(1)