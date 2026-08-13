#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
    int findRangeXOR(int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans = ans ^ i;
        }
        return ans;
    }
};


int main() {
    Solution obj;
    int l, r;
    cin >> l >> r;
    cout << obj.findRangeXOR(l, r);
    return 0;
}


// Time Coplexity : O(N)
// Space Complexity : O(1)