// Question: If the K-th bit is 1, make it 0; if it is 0, make it 1.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int toggleKthBit(int n, int k) {
        return n ^ (1 << k);
    }
};


int main() {
    Solution obj;
    int n , k ;
    cin >> n >> k ;
    cout << obj.toggleKthBit(n, k);
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