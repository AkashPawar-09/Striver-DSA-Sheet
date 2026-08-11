// Question: Set the K-th bit of n to 1.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int setKthBit(int n, int k) {
        return n | (1 << k);
    }
};


int main() {
    Solution obj;
    int n , k;
    cin >> n >> k ;
    cout << obj.setKthBit(n, k);
    return 0;
}



// Time Complexity: O(1)
// Space Complexity: O(1)


/*

1 << 0 = 1
1 << 1 = 2
1 << 2 = 4
1 << 3 = 8
1 << 4 = 16
1 << 5 = 32

*/