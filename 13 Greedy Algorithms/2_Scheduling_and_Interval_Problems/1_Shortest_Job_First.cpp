#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin() , bt.end());
        long long n = bt.size();
        long long sum = 0 ;
        long long curr_sum = 0 ;
        if (n==1) return 0 ;
        for (int i = 0 ; i < n-1 ; i++){
            sum = sum + bt[i];
            curr_sum = curr_sum + sum ;
        }
        return curr_sum / n ;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> bt(n);
    for(int i = 0; i < n; i++) cin >> bt[i];
    cout << sol.solve(bt) << endl;
    return 0;
}