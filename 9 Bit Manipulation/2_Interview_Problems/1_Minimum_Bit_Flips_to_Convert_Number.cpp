#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;

        return countSetBits(n);
    }

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

    int start = 10;
    int goal = 7;

    Solution obj;

    int result = obj.minBitFlips(start, goal);

    cout << "Start: " << start << endl;
    cout << "Goal: " << goal << endl;
    cout << "Minimum bit flips: " << result << endl;

    return 0;
}



// Time Complexity : O(log n)
// Space Complexity : O(1)