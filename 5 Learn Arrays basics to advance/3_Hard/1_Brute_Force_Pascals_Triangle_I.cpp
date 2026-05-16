/*

Pascal's Triangle : 
Upto 8 rows 

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
1 7 21 35 35 21 7 1

Input : r = 4 , c = 2
Output : 3
Explanation :
Pascal’s Triangle till row 4:
1
1 1
1 2 1
1 3 3 1
Value at row 4 and column 2 is 3.

Input : r = 5 , c = 3
Output : 6
Explanation : 
Pascal’s Triangle till row 5:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
Value at row 5 and column 3 is 6

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {                         // r = rows | c = columns

        vector<vector<int>> triangle;                           // Creating 2D vector named as triangle to store all 1D vector

        for (int i = 0; i < r; i++) {                           // iteration through row , used to pushback new created row

            vector<int> row(i + 1, 1);                          // create a vector with (i+1) elements in it & all elements assign with element as 1
            // it creates new vector everytime as i changes until it creates all row vectors i.e.( i+1 vectors )

            for (int j = 1; j < i; j++) {                       // iteration to fill elements in row vector

                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];   // replace row elements with upper row elememts addition to continue iteration in each row
            }                   // [i-1] = upper row and [j-1] = element before current element in upper row & [j] = current element in upper row

            triangle.push_back(row);                            // push_back crated row everytime when iteration occurs
        }

        return triangle[r - 1][c - 1];                          // return that element as it have indexes as row = [r-1] and column =[c-1]
    }
};

int main() {

    int r, c;

    cin >> r;
    cin >> c;

    Solution obj;
    int ans = obj.pascalTriangleI(r, c);

    cout <<  ans << endl;

    return 0;
}


// Time Complextiy : O(N²)
// Space Complexity : O(N²)
