/*

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false


Input: mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
Output: True
Explanation: The target = 8 exists in the 'mat' at index (1, 3).


Input: mat = [ [1, 2, 4], [6, 7, 8], [9, 10, 34] ], target = 78
Output: False
Explanation: The target = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();                      // number of rows
        int m = matrix[0].size();                   // number of cols

        for (int i = 0; i < n; i++) {               // traverse each rows

            // applying BS in each row to comapare and if not found go to next row
            
            int low = 0;
            int high = m - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (matrix[i][mid] == target) {
                    return true;
                }
                else if (matrix[i][mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
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


// Time Complexity : O(n × log m)
// Space Complexity : O(1)