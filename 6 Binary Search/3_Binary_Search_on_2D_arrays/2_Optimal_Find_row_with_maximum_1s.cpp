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
    int rowWithMax1s(vector<vector<int>> &matrix) {

        int n = matrix.size();                      // number of rows
        int m = matrix[0].size();                   // number of columns

        int cnt_max = 0;                            // initiate count as 0 
        int index = -1;                             // initiate index as -1

        for (int i = 0; i < n; i++) {               // iterations for cheaking new row

            int low = 0;                            // low as 0
            int high = m - 1;                       // high as size of column - 1
            int ans = m;                            // answer as m

            while (low <= high) {

                int mid = low + (high - low) / 2;   // calculates mid

                if (matrix[i][mid] >= 1) {          // if middle element in row is greater than or equal to 1
                    ans = mid;                      // then answer is mid
                    high = mid - 1;                 // move high to mid - 1 
                }
                else {                              // if mid is smaller than 1
                    low = mid + 1;                  // move low to mid + 1
                }
            }
            // this algo is written to find first occurance of 1

            int cnt_ones = m - ans;                 // total 1's in row = total elements - total zeros (index of 1st occured 1)

            if (cnt_ones > cnt_max) {               // everytime with new row compare 1's
                cnt_max = cnt_ones;                 // update cnt_max variable with greater cnt_ones
                index = i;                          // also store the index as i as row number
            }
        }

        return index;                               // return that row having maximum count of 1's
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

// Time Complexity : O(n × log m)
// Space Complexity : O(1)