#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string decimalToBinary(string decimal) {
        int n = stoi(decimal);
        if (n == 0) {return "0";}

        string binary = "";

        while (n > 0) {
            int bit = n % 2;
            binary = binary + char(bit + '0');
            n = n / 2;
        }
        
        reverse(binary.begin(), binary.end());
        
        return binary;
    }
};



int main() {
    Solution obj;
    string decimal;
    cin >> decimal;
    cout << obj.decimalToBinary(decimal);
    return 0;
}




// Time Complexity: O(log N)
// Space Complexity: O(log N)