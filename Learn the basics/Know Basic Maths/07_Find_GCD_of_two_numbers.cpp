/*
Example 1:
Input: N1 = 9, N2 = 12
Output: 3
Explanation:
Factors of 9: 1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3
Greatest common factor: 3 (GCD)

Example 2:
Input: N1 = 20, N2 = 15
Output: 5
Explanation:
Factors of 20: 1, 2, 4, 5, 10, 20
Factors of 15: 1, 3, 5, 15
Common Factors: 1, 5
Greatest common factor: 5 (GCD)
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int GCD(int n1,int n2) {
        int gcd ;
        int greater = max(n1,n2) ;
        for (int i=1 ; i<= greater ; i++){
            if (n1 % i == 0 && n2 % i == 0 )
                gcd = i ;
        }
        return gcd ;
    }
};


int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Solution obj;
    int result = obj.GCD(n1, n2);

    cout << result << endl;
    return 0;
}