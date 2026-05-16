/*
Input: N = 36
Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]  
Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, 36.
Input: N = 12
Output: [1, 2, 3, 4, 6, 12]
Explanation: The divisors of 12 are 1, 2, 3, 4, 6, 12.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> divisors(int n) {
        
        vector<int> v;

        for (int i = 1 ; i <= n ; i++ ){
            if (n % i == 0){
                v.push_back(i);
            }
        }
        return v ;
    }
};




int main() {
    int n;
    cin >> n;

    Solution obj;
    vector<int> ans = obj.divisors(n);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}


