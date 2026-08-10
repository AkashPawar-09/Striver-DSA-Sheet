#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int convert2Decimal(string x) {
//         int len = x.length();
//         int p2 = 1;
//         int ans = 0;

//         for (int i = len - 1; i >= 0; i--) {
//             if (x[i] == '1') {
//                 ans = ans + p2;
//             }

//             p2 = p2 * 2;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int BinaryToDecimal(string x) {
        if (x == "0" || x == "") {return 0;}        // if x is 0 OR empty , return 0
        if (x == "1") {return 1;}                   // if x = 1 return 1
        int len = x.length();                       // find lenght of x (starts from 2)
        reverse(x.begin(), x.end());                // reverse x string
        int ans = 0;                                // initilise ans = 0 ;
        for (int i = 0; i < len; i++) {             // loop from 0 to len
            ans = ans + (x[i] - '0') * pow(2, i);   // ans = ans + char in x * 2 raised to i
        }
        return ans;                                 // return ans 
    }
};




int main() {
    Solution obj;
    string x;
    cin >> x;
    cout << obj.BinaryToDecimal(x);
    return 0;
}



// Time Complexity: O(N)
// Space Complexity: O(1)