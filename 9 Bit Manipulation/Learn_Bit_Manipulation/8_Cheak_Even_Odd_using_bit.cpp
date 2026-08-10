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