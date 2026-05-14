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

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int pascalTriangleI(int r, int c) {

        vector<long long> row;                          // creates empty vector named as row to store values

        long long value = 1;                            // creating value variable as 1 & declared as long long beacause middle value can be large 
        row.push_back(value);                           // push_back the value variable because it is 1st row we have to declare 

        for (int k = 1; k < r; k++) {                   // iteration through k = 1 to k = r  
            value = value * (r - k) / k;                // update value as per loop iterates 
            row.push_back(value);                       // push_back new updated row 
        }

        return (int)row[c - 1];                         // return the latest element in row as there is [r-1]
    }
};

/*

In this better approach , 
there is time complexity O(N) because we used only one loop
and in this approach we are not iterating whole pascals triangle 
we are just iterationg the required row and updating the values in the row
then at last we are returning the element which is reqired (i.e. [c-1])


we are using the formula :  value = value * (r-k) / k 
the concept behind this formula comes from formula of nCr 
//          nCr  =  (n-1) C (r-1)  +  (n-1) C r

after simplification of this code , we get :
//          next_value = previous_value * (n-k) / k
where n = number of rows & k = iteration for column 

*/

int main() {

    int r, c;

    cin >> r;
    cin >> c;

    Solution obj;
    int ans = obj.pascalTriangleI(r, c);

    cout << ans << endl;

    return 0;
}


// Time Complextiy : O(N) 
// Space Complexity : O(N) 
