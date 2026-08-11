#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n = n >> 1;
        }
        return ans;
    }
};




int main() {
    uint32_t n = 43261596;
    Solution obj;
    uint32_t result = obj.reverseBits(n);
    cout << "Reversed bits: " << result << endl;
    return 0;
}



// Time Complexity : O(N)
// Space Complextiy  : O(1)