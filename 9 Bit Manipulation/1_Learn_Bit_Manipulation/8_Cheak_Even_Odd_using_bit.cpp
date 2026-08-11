// Question: Check whether a number is odd or even using bit manipulation.

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isEven(int n) {
        return (n & 1) == 0;
    }
};



int main() {
    Solution obj;
    int n ;
    cin >> n ;
    if (obj.isEven(n))
        cout << "Even";
    else
        cout << "Odd";

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