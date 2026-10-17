#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n = val.size();

        vector<pair<double, int>> items;

        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }

        sort(items.rbegin(), items.rend());

        double ans = 0;

        for(auto x : items) {
            int i = x.second;
            if(capacity >= wt[i]) {
                ans += val[i];
                capacity -= wt[i];
            }
            else {
                ans += ((double)val[i] / wt[i]) * capacity;
                break;
            }
        }

        return ans;
    }
};



int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<long long> val(n), wt(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++) cin >> wt[i];
    long long capacity;
    cin >> capacity;
    cout << fixed << setprecision(6) << sol.fractionalKnapsack(val, wt, capacity) << endl;
    return 0;
}