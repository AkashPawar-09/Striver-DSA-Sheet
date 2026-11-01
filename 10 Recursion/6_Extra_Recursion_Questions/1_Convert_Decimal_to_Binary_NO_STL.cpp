/*
Input: n = 12
Output: 1100
Explanation: The binary representation of 12 is "1100", since 12 = 1×2^3 + 1×2^2 + 0×2^1 + 0×2^0

Input: n = 33
Output: 100001
Explanation: The binary representation of 33 is "100001", since 33 = 1×2^5 + 0×2^4 + 0×2^3 + 0×2^2 + 0×2^1 + 1×2^0

*/

# include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void Solve (int n , string &ans){
        if (n == 0){
            return ;
        }
        int rem = n % 2 ;
        
        Solve(n/2,ans);
        string curr = to_string(rem) ;
        ans = ans + curr ;
    }
    string decToBinary(int n) {
        string ans = "" ;
        Solve(n,ans);
        return ans ;
    }
};

int main(){
    int n ; 
    cin >> n ;
    Solution obj ;
    string anss = obj.decToBinary(n);
    cout << anss ;
}

// Time Complexity : O(log N)
// Space Complexity : O(log N)