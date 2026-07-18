/*

Input: mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output: True
Explanation: The target = 8 exists in the 'mat' at index (1, 3).


Input: mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output: False
Explanation: The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

*/


#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();                      // number of rows
        int m = matrix[0].size();                   // number of cols
        
        int low = 0;                                // 1st element in 2D matrix
        int high = n * m - 1;                       // last element in 2D matrix

        while (low <= high) {

            int mid = low + (high - low) / 2;       // find middle element in 2D matrix

            int row = mid / m;                      // row of middle element as row
            int col = mid % m;                      // col of middle element as col

            if (matrix[row][col] == target) {       // if target is at exact expected column and row number  
                return true;                        // then return true
            }
            else if (matrix[row][col] < target) {   // if target is smaller than expected element 
                low = mid + 1;                      // then move low to mid + 1
            }
            else {
                high = mid - 1;                     // else move high to mid - 1
            }
        }

        return false;                               // if element not found return false 
    }
};

int main() {
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    if (obj.searchMatrix(matrix, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// Time Complexity : O(log(m * n)) 
// Space Complexity : O(1)