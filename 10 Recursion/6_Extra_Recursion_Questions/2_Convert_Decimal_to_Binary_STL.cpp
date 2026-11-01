/*
Input: n = 12
Output: 1100
Explanation: The binary representation of 12 is "1100", since 12 = 1×2^3 + 1×2^2 + 0×2^1 + 0×2^0

Input: n = 33
Output: 100001
Explanation: The binary representation of 33 is "100001", since 33 = 1×2^5 + 0×2^4 + 0×2^3 + 0×2^2 + 0×2^1 + 1×2^0

input : n = 15 
Output : 1111

input : n = 16
Output : 100000

*/


# include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    string decToBinary(int n) {
       string bin = bitset<32>(n).to_string();
       int i = 0;
        for(i = 0; i < bin.length(); i++) {
            if (bin[i] != '0') {
                break;
            }
        }
        if (i == bin.length()) return "0";
        return bin.substr(i);
       
    }
};


int main(){
    int n ; 
    cin >> n ;
    Solution obj ;
    string anss = obj.decToBinary(n);
    cout << anss ;
}


// Time Complexity : O(1)
// Space Complexity : O(1)