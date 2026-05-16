/*

// LeetCode 9. Palindrome Number

Example 1 :
Input: n = 121
Output: true
Explanation: When read from left to right : 121.
When read from right to left : 121.

Example 2 : 
Input: n = 123
Output: false
Explanation: When read from left to right : 123.
When read from right to left : 321.
*/



#include<iostream> 
using namespace std ;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int rev = 0;

        while (x > rev) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        return (x == rev || x == rev / 10);
    }
};


int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    Solution obj;   
    int result = obj.isPalindrome(n);  
    cout << result << endl;
    return 0;
}
