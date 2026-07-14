/*

Input: n = 36
Output: 6
Explanation: 6 is the square root of 36.


Input: n = 28
Output: 5
Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.


Input: n=50
Output: 7

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int floorSqrt(int n) {
        int ans = -1;

        for (int i = 0; i <= n; i++) {
            if (1LL * i * i <= n) {
                ans = i;
            }
            else {
                break;
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.floorSqrt(n) << endl;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)