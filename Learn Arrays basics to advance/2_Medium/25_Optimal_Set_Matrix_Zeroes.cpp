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

        int m = matrix.size();                                  // number of rows
        int n = matrix[0].size();                               // number of columns

        bool firstRowZero = false;                              // making firstRowZero false ;
        bool firstColZero = false;                              // making firstColZero false ;

        for (int j = 0; j < n; j++) {                           // cheaks first row by using variable j 
            if (matrix[0][j] == 0) {                            // cheaks until row contains 0
                firstRowZero = true;                            // if contains make firstRowZero as true
                break;                                          // immediately break the loop                      
            }
        }

        for (int i = 0; i < m; i++) {                           // cheaks first col by using variable i
            if (matrix[i][0] == 0) {                            // cheaks until col contains 0
                firstColZero = true;                            // if contains make firstColZero as true
                break;                                          // immediately break the loop 
            }
        }

        for (int i = 1; i < m; i++) {                           // traverse through all elements in matrix 
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {                        // if element found to be 0
                    matrix[i][0] = 0;                           // this marks column wise 0 (iteration)
                    matrix[0][j] = 0;                           // this marks row wise 0 (iteration)
                }
            }
        }

        for (int i = 1; i < m; i++) {                           // traverse through all elements in matrix  
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {   // cheak markings from above loop 
                    matrix[i][j] = 0;                           // make element zero (using OR operation)  
                }
            }
        }

        if (firstRowZero) {                                     // if row contains another zero 
            for (int j = 0; j < n; j++) {                       // iteration 
                matrix[0][j] = 0;                               // make whole row zero
            }
        }

        if (firstColZero) {                                     // if column contains another zero 
            for (int i = 0; i < m; i++) {                       // iteration 
                matrix[i][0] = 0;                               // make that whole column zero 
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

    cout << "Enter matrix elements :" << endl;

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

// Time Complexity : O(m × n)
// Space Complexity : O(1)