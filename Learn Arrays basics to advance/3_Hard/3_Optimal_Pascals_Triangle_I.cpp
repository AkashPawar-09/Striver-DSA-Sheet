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

        int k = c - 1;                              // creating k = c-1

        long long answer = 1;                       // creaing answer variable as 1 as long long d-type

        for (int i = 1; i <= k; i++) {              // iteration through i = 1 to i <= k (i.e. k = number of columns )

            answer = answer * (r - i) / i;      // update answer as per loop iterates 

        }
        
        return answer;                              // return the latest answer 
    }
};


/*

we have used formula as : answer = answer * (n - i + 1) / i 
original foemula :    next_value = previous_value * (N-k) / k       where N = no. of rows & k = column iteration 1 to k

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
// Space Complexity : O(1)
