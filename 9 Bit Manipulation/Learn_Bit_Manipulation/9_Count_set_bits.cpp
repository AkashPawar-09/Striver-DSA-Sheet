#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count = count + (n & 1);
            n = n >> 1;
        }
        return count;
    }
};



int main() {
    Solution obj;
    int n ;
    cin >> n ;
    cout << obj.countSetBits(n);
    return 0;
}



// Time Complexity: O(log n)
// Space Complexity: O(1)