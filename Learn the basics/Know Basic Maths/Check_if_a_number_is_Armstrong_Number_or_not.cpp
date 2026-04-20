/*
Example 1:
Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153
                                        
Example 2:
Input:N = 371                
Output: True
Explanation: 3^3+7^3+1^3 = 27 + 343 + 1 = 371
            
*/

#include <iostream>
using namespace std;




class Solution {
public:
    bool isArmstrong(int n) {
        int original = n;

        // count digits
        int digits = 0;
        for (int temp = n; temp > 0; temp /= 10) {
            digits++;
        }

        // handle n = 0 case
        if (original == 0) digits = 1;

        int sum = 0;

        // calculate sum of powers
        for (int temp = n; temp > 0; temp /= 10) {
            int digit = temp % 10;

            int power = 1;
            for (int i = 0; i < digits; i++) {
                power *= digit;
            }

            sum += power;
        }

        return sum == original;
    }
};



int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.isArmstrong(n);

    return 0;
}

// Time Complexity:O((log n)²)
// Space Complexity: O(1)