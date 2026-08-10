#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int clearKthBit(int n, int k) {
        return n =  n ^ (1 << k);
    }
};


int main() {
    Solution obj;
    int n , k;
    cin >> n >> k ;
    cout << obj.clearKthBit(n, k);
    return 0;
}




// Time Complexity: O(1)
// Space Complexity: O(1)