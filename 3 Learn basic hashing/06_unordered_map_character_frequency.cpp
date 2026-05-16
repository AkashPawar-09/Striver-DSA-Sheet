#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencyQuery(string& s, vector<char>& queries) {
        unordered_map<char, int> freq;

        // precompute
        for(char ch : s) {
            freq[ch]++;
        }

        // answer queries
        vector<int> result;
        for(char q : queries) {
            result.push_back(freq[q]);
        }

        return result;
    }
};

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<char> queries(q);
    for(int i = 0; i < q; i++) cin >> queries[i];

    Solution obj;
    vector<int> ans = obj.frequencyQuery(s, queries);

    for(int x : ans) {
        cout << x << endl;
    }

    return 0;
}