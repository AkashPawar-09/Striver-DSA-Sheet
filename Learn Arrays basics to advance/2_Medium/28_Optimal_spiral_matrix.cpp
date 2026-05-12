/*

Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Input: Matrix[][] = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } }
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // these 4 variables are directions to store element in new vector
        int top = 0 ;                                       // int top = 0
        int bottom = matrix.size() - 1;                     // int bottom as row size -1
        int left = 0 ;                                      // int left = 0 
        int right  = matrix[0].size() - 1;                  // int right as column size -1 

        vector<int> ans;                                    // creating new ans vector
        int k = 0;                                          // direction counter     // gives direction to push_back elements

        while (top <= bottom && left <= right) {            // loop until [ top to bottom and left to right ]

            if (k % 4 == 0) {                               // starting from k = 0 
                for (int j = left; j <= right; j++)         // 1st loop : left to right elements
                    ans.push_back(matrix[top][j]);          // update ans column wise as j increases 
                top++;                                      // update top ,to go in inner elements in another next loop

            } else if (k % 4 == 1) {                        // starting from k = 1
                for (int i = top; i <= bottom; i++)         // 2nd loop : top to bottom elements 
                    ans.push_back(matrix[i][right]);        // update ans row wise as i decrease
                right--;                                    // update right ,to go in inner elements in another next loop

            } else if (k % 4 == 2) {                        // starting from k = 2 
                for (int j = right; j >= left; j--)         // 3rd loop : right to left elements
                    ans.push_back(matrix[bottom][j]);       // update ans column wise as j decrease 
                bottom--;                                   // update bottom ,to go in inner elements in another next loop

            } else {                                        // starting from k = 3
                for (int i = bottom; i >= top; i--)         // 4th loop : bottom to top elements
                    ans.push_back(matrix[i][left]);         // update ans row wise as i increase
                left++;                                     // update left ,to go in inner elements in another next loop

            }

            k++;                                            // next iteration (changes the direaction) 
        }
        return ans;
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
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<int> result = obj.spiralOrder(matrix);

    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}

// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
