#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        int n = Jobs.size();
        sort(Jobs.begin(), Jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });
        vector<int> slot(n + 1, 0);
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            int deadline = min(Jobs[i][1], n);
            for(int j = deadline; j > 0; j--) {
                if(slot[j] == 0) {
                    slot[j] = 1;
                    count++;
                    profit += Jobs[i][2];
                    break;
                }
            }
        }
        return {count, profit};
    }
};


int main() {
    int n;
    cin >> n;
    vector<vector<int>> Jobs(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> Jobs[i][0] >> Jobs[i][1] >> Jobs[i][2];
    }
    Solution obj;
    vector<int> ans = obj.JobScheduling(Jobs);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}


// Time Complexity : O(N logN + N²)
// Space Complexity : O(N)