#include <iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        if (start >= end) {return true;}
        if (s[start] != s[end]) {return false;}
        return isPalindrome(s, start + 1, end - 1);
    }
};


int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    if (obj.isPalindrome(s, 0, s.size() - 1))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}




// Time Complexity : O(N/2)
// Space Complexity : O(N)