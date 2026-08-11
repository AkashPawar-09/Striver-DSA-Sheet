/*
1  → true
2  → true
4  → true
8  → true
16 → true

6  → false
10 → false

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};



int main() {
    Solution obj;
    int n;
    cin >> n;
    cout << boolalpha << obj.isPowerOfTwo(n);
    return 0;
}




// Time Complexity: O(N)
// Space Complexity: O(1)