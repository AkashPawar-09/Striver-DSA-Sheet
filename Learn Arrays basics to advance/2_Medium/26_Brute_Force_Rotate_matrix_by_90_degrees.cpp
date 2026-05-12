/*

Input  : matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output : matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
Explanation : First, we transpose the matrix: rows become columns. 
Then, we reverse each row to simulate 90° clockwise rotation. 
So element at (0,0) goes to (0,2), (0,1) goes to (1,2), and so on, achieving the rotated layout.

Input :  matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output : matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
Explanation : First, the matrix is transposed: rows become columns. Then, each row is reversed. 
This moves the last column to the first row, the second last column to the second row, and so on. 
The original position of each element is rotated 90° clockwise into its new location.

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output:matrix = [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();                                   // number of rows
        int cols = matrix[0].size();                                // number of columns

        vector<vector<int>> ansMatrix(rows, vector<int>(cols));     // defining new answer matrix   

        for (int i = 0; i < rows; i++) {                            // outer loop for rows
            for (int j = cols ; j > 0 ; j-- ) {                     // inner loop for cols
                for (int k = 0 ; k < cols ; k++ ) {                 // loop to store column wise in ansMatrix
                    ansMatrix[i][k] = matrix[i][j] ;                // updating ansMatrix
                }
            }
        }
        matrix = ansMatrix ;                                        // updating matrix with ansMatrix
    }
};

class Solution {
public:

    void rotateMatrix(vector<vector<int>>& matrix) {

        int rows = matrix.size();                                   // Number of rows
        int cols = matrix[0].size();                                // Number of columns

        vector<vector<int>> ansMatrix(cols, vector<int>(rows));     // Create answer matrix

        for (int i = 0; i < rows; i++) {                            // outer loop for rows
            for (int j = 0; j < cols; j++) {                        // inner loop for cols
                ansMatrix[j][rows - 1 - i] = matrix[i][j];          // updating ansMatrix by using i,j 
            }
        }
        matrix = ansMatrix;                                         // updating matrix with ansMatrix
    }
};

int main() {
    int n, m;

    cout << "Enter number of rows : ";
    cin >> n;

    cout << "Enter number of columns : ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements :" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> matrix[i][j];
        }
    }

    Solution obj;

    obj.rotateMatrix(matrix);

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[0].size(); j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

// Time Complexity : O(N × M)
// Space Complexity : O(N × M)






