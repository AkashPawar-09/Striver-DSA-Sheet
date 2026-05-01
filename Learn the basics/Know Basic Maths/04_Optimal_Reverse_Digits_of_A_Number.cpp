/*
// LeetCode 7. Reverse Integer


Example 1 : 
Input: N = 12345
Output:54321
Explanation: The reverse of 12345 is 54321.

Example 2 : 
Input: N = 7789                
Output: 9877
Explanation: The reverse of number 7789 is 9877.
*/


#include <bits/stdc++.h>
#include <climits>
using namespace std;
class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;

        while (n != 0) {
            int digit = n % 10;

            // Overflow check
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }

            rev = rev * 10 + digit;
            n = n / 10;
        }

        return rev;
    }
};



int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.reverseNumber(n); 
    cout << result << endl;
    return 0;
}
