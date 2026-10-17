#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size() ;
        int n2 = s.size() ;
        int gs = 0 ; 
        int ss = 0 ; 
        int count = 0 ; 

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        while(gs < n1 && ss < n2) {
            if(g[gs] <= s[ss]) {
                gs++;
                ss++;
                count++;
            }
            else {
                ss++;
            }
        }

        return count ;
    }
};

int main() {
    Solution sol;
    int n, m;
    cin >> n;
    vector<int> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    cin >> m;
    vector<int> s(m);
    for(int i = 0; i < m; i++) cin >> s[i];
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}