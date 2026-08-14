#include<bits/stdc++.h>
using namespace std;





class Solution {
public:
    long long power(long long a, long long b) {
        long long ans = 1;
        long long MOD = 1000000007;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b = b / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even_idx = (n + 1) / 2;
        long long odd_idx = n / 2;

        long long ans = 1;

        ans = (ans * power(5, even_idx)) % 1000000007;
        ans = (ans * power(4, odd_idx)) % 1000000007;

        return ans;
    }
};




int main() {
    Solution obj;

    long long n;
    cin >> n;

    cout << obj.countGoodNumbers(n);

    return 0;
}



// Time Complexity: O(log N)
// Space Complexity: O(1) 