/*

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0
There are two zeroes: (0,0) and (0,3).
Row 0 → all elements become 0
Column 0 and column 3 → all elements become 0

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();                              // Gives number of rows

        int n = matrix[0].size();                           // Gives number of columns

        for (int i = 0; i < m; i++) {                       // traverse through each element of 2D vector
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {                    // find the element which have value 0

                    for (int col = 0; col < n; col++) {     // traverse through each column
                        if (matrix[i][col] != 0) {          // if row is not zero 
                            matrix[i][col] = -1;            // then make it -1 (unique element)
                        }
                    }

                    for (int row = 0; row < m; row++) {     // traverse through each row
                        if (matrix[row][j] != 0) {          // if column is not zero 
                            matrix[row][j] = -1;            // then make it -1 (unique element)
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {                       // traverse through i rows
            for (int j = 0; j < n; j++) {                   // traverse through j columns
                if (matrix[i][j] == -1) {                   // if you found it -1 (unique element)
                    matrix[i][j] = 0;                       // make that element to 0
                }
            }
        }
    }
};




int main() {

    int n, m;

    cout << "Enter number of rows : ";
    cin >> n;

    cout << "Enter number of columns : ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity : O((N*M) * (N+M)) 
// Space Complexity : O(1)